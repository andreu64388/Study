/*1. ����������� �������� �������� XML-��������� � ������ PATH �� ������� TEACHER
��� �������������� ������� ����. */


--------------------------------------
---------------UNIVER-----------------
--------------------------------------

USE UNIVER;
GO
SELECT PULPIT.FACULTY[���������], TEACHER.PULPIT[�������], TEACHER.TEACHER_NAME[�������������]
FROM TEACHER INNER JOIN PULPIT ON TEACHER.PULPIT = PULPIT.PULPIT
WHERE TEACHER.PULPIT = '����' FOR XML RAW, ROOT('�������������_����'),ELEMENTS;

--------------------------------------�
-----------------BANK-----------------
--------------------------------------
USE BANK;
GO
SELECT ID [ID], ������ [������] FROM ���� FOR XML PATH ,ROOT('����')