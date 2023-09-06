


-- Теперь примените последовательности к вашим таблицам
-- Таблица "Cars"
CREATE TABLE Cars (
    Car_ID NUMBER DEFAULT Car_ID_Seq.NEXTVAL PRIMARY KEY, -- Используем последовательность для Car_ID
    License_Plate NVARCHAR2(20),
    Model NVARCHAR2(50),
    Year_of_Manufacture NUMBER,
    Rental_Price NUMBER(10, 2),
    Current_Status NVARCHAR2(50)
);



-- Таблица "Customers"
CREATE TABLE Customers (
    Customer_ID NUMBER DEFAULT Customer_ID_Seq.NEXTVAL PRIMARY KEY, -- Используем последовательность для Customer_ID
    First_Name NVARCHAR2(50),
    Last_Name NVARCHAR2(50),
    Address NVARCHAR2(100),
    Phone_Number NVARCHAR2(20),
    Email NVARCHAR2(100) CONSTRAINT Customer_Email UNIQUE
);


-- Таблица "Orders"
CREATE TABLE Orders (
    Order_ID NUMBER DEFAULT Order_ID_Seq.NEXTVAL PRIMARY KEY, -- Используем последовательность для Order_ID
    Customer_ID NUMBER,
    Car_ID NUMBER,
    Start_Date DATE,
    End_Date DATE,
    Order_Status NVARCHAR2(50),
    FOREIGN KEY (Customer_ID) REFERENCES Customers(Customer_ID),
    FOREIGN KEY (Car_ID) REFERENCES Cars(Car_ID)
);


-- Таблица "Payments"
CREATE TABLE Payments (
    Payment_ID NUMBER DEFAULT Payment_ID_Seq.NEXTVAL PRIMARY KEY, -- Используем последовательность для Payment_ID
    Order_ID NUMBER,
    Payment_Amount NUMBER(10, 2),
    Payment_Date DATE,
    FOREIGN KEY (Order_ID) REFERENCES Orders(Order_ID)
);
