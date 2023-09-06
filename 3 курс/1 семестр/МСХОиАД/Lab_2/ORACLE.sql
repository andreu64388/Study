-- Создание триггера UpdateOrderStatus
-- Этот триггер будет вызываться после обновления записи в таблице Orders.

CREATE OR REPLACE TRIGGER UpdateOrderStatus
AFTER UPDATE ON Orders
FOR EACH ROW
BEGIN
    -- Обновляем статус заказа на "Активен" для заказов, которые стали активными.
    IF :NEW.Start_Date <= SYSDATE AND :NEW.End_Date >= SYSDATE THEN
        :NEW.Order_Status := 'Активен';
    END IF;

    -- Обновляем статус заказа на "Завершен" для заказов, которые завершились.
    IF :NEW.End_Date < SYSDATE THEN
        :NEW.Order_Status := 'Завершен';
    END IF;
END;
/

-- Создание представления OrderCustomerView
CREATE OR REPLACE VIEW OrderCustomerView AS
SELECT o.Order_ID, o.Start_Date, o.End_Date, c.First_Name, c.Last_Name
FROM Orders o
JOIN Customers c ON o.Customer_ID = c.Customer_ID;

-- Создание индекса на столбце Customer_ID таблицы Orders
CREATE INDEX IX_Orders_Customer_ID ON Orders (Customer_ID);



-- Создание последовательности для Car_ID
CREATE SEQUENCE Car_ID_Seq START WITH 1 INCREMENT BY 1;

-- Создание последовательности для Customer_ID
CREATE SEQUENCE Customer_ID_Seq START WITH 1 INCREMENT BY 1;

-- Создание последовательности для Order_ID
CREATE SEQUENCE Order_ID_Seq START WITH 1 INCREMENT BY 1;

-- Создание последовательности для Payment_ID
CREATE SEQUENCE Payment_ID_Seq START WITH 1 INCREMENT BY 1;
