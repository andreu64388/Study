/*2. �� ������ ������ AUDITORIUM � AUDITORIUM_TYPE ����������� ������, ����������� ��� ������� ���� 
��������� ������������, �����������,
������� ����������� ���������, ��������� ���-�������� ���� ��������� � ����� ������-���� ���������
������� ����. �������������� ����� ������ �����-���� ������� � ������������� ���� ����-����� 
(������� AUDITORIUM_TYPE.AU-DITORIUM_TYPENAME) � ������� � ������������ ����������.
������������ ���������� ���������� ������, ������ GROUP BY � ���������� �������. */

use UNIVER;

SELECT AUDITORIUM_TYPENAME, max(AUDITORIUM_CAPACITY) as [������������ ���������������],
 min(AUDITORIUM_CAPACITY) as [����������� ���������������],
 avg(AUDITORIUM_CAPACITY) as [������� ���������������],
count(AUDITORIUM) as [����� ���-�� ���������],
 sum(AUDITORIUM_CAPACITY) as [����� ��������������� ��������� ������� ����]
From AUDITORIUM_TYPE  join AUDITORIUM A on AUDITORIUM_TYPE.AUDITORIUM_TYPE = A.AUDITORIUM_TYPE
Group By AUDITORIUM_TYPENAME


-------------------------------
USE BANK;
SELECT
��������_�������,
MAX(�����) AS [������������ �����],
min(�����) AS [����������� �����],
avg(�����) AS [������� �����],
count (�����) AS [���-��]
FROM ����������
join ���� on ����.id = ����������.id
group by ��������_�������