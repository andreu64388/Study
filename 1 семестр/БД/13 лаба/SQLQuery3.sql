/*3. Разработать табличную функцию FFACPUL, результа-ты работы которой продемонстрированы на рисунке ниже. 
Функция принимает два параметра, задающих код фа-культета (столбец FACULTY.FACULTY) и код кафедры (столбец PULPIT.PULPIT). Использует SELECT-запрос c левым внешним соединением между таблицами FACULTY и PULPIT. 
Если оба параметра функции равны NULL, то она воз-вращает список всех кафедр на всех факультетах. 
Если задан первый параметр (второй равен NULL), функ-ция возвращает список всех кафедр заданного факультета. 
Если задан второй параметр (первый равен NULL), функ-ция возвращает результирующий набор, содержащий стро-ку, соответствующую заданной кафедре.
*/
USE UNIVER;
CREATE FUNCTION FFACPUL(@FAC VARCHAR(10), @PUL VARCHAR(10)) RETURNS TABLE
    AS RETURN
    SELECT FACULTY.FACULTY, PULPIT.PULPIT
    FROM FACULTY LEFT OUTER JOIN PULPIT
    ON FACULTY.FACULTY = PULPIT.FACULTY
WHERE FACULTY.FACULTY=ISNULL(@FAC, FACULTY.FACULTY) AND PULPIT.PULPIT=ISNULL(@PUL, PULPIT.PULPIT);
GO
--DROP FUNCTION DBO.FFACPUL;

SELECT * FROM DBO.FFACPUL(NULL,NULL);
SELECT * FROM DBO.FFACPUL('ИЭФ',NULL);
SELECT * FROM DBO.FFACPUL(NULL,'ИСИТ');
SELECT * FROM DBO.FFACPUL('ТТЛП','ЛМИЛЗ');
SELECT * FROM DBO.FFACPUL('NO','NO');