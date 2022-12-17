/*2. Разработать сценарий создания XML-документа в режиме AUTO на основе SELECT-запроса к 
таблицам AUDITORIUM и AUDI-TORIUM_TYPE, который содержит следую-щие столбцы: наименование 
аудитории, наиме-нование типа аудитории и вместимость. Найти только лекционные аудитории*/

--------------------------------------
---------------UNIVER-----------------
--------------------------------------
USE UNIVER;
GO
SELECT AUDITORIUM.AUDITORIUM [АУДИТОРИЯ], AUDITORIUM.AUDITORIUM_TYPE [ТИП],AUDITORIUM.AUDITORIUM_CAPACITY [ВМЕСТИМОСТЬ] 
FROM AUDITORIUM JOIN AUDITORIUM_TYPE ON AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE
WHERE AUDITORIUM.AUDITORIUM_TYPE = 'ЛК' FOR XML AUTO, ROOT('СПИСОК');


--------------------------------------
-----------------BANK-----------------
--------------------------------------