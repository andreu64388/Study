/*10. �� ������ ������� PROGRESS ���������� ��� ������ ���������� ����-������ ���������, ���������� ������ 8 � 9.
������������ �����������, ������ HAVING, ����������. */

use UNIVER;
select SUBJECT,
       count(NOTE) as [���-��]
from PROGRESS
group by SUBJECT, NOTE
HAVING NOTE in (8, 9)


------------------------

USE BANK;
SELECT ����.��������_�������,
����.������, 
avg(����������.�����)
FROM ���� 
Full JOIN ���������� ON ����.id = ����������.id
GROUP BY ��������_�������,������
HAVING ������ >10