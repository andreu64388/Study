-- Создание представления UserOrderStatus
CREATE OR REPLACE VIEW UserOrderStatus AS
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
    Orders O ON C.Customer_id = O.Customer_ID
JOIN
    Status_ S ON O.Status_id = S.Status_id;

-- Просмотр данных из представления UserOrderStatus
SELECT * FROM UserOrderStatus;

-- Создание представления CarOrderStatus
CREATE OR REPLACE VIEW CarOrderStatus AS
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

-- Просмотр данных из представления CarOrderStatus
SELECT * FROM CarOrderStatus;

-- Создание индекса на поле Email в таблице Customers
CREATE drop  index IX_Customers_Email ON Customers (Email);

-- Создание индекса на поле Model в таблице Cars
CREATE INDEX IX_Cars_Model ON Cars (Model);

CREATE OR REPLACE PROCEDURE InsertOrder(
    p_Start_Date IN DATE,
    p_End_Date IN DATE,
    p_Customer_ID IN NUMBER,
    p_Car_id IN NUMBER,
    p_Status_id IN NUMBER
)
IS
BEGIN
    INSERT INTO Orders (Order_id, Start_Date, End_Date, Customer_ID, Car_id, Status_id)
    VALUES (Order_id_sequence.NEXTVAL, p_Start_Date, p_End_Date, p_Customer_ID, p_Car_id, p_Status_id);
    
    COMMIT;
EXCEPTION
    WHEN OTHERS THEN
        ROLLBACK;
        RAISE;
END InsertOrder;
/



