USE master


USE Salary
CREATE TABLE ��������
(  [���] nvarchar(50)  NOT NULL DEFAULT ('---'), 
   [���������] nvarchar(50) NOT NULL DEFAULT ('---'), 
   [����, ���] int NOT NULL DEFAULT ((0)), 
   [�����, ���] float NOT NULL DEFAULT ((0)), 
   [������, ���] float NOT NULL DEFAULT ((0)), 
   [�������� �� ����, ���] float NOT NULL DEFAULT ((0)), 
   [�����, ���] float NOT NULL DEFAULT ((0)), 
   [������, ���] float NOT NULL DEFAULT ((0)), 
   [��������, ���] float NOT NULL DEFAULT ((0)) 
) 

INSERT into �������� (���, ���������, [����, ���], [�����, ���], [������, ���])
  Values('���������� �.�.', '����������� ��������', 16, 3000, 105),
	      ('����� �.�.', '�������� ������ ����������', 9, 2180, 300),
	      ('������� �.�.', 'HR-��������', 5, 1200, 100),
	      ('����� �.�.', '��������� �� ������', 20, 2500, 200),
	      ('������� �.�.', '������� ���������', 12, 1700, 655)

