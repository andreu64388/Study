/*8. Разработать скрипт, демонстриру-ющий использование оператора RE-TURN. */
DECLARE @I INT = 20;
PRINT @I+1;
PRINT POWER(@I,3);
RETURN
PRINT @I+10;

DECLARE @INDEX INT = 0;
WHILE @INDEX <10
BEGIN
  IF @INDEX =5
  BEGIN
  PRINT 'THE END - 5'
  RETURN
  END
  PRINT @INDEX
  SET @INDEX +=1;
END