/*4. ��������� ������� STUDENT �������-���� XML-���������, ���������� ���������� ������ ��������: ����� � ����� ��������, ���-��� �����, ���� ������ � ����� ��������. 
����������� ��������, � ������� ������� �������� INSERT, ����������� ������ � XML-��������.
�������� � ���� �� �������� �������� UP-DATE, ���������� ������� INFO � ����� ������ ������� STUDENT � �������� SELECT, ����������� �������������� �����, ����������� ��������������� �� ��-�����. 
� SELECT-������� ������������ ������ QUERY � VALUEXML-����.
*/

--------------------------------------
---------------UNIVER-----------------
--------------------------------------
USE  UNIVER;
GO
 
INSERT INTO STUDENT(IDGROUP, NAME, BDAY, INFO)
VALUES(4, '�������� �.�.', '2001-10-15',
	'<�������>
		<������� �����="��" �����="4133033" ����="2013-04-19" />
		<�������>+375291247723</�������>
		<�����>
			<������>��������</������>
			<�����>�������</�����>
			<�����>����������</�����>
			<���>18</���>
			<��������>36</��������>
		</�����>
	</�������>');
GO
SELECT * FROM STUDENT WHERE NAME = '�������� �.�.'
GO
UPDATE STUDENT SET INFO = 
	'<�������>
		<������� �����="��" �����="4133033" ����="19.04.2013" />
		<�������>+375291234567</�������>
		<�����>
			<������>��������</������>
			<�����>������</�����>
			<�����>���������</�����>
			<���>10</���>
			<��������>10</��������>
		</�����>
	</�������>' WHERE NAME='�������� �.�.'; 
GO
SELECT NAME[���], INFO.value('(�������/�������/@�����)[1]', 'CHAR(2)')[����� ��������],
	INFO.value('(�������/�������/@�����)[1]', 'VARCHAR(20)')[����� ��������],
	INFO.query('/�������/�����')[�����]
		FROM  STUDENT
			WHERE NAME = '�������� �.�.';  


			
--------------------------------------
-----------------BANK-----------------
--------------------------------------