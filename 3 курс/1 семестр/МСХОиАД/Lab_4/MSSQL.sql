select * from Customers


--  1. Вычисление итогов предоставленных услуг для определенного вида услуги помесячно, за квартал, за полгода, за год.
SELECT
    YEAR(Start_Date) AS Year,
    MONTH(Start_Date) AS Month,
    Service_id,
    SUM(Payment_Amount) AS TotalAmount
FROM Orders
JOIN Order_Services ON Orders.Order_id = Order_Services.Order_id
JOIN Payments ON Orders.Order_id = Payments.Order_id
WHERE Service_id =1
GROUP BY YEAR(Start_Date), MONTH(Start_Date), Service_id
ORDER BY Year, Month;


-- 1
SELECT
    Service_name,
    YEAR(Start_Date) AS Year,
    MONTH(Start_Date) AS Month,
    SUM(Payment_Amount) AS Total_Cost
FROM
    Orders AS o
    INNER JOIN Order_Services AS os ON o.Order_id = os.Order_id
    INNER JOIN Services AS s ON os.Service_id = s.Service_id
    INNER JOIN Payments AS p ON o.Order_id = p.Order_ID
GROUP BY
    Service_name,
    YEAR(Start_Date),
    MONTH(Start_Date)
ORDER BY
    Service_name,
    Year,
    Month;



--2
WITH TotalServices AS (
    SELECT
        s.Service_name,
        SUM(p.Payment_Amount) AS TotalAmount
    FROM Orders o
    JOIN Order_Services os ON o.Order_id = os.Order_id
    JOIN Payments p ON o.Order_id = p.Order_ID
    JOIN Services s ON os.Service_id = s.Service_id
    WHERE s.Service_name = 'Аренда автомобиля'
    GROUP BY s.Service_name
),
PeriodServices AS (
    SELECT
        s.Service_name,
        SUM(p.Payment_Amount) AS PeriodAmount
    FROM Orders o
    JOIN Order_Services os ON o.Order_id = os.Order_id
    JOIN Payments p ON o.Order_id = p.Order_ID
    JOIN Services s ON os.Service_id = s.Service_id
    WHERE s.Service_name = 'Аренда автомобиля' -- Замените на нужное имя вашей услуги
    AND o.Start_Date BETWEEN '2023-10-05' AND '2023-12-05' -- Замените на даты начала и конца периода
    GROUP BY s.Service_name
)
SELECT
    ps.Service_name AS Услуга,
    ps.PeriodAmount AS Объем_услуг,
    (ps.PeriodAmount / ts.TotalAmount * 100) AS Объем_услуг_в_процентах_от_общего,
    (ps.PeriodAmount / MAX(ts.TotalAmount) OVER () * 100) AS Объем_услуг_в_процентах_от_максимального
FROM PeriodServices ps
JOIN TotalServices ts ON ps.Service_name = ts.Service_name;


--3
WITH CustomerRentData AS (
    SELECT
        c.Customer_id,
        c.First_Name,
        c.Last_Name,
        s.Service_name AS ServiceName,
        YEAR(o.Start_Date) AS RentYear,
        MONTH(o.Start_Date) AS RentMonth,
        SUM(p.Payment_Amount) AS RentAmount
    FROM Customers c
    JOIN Orders o ON c.Customer_id = o.Customer_id
    JOIN Payments p ON o.Order_id = p.Order_ID
    JOIN Order_Services os ON o.Order_id = os.Order_id
    JOIN Services s ON os.Service_id = s.Service_id
    WHERE o.Start_Date >= DATEADD(MONTH, -5, GETDATE()) -- Последние 6 месяцев
    GROUP BY c.Customer_id, c.First_Name, c.Last_Name, s.Service_name, YEAR(o.Start_Date), MONTH(o.Start_Date)
)
SELECT
    Customer_id AS CustomerID,
    First_Name AS FirstName,
    Last_Name AS LastName,
    ServiceName AS ServiceName,
    RentYear AS Year,
    RentMonth AS Month,
    ISNULL(RentAmount, 0) AS RentAmount
FROM CustomerRentData
ORDER BY Customer_id, RentYear, RentMonth, ServiceName;



WITH MonthlyRent AS (
    SELECT
        S.Status_name AS Customer_Status,
        MONTH(O.Start_Date) AS Month,
        YEAR(O.Start_Date) AS Year,
        SUM(C.Rental_price) AS Monthly_Rental_Sum
    FROM Orders O
    JOIN Customers Cus ON O.Customer_id = Cus.Customer_id
    JOIN Status_ S ON Cus.Status_id = S.Status_id
    WHERE O.Start_Date >= DATEADD(MONTH, -5, GETDATE())  -
    GROUP BY S.Status_name, YEAR(O.Start_Date), MONTH(O.Start_Date)
)
SELECT
    Customer_Status,
    CONCAT(Year, '-', RIGHT('0' + CAST(Month AS VARCHAR), 2)) AS YearMonth,
    Monthly_Rental_Sum
FROM MonthlyRent
ORDER BY Customer_Status, Year, Month;










--4

WITH OrderedOrders AS (
    SELECT
        Order_id,
        Start_Date,
        Customer_id,
        ROW_NUMBER() OVER (ORDER BY Start_Date) AS RowNum
    FROM Orders
)
SELECT *
FROM OrderedOrders
WHERE RowNum BETWEEN 1 AND 20; 

--5
WITH RankedCustomers AS (
    SELECT
        Customer_id,
        First_Name,
        Last_Name,
        Email,
        ROW_NUMBER() OVER (PARTITION BY Email ORDER BY Customer_id) AS RowNum
    FROM Customers
)
DELETE FROM Customers
WHERE Customer_id IN (
    SELECT Customer_id
    FROM RankedCustomers
    WHERE RowNum > 1
);



--last
WITH ServiceCounts AS (
    SELECT
        s.Service_name,
        s.Service_description,
        o.Customer_id,
        COUNT(os.Service_id) AS ServiceCount,
        RANK() OVER (PARTITION BY o.Customer_id ORDER BY COUNT(os.Service_id) DESC) AS ServiceRank
    FROM Orders o
    JOIN Order_Services os ON o.Order_id = os.Order_id
    JOIN Services s ON os.Service_id = s.Service_id
    GROUP BY o.Customer_id, s.Service_name, s.Service_description
)
SELECT
    sc.Customer_id AS CustomerID,
    c.First_Name AS FirstName,
    c.Last_Name AS LastName,
    sc.Service_name AS MostFrequentService,
    sc.Service_description AS MostFrequentServiceDescription,
    sc.ServiceCount AS ServiceCount
FROM ServiceCounts sc
JOIN Customers c ON sc.Customer_id = c.Customer_id
WHERE sc.ServiceRank = 1;
