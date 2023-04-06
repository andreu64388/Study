/*1. пЮГПЮАНРЮРЭ ЯЙЮКЪПМСЧ ТСМЙЖХЧ Я ХЛЕМЕЛ COUNT_STUDENTS, ЙНРНПЮЪ БШВХЯКЪЕР ЙНКХВЕЯРБН ЯРС-ДЕМРНБ МЮ ТЮЙСКЭРЕР
Е, ЙНД ЙНРНПНЦН ГЮДЮЕРЯЪ ОЮПЮЛЕРПНЛ РХОЮ VARCHAR(20) Я ХЛЕМЕЛ @faculty. хЯОНКЭГНБЮРЭ БМСРПЕММЕЕ ЯНЕДХМЕМХЕ РЮАКХЖ 
FACULTY, GROUPS, STU-DENT. нОПНАНБЮРЭ ПЮАНРС ТСМЙЖХХ.
*/
-------------------------------------------------
---------------------UNIVER----------------------
-------------------------------------------------
USE UNIVER;
GO
CREATE FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20)) RETURNS INT AS
BEGIN
    DECLARE @COUNT INT=0;
    SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
    FROM FACULTY
	JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
	JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
	WHERE FACULTY.FACULTY = @FACULTY)
    RETURN @COUNT;
END;
GO


--DROP FUNCTION COUNT_STUDENTS;

DECLARE @TEMP_1 INT = DBO.COUNT_STUDENTS('хдхо');
PRINT 'йнкхвеярбн ярсдемрнб мю тюйскэрере ' +CAST(@TEMP_1 AS NVARCHAR(20))+ ' векнбей.';

GO
SELECT FACULTY 'тюйскэрер',
DBO.COUNT_STUDENTS(FACULTY) 'йнк-бн ярсдемрнб'
FROM FACULTY
GO

/*бмеярх хглемемхъ б рейяр тсмйжхх я онлныэч ноепюрнпю ALTER я рел, врнаш тсмйжхъ опхмхлюкю 
брнпни оюпюлерп @PROF рхою VARCHAR(20), нангмювючыхи яоежхюкэмнярэ ярсдемрнб. дкъ оюпюлерпнб нопедекхрэ
гмювемхъ он слнквю-мхч NULL. нопнанбюрэ пюанрс тсмйжхх я онлныэч SE-LECT-гюопнянб.*/

ALTER FUNCTION COUNT_STUDENTS (@FACULTY NVARCHAR(20), @PROF NVARCHAR(20)) RETURNS INT AS
BEGIN
    DECLARE @COUNT INT=0;
    SET @COUNT=(SELECT COUNT(STUDENT.IDSTUDENT)
    FROM FACULTY
    INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
    INNER JOIN STUDENT ON STUDENT.IDGROUP = GROUPS.IDGROUP
    WHERE FACULTY.FACULTY = @FACULTY AND GROUPS.PROFESSION = @PROF)
    RETURN @COUNT;
END;
GO

DECLARE @RESULT INT = DBO.COUNT_STUDENTS('хщт', '1-25 01 07');
PRINT 'йнкхвеярбн ярсдемрнб: ' + CONVERT(VARCHAR, @RESULT);

SELECT FACULTY.FACULTY 'тюйскэрер',
	GROUPS.PROFESSION 'яоежхюкэмнярэ',
	DBO.COUNT_STUDENTS(FACULTY.FACULTY, GROUPS.PROFESSION) 'йнк-бн ярсдемрнб'
FROM FACULTY
	INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
GROUP BY FACULTY.FACULTY, GROUPS.PROFESSION
GO

-------------------------------------------------
-----------------------BANK----------------------
-------------------------------------------------


CREATE FUNCTION COUNT_CREDITS (@ID_USER INT) RETURNS INT AS 
BEGIN
DECLARE @COUNTS INT = 0;
SET @COUNTS = (SELECT COUNT(нТНПЛКЕМХЕ.id) AS йпедхрнб FROM нТНПЛКЕМХЕ
WHERE нТНПЛКЕМХЕ.id = @ID_USER)   
RETURN @COUNTS
END

DECLARE @RESULT INT = DBO.COUNT_CREDITS(2);
PRINT 'йн-бн йпедхрнб мю щрнцн векнбейю = ' + CAST(@RESULT AS NVARCHAR)


SELECT нтнплкемхе.мнлеп_йпедхрю [мнлеп йпедхрю],
 DBO.COUNT_CREDITS(нтнплкемхе.ID) [йнк-бн],
 нтнплкемхе.ясллю [ясллю]
FROM нтнплкемхе

------------------------------------------------
