/*5. Изменить (ALTER TABLE) таблицу STU-DENT в базе данных UNIVER таким образом, чтобы значения типизированного столбца с именем INFO контролировались коллекцией XML-схем (XML SCHEMACOLLECTION), представленной в правой части. 
Разработать сценарии, демонстрирующие ввод и корректировку данных (операторы IN-SERT и UPDATE) в столбец INFO таблицы STUDENT, как содержащие ошибки, так и правильные.
Разработать другую XML-схему и добавить ее в коллекцию XML-схем в БД UNIVER.
*/

--------------------------------------
---------------UNIVER-----------------
--------------------------------------
USE UNIVER
GO
CREATE XML SCHEMA COLLECTION STUDENT AS 
N'<?XML VERSION="1.0" ENCODING="UTF-16" ?>
<XS:SCHEMA ATTRIBUTEFORMDEFAULT="UNQUALIFIED" 
   ELEMENTFORMDEFAULT="QUALIFIED"
   XMLNS:XS="HTTP://WWW.W3.ORG/2001/XMLSCHEMA">
<XS:ELEMENT NAME="СТУДЕНТ">
<XS:COMPLEXTYPE><XS:SEQUENCE>
<XS:ELEMENT NAME="ПАСПОРТ" MAXOCCURS="1" MINOCCURS="1">
  <XS:COMPLEXTYPE>
    <XS:ATTRIBUTE NAME="СЕРИЯ" TYPE="XS:STRING" USE="REQUIRED" />
    <XS:ATTRIBUTE NAME="НОМЕР" TYPE="XS:UNSIGNEDINT" USE="REQUIRED"/>
    <XS:ATTRIBUTE NAME="ДАТА"  USE="REQUIRED">
	<XS:SIMPLETYPE>  <XS:RESTRICTION BASE ="XS:STRING">
		<XS:PATTERN VALUE="[0-9]{2}.[0-9]{2}.[0-9]{4}"/>
	 </XS:RESTRICTION> 	</XS:SIMPLETYPE>
     </XS:ATTRIBUTE>
  </XS:COMPLEXTYPE>
</XS:ELEMENT>
<XS:ELEMENT MAXOCCURS="10" NAME="ТЕЛЕФОН" TYPE="XS:STRING"/>
<XS:ELEMENT NAME="АДРЕС">   <XS:COMPLEXTYPE><XS:SEQUENCE>
   <XS:ELEMENT NAME="СТРАНА" TYPE="XS:STRING" />
   <XS:ELEMENT NAME="ГОРОД" TYPE="XS:STRING" />
   <XS:ELEMENT NAME="УЛИЦА" TYPE="XS:STRING" />
   <XS:ELEMENT NAME="ДОМ" TYPE="XS:STRING" />
   <XS:ELEMENT NAME="КВАРТИРА" TYPE="XS:STRING" />
</XS:SEQUENCE></XS:COMPLEXTYPE>  </XS:ELEMENT>
</XS:SEQUENCE></XS:COMPLEXTYPE>
</XS:ELEMENT></XS:SCHEMA>';


--DROP XML SCHEMA COLLECTION STUDENT;

SELECT NAME, INFO FROM STUDENT WHERE NAME='КОРЕНЧУК А.В.';
GO
ALTER TABLE STUDENT ALTER COLUMN INFO XML;
GO
SELECT NAME, INFO FROM STUDENT;


--------------------------------------
-----------------BANK-----------------
--------------------------------------