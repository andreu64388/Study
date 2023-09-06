-- ������� "Cars" �������� ���������� � �����������.
CREATE TABLE Cars (
    Car_ID INT PRIMARY KEY,           -- ���������� ������������� ����������.
    License_Plate NVARCHAR(20),       -- �������� ���� ����������.
    Model NVARCHAR(50),               -- ������ ����������.
    Year_of_Manufacture INT,          -- ��� ������� ����������.
    Rental_Price DECIMAL(10, 2),      -- ��������� ������ � ����.
    Current_Status NVARCHAR(50)       -- ������� ������ ���������� (��������, ��������, � ������, � ������� � �.�.).
);

-- ������� "Customers" ������ ���������� � ��������.
CREATE TABLE Customers (
    Customer_ID INT PRIMARY KEY,       -- ���������� ������������� �������.
    First_Name NVARCHAR(50),          -- ��� �������.
    Last_Name NVARCHAR(50),           -- ������� �������.
    Address NVARCHAR(100),            -- ����� �������.
    Phone_Number NVARCHAR(20),        -- ����� �������� �������.
    Email NVARCHAR(100),              -- ����� ����������� ����� �������.
    CONSTRAINT UC_Email UNIQUE (Email) -- ����������� ������������ ������� ����������� �����.
);

-- ������� "Orders" ����������� ���������� � ������� ��������.
CREATE TABLE Orders (
    Order_ID INT PRIMARY KEY,          -- ���������� ������������� ������.
    Customer_ID INT,                   -- ����� � �������� (������� ����).
    Car_ID INT,                        -- ����� � ����������� (������� ����).
    Start_Date DATE,                   -- ���� ������ ������.
    End_Date DATE,                     -- ���� ��������� ������.
    Order_Status NVARCHAR(50),         -- ������ ������ (��������, �������, ������ � �.�.).
    FOREIGN KEY (Customer_ID) REFERENCES Customers(Customer_ID), -- ����� � �������� Customers.
    FOREIGN KEY (Car_ID) REFERENCES Cars(Car_ID)                -- ����� � �������� Cars.
);

-- ������� "Payments" �������� ���������� � �������� �� ������.
CREATE TABLE Payments (
    Payment_ID INT PRIMARY KEY,        -- ���������� ������������� �������.
    Order_ID INT,                      -- ����� � ������� (������� ����).
    Payment_Amount DECIMAL(10, 2),     -- ����� �������.
    Payment_Date DATE,                 -- ���� �������.
    FOREIGN KEY (Order_ID) REFERENCES Orders(Order_ID) -- ����� � �������� Orders.
);

