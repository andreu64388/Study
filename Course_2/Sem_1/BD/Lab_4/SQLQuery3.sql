/*2. �� ������ ������ AUDITORI-UM_TYPE � AUDITORIUM ������������ �������� ����� ��������� (������� AUDI-TORIUM.AUDITORIUM) � ������������-��� �� ������������ ����� ��������� (������� AUDITORIUM_ TYPE.AUDITO-RIUM_TYPENAME). ��� ���� ������� ������� ������ �� ����-�����, � ������������ ������� ����������-�� ��������� ���������.
����������: ������������ ���������� ������ INNER JOIN � �������� LIKE.*/

use UNIVER
select AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
from AUDITORIUM_TYPE
         Inner Join AUDITORIUM
                    on AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE And
                       AUDITORIUM_TYPE.AUDITORIUM_TYPENAME Like '%���������%';


----------------------------------------------------
use BANK;

select ����.��������_������� ,����������.����� from ���� 
join ���������� on 
����.id = ����������.id and  ����.��������_������� Like '���%'