SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		Jim P <jimp@ebizresults.com>
-- Create date: 2012-09-13
-- Description:	This function Generates a comma separated list of column names in MS SQL format
-- =============================================
CREATE FUNCTION fnColListMssql 
(
	@tablename nvarchar(max)
)
RETURNS nvarchar(max)
AS
BEGIN
	DECLARE @return nvarchar(max)

	SELECT @return = coalesce(@return+ ',', '') + '[' + B.NAME + ']' 
	FROM SYSOBJECTS A JOIN SYSCOLUMNS B ON A.ID = B.ID
	WHERE A.ID = OBJECT_ID(@tablename)
	ORDER BY B.COLORDER

	RETURN @return

END
GO