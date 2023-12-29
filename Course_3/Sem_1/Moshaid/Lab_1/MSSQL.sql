
    CREATE TABLE Cars (
        Car_id INT PRIMARY KEY,
        License_Plate VARCHAR(20) UNIQUE,
        Model VARCHAR(255),
        Year_of_Manufactory INT,
        Rental_price DECIMAL(10, 2),
        Color VARCHAR(50),
        Fuel_Type VARCHAR(50),
        Location VARCHAR(255),
        Status_id INT,
        FOREIGN KEY (Status_id) REFERENCES Status_(Status_id),
    );


    CREATE TABLE Customers (
        Customer_id INT PRIMARY KEY,
        First_Name VARCHAR(50),
        Last_Name VARCHAR(50),
        Address VARCHAR(255),
        Phone_number VARCHAR(15),
        Email VARCHAR(255),
        Drivers_license VARCHAR(20)
    );

    CREATE TABLE Orders (
        Order_id INT PRIMARY KEY,
        Start_Date DATE,
        End_Date DATE,
        Customer_id INT,
        Car_ID INT,
        Status_id INT,
        FOREIGN KEY (Customer_id) REFERENCES Customers(Customer_id),
        FOREIGN KEY (Car_ID) REFERENCES Cars(Car_id),
        FOREIGN KEY (Status_id) REFERENCES Status_(Status_id)
    );




    CREATE TABLE Payments (
        Payment_ID INT PRIMARY KEY,
        Order_ID INT,
        Payment_Amount DECIMAL(10, 2),
        Payment_Date DATE,
        FOREIGN KEY (Order_ID) REFERENCES Orders(Order_id)
    );


    CREATE TABLE Status_ (
        Status_id INT PRIMARY KEY,
        Status_name VARCHAR(50)
    );

    SELECT Email
    FROM Customers
    WHERE Email = 'email3@example.com';

	-- Создание таблицы для услуг
CREATE TABLE Services (
    Service_id INT PRIMARY KEY,
    Service_name VARCHAR(255),
    Service_description VARCHAR(255)
);

-- Создание таблицы для отслеживания, какие услуги были предоставлены в каждом заказе
CREATE TABLE Order_Services (
    Order_Service_id INT PRIMARY KEY,
    Order_id INT,
    Service_id INT,
    FOREIGN KEY (Order_id) REFERENCES Orders(Order_id),
    FOREIGN KEY (Service_id) REFERENCES Services(Service_id)
);

INSERT INTO Status_ (Status_id, Status_name)
VALUES
    (1, 'Активный'),
    (2, 'Зарезервирован'),
    (3, 'Продан');

INSERT INTO Cars (Car_id, License_Plate, Model, Year_of_Manufactory, Rental_price, Color, Fuel_Type, Location, Status_id)
VALUES
    (1, 'AB123CD', 'Toyota Camry', 2020, 50.00, 'Серый', 'Бензин', 'Лос-Анджелес', 1),
    (2, 'EF456GH', 'Honda Civic', 2019, 45.00, 'Синий', 'Дизель', 'Нью-Йорк', 1),
    (3, 'IJ789KL', 'Ford Focus', 2021, 55.00, 'Красный', 'Бензин', 'Чикаго', 2);


INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_id, Car_ID, Status_id)
VALUES
    (1, '2023-10-01', '2023-10-10', 1, 1, 1),
    (2, '2023-11-15', '2023-11-25', 2, 2, 1),
    (3, '2023-12-05', '202-12-15', 3, 3, 2);


INSERT INTO Payments (Payment_ID, Order_ID, Payment_Amount, Payment_Date)
VALUES
    (1, 1, 500.00, '2023-10-05'),
    (2, 2, 450.00, '2023-11-20'),
    (3, 3, 550.00, '2023-12-10');

INSERT INTO Services (Service_id, Service_name, Service_description)
VALUES
    (1, 'Аренда автомобиля', 'Аренда автомобиля на день'),
    (2, 'Дополнительные услуги', 'Страховка, навигатор и т.д.');

INSERT INTO Order_Services (Order_Service_id, Order_id, Service_id)
VALUES
    (4, 1, 1),  
    (2, 1, 2),  
    (3, 2, 1);  
