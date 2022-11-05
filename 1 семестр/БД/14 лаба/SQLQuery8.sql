/*8.  Для таблицы FACULTY создать IN-STEAD OF-триггер, запрещающий удаление строк в таблице. 
Разработать сценарий, который демонстри-рует на примере базы данных X_UNIVER, что проверка ограничения целостности выполнена, если есть INSTEAD OF-триггер.
С помощью оператора DROP удалить все DML-триггеры, созданные в этой лабораторной работе.
*/
USE UNIVER
GO
	CREATE TRIGGER F_INSTEAD_OF
	ON FACULTY INSTEAD OF DELETE
	AS
	    BEGIN
RAISERROR(N'УДАЛЕНИЕ ЗАПРЕЩЕНО', 10, 1);

END;
	RETURN;

 DELETE FACULTY WHERE FACULTY = 'NEW';

DROP TRIGGER F_INSTEAD_OF,PTRAN,TEACH_AFTER_DEL1,TEACH_AFTER_DEL2,TEACH_AFTER_DEL3,TR_TEACHER