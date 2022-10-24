use H_MyBase_H;


CREATE table NEWGOODS
(     NEWGOODS char(20) primary key,              
      NEWGOODS_TYPE nvarchar(50),
      NEWGOODS_CAPACITY int default 1 check (NEWGOODS_CAPACITY between 1 and 300),  
      NEWGOODS_NAME  varchar(50)                                     
) on FG1;