create database Shop;

use shop;
-- Таблица "Users"
CREATE TABLE Users (
    UserID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Email VARCHAR(50),
    Phone VARCHAR(20),
    Address VARCHAR(100)
)
ALTER TABLE Users ADD Image VARBINARY(MAX);
-- Таблица "Products"
CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(50),
    Category VARCHAR(50),
    Price DECIMAL(10,2),
    Description VARCHAR(100),
    Image VARBINARY(MAX)
)

-- Таблица "Orders"
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    UserID INT,
    OrderDate DATETIME,
    TotalAmount DECIMAL(10,2),
    FOREIGN KEY (UserID) REFERENCES Users(UserID)
)

-- Таблица "OrderDetails"
CREATE TABLE OrderDetails (
    OrderDetailID INT PRIMARY KEY,
    OrderID INT,
    ProductID INT,
    Quantity INT,
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID)
)


CREATE TRIGGER tr_Products_UpdatePrice
ON Products
AFTER UPDATE
AS
BEGIN
    IF UPDATE(Price)
    BEGIN
        UPDATE Products
        SET Price = i.Price * 1.1
        FROM inserted i
        INNER JOIN Products p ON i.ProductID = p.ProductID
    END
END




-- Создание хранимой процедуры для добавления нового продукта
CREATE PROCEDURE AddProduct
@ProductName VARCHAR(50),
@Category VARCHAR(50),
@Price DECIMAL(10,2),
@Description VARCHAR(100),
@Image VARBINARY(MAX)
AS
BEGIN
INSERT INTO Products (ProductName, Category, Price, Description, Image)
VALUES (@ProductName, @Category, @Price, @Description, @Image)
END

-- Создание хранимой процедуры для добавления нового пользователя
ALTER PROCEDURE AddUsers
@FirstName VARCHAR(50),
@LastName VARCHAR(50),
@Email VARCHAR(50),
@Phone VARCHAR(20),
@UserID INT ,
@Address VARCHAR(100),
@Image VARBINARY(MAX)
AS
BEGIN
INSERT INTO Users (FirstName, LastName, Email, Phone, Address,UserID,Image)
VALUES (@FirstName, @LastName, @Email, @Phone, @Address,@UserID,@Image)
END

Create table Images(
id_image int primary key ,
id_user int ,
 FOREIGN KEY (id_user) REFERENCES Users(UserID),
)

select * from users