/*1. пюгпюанрюрэ яжемюпхи янгдюмхъ XML-днйслемрю б пефхле PATH хг рюакхжш TEACHER
дкъ опеондюбюрекеи йютедпш хяхр. */


--------------------------------------
---------------UNIVER-----------------
--------------------------------------

USE UNIVER;
GO
SELECT PULPIT.FACULTY[тюйскэрер], TEACHER.PULPIT[йютедпю], TEACHER.TEACHER_NAME[опеондюбюрекэ]
FROM TEACHER INNER JOIN PULPIT ON TEACHER.PULPIT = PULPIT.PULPIT
WHERE TEACHER.PULPIT = 'хяхр' FOR XML PATH, ROOT('опеондюбюрекх_хяхр');

--------------------------------------
-----------------BANK-----------------
--------------------------------------