/*12*. ���������� ���������� ��������� � ������ ������, �� ������ ���������� � ����� � ������������ ����� ��������.
  ���������� ���������� ��������� �� ����� � ��������� ����������� � �������� � ����� ����� ��������.*/

use UNIVER;


select  FACULTY.FACULTY, G.IDGROUP ,count(IDSTUDENT) as [���-�� ���������]
from FACULTY full join GROUPS G on FACULTY.FACULTY = G.FACULTY
full join STUDENT S on G.IDGROUP = S.IDGROUP
group by rollup (FACULTY.FACULTY,G.IDGROUP)


select AUDITORIUM_TYPE.AUDITORIUM_TYPE , count(AUDITORIUM) as [���-�� ���������],sum(AUDITORIUM_CAPACITY) as [��������� �����������]
from AUDITORIUM_TYPE full join AUDITORIUM A on AUDITORIUM_TYPE.AUDITORIUM_TYPE = A.AUDITORIUM_TYPE
group by rollup (AUDITORIUM_TYPE.AUDITORIUM_TYPE)