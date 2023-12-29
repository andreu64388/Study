use cars
CREATE VIEW UserOrderStatus AS
SELECT
    C.Customer_id,
    C.First_Name,
    C.Last_Name,
    O.Order_id,
    O.Start_Date,
    O.End_Date,
    S.Status_name
FROM
    Customers C
JOIN
    Orders O ON C.Customer_id = O.Customer_id
JOIN
    Status_ S ON O.Status_id = S.Status_id;


select * from UserOrderStatus

-- Создание представления CarOrderStatus
CREATE VIEW CarOrderStatus AS
SELECT
    C.Car_id,
    C.Model,
    O.Order_id,
    O.Start_Date,
    O.End_Date,
    S.Status_name
FROM
    Cars C
JOIN
    Orders O ON C.Car_id = O.Car_ID
JOIN
    Status_ S ON O.Status_id = S.Status_id;


	select * from CarOrderStatus

	-- Создание индекса на поле Email в таблице Customers
 drop INDEX IX_Customers_Email ON Customers (Email);


-- Создание индекса на поле Model в таблице Cars
drop INDEX IX_Cars_Model ON Cars (Model);


-- Создайте покрывающий индекс для поля Email
drop INDEX IX_Customers_Email_Covering ON Customers (Email)
INCLUDE (Customer_id, First_Name, Last_Name, Address, Phone_number, Drivers_license);

SELECT *
FROM Customers
WHERE Email = 'email@example.com';
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (1, 'Имя', 'Фамилия', 'Адрес', 'Номер телефона', 'email@example.com', 'Водительские права');
-- Запись 1
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (1, 'Имя1', 'Фамилия1', 'Адрес1', 'Телефон1', 'email1@example.com', 'Права1');

-- Запись 2
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (2, 'Имя2', 'Фамилия2', 'Адрес2', 'Телефон2', 'email2@example.com', 'Права2');

-- Запись 3
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (3, 'Имя3', 'Фамилия3', 'Адрес3', 'Телефон3', 'email3@example.com', 'Права3');

-- Запись 4
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (4, 'Имя4', 'Фамилия4', 'Адрес4', 'Телефон4', 'email4@example.com', 'Права4');

-- Запись 5
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (5, 'Имя5', 'Фамилия5', 'Адрес5', 'Телефон5', 'email5@example.com', 'Права5');

-- Запись 6
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (6, 'Имя6', 'Фамилия6', 'Адрес6', 'Телефон6', 'email6@example.com', 'Права6');

-- Запись 7
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (7, 'Имя7', 'Фамилия7', 'Адрес7', 'Телефон7', 'email7@example.com', 'Права7');

-- Запись 8
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (8, 'Имя8', 'Фамилия8', 'Адрес8', 'Телефон8', 'email8@example.com', 'Права8');

-- Запись 9
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (9, 'Имя9', 'Фамилия9', 'Адрес9', 'Телефон9', 'email9@example.com', 'Права9');

-- Запись 10
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (10, 'Имя10', 'Фамилия10', 'Адрес10', 'Телефон10', 'email10@example.com', 'Права10');


SELECT Email
FROM Customers
WHERE Email = 'email@example.com';



set statistics io on;
SELECT Email
FROM Customers
WHERE Email = 'email@example.com';


-- Включите вывод статистики
SET STATISTICS IO off;
SET STATISTICS TIME Off;

-- Выполните запрос без индекса
SELECT * FROM Customers WHERE Email = 'email10@example.com';


-- Создание хранимой процедуры для вставки новых заказов
CREATE PROCEDURE InsertOrder
    @Start_Date DATE,
    @End_Date DATE,
    @Customer_id INT,
    @Car_ID INT
AS
BEGIN
    DECLARE @Order_id INT;
    INSERT INTO Orders (Start_Date, End_Date, Customer_id, Car_ID, Status_id)
    VALUES (@Start_Date, @End_Date, @Customer_id, @Car_ID, 1); -- 1 - это предполагаемый статус заказа

    SET @Order_id = SCOPE_IDENTITY(); -- Получаем идентификатор нового заказа

    INSERT INTO Payments (Order_ID, Payment_Amount, Payment_Date)
    VALUES (@Order_id, 0.00, GETDATE()); -- Создаем начальный платеж для заказа
END;
