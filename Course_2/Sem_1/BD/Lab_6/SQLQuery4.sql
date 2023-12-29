/*4. ����������� SELECT-������� �� ������ ������ FACULTY, GROUPS, STUDENT � PROGRESS, ������� �������� �������
��������������� ������ ��� ������� ���-�� ������ �������������. 
������ �������-������ � ������� �������� ������� ������.��� ���� ������� ������,
��� ������� ������ ������ �������������� � ��������� �� ���� ������ ����� �������.
��������-���� ���������� ���������� ������, ����-������ ������� AVG � ���������� ����-��� CAST � ROUND.*/
use UNIVER
select a.FACULTY,
       G.PROFESSION,
       (2014 - G.YEAR_FIRST ) [����],
       round(avg(cast(NOTE as float(4))), 2) as [������� ������]
from FACULTY a
         join GROUPS G on a.FACULTY = G.FACULTY
         join STUDENT S on G.IDGROUP = S.IDGROUP
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by a.FACULTY, G.PROFESSION, G.YEAR_FIRST



/*���������� SELECT-������, ����������-��� � ������� 4 ���,
����� � ������� ����-���� �������� ������ �������������� ����-�� ������ �� ����������� �
������ �� � ����. ������������ WHERE.*/



select a.FACULTY,	
       G.PROFESSION,
       (2014 - G.YEAR_FIRST) [����],
       round(avg(cast(NOTE as float(4))), 2) as [������� ������]
from FACULTY a
         join GROUPS G on a.FACULTY = G.FACULTY
         join STUDENT S on G.IDGROUP = S.IDGROUP
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT and P.SUBJECT in ('����','����')
group by a.FACULTY, G.PROFESSION, G.YEAR_FIRST



-----------------------------------
USE BANK;
SELECT ����.��������_�������,
����.������, 
avg(����������.�����)
FROM ���� 
JOIN ���������� ON ����.id = ����������.id
GROUP BY ��������_�������,������