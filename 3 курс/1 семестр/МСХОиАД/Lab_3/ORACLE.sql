

ALTER TABLE Customers ADD Parent_Customer_id NUMBER;


select * from customers
CREATE OR REPLACE PROCEDURE DisplayCustomerHierarchy(p_Customer_id NUMBER) AS
BEGIN
    FOR rec IN (
        SELECT LEVEL, Customer_id, First_Name, Last_Name
        FROM Customers
        START WITH Customer_id = p_Customer_id
        CONNECT BY PRIOR Customer_id = Parent_Customer_id
        ORDER SIBLINGS BY Customer_id
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Level: ' || rec.LEVEL || ', Customer_id: ' || rec.Customer_id || ', Name: ' || rec.First_Name || ' ' || rec.Last_Name);
    END LOOP;
END;
/

BEGIN
    DisplayCustomerHierarchy(1); 
END;


CREATE OR REPLACE PROCEDURE AddSubordinateCustomer(p_Parent_Customer_id NUMBER, p_First_Name VARCHAR2, p_Last_Name VARCHAR2) AS
    v_NewCustomerId NUMBER;
BEGIN

    SELECT MAX(Customer_id) + 1 INTO v_NewCustomerId FROM Customers;


    INSERT INTO Customers (Customer_id, Parent_Customer_id, First_Name, Last_Name)
    VALUES (v_NewCustomerId, p_Parent_Customer_id, p_First_Name, p_Last_Name);
    
    COMMIT;
END;
/

BEGIN
    AddSubordinateCustomer(3, 'Jane', 'Smith'); 
END;
/

select * from customers


CREATE OR REPLACE PROCEDURE MoveSubtreeToNewParent(p_Source_Customer_id NUMBER, p_Target_Customer_id NUMBER) AS
BEGIN
  
    UPDATE Customers
    SET Parent_Customer_id = p_Target_Customer_id
    WHERE Customer_id = p_Source_Customer_id OR
          Parent_Customer_id = p_Source_Customer_id;

    COMMIT; 
END;
/

BEGIN
    MoveSubtreeToNewParent(3, 1); -- Переместить подчиненную ветку с Customer_id 3 в нового родителя с Customer_id 1
END;
/

