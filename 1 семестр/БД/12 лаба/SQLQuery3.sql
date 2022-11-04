/*3. Создать временную локальную таблицу с именем #SUBJECT. Наименование и тип столбцов таблицы должны соответствовать столбцам результирующего набора процедуры PSUBJECT, разработанной в зада-нии 2. 
Изменить процедуру PSUBJECT таким образом, чтобы она не содержала выходного параметра.
Применив конструкцию INSERT… EXECUTE с мо-дифицированной процедурой PSUBJECT, добавить строки в таблицу #SUBJECT. 
*/
USE UNIVER;
CREATE TABLE #SUBJECT
(
SUBJ NVARCHAR(20),
SUBJ_NAME NVARCHAR(300),
PULP NVARCHAR(20)
)

GO
ALTER PROCEDURE PSUBJECT @P VARCHAR(20) = NULL AS
BEGIN
SELECT SUBJECT [КОД], SUBJECT_NAME [ДИСЦИПЛИНА], PULPIT [КАФЕДРА] FROM SUBJECT WHERE PULPIT = @P;
END
GO

GO
INSERT #SUBJECT EXEC PSUBJECT @P = 'ИСИТ'
INSERT #SUBJECT EXEC PSUBJECT @P = 'ЛУ'
SELECT * FROM #SUBJECT

drop table #SUBJECT