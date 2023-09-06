use UNIVER;

SELECT PROFESSION,SUBJECT,G.FACULTY , AVG(NOTE) AS [������� ����]
from FACULTY join GROUPS G on FACULTY.FACULTY = G.FACULTY and G.FACULTY = '����'
join STUDENT S on G.IDGROUP = S.IDGROUP
join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by  cube (G.FACULTY,PROFESSION,SUBJECT)

/*6. ��������� �������� SELECT-������ �.5 � �������������� CUBE-�����������. ���������������� ���������.*/

--------------------------------------------------

USE BANK;
SELECT ����.��������_�������,
����.������, 
avg(����������.�����)
FROM ���� 
JOIN ���������� ON ����.id = ����������.id
GROUP BY cube(��������_�������,������)