
/*OIN.
7. � �������, ����������� ����� 6, ����-���� ������� ������ � ��������� LEFT OUTER JOIN. ���������: ������ � ������� ������� �� ����� ���� �������� NULL.
���������� ������ ����� �������, ����� ��������� ����������� ���������, �� ���-�������� ���������� ������ RIGHT OUTER JOIN.*/

use UNIVER;
select PULPIT.PULPIT_NAME [�������], isnull(TEACHER.TEACHER_NAME, '***') [�������������]
from TEACHER
         left outer join PULPIT
                         on PULPIT.PULPIT = TEACHER.PULPIT;


select PULPIT.PULPIT_NAME as '�������', isnull(TEACHER.TEACHER_NAME, '***') as '�������������'
from TEACHER
         right outer join PULPIT
                          on PULPIT.PULPIT = TEACHER.PULPIT;

