use UNIVER;
/*8. ����������� SELECT-������, �����-���������� ������� ���������� 
ANY ��������� � �����������.*/
use UNIVER
select SUBJECT, NOTE, IDSTUDENT from PROGRESS
	where NOTE =any (select NOTE from PROGRESS
		where IDSTUDENT=1019 and SUBJECT='��')

/*-������� �������, ���� �������� , ������� ������� �� ����� �������� ����� �� �������,��� ������� 1019 ������� �� �� -*/

-----------------------------------
use BANK;

select ��������_������� ,������ from ���� a
where ������ =any (select ������ from ����
where ������ = a.������) 
