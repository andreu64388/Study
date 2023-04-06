/*9. ������� DDL-�������, ����������� �� ��� DDL-������� � �� UNIVER.
������� ���-��� ��������� ��������� ����� ������� � ���-���� ������������. 
���� ���������� ������� ������ ������������ ����������, ������� ��������:
��� �������, ��� � ��� �������, � ����� ������������� �����, � ������ �������-��� ���������� ���������. 
����������� ��������, ��������������� ������ ��������. 

*/

USE UNIVER

GO

CREATE TRIGGER TR_TEACHER_DDL ON DATABASE FOR DDL_DATABASE_LEVEL_EVENTS  
AS   
DECLARE @EVENT_TYPE VARCHAR(50) = EVENTDATA().VALUE('(/EVENT_INSTANCE/EVENTTYPE)[1]', 'VARCHAR(50)')
DECLARE @OBJ_NAME VARCHAR(50) = EVENTDATA().VALUE('(/EVENT_INSTANCE/OBJECTNAME)[1]', 'VARCHAR(50)')
DECLARE @OBJ_TYPE VARCHAR(50) = EVENTDATA().VALUE('(/EVENT_INSTANCE/OBJECTTYPE)[1]', 'VARCHAR(50)')
IF @OBJ_NAME = 'TEACHER' 
BEGIN
       PRINT '��� �������: '+@EVENT_TYPE;
       PRINT '��� �������: '+@OBJ_NAME;
       PRINT '��� �������: '+@OBJ_TYPE;
       RAISERROR( N'�������� � �������� ������ ���������', 16, 1);  
ROLLBACK  
END

ALTER TABLE TEACHER DROP COLUMN TEACHER_NAME

SELECT * FROM TEACHER

DROP TRIGGER TR_TEACHER_DDL
DROP TABLE TR_AUDIT