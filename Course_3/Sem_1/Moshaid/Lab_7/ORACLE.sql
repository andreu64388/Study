SELECT 
    Customer_ID,
    Start_Date,
    End_Date,
    Rental_price,
    Updated_Rental_price,
    Total_Cost
FROM (
    SELECT 
        c.Customer_ID,
        o.Start_Date,
        o.End_Date,
        car.Rental_price,
        car.Rental_price * 1.1 AS Updated_Rental_price
    FROM 
        Customers c
    JOIN 
        Orders o ON c.Customer_ID = o.Customer_ID
    JOIN
        Cars car ON o.Car_id = car.Car_id
    WHERE 
        o.Start_Date >= TRUNC(SYSDATE, 'YEAR') AND o.Start_Date < ADD_MONTHS(TRUNC(SYSDATE, 'YEAR'), 12)
)
MODEL
    PARTITION BY (Customer_ID)
    DIMENSION BY (ROW_NUMBER() OVER (PARTITION BY Customer_ID ORDER BY Start_Date) AS rn)
    MEASURES (
        Start_Date,
        End_Date,
        Rental_price,
        Updated_Rental_price,
        0 AS Total_Cost
    )
    RULES (
        Total_Cost[ANY] = Updated_Rental_price[CV()] + NVL(Total_Cost[CV() - 1], 0)
    );



SELECT *
FROM Orders
MATCH_RECOGNIZE (
    PARTITION BY Car_id
    ORDER BY Start_Date
    MEASURES
        A.Order_id AS start_order_id,
        B.Order_id AS end_order_id,
        A.Start_Date AS start_date,
        B.End_Date AS end_date
    PATTERN (A B C)
    DEFINE
        C AS C.End_Date > A.Start_Date AND B.End_Date > A.Start_Date
);
SELECT *
FROM (
    SELECT
        o.Order_id,
        o.Start_Date,
        o.End_Date,
        o.Customer_ID,
        o.Car_id,
        o.Service_id,
        s.Service_name
    FROM Orders o
    JOIN Services s ON o.Service_id = s.Service_id
)
MATCH_RECOGNIZE (
    PARTITION BY Service_id
    ORDER BY Start_Date
    MEASURES
        FIRST(A.Order_id) AS start_order_id,
        LAST(B.Order_id) AS end_order_id,
        FIRST(A.Start_Date) AS start_date,
        LAST(B.End_Date) AS end_date
    PATTERN (A B C)
    DEFINE
        C AS C.End_Date > A.Start_Date AND B.End_Date > A.Start_Date
);












INSERT INTO Services (Service_id, Service_name)
VALUES (1, 'Car Rental');


INSERT INTO Services (Service_id, Service_name)
VALUES (2, 'Car buy');

-- Update data for Car Rental service
UPDATE Services
SET Provision_amount = 1500.00, Transaction_date = TO_DATE('2023-11-25', 'YYYY-MM-DD')
WHERE Service_id = 1;

-- Update data for Car Buy service
UPDATE Services
SET Provision_amount = 5000.00, Transaction_date = TO_DATE('2023-11-25', 'YYYY-MM-DD')
WHERE Service_id = 2;


select * from cars
delete from cars
INSERT INTO Cars (Car_id, License_Plate, Model, Year_of_Manufactory, Rental_price, Color, Fuel_Type, Location, Status_id)
VALUES (1, 'ABC123', 'Toyota Camry', 2022, 100.00, 'Blue', 'Gas', 'Location1', 1);

INSERT INTO Cars (Car_id, License_Plate, Model, Year_of_Manufactory, Rental_price, Color, Fuel_Type, Location, Status_id)
VALUES (2, 'XYZ456', 'Honda Accord', 2021, 90.00, 'Red', 'Gas', 'Location2', 1);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id)
VALUES (3, TO_DATE('2023-01-15', 'YYYY-MM-DD'), TO_DATE('2023-01-25', 'YYYY-MM-DD'), 1, 1, 1);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (4, TO_DATE('2022-01-01', 'YYYY-MM-DD'), TO_DATE('2022-01-10', 'YYYY-MM-DD'), 1, 1, 1, 1);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (6, TO_DATE('2022-02-01', 'YYYY-MM-DD'), TO_DATE('2022-02-15', 'YYYY-MM-DD'), 2, 2, 1, 2);


-- Добавление заказов для первого вида услуги (рост, падение, рост)
INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (7, TO_DATE('2022-01-01', 'YYYY-MM-DD'), TO_DATE('2022-01-10', 'YYYY-MM-DD'), 1, 1, 1, 1);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (8, TO_DATE('2022-01-15', 'YYYY-MM-DD'), TO_DATE('2022-02-01', 'YYYY-MM-DD'), 1, 1, 1, 1);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (9, TO_DATE('2022-02-10', 'YYYY-MM-DD'), TO_DATE('2022-03-01', 'YYYY-MM-DD'), 1, 1, 1, 1);

-- Добавление заказов для второго вида услуги (рост, падение, рост)
INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (10, TO_DATE('2022-01-01', 'YYYY-MM-DD'), TO_DATE('2022-01-10', 'YYYY-MM-DD'), 1, 1, 1, 2);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (11, TO_DATE('2022-01-15', 'YYYY-MM-DD'), TO_DATE('2022-02-01', 'YYYY-MM-DD'), 1, 1, 1, 2);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id, Service_ID)
VALUES (12, TO_DATE('2022-02-10', 'YYYY-MM-DD'), TO_DATE('2022-03-01', 'YYYY-MM-DD'), 1, 1, 1, 2);

INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (1, 'John', 'Doe', '123 Main St', '555-1234', 'john@example.com', 'DL12345');

INSERT INTO Customers (Customer_id, First_Name, Last_Name, Address, Phone_number, Email, Drivers_license)
VALUES (2, 'Jane', 'Smith', '456 Oak St', '555-5678', 'jane@example.com', 'DL67890');


INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id)
VALUES (1, TO_DATE('2022-01-01', 'YYYY-MM-DD'), TO_DATE('2022-01-10', 'YYYY-MM-DD'), 1, 1, 1);

INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id)
VALUES (2, TO_DATE('2022-02-01', 'YYYY-MM-DD'), TO_DATE('2022-02-15', 'YYYY-MM-DD'), 2, 2, 1);


INSERT INTO Payments (Payment_ID, Order_ID, Payment_Amount, Payment_Date)
VALUES (1, 1, 100.00, TO_DATE('2022-01-05', 'YYYY-MM-DD'));

INSERT INTO Payments (Payment_ID, Order_ID, Payment_Amount, Payment_Date)
VALUES (2, 2, 90.00, TO_DATE('2022-02-10', 'YYYY-MM-DD'));


