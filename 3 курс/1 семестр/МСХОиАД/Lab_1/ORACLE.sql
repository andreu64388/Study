
CREATE TABLE Cars (
    Car_id NUMBER PRIMARY KEY,
    License_Plate VARCHAR2(20) UNIQUE,
    Model VARCHAR2(255),
    Year_of_Manufactory NUMBER,
    Rental_price NUMBER(10, 2),
    Color VARCHAR2(50),
    Fuel_Type VARCHAR2(50),
    Location VARCHAR2(255),
    Status_id NUMBER,
    CONSTRAINT fk_status FOREIGN KEY (Status_id) REFERENCES Status_(Status_id)
);


CREATE TABLE Customers (
    Customer_id NUMBER PRIMARY KEY,
    First_Name VARCHAR2(50),
    Last_Name VARCHAR2(50),
    Address VARCHAR2(255),
    Phone_number VARCHAR2(15),
    Email VARCHAR2(255),
    Drivers_license VARCHAR2(20)
);

DROP TABLE orders CASCADE CONSTRAINTS;

CREATE TABLE Orders (
    Order_id NUMBER PRIMARY KEY,
    Start_Date DATE,
    End_Date DATE,
    Customer_ID NUMBER,
    Car_id NUMBER,
    Status_id NUMBER,
    CONSTRAINT fk_customer FOREIGN KEY (Customer_ID) REFERENCES Customers(Customer_id),
    CONSTRAINT fk_car FOREIGN KEY (Car_id) REFERENCES Cars(Car_id),
    CONSTRAINT fk_order_status FOREIGN KEY (Status_id) REFERENCES Status_(Status_id)
);


CREATE TABLE Payments (
    Payment_ID NUMBER PRIMARY KEY,
    Order_ID NUMBER,
    Payment_Amount NUMBER(10, 2),
    Payment_Date DATE,
    CONSTRAINT fk_order_payment FOREIGN KEY (Order_ID) REFERENCES Orders(Order_id)
);


CREATE TABLE Status_ (
    Status_id NUMBER PRIMARY KEY,
    Status_name VARCHAR2(50)
);
