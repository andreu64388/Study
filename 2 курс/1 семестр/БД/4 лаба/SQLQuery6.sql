

/*4. �� ������ ������ PRORGESS, STU-DENT, GROUPS, SUBJECT, PULPIT � FACULTY ������������ �������� ������-���, ���������� ��������������� ������ (������� PROGRESS.NOTE) �� 6 �� 8.
�������������� ����� ������ ��������� �������: ���������, �������, ��������-�����, ����������, ��� ��������, ����-��. � ������� ������ ������ ���� ������-�� ��������������� ������ ��������: �����, ����, ������.
�������������� ����� ������������� � 4. �� ������ ������ PRORGESS, STU-DENT, GROUPS, SUBJECT, PULPIT � FACULTY ������������ �������� ������-���, ���������� ��������������� ������ (������� PROGRESS.NOTE) �� 6 �� 8.
�������������� ����� ������ ��������� �������: ���������, �������, ��������-�����, ����������, ��� ��������, ����-��. � ������� ������ ������ ���� ������-�� ��������������� ������ ��������: �����, ����, ������.
�������������� ����� ������������� � */
use UNIVER;

select STUDENT.[NAME],
       FACULTY.FACULTY,
       PULPIT.PULPIT,
       PROFESSION.PROFESSION_NAME,
       SUBJECT.SUBJECT_NAME,
       case
           when (PROGRESS.NOTE = 6) then '�����'
           when (PROGRESS.NOTE = 7) then '����'
           when (PROGRESS.NOTE = 8) then '������'
           end [O�����]
from PROGRESS
          join STUDENT on PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
          join [SUBJECT] on [SUBJECT].[SUBJECT] = PROGRESS.[SUBJECT]
          join GROUPS on GROUPS.IDGROUP = STUDENT.IDGROUP
          join PROFESSION on PROFESSION.PROFESSION = GROUPS.PROFESSION
          join PULPIT on PULPIT.PULPIT = [SUBJECT].PULPIT
          join FACULTY on FACULTY.FACULTY = PULPIT.FACULTY
where PROGRESS.NOTE between 6 and 8
order by FACULTY.FACULTY

--------------------
use BANK;
select ����.��������_������� ,case

           when (����������.����� = 1020) then '1020 �����'
           when (����������.����� = 1000) then '1020 �����'
           end [O�����] from ���� , ����������
where ����.id = ����������.id

