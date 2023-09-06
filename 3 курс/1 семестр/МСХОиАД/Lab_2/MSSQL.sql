-- Создание триггера UpdateOrderStatus
-- Этот триггер будет вызываться после обновления записи в таблице Orders.

-- Обновление статуса заказа на "Активен", если дата начала аренды меньше текущей даты и дата окончания аренды больше текущей даты.
-- Обновление статуса заказа на "Завершен", если дата окончания аренды меньше текущей даты.
-- Иначе оставляем статус заказа без изменений.

CREATE TRIGGER UpdateOrderStatus
ON Orders
AFTER UPDATE
AS
BEGIN
    -- Обновляем статус заказа на "Активен" для заказов, которые стали активными.
    UPDATE o
    SET o.Order_Status = 'Активен'
    FROM Orders o
    JOIN inserted i ON o.Order_ID = i.Order_ID
    WHERE i.Start_Date <= GETDATE() AND i.End_Date >= GETDATE();

    -- Обновляем статус заказа на "Завершен" для заказов, которые завершились.
    UPDATE o
    SET o.Order_Status = 'Завершен'
    FROM Orders o
    JOIN inserted i ON o.Order_ID = i.Order_ID
    WHERE i.End_Date < GETDATE();
END;



CREATE VIEW OrderCustomerView AS
SELECT o.Order_ID, o.Start_Date, o.End_Date, c.First_Name, c.Last_Name
FROM Orders o
JOIN Customers c ON o.Customer_ID = c.Customer_ID;


CREATE INDEX IX_Orders_Customer_ID ON Orders (Customer_ID);

select * from OrderCustomerView;