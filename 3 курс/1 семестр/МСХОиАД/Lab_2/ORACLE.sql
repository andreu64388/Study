-- �������� �������� UpdateOrderStatus
-- ���� ������� ����� ���������� ����� ���������� ������ � ������� Orders.

CREATE OR REPLACE TRIGGER UpdateOrderStatus
AFTER UPDATE ON Orders
FOR EACH ROW
BEGIN
    -- ��������� ������ ������ �� "�������" ��� �������, ������� ����� ���������.
    IF :NEW.Start_Date <= SYSDATE AND :NEW.End_Date >= SYSDATE THEN
        :NEW.Order_Status := '�������';
    END IF;

    -- ��������� ������ ������ �� "��������" ��� �������, ������� �����������.
    IF :NEW.End_Date < SYSDATE THEN
        :NEW.Order_Status := '��������';
    END IF;
END;
/

-- �������� ������������� OrderCustomerView
CREATE OR REPLACE VIEW OrderCustomerView AS
SELECT o.Order_ID, o.Start_Date, o.End_Date, c.First_Name, c.Last_Name
FROM Orders o
JOIN Customers c ON o.Customer_ID = c.Customer_ID;

-- �������� ������� �� ������� Customer_ID ������� Orders
CREATE INDEX IX_Orders_Customer_ID ON Orders (Customer_ID);



-- �������� ������������������ ��� Car_ID
CREATE SEQUENCE Car_ID_Seq START WITH 1 INCREMENT BY 1;

-- �������� ������������������ ��� Customer_ID
CREATE SEQUENCE Customer_ID_Seq START WITH 1 INCREMENT BY 1;

-- �������� ������������������ ��� Order_ID
CREATE SEQUENCE Order_ID_Seq START WITH 1 INCREMENT BY 1;

-- �������� ������������������ ��� Payment_ID
CREATE SEQUENCE Payment_ID_Seq START WITH 1 INCREMENT BY 1;
