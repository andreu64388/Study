/*5. Разработать сценарий, который демон-стрирует на примере базы данных X_UNIVER, 
что проверка ограничения целостности выпол-няется до срабатывания 
AFTER-триггера.*/

USE UNIVER
GO

UPDATE TEACHER SET GENDER = 'Ж' WHERE TEACHER='КРАВ'
 SELECT * FROM TR_AUDIT