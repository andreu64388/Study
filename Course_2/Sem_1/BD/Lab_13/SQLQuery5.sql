USE UNIVER
GO
CREATE FUNCTION COUNT_PULPIT(@FACULTY NVARCHAR(10)) RETURNS INT
AS BEGIN
    DECLARE @RC INT=0;
    SET @RC=(SELECT COUNT(*) FROM PULPIT
        WHERE PULPIT.FACULTY=@FACULTY)
    RETURN @RC;
END;
----DROP FUNCTION COUNT_PULPIT;
GO

CREATE FUNCTION COUNT_GROUPS(@FACULTY NVARCHAR(10)) RETURNS INT
AS BEGIN
    DECLARE @RC INT=0;
    SET @RC=(SELECT COUNT(*) FROM GROUPS
        WHERE GROUPS.FACULTY=@FACULTY)
    RETURN @RC;
END;
--DROP FUNCTION COUNT_GROUPS;
GO

CREATE FUNCTION COUNT_PROFESSION(@FACULTY VARCHAR(20)) RETURNS INT
	AS BEGIN
		DECLARE @RC INT = 0;
		SET @RC = (SELECT COUNT(*) FROM PROFESSION
			WHERE PROFESSION.FACULTY = @FACULTY)
		RETURN @RC;
	END;
--DROP FUNCTION COUNT_PROFESSION;
GO
DROP FUNCTION COUNT_STUDENTS

CREATE FUNCTION COUNT_STUDENTS (@FACULTY VARCHAR(20)) RETURNS INT
AS 
 BEGIN 
 DECLARE @RC INT = 0;
		SET @RC = (SELECT COUNT(*) FROM STUDENT
	     JOIN GROUPS ON GROUPS.IDGROUP = STUDENT.IDGROUP
			WHERE GROUPS.FACULTY = @FACULTY)
		RETURN @RC;
 END


CREATE FUNCTION FACULTY_REPORT(@C INT) RETURNS @FR TABLE
	([���������] VARCHAR(50),
	[���������� ������] INT,
	[���������� �����] INT,
	[���������� ���������] INT,
	[���������� ��������������] INT)
	AS BEGIN
		DECLARE CC CURSOR LOCAL STATIC FOR
			SELECT FACULTY FROM FACULTY WHERE DBO.COUNT_STUDENTS(FACULTY.FACULTY) > @C;
		DECLARE @F VARCHAR(30);
		OPEN CC;
			FETCH CC INTO @F;
		WHILE @@FETCH_STATUS = 0
			BEGIN
				INSERT @FR VALUES(
				@F,
				DBO.COUNT_PULPIT(@F),
	            DBO.COUNT_GROUPS(@F),
				DBO.COUNT_STUDENTS(@F),
				DBO.COUNT_PROFESSION(@F));
	            FETCH CC INTO @F;
			END;
		CLOSE CC;
		DEALLOCATE CC;
		RETURN;
	END;
GO
DROP FUNCTION 
DROP FUNCTION COUNT_PULPIT;
SELECT * FROM DBO.FACULTY_REPORT(1);
GO