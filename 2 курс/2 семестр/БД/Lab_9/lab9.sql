---------------------- Task1 ----------------------

select * from user_tables;

grant create sequence to KAVCORE;
grant create table to KAVCORE;
grant create cluster to KAVCORE;
grant create synonym to KAVcore;
grant create public synonym to KAVcore;
grant create materialized view to KAVCORE;


---------------------- Task 2 ----------------------
/*2.	�������� ��������� �������, �������� � ��� ������ � �����������������,
��� ����� ��� ��������. �������� ����������� ������ � ���������� ���������.*/
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
/*3.	�������� ������������������ S1 (SEQUENCE), �� ���������� 
����������������: ��������� �������� 1000; ���������� 10; ��� ������������ 
��������; ��� ������������� ��������; �� �����������; �������� �� ����������
� ������; ���������� �������� �� �������������. �������� ��������� ��������
������������������. �������� ������� �������� ������������������.*/
---------------------- Task 3 ----------------------

create sequence S1
  start with 1000
  increment by 10
  nominvalue
  nomaxvalue
  nocycle
  nocache
  noorder;
--�������� ��������� �������� ������������������. 
select S1.nextval from dual;
--�������� ������� �������� ������������������.
select S1.currval from dual;


---------------------- Task 4 ----------------------
/*4.	�������� ������������������ S2 (SEQUENCE), �� ���������� ����������������: 
��������� �������� 10; ���������� 10; ������������ �������� 100; �� �����������.
�������� ��� �������� ������������������. ����������� �������� ��������,
��������� �� ������������ ��������.*/
---------------------- Task 4 ----------------------

create sequence S2
  start with 10
  increment by 10
  maxvalue 100
  nocycle;
--�������� ��� �������� ������������������. 
select S2.nextval from dual;
select S2.currval from dual;

---------------------- Task 5 ----------------------
/*5.	�������� ������������������ S3 (SEQUENCE), �� ����������
����������������: ��������� �������� 10; ���������� -10; ����������� 
�������� -100; �� �����������; ������������� ���������� ��������. �������� 
��� �������� ������������������. ����������� �������� ��������, ������ 
������������ ��������.*/
---------------------- Task 5 ----------------------

create sequence S3
  start with 10
  increment by -10
  maxvalue 11 
  minvalue -100
  nocycle
  order;
--�������� ��� �������� ������������������. 
select S3.nextval from dual;
select S3.currval from dual;

---------------------- Task 6 ----------------------
/*6.	�������� ������������������ S4 (SEQUENCE), �� ���������� ����������������:
��������� �������� 1; ���������� 1; ����������� �������� 10; �����������; ����������
� ������ 5 ��������; ���������� �������� �� �������������. ����������������� ����������� 
��������� �������� ������������������� S4.*/
---------------------- Task 6 ----------------------

create sequence S4
  start with 1
  increment by 1
  --minvalue 10
  maxvalue 10
  cycle
  cache 5
  noorder;
--����������������� ����������� ��������� �������� ������������������� S4.
select S4.nextval from dual;
select S4.currval from dual;

---------------------- Task 7 ----------------------
/*7.	�������� ������ ���� ������������������� � ������� ���� ������, 
���������� ������� �������� ������������ XXX.*/
---------------------- Task 7 ----------------------
select * from user_sequences;

---------------------- Task 8 ----------------------
/*8.	�������� ������� T1, ������� ������� N1, N2, N3, N4, ���� NUMBER (20),
���������� � ������������� � �������� ���� KEEP. � ������� ��������� INSERT 
�������� 7 �����, �������� �������� ��� �������� ������ ������������� � 
������� ������������������� S1, S2, S3, S4.*/
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
/*9.	�������� ������� ABC, ������� hash-��� (������ 200) �
���������� 2 ����: X (NUMBER (10)), V (VARCHAR2(12)).*/
---------------------- Task 9 ----------------------
create cluster abc ( 
                    x number (10), 
                    v varchar2(12)) 
        hashkeys 200;
        
---------------------- Task 10 ----------------------
/*10.	�������� ������� A, ������� ������� XA (NUMBER (10)) � VA (VARCHAR2(12)),
������������� �������� ABC, � ����� ��� ���� ������������ �������.*/
---------------------- Task 10 ----------------------
create table A(XA number(10),
               VA varchar2(12), 
               aa number(10))
cluster ABC (XA, VA);

---------------------- Task 11 ----------------------
/*11.	�������� ������� B, ������� ������� XB (NUMBER (10)) � VB (VARCHAR2(12)), 
������������� �������� ABC, � ����� ��� ���� ������������ �������.*/
---------------------- Task 11 ----------------------
create table B(xb number(10),
               VB varchar2(12), 
               bb number(10))
cluster ABC (XB, VB);

---------------------- Task 12 ----------------------
/*12.	�������� ������� �, ������� ������� X� (NUMBER (10)) � V� (VARCHAR2(12))
, ������������� �������� ABC, � ����� ��� ���� ������������ �������. */
---------------------- Task 12 ----------------------
create table c(XC number(10),
               VC varchar2(12), 
               cc number(10))
cluster ABC (XC, VC);

---------------------- Task 13 ----------------------
/*13.	������� ��������� ������� � ������� � �������������� ������� Oracle.*/
---------------------- Task 13 ----------------------
select * from user_tables;
select * from user_clusters;

---------------------- Task 14 ----------------------
/*14.	�������� ������� ������� ��� ������� XXX.� � ����������������� ��� ����������.*/
---------------------- Task 14 ----------------------
create synonym sc for kavcore.c;
select * from sc;
select * from user_synonyms;

---------------------- Task 15 ----------------------
/*15.	�������� ��������� ������� ��� ������� XXX.B � ����������������� ��� ����������.*/
---------------------- Task 15 ----------------------
create public synonym sb for kavcore.b;
select * from sb;
---------------------- Task 16 ----------------------
/*16.	�������� ��� ������������ ������� A � B (� ��������� � ������� �������)
, ��������� �� �������, �������� ������������� V1, ���������� �� SELECT... FOR 
A inner join B. ����������������� ��� �����������������.*/
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
/*17.	�� ������ ������ A � B �������� ����������������� ������������� MV_XXX,
������� ����� ������������� ���������� 2 ������. ����������������� ��� �����������������.*/
---------------------- Task 17 ----------------------

create materialized view MV_KAV
build immediate 
refresh complete on demand next sysdate + numtodsinterval(2, 'minute') 
as select * from A1;

select * from  MV_KAV

insert into a1 (x, y) values (4,'aa');
insert into A1 (x, y) values (5,'bb');

---------------------- Task 18 ----------------------
/*18.	�������� DBlink �� ����� USER1-USER2 ��� ����������� � ������ ���� ������ 
(���� ���� �� ��������� �� ������� ORA12W, �� ���� ������������ � �� �� ������� 
ORA12D, ���� �� ��������� �� ����� �������, �� ������������ � ���-�� �� ������). */
---------------------- Task 18 ----------------------