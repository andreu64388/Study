---------------------- Task1 ----------------------

select * from user_tables;

grant create sequence to KAVCORE;
grant create table to KAVCORE;
grant create cluster to KAVCORE;
grant create synonym to KAVcore;
grant create public synonym to KAVcore;
grant create materialized view to KAVCORE;


---------------------- Task 2 ----------------------
/*2.	Создайте временную таблицу, добавьте в нее данные и продемонстрируйте,
как долго они хранятся. Поясните особенности работы с временными таблицами.*/
---------------------- Task 2 ----------------------

CREATE GLOBAL TEMPORARY TABLE temp_table (
    id NUMBER,
    name VARCHAR2(50)
);

INSERT INTO temp_table (id, name)
VALUES (1, 'John');

INSERT INTO temp_table (id, name)
VALUES (2, 'Jane');


---------------------- Task 3 ----------------------
/*3.	Создайте последовательность S1 (SEQUENCE), со следующими 
характеристиками: начальное значение 1000; приращение 10; нет минимального 
значения; нет максимального значения; не циклическая; значения не кэшируются
в памяти; хронология значений не гарантируется. Получите несколько значений
последовательности. Получите текущее значение последовательности.*/
---------------------- Task 3 ----------------------

create sequence S1
  start with 1000
  increment by 10
  nominvalue
  nomaxvalue
  nocycle
  nocache
  noorder;
--Получите несколько значений последовательности. 
select S1.nextval from dual;
--Получите текущее значение последовательности.
select S1.currval from dual;


---------------------- Task 4 ----------------------
/*4.	Создайте последовательность S2 (SEQUENCE), со следующими характеристиками: 
начальное значение 10; приращение 10; максимальное значение 100; не циклическую.
Получите все значения последовательности. Попытайтесь получить значение,
выходящее за максимальное значение.*/
---------------------- Task 4 ----------------------

create sequence S2
  start with 10
  increment by 10
  maxvalue 100
  nocycle;
--Получите все значения последовательности. 
select S2.nextval from dual;
select S2.currval from dual;

---------------------- Task 5 ----------------------
/*5.	Создайте последовательность S3 (SEQUENCE), со следующими
характеристиками: начальное значение 10; приращение -10; минимальное 
значение -100; не циклическую; гарантирующую хронологию значений. Получите 
все значения последовательности. Попытайтесь получить значение, меньше 
минимального значения.*/
---------------------- Task 5 ----------------------

create sequence S3
  start with 10
  increment by -10
  maxvalue 11 
  minvalue -100
  nocycle
  order;
--Получите все значения последовательности. 
select S3.nextval from dual;
select S3.currval from dual;

---------------------- Task 6 ----------------------
/*6.	Создайте последовательность S4 (SEQUENCE), со следующими характеристиками:
начальное значение 1; приращение 1; минимальное значение 10; циклическая; кэшируется
в памяти 5 значений; хронология значений не гарантируется. Продемонстрируйте цикличность 
генерации значений последовательностью S4.*/
---------------------- Task 6 ----------------------

create sequence S4
  start with 1
  increment by 1
  --minvalue 10
  maxvalue 10
  cycle
  cache 5
  noorder;
--Продемонстрируйте цикличность генерации значений последовательностью S4.
select S4.nextval from dual;
select S4.currval from dual;

---------------------- Task 7 ----------------------
/*7.	Получите список всех последовательностей в словаре базы данных, 
владельцем которых является пользователь XXX.*/
---------------------- Task 7 ----------------------
select * from user_sequences;

---------------------- Task 8 ----------------------
/*8.	Создайте таблицу T1, имеющую столбцы N1, N2, N3, N4, типа NUMBER (20),
кэшируемую и расположенную в буферном пуле KEEP. С помощью оператора INSERT 
добавьте 7 строк, вводимое значение для столбцов должно формироваться с 
помощью последовательностей S1, S2, S3, S4.*/
---------------------- Task 8 ----------------------
create table T1 (
        N1 NUMBER(20),
        N2 NUMBER(20),
        N3 NUMBER(20),
        N4 NUMBER(20)) cache storage(buffer_pool keep);

begin
  for i in 1..7 loop
  insert into T1(N1, N2, N3, N4) values (S1.nextval, S2.nextval, S3.nextval, S4.nextval);
  end loop;
end;
select * from t1;

---------------------- Task 9 ----------------------
/*9.	Создайте кластер ABC, имеющий hash-тип (размер 200) и
содержащий 2 поля: X (NUMBER (10)), V (VARCHAR2(12)).*/
---------------------- Task 9 ----------------------
create cluster abc ( 
                    x number (10), 
                    v varchar2(12)) 
        hashkeys 200;
        
---------------------- Task 10 ----------------------
/*10.	Создайте таблицу A, имеющую столбцы XA (NUMBER (10)) и VA (VARCHAR2(12)),
принадлежащие кластеру ABC, а также еще один произвольный столбец.*/
---------------------- Task 10 ----------------------
create table A(XA number(10),
               VA varchar2(12), 
               aa number(10))
cluster ABC (XA, VA);

---------------------- Task 11 ----------------------
/*11.	Создайте таблицу B, имеющую столбцы XB (NUMBER (10)) и VB (VARCHAR2(12)), 
принадлежащие кластеру ABC, а также еще один произвольный столбец.*/
---------------------- Task 11 ----------------------
create table B(xb number(10),
               VB varchar2(12), 
               bb number(10))
cluster ABC (XB, VB);

---------------------- Task 12 ----------------------
/*12.	Создайте таблицу С, имеющую столбцы XС (NUMBER (10)) и VС (VARCHAR2(12))
, принадлежащие кластеру ABC, а также еще один произвольный столбец. */
---------------------- Task 12 ----------------------
create table c(XC number(10),
               VC varchar2(12), 
               cc number(10))
cluster ABC (XC, VC);

---------------------- Task 13 ----------------------
/*13.	Найдите созданные таблицы и кластер в представлениях словаря Oracle.*/
---------------------- Task 13 ----------------------
select * from user_tables;
select * from user_clusters;

---------------------- Task 14 ----------------------
/*14.	Создайте частный синоним для таблицы XXX.С и продемонстрируйте его применение.*/
---------------------- Task 14 ----------------------
create synonym sc for kavcore.c;
select * from sc;
select * from user_synonyms;

---------------------- Task 15 ----------------------
/*15.	Создайте публичный синоним для таблицы XXX.B и продемонстрируйте его применение.*/
---------------------- Task 15 ----------------------
create public synonym sb for kavcore.b;
select * from sb;
---------------------- Task 16 ----------------------
/*16.	Создайте две произвольные таблицы A и B (с первичным и внешним ключами)
, заполните их данными, создайте представление V1, основанное на SELECT... FOR 
A inner join B. Продемонстрируйте его работоспособность.*/
---------------------- Task 16 ----------------------
create table A1(x number(10), y varchar(12),constraint x_pk primary key (x));
create table B1(x number(10),y varchar(12), constraint x_fk foreign key (x) references A1(x));

insert into A1 (x, y) values (1,'a');
insert into A1 (x, y) values (2,'b');
insert into A1 (x, y) values (3,'c');
insert into B1 (x, y) values (1,'d');
insert into B1 (x, y) values (2,'e');
insert into B1 (x, y) values (3,'f');

select * from a1;
select * from b1;

create view V1 as select A1.y as ay, B1.y as byf, A1.x from A1 inner join B1 on A1.x=B1.x;
select * from V1;

---------------------- Task 17 ----------------------
/*17.	На основе таблиц A и B создайте материализованное представление MV_XXX,
которое имеет периодичность обновления 2 минуты. Продемонстрируйте его работоспособность.*/
---------------------- Task 17 ----------------------

create materialized view MV_KAV
build immediate 
refresh complete on demand next sysdate + numtodsinterval(2, 'minute') 
as select * from A1;

select * from  MV_KAV

insert into a1 (x, y) values (4,'aa');
insert into A1 (x, y) values (5,'bb');

---------------------- Task 18 ----------------------
/*18.	Создайте DBlink по схеме USER1-USER2 для подключения к другой базе данных 
(если ваша БД находится на сервере ORA12W, то надо подключаться к БД на сервере 
ORA12D, если вы работаете на своем сервере, то договоритесь с кем-то из группы). */
---------------------- Task 18 ----------------------