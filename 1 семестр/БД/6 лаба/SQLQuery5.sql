/*5. �� ������ ������ FACULTY,GROUPS, STUDENT � PROGRESS �����-������ SELECT-������,
� ������� �������-�� �������������, ���������� � ������� ������ ��� ����� ��������� ��
���������� ���. ������������ ����������� �� ����� FACULTY, PROFESSION, SUBJECT.
 �������� � ������ ����������� ROLLUP � ���������������� ���������. */

/*��������� ������ �� ����, ��� ��� ������ ��� �� �������� �����
*/

use UNIVER;

SELECT PROFESSION,SUBJECT,G.FACULTY , AVG(NOTE) AS [������� ����]
from FACULTY join GROUPS G on FACULTY.FACULTY = G.FACULTY and G.FACULTY = '����'
join STUDENT S on G.IDGROUP = S.IDGROUP
join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by  rollup (SUBJECT,G.FACULTY,PROFESSION) 
SELECT PROFESSION,SUBJECT,G.FACULTY , AVG(NOTE) AS [������� ����]
from FACULTY join GROUPS G on FACULTY.FACULTY = G.FACULTY and G.FACULTY = '����'
join STUDENT S on G.IDGROUP = S.IDGROUP
join PROGRESS P on S.IDSTUDENT = P.IDSTUDENT
group by  rollup(G.FACULTY,PROFESSION,SUBJECT)


USE BANK;
SELECT ����.��������_�������,
����.������, 
avg(����������.�����)
FROM ���� 
JOIN ���������� ON ����.id = ����������.id
GROUP BY cube(��������_�������,������)