
-- пюгпюанрюрэ опедярюбкемхе дкъ рюакхжш TIMETABLE (кюанпюрнпмюъ пюанрю 6) б бхде пюяохяюмхъ. 
-- хгсвхрэ ноепюрнп PIVOT х хяонкэгнбюрэ ецн.

-- PIVOT(юцпецюрмюъ тсмйжхъ
-- FOR ярнкаеж, яндепфюыхи гмювемхъ, йнрнпше ярюмср хлемюлх ярнкажнб
-- IN ([гмювемхъ он цнпхгнмрюкх],┘)
-- ) AS ояебднмхл рюакхжш (наъгюрекэмн)


USE UNIVER;
GO
ALTER TABLE TIMETABLE ADD CLASSNUMBER INT;

GO
CREATE VIEW [пюяохяюмхе]
AS SELECT CLASSNUMBER [мнлеп оюпш], SUBJECT [опедлер], IDGROUP [цпсоою] FROM TIMETABLE
GROUP BY IDGROUP, CLASSNUMBER, SUBJECT;
GO
SELECT * FROM [пюяохяюмхе];

SELECT [цпсоою], [1] AS [14.40-16.00], [2] AS [16.30-17.50], [3] AS [18.05-19.25], [4] AS [19.40-21.00]
FROM [пюяохяюмхе]
PIVOT(COUNT([опедлер]) FOR [мнлеп оюпш] IN([1], [2], [3], [4])) AS PVT

SELECT [цпсоою], [йля], [ад], [хмт], [хо], [хц]
FROM [пюяохяюмхе]
PIVOT(COUNT([мнлеп оюпш]) FOR [опедлер] IN([йля], [ад], [хмт], [хо], [хц])) AS PVT1