ALTER procedure [dbo].[sp_loaddata]

as

declare @tablename varchar(100)
declare	@sql nvarchar(max)
declare @statement1 varchar(max)
declare @statement2 varchar(max)

-- get the table names from the database
declare table_cursor cursor for
select table_name
from information_schema.tables
where table_type = 'BASE TABLE'
and objectproperty(object_id(table_name), 'IsMsShipped') = 0

-- get the first table name
open table_cursor
fetch next from table_cursor into @tablename

--  repeat the following until we are through the list
while @@fetch_status = 0
begin

	--Truncate the acuheader table
	EXEC('TRUNCATE TABLE `' + @tablename + '`') AT [HELIVALUESMYSQL]
	-- generate the sql to insert the data
	set @statement1 = dbo.fnColList(@tablename)
	set @statement2 = dbo.fnColListMysql(@tablename)

	set @sql = N'INSERT OPENQUERY([HELIVALUESMYSQL],''SELECT ' + @statement2 + ' FROM `' + @tablename + '`'')
	SELECT ' + @statement1 + ' 
	FROM [HelivaluesSQL].dbo.' + @tablename

	--select @statement1
	--select @statement2
	--select @sql
	--execute the sql from above
	--exec sp_executesql @sql

	-- get the next table name
	fetch next from table_cursor into @tablename
end

close table_cursor
deallocate table_cursor
GO