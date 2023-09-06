use UNIVER;
/*5. ���������� ������, ����������� ����-��� 4 ����� �������, ����� � �����������-��� ������ ���������� �� ��������������� ������� ���� ���������: ������� ������-���� ������ � ������� 7, ����� ������ � ������� 8 � ����� ������ � ������� 6.
����������: ������������ ��������� CASE � ������ ORDER BY.
*/
select FACULTY.FACULTY,
       PULPIT.PULPIT,
       PROFESSION.PROFESSION_NAME,
       SUBJECT.SUBJECT_NAME,
     STUDENT.NAME,
       case
           when (PROGRESS.NOTE = 6) then '�����'
           when (PROGRESS.NOTE = 7) then '����'
           when (PROGRESS.NOTE = 8) then '������'
           end [PROGRESS.NOTE]
from PROGRESS
          join STUDENT on PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
          join [SUBJECT] on [SUBJECT].[SUBJECT] = PROGRESS.[SUBJECT]
          join GROUPS on GROUPS.IDGROUP = STUDENT.IDGROUP
          join PROFESSION on PROFESSION.PROFESSION = GROUPS.PROFESSION
          join PULPIT on PULPIT.PULPIT = [SUBJECT].PULPIT
          join FACULTY on FACULTY.FACULTY = PULPIT.FACULTY
where PROGRESS.NOTE between 6 and 8
order by (case
              when (PROGRESS.NOTE = 6) then 3
              when (PROGRESS.NOTE = 7) then 2
              when (PROGRESS.NOTE = 8) then 1
    end);


use BANK;
select ����.��������_������� ,case

           when (����������.����� = 1000) then '1000 �����'
           when (����������.����� = 1020) then '1020 �����'
           end [O�����] from ���� , ����������
where ����.id = ����������.id

order by(  case
when (����������.����� = 1000) then 2
           when (����������.����� = 1020) then 1
           end)

