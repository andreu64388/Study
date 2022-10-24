/*4. Разработать и создать представление с именем Лекционные_аудитории. 
Представление должно быть построено на основе SELECT-запроса к таблице AUDITORIUM и содержать следующие столбцы: код (AUDITORIUM), наименование аудитории (AUDITORIUM_NAME). 
Представление должно отображать только лекционные аудитории (в столбце AUDITORIUM_TYPE строка, начинающаяся с символов ЛК). 
Выполнение INSERT и UPDATE допускается, но с учетом ограничения, задаваемого опцией WITH CHECK OPTION. */

USE UNIVER;
GO 
CREATE VIEW  [Лекционные аудитории] (AUDITORIUM_TYPE,AUDITORIUM)
as select AUDITORIUM.AUDITORIUM_TYPE as [наименование аудитории],
AUDITORIUM.AUDITORIUM as [код]
FROM AUDITORIUM
WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE 'ЛК%' WITH CHECK OPTION

SELECT * FROM [Лекционные аудитории]
-----------------------------------
USE BANK;
GO
CREATE VIEW [Банки_test] 
AS SELECT БАНК.id [Код],
БАНК.Назаание_кредита [Название кредита],
БАНК.Ставка [Ставка]
FROM БАНК
WHERE Ставка > 10 WITH CHECK OPTION

SELECT * FROM [Банки_test]