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

-- �������� ������������� CarOrderStatus
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

	-- �������� ������� �� ���� Email � ������� Customers
 drop INDEX IX_Customers_Email ON Customers (Email);


-- �������� ������� �� ���� Model � ������� Cars
drop INDEX IX_Cars_Model ON Cars (Model);


-- �������� ����������� ������ ��� ���� Email
drop INDEX IX_Customers_Email_Covering ON Customers (Email)
INCLUDE (Customer_id, First_Name, Last_Name, Address, Phone_number, Drivers_license);

SELECT *
FROM Customers
WHERE Email = 'email@example.com';
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (1, '���', '�������', '�����', '����� ��������', 'email@example.com', '������������ �����');
-- ������ 1
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (1, '���1', '�������1', '�����1', '�������1', 'email1@example.com', '�����1');

-- ������ 2
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (2, '���2', '�������2', '�����2', '�������2', 'email2@example.com', '�����2');

-- ������ 3
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (3, '���3', '�������3', '�����3', '�������3', 'email3@example.com', '�����3');

-- ������ 4
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (4, '���4', '�������4', '�����4', '�������4', 'email4@example.com', '�����4');

-- ������ 5
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (5, '���5', '�������5', '�����5', '�������5', 'email5@example.com', '�����5');

-- ������ 6
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (6, '���6', '�������6', '�����6', '�������6', 'email6@example.com', '�����6');

-- ������ 7
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (7, '���7', '�������7', '�����7', '�������7', 'email7@example.com', '�����7');

-- ������ 8
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (8, '���8', '�������8', '�����8', '�������8', 'email8@example.com', '�����8');

-- ������ 9
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (9, '���9', '�������9', '�����9', '�������9', 'email9@example.com', '�����9');

-- ������ 10
INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (10, '���10', '�������10', '�����10', '�������10', 'email10@example.com', '�����10');


SELECT Email
FROM Customers
WHERE Email = 'email@example.com';



set statistics io on;
SELECT Email
FROM Customers
WHERE Email = 'email@example.com';


-- �������� ����� ����������
SET STATISTICS IO off;
SET STATISTICS TIME Off;

-- ��������� ������ ��� �������
SELECT * FROM Customers WHERE Email = 'email10@example.com';


-- �������� �������� ��������� ��� ������� ����� �������
CREATE PROCEDURE InsertOrder
    @Start_Date DATE,
    @End_Date DATE,
    @Customer_id INT,
    @Car_ID INT
AS
BEGIN
    DECLARE @Order_id INT;
    INSERT INTO Orders (Start_Date, End_Date, Customer_id, Car_ID, Status_id)
    VALUES (@Start_Date, @End_Date, @Customer_id, @Car_ID, 1); -- 1 - ��� �������������� ������ ������

    SET @Order_id = SCOPE_IDENTITY(); -- �������� ������������� ������ ������

    INSERT INTO Payments (Order_ID, Payment_Amount, Payment_Date)
    VALUES (@Order_id, 0.00, GETDATE()); -- ������� ��������� ������ ��� ������
END;
