/*7. ����������� ������� ��� ���� ������ X_MyBASE � ������������������ �� ������. */
USE BANK;
DECLARE @NAME VARCHAR(20)
DECLARE LOCAL CURSOR GLOBAL STATIC SCROLL FOR
SELECT ��������_������� FROM ����
OPEN LOCAL
PRINT '���: '
FETCH LOCAL INTO @NAME
WHILE @@FETCH_STATUS = 0
BEGIN
PRINT '' + @NAME
FETCH LOCAL INTO @NAME
END
CLOSE LOCAL

OPEN LOCAL
PRINT '������ ������: '
FETCH FIRST FROM LOCAL INTO @NAME
PRINT @NAME

PRINT '������ ������ (ABSOLUTE)'
FETCH ABSOLUTE 2 FROM LOCAL INTO @NAME
PRINT @NAME

PRINT '����� ������ � ����� (ABSOLUTE)'
FETCH ABSOLUTE -5 FROM LOCAL INTO @NAME
PRINT @NAME

PRINT '������ ������ (RELATIVE)'
FETCH RELATIVE 2 FROM LOCAL INTO @NAME
PRINT @NAME

PRINT '��������� ������: '
FETCH NEXT FROM LOCAL INTO @NAME
PRINT @NAME

PRINT '��������������� ������: '
FETCH PRIOR FROM LOCAL INTO @NAME
PRINT @NAME

PRINT '��������� ������: '
FETCH LAST FROM LOCAL INTO @NAME
PRINT @NAME

CLOSE LOCAL