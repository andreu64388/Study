CREATE TABLE KAV_T(
X NUMBER(3),
S VARCHAR2(50)
);

alter table KAV_T add primary key (x);


insert INTO KAV_T (X,S) values (1,'22');
insert INTO KAV_T (X,S) values (12,'221');
insert INTO KAV_T (X,S) values (13,'224');
insert INTO KAV_T (X,S) values (15,'224');
commit;

SELECT * FROM kav_t


update KAV_T set S = 'EDIT'  where X = 1;
update  KAV_T set S = 'EDIT2'  where X = 12;
commit;

SELECT MAX(X)  FROM KAV_T 
WHERE X>3

delete from KAV_T where S = '224';
commit;


create table KAV_T1 (
    id number(3) not null , 
    name VARCHAR(50),
    CONSTRAINT FK_ FOREIGN KEY (id)
    REFERENCES KAV_T(X)
);

insert INTO KAV_T1 (id,name) values (1,'test');
insert INTO KAV_T1 (id,name) values (12,'ilya');
insert INTO KAV_T1 (id,name) values (13,'cat');
commit;


select x,name from 
    KAV_T left outer join KAV_T1
    on KAV_T.x = KAV_T1.id ;
    
select x,name from 
    KAV_T RIGHT OUTER JOIN KAV_T1
    on KAV_T.x = KAV_T1.id ;
    
select x,name from 
    KAV_T JOIN KAV_T1
    on KAV_T.x = KAV_T1.id ;
    
    
ALTER TABLE KAV_T1
DROP CONSTRAINT FK_; 
    
drop table KAV_T;
drop table KAV_T1;
    
