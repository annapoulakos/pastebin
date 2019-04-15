--Msg 257, Level 16, State 3, Server HI-SBS01\EBIZ, Line 1
--Implicit conversion from data type datetime to int is not allowed. Use the CONVERT function to run this query.
--------------------------------------------------------------------------------------------------------------
INSERT OPENQUERY([HELIVALUESMYSQL],'SELECT * FROM `heli_economic_obsolescence`')
SELECT *
FROM dbo.heli_economic_obsolescence
--(0 rows affected)


--Msg 257, Level 16, State 3, Server HI-SBS01\EBIZ, Line 1
--Implicit conversion from data type datetime to int is not allowed. Use the CONVERT function to run this query.
--------------------------------------------------------------------------------------------------------------
INSERT OPENQUERY([HELIVALUESMYSQL],'SELECT * FROM `helicopter_rcn`')
SELECT *
FROM dbo.helicopter_rcn

--(0 rows affected)
