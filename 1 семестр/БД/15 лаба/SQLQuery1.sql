/*1. Разработать сценарий создания XML-документа в режиме PATH из таблицы TEACHER
для преподавателей кафедры ИСиТ. */

USE UNIVER;


SELECT * FROM TEACHER 
JOIN PULPIT ON TEACHER.PULPIT = PULPIT.PULPIT
 WHERE TEACHER.PULPIT = 'ИСИТ' FOR XML PATH, ROOT('СПИСОК_ПРЕПОДАВАТЕЛЕЙ_КАФЕДРЫ_ИСИТ');