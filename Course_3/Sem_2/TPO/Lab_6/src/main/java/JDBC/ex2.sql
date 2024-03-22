create database rus_bel;
create database bel_rus;

create table rus_bel.dict (
	word nvarchar(50),
    translate nvarchar(50)
);

create table bel_rus.dict (
	word nvarchar(50),
    translate nvarchar(50)
);

insert into rus_bel.dict values ('диван', 'дыван');
insert into rus_bel.dict values ('стол', 'тэбля');

insert into bel_rus.dict values ('святыльник', 'светильник');
insert into bel_rus.dict values ('ваверка', 'белка');