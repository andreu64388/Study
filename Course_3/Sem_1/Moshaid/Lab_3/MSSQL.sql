use cars;


--1.	ƒл€ базы данных в —”Ѕƒ SQL Server добавить дл€ одной из таблиц столбец данных иерархического типа. 
ALTER TABLE Customers
ADD Parent_Customer_id INT;


--2.	—оздать процедуру, котора€ отобразит все подчиненные узлы с указанием уровн€ иерархии (параметр Ц значение узла).
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
--3.	—оздать процедуру, котора€ добавит подчиненный узел (параметр Ц значение узла).
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

EXEC AddSubordinateCustomer @Parent_Customer_id = 12, @First_Name = 'пет€', @Last_Name = '»ванов';

--4.	—оздать процедуру, котора€ переместит всю подчиненную ветку (первый параметр Ц значение верхнего перемещаемого узла, второй параметр Ц значение узла, в который происходит перемещение).
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
