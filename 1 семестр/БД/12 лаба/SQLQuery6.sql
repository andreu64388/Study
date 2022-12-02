/*6. –¿«–¿¡Œ“¿“‹ œ–Œ÷≈ƒ”–” — »Ã≈Õ≈Ã PAUDITORI-UM_INSERTX. œ–Œ÷≈ƒ”–¿ œ–»Õ»Ã¿≈“ œﬂ“‹ ¬’ŒƒÕ€’ œ¿–¿Ã≈“–Œ¬: @A, @N, @C, @T » @TN. 
œ¿–¿Ã≈“–€ @A, @N, @C, @T ¿Õ¿ÀŒ√»◊Õ€ œ¿–¿Ã≈“-–¿Ã œ–Œ÷≈ƒ”–€ PAUDITORIUM_INSERT. ƒŒœŒÀÕ»-“≈À‹Õ€… œ¿–¿Ã≈“– @TN ﬂ¬Àﬂ≈“—ﬂ ¬’ŒƒÕ€Ã, »Ã≈≈“ “»œ VARCHAR(50), œ–≈ƒÕ¿«Õ¿◊≈Õ ƒÀﬂ ¬¬Œƒ¿ «Õ¿◊≈Õ»ﬂ ¬
—“ŒÀ¡≈÷ AUDITORIUM_TYPE.AUDITORIUM_TYPENAME.
œ–Œ÷≈ƒ”–¿ ƒŒ¡¿¬Àﬂ≈“ ƒ¬≈ —“–Œ ». œ≈–¬¿ﬂ —“–Œ ¿ ƒŒ¡¿¬Àﬂ≈“—ﬂ ¬ “¿¡À»÷” AUDITORIUM_TYPE. «Õ¿◊≈-Õ»ﬂ —“ŒÀ¡÷Œ¬ AUDITORIUM_TYPE » AUDITORI-UM_ TYPENAME ƒŒ¡¿¬Àﬂ≈ÃŒ… —“–Œ » «¿ƒ¿ﬁ“—ﬂ —Œ-Œ“¬≈“—“¬≈ÕÕŒ œ¿–¿Ã≈“–¿Ã» @T » @TN. ¬“Œ–¿ﬂ —“–Œ ¿
ƒŒ¡¿¬Àﬂ≈“—ﬂ œ”“≈Ã ¬€«Œ¬¿ œ–Œ÷≈ƒ”–€ PAUDITORI-UM_INSERT.
ƒŒ¡¿¬À≈Õ»≈ —“–Œ » ¬ “¿¡À»÷” AUDITORI-UM_TYPE » ¬€«Œ¬ œ–Œ÷≈ƒ”–€ PAUDITORI-UM_INSERT ƒŒÀ∆Õ€ ¬€œŒÀÕﬂ“‹—ﬂ ¬ –¿Ã ¿’ ŒƒÕŒ… ﬂ¬ÕŒ… “–¿Õ«¿ ÷»» — ”–Œ¬Õ≈Ã »«ŒÀ»–Œ¬¿ÕÕŒ—“» SERI-ALIZABLE. 
¬ œ–Œ÷≈ƒ”–≈ ƒŒÀ∆Õ¿ ¡€“‹ œ–≈ƒ”—ÃŒ“–≈Õ¿ Œ¡–¿¡Œ“ ¿ Œÿ»¡Œ  — œŒÃŒŸ‹ﬁ Ã≈’¿Õ»«Ã¿ TRY/CATCH. ¬—≈ Œÿ»¡ » ƒŒÀ∆Õ€ ¡€“‹ Œ¡–¿¡Œ“¿Õ€ — ¬€ƒ¿◊≈… —ŒŒ“¬≈“-—“¬”ﬁŸ≈√Œ —ŒŒ¡Ÿ≈Õ»ﬂ ¬ —“¿Õƒ¿–“Õ€… ¬€’ŒƒÕŒ… œŒ“Œ . 
œ–Œ÷≈ƒ”–¿ PAUDITORIUM_INSERTX ƒŒÀ∆Õ¿ ¬Œ«¬–¿Ÿ¿“‹   “Œ◊ ≈ ¬€«Œ¬¿ «Õ¿◊≈Õ»≈ -1 ¬ “ŒÃ —À”◊¿≈, ≈—À» œ–Œ»«ŒÿÀ¿ Œÿ»¡ ¿ » 1, ≈—À» ¬€œŒÀÕ≈Õ»ﬂ œ–Œ÷≈-ƒ”–€ «¿¬≈–ÿ»ÀŒ—‹ ”—œ≈ÿÕŒ. 
*/

------------------------------------------------
----------------------UNVER---------------------
------------------------------------------------

USE UNIVER;
GO
CREATE PROCEDURE PAUDITORIUM_INSERTX
		@A CHAR(20),
		@N VARCHAR(50),
		@C INT = 0,
		@T CHAR(10),
		@TN VARCHAR(50)	--ƒŒœ., ƒÀﬂ ¬¬Œƒ¿ ¬ AUD_TYPEAUD_TYPENAME
AS BEGIN
DECLARE @RC INT = 1;
BEGIN TRY
	SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
	BEGIN TRAN
	INSERT INTO AUDITORIUM_TYPE(AUDITORIUM_TYPE, AUDITORIUM_TYPENAME)
				VALUES(@N, @TN);
	EXEC @RC = PAUDITORIUM_INSERT @A, @N, @C, @T;
	COMMIT TRAN;
	RETURN @RC;
END TRY
BEGIN CATCH
	PRINT 'ÕŒÃ≈– Œÿ»¡ »: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT '—ŒŒ¡Ÿ≈Õ»≈: ' + ERROR_MESSAGE();
	PRINT '”–Œ¬≈Õ‹: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT 'Ã≈“ ¿: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT 'ÕŒÃ≈– —“–Œ »: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT  NULL
	PRINT '»Ãﬂ œ–Œ÷≈ƒ”–€: ' + ERROR_PROCEDURE();
	IF @@TRANCOUNT > 0 ROLLBACK TRAN ;
	RETURN -1;
END CATCH;
END;


DECLARE @K3 INT;
EXEC @K3 = PAUDITORIUM_INSERTX '102-3', @N = ' √', @C = 85, @T = '102-3', @TN = 'œ–Œ÷≈ƒ”–¿';
PRINT ' Œƒ : ' + CAST(@K3 AS VARCHAR(3));
GO
SELECT * FROM AUDITORIUM;
SELECT * FROM AUDITORIUM_TYPE;

DELETE AUDITORIUM WHERE AUDITORIUM='102-3';
DELETE AUDITORIUM_TYPE WHERE AUDITORIUM_TYPE=' √';
GO
DROP PROCEDURE PAUDITORIUM_INSERTX;


------------------------------------------------
----------------------BANK----------------------
------------------------------------------------

USE BANK;
GO
CREATE PROCEDURE PBANK_INSERTX @ID_CL INT,@MOBILE INT,@FACE NVARCHAR(20),@ADDRES NVARCHAR(20),@VALUES INT
AS BEGIN
DECLARE @RC INT = 1;
BEGIN TRY
	SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
	BEGIN TRAN
	INSERT INTO TEST_X(VAL)
				VALUES(@VALUES);
	EXEC @RC = PBANK_INSERT @ID_CL, @MOBILE, @FACE, @ADDRES
	COMMIT TRAN;
	RETURN @RC;
END TRY
BEGIN CATCH
	PRINT 'ÕŒÃ≈– Œÿ»¡ »: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
	PRINT '—ŒŒ¡Ÿ≈Õ»≈: ' + ERROR_MESSAGE();
	PRINT '”–Œ¬≈Õ‹: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
	PRINT 'Ã≈“ ¿: ' + CAST(ERROR_STATE() AS VARCHAR(8));
	PRINT 'ÕŒÃ≈– —“–Œ »: ' + CAST(ERROR_LINE() AS VARCHAR(8));
	IF ERROR_PROCEDURE() IS NOT  NULL
	PRINT '»Ãﬂ œ–Œ÷≈ƒ”–€: ' + ERROR_PROCEDURE();
	IF @@TRANCOUNT > 0 ROLLBACK TRAN ;
	RETURN -1;
END CATCH;
END;


DECLARE @K3 INT;
EXEC @K3 = PBANK_INSERTX @ID_CL = 13, @MOBILE = 31, @FACE = 'NO', @ADDRES = 'FLAT' , @VALUES =6
PRINT ' Œƒ : ' + CAST(@K3 AS VARCHAR(3));
GO
SELECT * FROM  À»≈Õ“
SELECT * FROM TEST_X



