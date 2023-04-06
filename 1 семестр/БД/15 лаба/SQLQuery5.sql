/*5. �������� (ALTER TABLE) ������� STU-DENT � ���� ������ UNIVER ����� �������, ����� �������� ��������������� ������� � ������ INFO ���������������� ���������� XML-���� (XML SCHEMACOLLECTION), �������������� � ������ �����. 
����������� ��������, ��������������� ���� � ������������� ������ (��������� IN-SERT � UPDATE) � ������� INFO ������� STUDENT, ��� ���������� ������, ��� � ����������.
����������� ������ XML-����� � �������� �� � ��������� XML-���� � �� UNIVER.
*/

--------------------------------------
---------------UNIVER-----------------
--------------------------------------
USE UNIVER
GO
create xml schema collection Student as
N'<?xml version="1.0" encoding="utf-16" ?>
<xs:schema attributeFormDefault="unqualified"
   elementFormDefault="qualified"
   xmlns:xs="http://www.w3.org/2001/XMLSchema">
<xs:element name="�������">
<xs:complexType><xs:sequence>
<xs:element name="�������" maxOccurs="1" minOccurs="1">
  <xs:complexType>
    <xs:attribute name="�����" type="xs:string" use="required" />
    <xs:attribute name="�����" type="xs:unsignedLong" use="required"/>
    <xs:attribute name="����"  use="required">
	<xs:simpleType>  <xs:restriction base ="xs:string">
		<xs:pattern value="[0-9]{2}.[0-9]{2}.[0-9]{4}"/>
	 </xs:restriction> 	</xs:simpleType>
     </xs:attribute>
  </xs:complexType>
</xs:element>
<xs:element maxOccurs="3" name="�������" type="xs:unsignedLong"/>
<xs:element name="�����">   <xs:complexType><xs:sequence>
   <xs:element name="������" type="xs:string" />
   <xs:element name="�����" type="xs:string" />
   <xs:element name="�����" type="xs:string" />
   <xs:element name="���" type="xs:string" />
   <xs:element name="��������" type="xs:string" />
</xs:sequence></xs:complexType>  </xs:element>
</xs:sequence></xs:complexType>
</xs:element></xs:schema>';


--DROP XML SCHEMA COLLECTION STUDENT;

SELECT NAME, INFO FROM STUDENT WHERE NAME='�������� �.�.';
GO
ALTER TABLE STUDENT ALTER COLUMN INFO XML;
GO
SELECT NAME, INFO FROM STUDENT;


--------------------------------------
-----------------BANK-----------------
--------------------------------------