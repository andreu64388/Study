
/*	2. ���������� ������ ������ 1 ����� �������, ����� ��� �� ���������
                            ��� ��-����� � ����������� INNER JOIN ������ FROM �������� �������. 
                            ��� ���� ��-������� ���������� ������� ������ ���� ����������� ���������� 
                            ��������� �����-��. */
							use UNIVER;
select PULPIT.PULPIT_NAME from PULPIT
join FACULTY on  PULPIT.FACULTY = FACULTY.FACULTY
  and FACULTY.FACULTY in (select PROFESSION.FACULTY
                        from PROFESSION
                         where PROFESSION_NAME LIKE ('%����������%')
                            or PROFESSION_NAME LIKE ('%����������%'))



--------------------------------------------------------------

use BANK;
select ����.��������_������� ,����������.����� from ���� 
join ���������� on ����.id = ����������.id
where ����.id = (select id from ���������� 
where ����� = 1000
)
