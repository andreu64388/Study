use cars;


--1.	��� ���� ������ � ���� SQL Server �������� ��� ����� �� ������ ������� ������ �������������� ����. 
ALTER TABLE Customers
ADD Parent_Customer_id INT;


--2.	������� ���������, ������� ��������� ��� ����������� ���� � ��������� ������ �������� (�������� � �������� ����).
CREATE PROCEDURE GetCustomerHierarchy(@Customer_id INT) AS
BEGIN
    WITH CustomerHierarchy AS
    (
        SELECT
            Customer_id,
            First_Name,
            Last_Name,
            0 AS Level
        FROM
            Customers
        WHERE
            Customer_id = @Customer_id
        UNION ALL
        SELECT
            c.Customer_id,
            c.First_Name,
            c.Last_Name,
            ch.Level + 1
        FROM
            Customers c
        INNER JOIN
            CustomerHierarchy ch ON c.Parent_Customer_id = ch.Customer_id
    )
    SELECT
        Customer_id,
        First_Name,
        Last_Name,
        Level
    FROM
        CustomerHierarchy;
END;

EXEC GetCustomerHierarchy @Customer_id = 2;


select * from Customers
--3.	������� ���������, ������� ������� ����������� ���� (�������� � �������� ����).
create PROCEDURE AddSubordinateCustomer
    @Parent_Customer_id INT,
    @First_Name VARCHAR(50),
    @Last_Name VARCHAR(50)
AS
BEGIN
    DECLARE @NewCustomerID INT;


    SELECT @NewCustomerID = ISNULL(MAX(Customer_id), 0) + 1 FROM Customers;


    INSERT INTO Customers (Customer_id, Parent_Customer_id, First_Name, Last_Name)
    VALUES (@NewCustomerID, @Parent_Customer_id, @First_Name, @Last_Name);
END;

EXEC AddSubordinateCustomer @Parent_Customer_id = 12, @First_Name = '����', @Last_Name = '������';

--4.	������� ���������, ������� ���������� ��� ����������� ����� (������ �������� � �������� �������� ������������� ����, ������ �������� � �������� ����, � ������� ���������� �����������).
create PROCEDURE MoveSubtreeToNewParent
    @Source_Customer_id INT,
    @Target_Customer_id INT
AS
BEGIN
    
    UPDATE Customers
    SET Parent_Customer_id = @Target_Customer_id
    WHERE Customer_id = @Source_Customer_id OR
          Parent_Customer_id = @Source_Customer_id;
END;

EXEC MoveSubtreeToNewParent @Source_Customer_id = 1, @Target_Customer_id = 3;

select * from Customers
