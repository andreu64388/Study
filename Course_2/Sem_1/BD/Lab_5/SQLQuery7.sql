use UNIVER;

/*7. ����������� SELECT-������, �����-���������� ������� ����������
ALL ��������� � �����������.*/


select [SUBJECT], IDSTUDENT , NOTE from PROGRESS a
	where NOTE >=all (select NOTE from PROGRESS
		where [SUBJECT] = a.[SUBJECT] )



-----------------------------------
use BANK;

select ��������_������� ,������ from ���� a
where ������ >= all (select ������ from ����
where ������ = a.������) 