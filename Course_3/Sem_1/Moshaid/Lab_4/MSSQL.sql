use cars;


	--  1. Вычисление итогов предоставленных услуг для определенного вида услуги помесячно, за квартал, за полгода, за год.

	WITH DateIntervals AS (
		SELECT 'За последний месяц' AS Interval
		UNION SELECT 'За последний квартал'
		UNION SELECT 'За последние полгода'
		UNION SELECT 'За последний год'
	)
	SELECT
		di.Interval AS Period,
		COALESCE(SUM(p.Payment_Amount), 0) AS TotalAmount
	FROM DateIntervals di
	LEFT JOIN Orders o ON (
		(di.Interval = 'За последний месяц' AND o.Start_Date >= DATEADD(MONTH, -1, GETDATE())) OR
		(di.Interval = 'За последний квартал' AND o.Start_Date >= DATEADD(QUARTER, -1, GETDATE())) OR
		(di.Interval = 'За последние полгода' AND o.Start_Date >= DATEADD(MONTH, -6, GETDATE())) OR
		(di.Interval = 'За последний год' AND o.Start_Date >= DATEADD(YEAR, -1, GETDATE()))
	)
	LEFT JOIN Payments p ON o.Order_id = p.Order_ID
	LEFT JOIN Order_Services os ON o.Order_id = os.Order_id
	LEFT JOIN Services s ON os.Service_id = s.Service_id
	WHERE s.Service_name = 'Аренда автомобиля'
	GROUP BY di.Interval
	ORDER BY di.Interval;





select * from Order_Services

select * from Payments

select * from Orders


--2 Вычисление итогов предоставленных услуг для определенного вида услуги за период:
--	объем услуг;
--	сравнение их с общим объемом услуг (в %);
--	сравнение с наибольшим объемом услуг (в %).

WITH ServiceSummary AS (
    SELECT
        S.Service_id,
        S.Service_name,
        SUM(P.Payment_Amount) AS TotalAmount
    FROM
        Services S
    LEFT JOIN
        Order_Services OS ON S.Service_id = OS.Service_id
    LEFT JOIN
        Payments P ON OS.Order_id = P.Order_ID
    WHERE
        P.Payment_Date >= '2023-10-05' 
        AND P.Payment_Date <= '2023-12-05' 
    GROUP BY
        S.Service_id, S.Service_name
),
TotalServices AS (
    SELECT
        SUM(TotalAmount) AS TotalServiceAmount
    FROM
        ServiceSummary
),
MaxService AS (
    SELECT
        MAX(TotalAmount) AS MaxServiceAmount
    FROM
        ServiceSummary
)
SELECT
    S.Service_id,
    S.Service_name,
    S.TotalAmount AS ServiceAmount,
    (S.TotalAmount / TS.TotalServiceAmount) * 100 AS PercentageOfTotal,
    (S.TotalAmount / MS.MaxServiceAmount) * 100 AS PercentageOfMax
FROM
    ServiceSummary S
CROSS JOIN TotalServices TS
CROSS JOIN MaxService MS;








select * from Services
--4.	Продемонстрируйте применение функции ранжирования ROW_NUMBER() для разбиения результатов 
--запроса на страницы (по 20 строк на каждую страницу).


WITH OrderedOrders AS (
    SELECT
        Order_id,
        Start_Date,
        End_Date,
        Customer_id,
        Car_ID,
        Status_id,
        ROW_NUMBER() OVER (ORDER BY Order_id) AS RowNum
    FROM
        Orders
)

SELECT
    Order_id,
    Start_Date,
    End_Date,
    Customer_id,
    Car_ID,
    Status_id
FROM
    OrderedOrders
WHERE
    RowNum BETWEEN 1 AND 2; -- Первая страница


--5.	Продемонстрируйте применение функции ранжирования ROW_NUMBER() для удаления дубликатов.

WITH DeduplicatedCustomers AS (
    SELECT
        Customer_id,
        First_Name,
        Last_Name,
        Address,
        Phone_number,
        Email,
        Drivers_license,
        ROW_NUMBER() OVER (PARTITION BY Email ORDER BY Customer_id) AS RowNum
    FROM
        Customers
)

DELETE FROM DeduplicatedCustomers
WHERE
    RowNum > 1;

--6 Вернуть для каждого вида клиентов суммы за аренду последних 6 месяцев помесячно.
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


--7  Какая услуга была предоставлена наибольшее число раз для определенного вида? Вернуть для всех клиентов.

WITH ServiceCounts AS (
    SELECT
        S.Service_name,
        C.Customer_id,
        COUNT(*) AS ServiceCount,
        RANK() OVER (PARTITION BY S.Service_name ORDER BY COUNT(*) DESC) AS Rank
    FROM
        Customers C
    JOIN Orders O ON C.Customer_id = O.Customer_id
    JOIN Order_Services OS ON O.Order_id = OS.Order_id
    JOIN Services S ON OS.Service_id = S.Service_id
    GROUP BY
        S.Service_name,
        C.Customer_id
)

SELECT
    SC.Service_name,
    SC.Customer_id,
    SC.ServiceCount
FROM
    ServiceCounts SC
WHERE
    SC.Rank = 1
ORDER BY
    SC.Service_name;
