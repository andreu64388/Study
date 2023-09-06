use UNIVER;
create table TIMETABLE
(
    DAY_NAME   nvarchar(2) check (DAY_NAME in ('��', '��', '��', '��', '��', '��')),
    LESSON     int check (LESSON between 1 and 4),
    TEACHER   nvarchar(10)
        constraint TIMETABLE_TEACHER_FK foreign key references TEACHER (TEACHER),
    AUDITORIUM nvarchar(20)
        constraint TIMETABLE_AUDITORIUM_FK foreign key references AUDITORIUM (AUDITORIUM),
    SUBJECT    nvarchar(10)
        constraint TIMETABLE_SUBJECT_FK foreign key references SUBJECT (SUBJECT),
    IDGROUP    int
        constraint TIMETABLE_GROUP_FK foreign key references GROUPS (IDGROUP),
)
insert into TIMETABLE
values ('��', 1, '����', '313-1', '����', 2),
       ('��', 2, '����', '313-1', '����', 4),
       ('��', 3, '����', '313-1', '����', 11),
       ('��', 1, '���', '324-1', '����', 6),
       ('��', 3, '���', '324-1', '���', 4),
       ('��', 1, '���', '206-1', '���', 10),
       ('��', 4, '����', '206-1', '����', 3),
       ('��', 1, '�����', '301-1', '����', 7),
       ('��', 4, '�����', '301-1', '����', 7),
       ('��', 2, '�����', '413-1', '����', 8),
       ('��', 2, '���', '423-1', '����', 7),
       ('��', 4, '���', '423-1', '����', 2),
       ('��', 1, '����', '313-1', '����', 2),
       ('��', 2, '����', '313-1', '����', 4),
       ('��', 3, '���', '324-1', '���', 4),
       ('��', 4, '����', '206-1', '����', 3);


select AUDITORIUM_NAME as '���������, ��������� �� 2 ���� �� ��'
from AUDITORIUM




select AUDITORIUM_NAME as '���������, ��������� �� �� ��'
from AUDITORIUM

select distinct AUDITORIUM.AUDITORIUM_NAME
from AUDITORIUM inner join TIMETABLE T on T.DAY_NAME='��' and AUDITORIUM.AUDITORIUM = T.AUDITORIUM



select distinct TEACHER_NAME,DAY_NAME, case
           when ( count(*)= 0) then 4
           when ( count(*)= 1) then 3
           when ( count(*)= 2) then 2
           when ( count(*)= 3) then 1
           when ( count(*)= 4) then 0
           end [���-�� ����]
FROM  TEACHER inner join dbo.TIMETABLE T on TEACHER.TEACHER = T.TEACHER
group by TEACHER_NAME,DAY_NAME
order by TEACHER_NAME

select distinct GROUPS.IDGROUP,DAY_NAME, case
           when ( count(*)= 0) then 4
           when ( count(*)= 1) then 3
           when ( count(*)= 2) then 2
           when ( count(*)= 3) then 1
           when ( count(*)= 4) then 0
           end [���-�� ����]
FROM  GROUPS inner join dbo.TIMETABLE T on GROUPS.IDGROUP = T.IDGROUP
group by GROUPS.IDGROUP,DAY_NAME
order by GROUPS.IDGROUP



