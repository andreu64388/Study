/*6. пюгпюанрюрэ опнжедспс я хлемел PAUDITORI-UM_INSERTX. опнжедспю опхмхлюер оърэ бундмшу оюпюлерпнб: @A, @N, @C, @T х @TN. 
оюпюлерпш @A, @N, @C, @T юмюкнцхвмш оюпюлер-пюл опнжедспш PAUDITORIUM_INSERT. днонкмх-рекэмши оюпюлерп @TN ъбкъеряъ бундмшл, хлеер рхо VARCHAR(50), опедмюгмювем дкъ ббндю гмювемхъ б ярнкаеж AUDITORIUM_TYPE.AUDITORIUM_TYPENAME.
опнжедспю днаюбкъер дбе ярпнйх. оепбюъ ярпнйю днаюбкъеряъ б рюакхжс AUDITORIUM_TYPE. гмюве-мхъ ярнкажнб AUDITORIUM_TYPE х AUDITORI-UM_ TYPENAME днаюбкъелни ярпнйх гюдючряъ ян-нрберярбеммн оюпюлерпюлх @T х @TN. брнпюъ ярпнйю днаюбкъеряъ осрел бшгнбю опнжедспш PAUDITORI-UM_INSERT.

днаюбкемхе ярпнйх б рюакхжс AUDITORI-UM_TYPE х бшгнб опнжедспш PAUDITORI-UM_INSERT днкфмш бшонкмърэяъ б пюлйюу ндмни ъбмни рпюмгюйжхх я спнбмел хгнкхпнбюммнярх SERI-ALIZABLE. 
б опнжедспе днкфмю ашрэ опедсялнрпемю напюанрйю ньханй я онлныэч леуюмхглю TRY/CATCH. бяе ньхайх днкфмш ашрэ напюанрюмш я бшдювеи яннрбер-ярбсчыецн яннаыемхъ б ярюмдюпрмши бшундмни онрнй. 
опнжедспю PAUDITORIUM_INSERTX днкфмю бнгбпюыюрэ й рнвйе бшгнбю гмювемхе -1 б рнл яксвюе, еякх опнхгнькю ньхайю х 1, еякх бшонкмемхъ опнже-дспш гюбепьхкняэ сяоеьмн. 
*/

USE UNIVER;
CREATE PROCEDURE PAUDITORIUM_INSERTX
@A CHAR(20),
@N VARCHAR(50),
@C INT = 0,
@T CHAR(10),
@TN VARCHAR(50)--дно., дкъ ббндю б AUD_TYPEAUD_TYPENAME
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
PRINT 'мнлеп ньхайх: ' + CAST(ERROR_NUMBER() AS VARCHAR(6));
PRINT 'яннаыемхе: ' + ERROR_MESSAGE();
PRINT 'спнбемэ: ' + CAST(ERROR_SEVERITY() AS VARCHAR(6));
PRINT 'лерйю: ' + CAST(ERROR_STATE() AS VARCHAR(8));
PRINT 'мнлеп ярпнйх: ' + CAST(ERROR_LINE() AS VARCHAR(8));
IF ERROR_PROCEDURE() IS NOT NULL
PRINT 'хлъ опнжедспш: ' + ERROR_PROCEDURE();
IF @@TRANCOUNT > 0 ROLLBACK TRAN ;
RETURN -1;
END CATCH;
END;


DECLARE @K3 INT;
EXEC @K3 = PAUDITORIUM_INSERTX '652-3', @N = 'йц', @C = 85, @T = '652-3', @TN = 'аддддддддддддддд!!!';
PRINT 'йнд ньхайх: ' + CAST(@K3 AS VARCHAR(3));

SELECT * FROM AUDITORIUM;
SELECT * FROM AUDITORIUM_TYPE;

DELETE AUDITORIUM WHERE AUDITORIUM='622-3';
DELETE AUDITORIUM_TYPE WHERE AUDITORIUM_TYPE='йц';
GO

DROP PROCEDURE PAUDITORIUM_INSERTX;