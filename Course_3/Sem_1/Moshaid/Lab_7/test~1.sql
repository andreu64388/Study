create user lab_5 identified by Admin1234; --������� ������������ lab_5 � ������� Admin1
alter session set "_oracle_script"=true
--����� ������ �����       
grant create session to lab_5; --�������� ������ (����� ����� ��������������� � ��)
grant unlimited tablespace to lab_5; --�������� ������ � ����������� ��������� ������������
grant create table to lab_5; --�������� ������
grant create any index to lab_5; --�������� ��������
grant create tablespace to lab_5; --�������� ��������� �����������
grant create any sequence to lab_5; --�������� �������������������
grant create user to lab_5; --�������� ����� �������������
GRANT CREATE TRIGGER TO lab_5;
GRANT CREATE VIEW TO lab_5;
grant drop user to lab_5; --�������� ������������ �������������
grant insert any table to lab_5; --���������� ������ � �������
grant update any table to lab_5; --��������� ������ � ��������
grant delete any table to lab_5; --�������� ������ � ��������
grant select on dba_source to lab_5; --�������� ������� ���� �������� 
grant select on dba_objects to lab_5; --�������� ������� ����������� �������� � ��
grant select on dba_indexes to lab_5; --�������� ������� ������������ �������� ��