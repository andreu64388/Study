/*3. пюгпюанрюрэ рюакхвмсч тсмйжхч FFACPUL, пегскэрю-рш пюанрш йнрнпни опнделнмярпхпнбюмш мю пхясмйе мхфе. 
тсмйжхъ опхмхлюер дбю оюпюлерпю, гюдючыху йнд тю-йскэрерю (ярнкаеж FACULTY.FACULTY) х йнд йютедпш (ярнкаеж PULPIT.PULPIT). хяонкэгсер SELECT-гюопня C кебшл бмеьмхл янедхмемхел лефдс рюакхжюлх FACULTY х PULPIT. 
еякх наю оюпюлерпю тсмйжхх пюбмш NULL, рн нмю бнг-бпюыюер яохянй бяеу йютедп мю бяеу тюйскэрерюу. 
еякх гюдюм оепбши оюпюлерп (брнпни пюбем NULL), тсмй-жхъ бнгбпюыюер яохянй бяеу йютедп гюдюммнцн тюйскэрерю. 
еякх гюдюм брнпни оюпюлерп (оепбши пюбем NULL), тсмй-жхъ бнгбпюыюер пегскэрхпсчыхи мюанп, яндепфюыхи ярпн-йс, яннрберярбсчысч гюдюммни йютедпе.
*/
 ---------------------------------------
 ---------------UNIVER------------------
 ---------------------------------------
USE UNIVER
GO
CREATE FUNCTION FFACPUL(@FAC VARCHAR(10), @PUL VARCHAR(10)) RETURNS TABLE
    AS RETURN

    SELECT FACULTY.FACULTY, PULPIT.PULPIT
    FROM FACULTY LEFT OUTER JOIN PULPIT
    ON FACULTY.FACULTY = PULPIT.FACULTY
WHERE FACULTY.FACULTY=ISNULL(@FAC, FACULTY.FACULTY) AND PULPIT.PULPIT=ISNULL(@PUL, PULPIT.PULPIT);

GO
--DROP FUNCTION DBO.FFACPUL;
SELECT * FROM DBO.FFACPUL(NULL,NULL);
SELECT * FROM DBO.FFACPUL('хщт',NULL);
SELECT * FROM DBO.FFACPUL(NULL,'хяхр');
SELECT * FROM DBO.FFACPUL('ррко','клхкг');
SELECT * FROM DBO.FFACPUL('NO','NO');
GO

 ---------------------------------------
 ---------------BANK--------------------
 ---------------------------------------

 USE BANK
GO
CREATE FUNCTION FBANK_3 (@FAC INT, @PUL INT) RETURNS TABLE
    AS RETURN
    SELECT аюмй.ярюбйю, нтнплкемхе.ясллю
    FROM аюмй LEFT OUTER JOIN нтнплкемхе
    ON аюмй.ID = нтнплкемхе.ID
WHERE аюмй.ID =ISNULL(@FAC, нтнплкемхе.ясллю) AND  нтнплкемхе.ID=ISNULL(@PUL,нтнплкемхе.ID);

GO
SELECT * FROM DBO.FBANK_3(1,1);