use UNIVER;
--9. ����������� SELECT-������ �� ������ CROSS JOIN-���������� ������ AUDITORIUM_TYPE � AUDITORIUM, �������-����� ���������, ����������� ����������, ����������� ��� ���������� ������� � ��-����� 1.

select AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPE
from AUDITORIUM
cross join AUDITORIUM_TYPE
where AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE;


----------------------
use BANK;
select ����.��������_�������,����������.�����_������� 
from ���� cross join
���������� 


