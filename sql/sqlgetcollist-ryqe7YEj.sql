create function fnColListMysql(@in_vcTbl_name varchar(8000))
returns varchar(8000)
as
begin 
declare @colList2BuildAuditTable  varchar(max)
SELECT @colList2BuildAuditTable = coalesce(@colList2BuildAuditTable+ ',', '')+ '`'+ B.NAME +'`' 
FROM SYSOBJECTS A JOIN SYSCOLUMNS B ON A.ID = B.ID
WHERE A.ID = OBJECT_ID(@in_vcTbl_name)
ORDER BY B.COLORDER

return @colList2BuildAuditTable 
end 

create function fnColList(@in_vcTbl_name varchar(8000))
returns varchar(8000)
as
begin 
declare @colList2BuildAuditTable  varchar(max)
SELECT @colList2BuildAuditTable = coalesce(@colList2BuildAuditTable+ ',', '')+ '['+ B.NAME +']' 
FROM SYSOBJECTS A JOIN SYSCOLUMNS B ON A.ID = B.ID
WHERE A.ID = OBJECT_ID(@in_vcTbl_name)
ORDER BY B.COLORDER

return @colList2BuildAuditTable 
end