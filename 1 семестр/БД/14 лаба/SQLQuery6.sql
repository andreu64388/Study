/*6. Создать для таблицы TEACHER три AF-TER-триггера с именами: TR_TEACHER_ DEL1, TR_TEACHER_DEL2 и TR_TEA-CHER_ DEL3. Триггеры должны реагировать на событие DELETE и формировать соответ-ствующие строки в таблицу TR_AUDIT.  По-лучить список триггеров таблицы TEACHER. 
Упорядочить выполнение триггеров для таб-лицы TEACHER, реагирующих на событие DELETE следующим образом: первым должен выполняться триггер с именем TR_TEA-CHER_DEL3, последним – триггер TR_TEACHER_DEL2. 
Примечание: использовать системные пред-ставления SYS.TRIGGERS и SYS.TRIG-GERS_ EVENTS, а также системную процеду-ру SP_SETTRIGGERORDERS. 

*/

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

DELETE TEACHER WHERE TEACHER='КРАВ'


SELECT T.NAME, E.TYPE_DESC
  FROM SYS.TRIGGERS  T JOIN  SYS.TRIGGER_EVENTS E  ON T.OBJECT_ID = E.OBJECT_ID
  WHERE OBJECT_NAME(T.PARENT_ID)='TEACHER' AND E.TYPE_DESC = 'DELETE' ;

EXEC  SP_SETTRIGGERORDER @TRIGGERNAME = 'TEACH_AFTER_DEL3',
	                        @ORDER='FIRST', @STMTTYPE = 'DELETE';
EXEC  SP_SETTRIGGERORDER @TRIGGERNAME = 'TEACH_AFTER_DEL2',
	                        @ORDER='LAST', @STMTTYPE = 'DELETE';