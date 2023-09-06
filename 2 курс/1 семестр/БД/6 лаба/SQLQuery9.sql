/*9. �������� ������� ����� ���������� �����, ��������� � ���������� �������� ������ 8.
 ��������� ���������.
������������ �������� EXCEPT.*/
use UNIVER;

select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = '���'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION
select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = '����'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
EXCEPT
select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = '���'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION
UNION ALL
select GROUPS.PROFESSION, P.SUBJECT, AVG(NOTE) as AVERAGE_NOTE
from GROUPS
         join STUDENT S on GROUPS.IDGROUP = S.IDGROUP and GROUPS.FACULTY = '����'
         join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by P.SUBJECT, GROUPS.PROFESSION




------------------------------------------
USE BANK;
SELECT ����.��������_�������,
����.������, 
avg(����������.�����)
FROM ���� 
Full JOIN ���������� ON ����.id = ����������.id
GROUP BY ��������_�������,������
EXCEPT
SELECT ����.��������_�������,
����.������, 
avg(����������.�����)
FROM ���� 
JOIN ���������� ON ����.id = ����������.id
GROUP BY ��������_�������,������