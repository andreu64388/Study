/*4. ����������� ��������, ���������-������ �������� ��������� � ������-�������� ������ 
������� � ��������� SCROLL �� ������� ���� ������ X_UNIVER.
������������ ��� ��������� �����-��� ����� � ��������� FETCH.
*/
DECLARE @TYPE NVARCHAR(20), @CAPACITY NVARCHAR(20)
DECLARE LOCAL CURSOR GLOBAL STATIC SCROLL FOR SELECT AUDITORIUM_TYPE, AUDITORIUM_CAPACITY FROM AUDITORIUM

OPEN LOCAL
PRINT '���: '
FETCH LOCAL INTO @TYPE, @CAPACITY
WHILE @@FETCH_STATUS = 0
BEGIN
PRINT '' + @TYPE + ' ' + @CAPACITY
FETCH LOCAL INTO @TYPE, @CAPACITY
END
CLOSE LOCAL

OPEN LOCAL
PRINT '������ ������: '
FETCH FIRST FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

PRINT '������ ������ (ABSOLUTE)'
FETCH ABSOLUTE 2 FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

PRINT '����� ������ � ����� (ABSOLUTE)'
FETCH ABSOLUTE -5 FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

PRINT '������ ������ (RELATIVE)'
FETCH RELATIVE 2 FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

PRINT '��������� ������: '
FETCH NEXT FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

PRINT '��������������� ������: '
FETCH PRIOR FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

PRINT '��������� ������: '
FETCH LAST FROM LOCAL INTO @TYPE, @CAPACITY
PRINT '' + @TYPE + @CAPACITY

CLOSE LOCAL
