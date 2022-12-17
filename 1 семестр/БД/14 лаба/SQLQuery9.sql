/*9. янгдюрэ DDL-рпхццеп, пеюцхпсчыхи мю бяе DDL-янашрхъ б ад UNIVER.
рпхццеп днк-фем гюопеыюрэ янгдюбюрэ мнбше рюакхжш х сдю-кърэ ясыеярбсчыхе. 
ябне бшонкмемхе рпхццеп днкфем янопнбнфдюрэ яннаыемхел, йнрнпне яндепфхр:
рхо янашрхъ, хлъ х рхо назейрю, ю рюйфе онъямхрекэмши рейяр, б яксвюе гюопеые-мхъ бшонкмемхъ ноепюрнпю. 
пюгпюанрюрэ яжемюпхи, делнмярпхпсчыхи пюанрс рпхццепю. 

*/

USE UNIVER

GO

CREATE TRIGGER TR_TEACHER_DDL ON DATABASE FOR DDL_DATABASE_LEVEL_EVENTS  
AS   
DECLARE @EVENT_TYPE VARCHAR(50) = EVENTDATA().VALUE('(/EVENT_INSTANCE/EVENTTYPE)[1]', 'VARCHAR(50)')
DECLARE @OBJ_NAME VARCHAR(50) = EVENTDATA().VALUE('(/EVENT_INSTANCE/OBJECTNAME)[1]', 'VARCHAR(50)')
DECLARE @OBJ_TYPE VARCHAR(50) = EVENTDATA().VALUE('(/EVENT_INSTANCE/OBJECTTYPE)[1]', 'VARCHAR(50)')
IF @OBJ_NAME = 'TEACHER' 
BEGIN
       PRINT 'рхо янашрхъ: '+@EVENT_TYPE;
       PRINT 'хлъ назейрю: '+@OBJ_NAME;
       PRINT 'рхо назейрю: '+@OBJ_TYPE;
       RAISERROR( N'ноепюжхх я рюакхжеи рнбюпш гюопеыемш', 16, 1);  
ROLLBACK  
END

ALTER TABLE TEACHER DROP COLUMN TEACHER_NAME

SELECT * FROM TEACHER

DROP TRIGGER TR_TEACHER_DDL
DROP TABLE TR_AUDIT