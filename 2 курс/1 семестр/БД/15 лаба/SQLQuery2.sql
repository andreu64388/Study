/*2. ����������� �������� �������� XML-��������� � ������ AUTO �� ������ SELECT-������� � 
�������� AUDITORIUM � AUDI-TORIUM_TYPE, ������� �������� ������-��� �������: ������������ 
���������, �����-������� ���� ��������� � �����������. ����� ������ ���������� ���������*/

--------------------------------------
---------------UNIVER-----------------
--------------------------------------
USE UNIVER;
GO
SELECT AUDITORIUM.AUDITORIUM [���������], AUDITORIUM.AUDITORIUM_TYPE [���],AUDITORIUM.AUDITORIUM_CAPACITY [�����������] 
FROM AUDITORIUM JOIN AUDITORIUM_TYPE ON AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE
WHERE AUDITORIUM.AUDITORIUM_TYPE = '��' FOR XML AUTO, ROOT('������'),ELEMENTS ;

--------------------------------------
-----------------BANK-----------------
--------------------------------------
USE BANK;
GO
SELECT �����_������� [�����],ID [ID],����� [�����] FROM ���������� FOR XML AUTO, ROOT('���');
