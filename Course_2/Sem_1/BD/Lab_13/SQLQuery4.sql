/*
4. мю пхясмйе мхфе онйюгюм яжемюпхи, делнмярпхпсчыхи пюанрс яйюкъпмни тсмйжхх FCTEACHER.
тсмйжхъ опхмх-люер ндхм оюпюлерп, гюдючыхи йнд йютедпш. тсмйжхъ бнг-бпюыюер йнкхвеярбн опеондюбюрекеи
мю гюдюммни оюпюлер-пнл йютедпе.
еякх оюпюлерп пюбем NULL, рн бнгбпюыюеряъ наыее йнкхвеярбн опеондюбюрекеи. */
USE UNIVER
GO
CREATE FUNCTION FCTEACHER(@PUL NVARCHAR(10)) RETURNS INT AS
    BEGIN
        DECLARE @COUNT INT=(SELECT COUNT(*) FROM TEACHER
        WHERE PULPIT=ISNULL(@PUL, PULPIT));
        RETURN @COUNT;
    END;
GO
-- DROP FUNCTION FCTEACHER;

SELECT PULPIT, DBO.FCTEACHER(PULPIT) [йнкхвеярбн опеондюбюрекеи] FROM PULPIT;

SELECT DBO.FCTEACHER(NULL) [бяецн опеондюбюрекеи];

 ---------------------------------------
 ---------------BANK--------------------
 ---------------------------------------
USE BANK
GO
CREATE FUNCTION FBAKR(@ID INT) RETURNS INT AS
    BEGIN
        DECLARE @COUNT INT=(SELECT COUNT(*) FROM аюмй
        WHERE ID =ISNULL(@ID, ID));
        RETURN @COUNT;
    END;
GO

SELECT DBO.FBAKR(NULL) [бяецн аюмйнб];

SELECT DBO.FBAKR(1) [бяецн аюмйнб];

