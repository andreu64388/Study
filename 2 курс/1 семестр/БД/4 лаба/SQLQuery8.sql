

/*6. �� ������ ������ PULPIT � TEACHER �������� ������ �������� ������ (������� PULPIT.PULPIT_ NAME) � �������������� (������� TEACHER.TEA-CHER_NAME) �� ���� ��������. �������������� ����� ������ ��������� ��� �������: ������� � �������������. ���� �� ������� ��� �����-���������, �� � ������� ������������� ������ ���� �������� ������ ***.
����������: ������������ ���������� ������ LEFT OUTER JOIN � ������� isnull.*/
use UNIVER;

select PULPIT.PULPIT_NAME [�������], isnull(TEACHER.TEACHER_NAME, '***') [�������������]
from PULPIT
         left  join TEACHER
                         on PULPIT.PULPIT = TEACHER.PULPIT;

--------------------------------------------

use BANK;
select ����.��������_�������,����.������ from ���� 
left join  ����������
on ����.id = ����������.id