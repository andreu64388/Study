-- Таблица "Cars" содержит информацию о автомобилях.
CREATE TABLE Cars (
    Car_ID INT PRIMARY KEY,           -- Уникальный идентификатор автомобиля.
    License_Plate NVARCHAR(20),       -- Номерной знак автомобиля.
    Model NVARCHAR(50),               -- Модель автомобиля.
    Year_of_Manufacture INT,          -- Год выпуска автомобиля.
    Rental_Price DECIMAL(10, 2),      -- Стоимость аренды в день.
    Current_Status NVARCHAR(50)       -- Текущий статус автомобиля (например, доступен, в аренде, в ремонте и т.д.).
);

-- Таблица "Customers" хранит информацию о клиентах.
CREATE TABLE Customers (
    Customer_ID INT PRIMARY KEY,       -- Уникальный идентификатор клиента.
    First_Name NVARCHAR(50),          -- Имя клиента.
    Last_Name NVARCHAR(50),           -- Фамилия клиента.
    Address NVARCHAR(100),            -- Адрес клиента.
    Phone_Number NVARCHAR(20),        -- Номер телефона клиента.
    Email NVARCHAR(100),              -- Адрес электронной почты клиента.
    CONSTRAINT UC_Email UNIQUE (Email) -- Гарантирует уникальность адресов электронной почты.
);

-- Таблица "Orders" отслеживает информацию о заказах клиентов.
CREATE TABLE Orders (
    Order_ID INT PRIMARY KEY,          -- Уникальный идентификатор заказа.
    Customer_ID INT,                   -- Связь с клиентом (внешний ключ).
    Car_ID INT,                        -- Связь с автомобилем (внешний ключ).
    Start_Date DATE,                   -- Дата начала аренды.
    End_Date DATE,                     -- Дата окончания аренды.
    Order_Status NVARCHAR(50),         -- Статус заказа (например, активен, закрыт и т.д.).
    FOREIGN KEY (Customer_ID) REFERENCES Customers(Customer_ID), -- Связь с таблицей Customers.
    FOREIGN KEY (Car_ID) REFERENCES Cars(Car_ID)                -- Связь с таблицей Cars.
);

-- Таблица "Payments" содержит информацию о платежах за заказы.
CREATE TABLE Payments (
    Payment_ID INT PRIMARY KEY,        -- Уникальный идентификатор платежа.
    Order_ID INT,                      -- Связь с заказом (внешний ключ).
    Payment_Amount DECIMAL(10, 2),     -- Сумма платежа.
    Payment_Date DATE,                 -- Дата платежа.
    FOREIGN KEY (Order_ID) REFERENCES Orders(Order_ID) -- Связь с таблицей Orders.
);

