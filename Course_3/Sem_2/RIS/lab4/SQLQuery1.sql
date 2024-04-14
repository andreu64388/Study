use master;
go
create database ServerDB;
create database FirstDB;
create database SecondDB;

go
use ServerDB;
go
select * from dbo.Data;

use FirstDB
go
select * from dbo.Data;

use SecondDB
go
select * from dbo.Data;
--truncate table dbo.Data;
commit;