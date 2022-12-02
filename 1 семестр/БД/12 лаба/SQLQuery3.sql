/*3. Создать временную локальную таблицу с именем #SUBJECT. Наименование и тип столбцов таблицы должны соответствовать столбцам результирующего набора процедуры
XPSUBJECT, разработанной в зада-нии 2. 
Изменить процедуру PSUBJECT таким образом, чтобы она не содержала выходного параметра.
Применив конструкцию INSERT… EXECUTE с мо-дифицированной процедурой PSUBJECT, добавить строки в таблицу #SUBJECT. 
*/
------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------
USE UNIVER;
GO
ALTER PROCEDURE PSUBJECT @P VARCHAR(20)
AS BEGIN
	SELECT * FROM SUBJECT WHERE SUBJECT = @P;
END;
GO
CREATE TABLE #SUBJECTS
(
	[SUBJECT] VARCHAR(20),
	[SUBJECT_NAME] VARCHAR(100),
	[PULPIT] VARCHAR(20)
);
GO
INSERT #SUBJECTS EXEC PSUBJECT @P = 'ООП';
INSERT #SUBJECTS EXEC PSUBJECT @P = 'ОАИП';

SELECT * FROM #SUBJECTS;
SELECT * FROM SUBJECT

------------------------------------------------
----------------------BANK----------------------
------------------------------------------------
USE BANK;
GO
ALTER PROCEDURE PBANK @ID INT
AS BEGIN
	SELECT * FROM КРЕДИТ WHERE ID_CLIENT = @ID;
END;
GO
CREATE TABLE #BANK_
(
  NOMER_CR INT,
  ID_CL INT
);
GO
INSERT #BANK_ EXEC PBANK @ID = 10;
INSERT #BANK_ EXEC PBANK @ID=11;

SELECT * FROM #BANK_;
