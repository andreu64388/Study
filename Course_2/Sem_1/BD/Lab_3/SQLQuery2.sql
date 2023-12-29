
use My_Three;

create table ТОВАРЫ(
Наименование nvarchar(20) primary key,
Цена real,
Количество int 
);

create table ЗАКАЗЧИКИ (
Наименование_фирмы nvarchar(20) primary key,
Адрес nvarchar(20),
Растченый_счет nvarchar(20)
);

create table ЗАКАЗЫ (
Номер_заказа int primary key,
Наименование_товара nvarchar(20) foreign key REFERENCES ТОВАРЫ(Наименование),
цена_продажи real,
Количество int,
Дата_поставки date,
Заказчик nvarchar(20) foreign key REFERENCES ЗАКАЗЧИКИ(Наименование_фирмы)
);
