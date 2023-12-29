
-- ����������� ������������� ��� ������� TIMETABLE (������������ ������ 6) � ���� ����������. 
-- ������� �������� PIVOT � ������������ ���.

-- PIVOT(���������� �������
-- FOR �������, ���������� ��������, ������� ������ ������� ��������
-- IN ([�������� �� �����������],�)
-- ) AS ��������� ������� (�����������)


USE UNIVER;
GO
ALTER TABLE TIMETABLE ADD CLASSNUMBER INT;

GO
CREATE VIEW [����������]
AS SELECT CLASSNUMBER [����� ����], SUBJECT [�������], IDGROUP [������] FROM TIMETABLE
GROUP BY IDGROUP, CLASSNUMBER, SUBJECT;
GO
SELECT * FROM [����������];

SELECT [������], [1] AS [14.40-16.00], [2] AS [16.30-17.50], [3] AS [18.05-19.25], [4] AS [19.40-21.00]
FROM [����������]
PIVOT(COUNT([�������]) FOR [����� ����] IN([1], [2], [3], [4])) AS PVT

SELECT [������], [���], [��], [���], [��], [��]
FROM [����������]
PIVOT(COUNT([����� ����]) FOR [�������] IN([���], [��], [���], [��], [��])) AS PVT1