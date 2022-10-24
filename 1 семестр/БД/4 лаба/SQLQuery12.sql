use UNIVER;
create table TIMETABLE
(
    DAY_NAME   nvarchar(2) check (DAY_NAME in ('пн', 'вт', 'ср', 'чт', 'пт', 'сб')),
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
values ('пн', 1, '—ћЋ¬', '313-1', '—”Ѕƒ', 2),
       ('пн', 2, '—ћЋ¬', '313-1', 'ќјиѕ', 4),
       ('пн', 3, '—ћЋ¬', '313-1', 'ќјиѕ', 11),
       ('пн', 1, 'ћ–«', '324-1', '—”Ѕƒ', 6),
       ('пн', 3, '”–Ѕ', '324-1', 'ѕ»—', 4),
       ('пн', 1, '”–Ѕ', '206-1', 'ѕ»—', 10),
       ('пн', 4, '—ћЋ¬', '206-1', 'ќјиѕ', 3),
       ('пн', 1, 'Ѕ– ¬„', '301-1', '—”Ѕƒ', 7),
       ('пн', 4, 'Ѕ– ¬„', '301-1', 'ќјиѕ', 7),
       ('пн', 2, 'Ѕ– ¬„', '413-1', '—”Ѕƒ', 8),
       ('пн', 2, 'ƒ“ ', '423-1', '—”Ѕƒ', 7),
       ('пн', 4, 'ƒ“ ', '423-1', 'ќјиѕ', 2),
       ('вт', 1, '—ћЋ¬', '313-1', '—”Ѕƒ', 2),
       ('вт', 2, '—ћЋ¬', '313-1', 'ќјиѕ', 4),
       ('вт', 3, '”–Ѕ', '324-1', 'ѕ»—', 4),
       ('вт', 4, '—ћЋ¬', '206-1', 'ќјиѕ', 3);


select AUDITORIUM_NAME as 'јудитори€, свободные на 2 паре во вт'
from AUDITORIUM




select AUDITORIUM_NAME as 'јудитори€, свободные на во вт'
from AUDITORIUM

select distinct AUDITORIUM.AUDITORIUM_NAME
from AUDITORIUM inner join TIMETABLE T on T.DAY_NAME='вт' and AUDITORIUM.AUDITORIUM = T.AUDITORIUM



select distinct TEACHER_NAME,DAY_NAME, case
           when ( count(*)= 0) then 4
           when ( count(*)= 1) then 3
           when ( count(*)= 2) then 2
           when ( count(*)= 3) then 1
           when ( count(*)= 4) then 0
           end [ ол-во окон]
FROM  TEACHER inner join dbo.TIMETABLE T on TEACHER.TEACHER = T.TEACHER
group by TEACHER_NAME,DAY_NAME
order by TEACHER_NAME

select distinct GROUPS.IDGROUP,DAY_NAME, case
           when ( count(*)= 0) then 4
           when ( count(*)= 1) then 3
           when ( count(*)= 2) then 2
           when ( count(*)= 3) then 1
           when ( count(*)= 4) then 0
           end [ ол-во окон]
FROM  GROUPS inner join dbo.TIMETABLE T on GROUPS.IDGROUP = T.IDGROUP
group by GROUPS.IDGROUP,DAY_NAME
order by GROUPS.IDGROUP



