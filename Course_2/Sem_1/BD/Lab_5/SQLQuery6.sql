/*6. �� ������ ������� PROGRESS ������������ ������,
���������� ����-��� �������� ������ (������� NOTE) �� �����������,
������� ��������� ����: ����, �� � ����. ����������: ������-������ ���
����������������� ���������� � ������ SELECT; 
� ����������� �����-���� ���������� ������� AVG. 
*/
use UNIVER;
SELECT 
top(1)
(SELECT  AVG(NOTE) FROM PROGRESS WHERE [SUBJECT] = '����') AS '����',
(SELECT AVG(NOTE) FROM PROGRESS WHERE [SUBJECT] = '��') AS '��',
(SELECT  AVG(NOTE) FROM PROGRESS WHERE [SUBJECT] = '����') AS '����'
FROM PROGRESS;



