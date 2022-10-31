/*2. Ðàçðàáîòàòü ñêðèïò, â êîòîðîì îïðåäåëÿåòñÿ îáùàÿ âìåñòèìîñòü àóäè-òîðèé. 
Êîãäà îáùàÿ âìåñòèìîñòü ïðå-âûøàåò 200, òî âûâåñòè êîëè÷åñòâî àóäèòîðèé, ñðåäíþþ âìåñòèìîñòü àóäè-òîðèé,
êîëè÷åñòâî àóäèòîðèé, âìåñòè-ìîñòü êîòîðûõ ìåíüøå ñðåäíåé, è ïðî-öåíò òàêèõ àóäèòîðèé. Êîãäà îáùàÿ âìåñòèìîñòü
àóäèòîðèé ìåíüøå 200, òî âûâåñòè ñîîáùåíèå î ðàçìåðå îáùåé âìåñòèìîñòè.*/
USE UNIVER;

DECLARE 
@CAPACITY INT = (SELECT SUM(AUDITORIUM_CAPACITY) FROM AUDITORIUM),
@TOTAL INT,
@AVGCAPACITY INT,
@TOTALLESSTHANAVG INT,
@PROCENT NUMERIC(4,2);

IF @CAPACITY > 200
BEGIN
SET @TOTAL = (SELECT COUNT(*) FROM AUDITORIUM);
SET @AVGCAPACITY = (SELECT AVG(AUDITORIUM_CAPACITY) FROM AUDITORIUM);
SET @TOTALLESSTHANAVG = (SELECT COUNT(*) FROM AUDITORIUM
WHERE AUDITORIUM_CAPACITY < @AVGCAPACITY);

SET @PROCENT = @TOTALLESSTHANAVG * 100 / @TOTAL;
SELECT @CAPACITY 'ÎÁÙÀß ÂÌÅÑÒÈÌÎÑÒÜ',
@TOTAL 'ÂÑÅÃÎ ÀÓÄÈÒÎÐÈÉ',
@AVGCAPACITY 'ÑÐÅÄÍßß ÂÌÅÑÒÈÌÎÑÒÜ',
@TOTALLESSTHANAVG 'ÀÓÄÈÒÎÐÈÉ Ñ ÂÌÅÑÒÈÌÎÑÒÜÞ ÍÈÆÅ ÑÐÅÄÍÅÃÎ',
@PROCENT 'ÏÐÎÖÅÍÒ ÒÀÊÈÕ ÀÓÄÈÒÎÐÈÉ'
END

ELSE PRINT 'ÎÁÙÀß ÂÌÅÑÒÈÌÎÑÒÜ < 200'