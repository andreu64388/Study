/*6. ������� ��� ������� TEACHER ��� AF-TER-�������� � �������: TR_TEACHER_ DEL1, TR_TEACHER_DEL2 � TR_TEA-CHER_ DEL3. �������� ������ ����������� �� ������� DELETE � ����������� �������-�������� ������ � ������� TR_AUDIT.  ��-������ ������ ��������� ������� TEACHER. 
����������� ���������� ��������� ��� ���-���� TEACHER, ����������� �� ������� DELETE ��������� �������: ������ ������ ����������� ������� � ������ TR_TEA-CHER_DEL3, ��������� � ������� TR_TEACHER_DEL2. 
����������: ������������ ��������� ����-��������� SYS.TRIGGERS � SYS.TRIG-GERS_ EVENTS, � ����� ��������� �������-�� SP_SETTRIGGERORDERS. 

*/

--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------
USE UNIVER
GO
CREATE TRIGGER TEACH_AFTER_DEL1 ON TEACHER AFTER DELETE
AS PRINT '1';
 RETURN;
GO
CREATE TRIGGER TEACH_AFTER_DEL2 ON TEACHER AFTER DELETE
AS PRINT '2';
 RETURN;
GO
CREATE TRIGGER TEACH_AFTER_DEL3 ON TEACHER AFTER DELETE
AS PRINT '3';
 RETURN;
GO

DELETE TEACHER WHERE TEACHER='����'


SELECT T.NAME, E.TYPE_DESC
  FROM SYS.TRIGGERS  T JOIN  SYS.TRIGGER_EVENTS E  ON T.OBJECT_ID = E.OBJECT_ID
  WHERE OBJECT_NAME(T.PARENT_ID)='TEACHER' AND E.TYPE_DESC = 'DELETE' ;

EXEC  SP_SETTRIGGERORDER @TRIGGERNAME = 'TEACH_AFTER_DEL3',
	                        @ORDER='FIRST', @STMTTYPE = 'DELETE';
EXEC  SP_SETTRIGGERORDER @TRIGGERNAME = 'TEACH_AFTER_DEL2',
	                        @ORDER='LAST', @STMTTYPE = 'DELETE';




--------------------------------------------
--------------------BANK--------------------
--------------------------------------------
USE BANK
GO
CREATE TRIGGER BANK_AFTER_DEL1 ON ���� AFTER DELETE
AS PRINT '1';
 RETURN;
GO
CREATE TRIGGER BANK_AFTER_DEL2 ON ���� AFTER DELETE
AS PRINT '2';
 RETURN;
GO
CREATE TRIGGER BANK_AFTER_DEL3 ON ���� AFTER DELETE
AS PRINT '3';
 RETURN;
GO

DELETE ���� WHERE ID=5


SELECT T.NAME, E.TYPE_DESC
  FROM SYS.TRIGGERS  T JOIN  SYS.TRIGGER_EVENTS E  ON T.OBJECT_ID = E.OBJECT_ID
  WHERE OBJECT_NAME(T.PARENT_ID)='����' AND E.TYPE_DESC = 'DELETE' ;

EXEC  SP_SETTRIGGERORDER @TRIGGERNAME = 'BANK_AFTER_DEL3',
	                        @ORDER='FIRST', @STMTTYPE = 'DELETE';
EXEC  SP_SETTRIGGERORDER @TRIGGERNAME = 'BANK_AFTER_DEL2',
	                        @ORDER='LAST', @STMTTYPE = 'DELETE';