/*6. ����������� ��������, � ������� � ������� CASE ������������� ������, ����������
���������� ���������� ��-�������� ��� ����� ���������.*/

USE UNIVER;

SELECT (CASE
WHEN NOTE BETWEEN 0 AND 3 THEN '�� ����'
WHEN NOTE BETWEEN 4 AND 5 THEN '���������'
WHEN NOTE BETWEEN 6 AND 7 THEN '������'
WHEN NOTE BETWEEN 8 AND 10 THEN '�����'
END) ������, COUNT(*) [����������] FROM PROGRESS
GROUP BY (CASE
WHEN NOTE BETWEEN 0 AND 3 THEN '�� ����'
WHEN NOTE BETWEEN 4 AND 5 THEN '���������'
WHEN NOTE BETWEEN 6 AND 7 THEN '������'
WHEN NOTE BETWEEN 8 AND 10 THEN '�����'
END)
