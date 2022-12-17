/*5. Разработать сценарий, который демон-стрирует на примере базы данных X_UNIVER, 
что проверка ограничения целостности выпол-няется до срабатывания 
AFTER-триггера.*/

--------------------------------------------
------------------UNIVER--------------------
--------------------------------------------
USE UNIVER
GO
INSERT INTO TEACHER(TEACHER,TEACHER_NAME,GENDER,PULPIT)
VALUES(1,2,4,4)
UPDATE TEACHER SET GENDER = 'Ж54' WHERE TEACHER='КРАВ'

 SELECT * FROM TR_AUDIT
 SELECT *FROM TEACHER


update TEACHER set PULPIT = 'ИСиТ' where TEACHER = 'ФЫВ'