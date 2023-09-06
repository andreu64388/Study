
CREATE DATABASE UNIVER;
go
use UNIVER;



create table AUDITORIUM_TYPE
(    AUDITORIUM_TYPE  nvarchar(10) primary key,
      AUDITORIUM_TYPENAME  nvarchar(30)
);
insert into AUDITORIUM_TYPE   (AUDITORIUM_TYPE,  AUDITORIUM_TYPENAME )
	values	('ЛК', 'Лекционная'),
			('ЛБ-К', 'Компьютерный класс'),
			('ЛК-К', 'Лекционная с уст. проектором'),
			('ЛБ-X', 'Химическая лаборатория'),
			('ЛБ-СК', 'Спец. компьютерный класс');


create table AUDITORIUM
(  AUDITORIUM   nvarchar(20)   primary key,
   AUDITORIUM_TYPE     nvarchar(10)  foreign key references AUDITORIUM_TYPE(AUDITORIUM_TYPE),
   AUDITORIUM_CAPACITY  int  default 1  check (AUDITORIUM_CAPACITY between 1 and 300),  -- вместимость
   AUDITORIUM_NAME      nvarchar(50)
);
insert into  AUDITORIUM   (AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY)
	values	('206-1', '206-1','ЛБ-К', 15),
			('301-1', '301-1', 'ЛБ-К', 15),
			('236-1', '236-1', 'ЛК', 60),
			('313-1', '313-1', 'ЛК-К', 60),
			('324-1', '324-1', 'ЛК-К', 50),
			('413-1', '413-1', 'ЛБ-К', 15),
			('423-1', '423-1', 'ЛБ-К', 90),
			('408-2', '408-2', 'ЛК', 90);


