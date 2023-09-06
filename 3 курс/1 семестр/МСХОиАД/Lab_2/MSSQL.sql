-- �������� �������� UpdateOrderStatus
-- ���� ������� ����� ���������� ����� ���������� ������ � ������� Orders.

-- ���������� ������� ������ �� "�������", ���� ���� ������ ������ ������ ������� ���� � ���� ��������� ������ ������ ������� ����.
-- ���������� ������� ������ �� "��������", ���� ���� ��������� ������ ������ ������� ����.
-- ����� ��������� ������ ������ ��� ���������.

CREATE TRIGGER UpdateOrderStatus
ON Orders
AFTER UPDATE
AS
BEGIN
    -- ��������� ������ ������ �� "�������" ��� �������, ������� ����� ���������.
    UPDATE o
    SET o.Order_Status = '�������'
    FROM Orders o
    JOIN inserted i ON o.Order_ID = i.Order_ID
    WHERE i.Start_Date <= GETDATE() AND i.End_Date >= GETDATE();

    -- ��������� ������ ������ �� "��������" ��� �������, ������� �����������.
    UPDATE o
    SET o.Order_Status = '��������'
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