------------------- Task 1 -------------------

begin
  null;
end;

------------------- Task 2 -------------------
begin
  dbms_output.put_line('Hello world');
end;

------------------- Task 3 -------------------

select keyword from v$reserved_words where length = 1 and keyword != 'A';

------------------- Task 4 -------------------
select keyword from v$reserved_words where length > 1 and keyword!='A' order by keyword;

------------------- Task 5 -------------------
DECLARE 
num1 INTEGER(4);
num2 INTEGER(10):=10;
num3 INTEGER(3,2):=1.333;
num4 INTEGER(5,-2):=10000;
num5_float binary_float:=.10f;
num6_double binary_double:= .10d;
num7_degree number(10,15):=12E-10;
bool_var boolean :=true;

BEGIN 
DBMS_OUTPUT.PUT_LINE('num1: ' || num1);
DBMS_OUTPUT.PUT_LINE('num2: ' || num2);
DBMS_OUTPUT.PUT_LINE('num3: ' || num3);
DBMS_OUTPUT.PUT_LINE('num4: ' || num4);
DBMS_OUTPUT.PUT_LINE('num5_float: ' || num5_float);
DBMS_OUTPUT.PUT_LINE('num6_double: ' || num6_double);
DBMS_OUTPUT.PUT_LINE('num7_degree: ' || num7_degree);
IF BOOL_VAR THEN
DBMS_OUTPUT.PUT_LINE('BOOL IS TRUE');
ELSE
DBMS_OUTPUT.PUT_LINE('BOOL IS FALSE');
END IF;
END;

------------------- Task 6 -------------------

DECLARE 
V_CONST_VAR CONSTANT VARCHAR2(10):='Andrey';
V_CONST_NUM CONSTANT NUMBER(2):=2;
V_CONST_CHAR CONSTANT CHAR(3):='MIR';
BEGIN
   dbms_output.put_line('Constant V_CONST_VAR = '|| V_CONST_VAR);
   dbms_output.put_line('Constant V_CONST_VAR || V_CONST_VAR = '||(V_CONST_VAR || V_CONST_VAR)); 
   dbms_output.put_line('Constant V_CONST_NUM = '|| V_CONST_NUM);
   dbms_output.put_line('Constant V_CONST_CHAR = '|| V_CONST_CHAR);

END;
------------------- Task 7 -------------------

DECLARE
    example  AUDITORIUM%ROWTYPE;
    example2 AUDITORIUM.AUDITORIUM_CAPACITY%TYPE;

BEGIN
    example2 := 100;
    SELECT * INTO example FROM AUDITORIUM WHERE AUDITORIUM_NAME = '429-4'; 
    DBMS_OUTPUT.PUT_LINE('AUDIT NAME: ' || example.AUDITORIUM_NAME || ' AUDIT CAPACITY '
        || example2);
END;



------------------- Task 9 -------------------
DECLARE 
    v_num1 NUMBER := 10;
    v_num2 NUMBER := 20;
    v_str1 VARCHAR2(10) := 'abc';
    v_str2 VARCHAR2(10) := 'xyz';
    v_bool BOOLEAN := TRUE;
BEGIN
    IF v_num1 > v_num2 THEN
        dbms_output.put_line('v_num1 is greater than v_num2');
    ELSE
        dbms_output.put_line('v_num1 is less than or equal to v_num2');
    END IF;

    IF v_num1 > v_num2 THEN
        dbms_output.put_line('v_num1 is greater than v_num2');
    ELSIF v_num1 = v_num2 THEN
        dbms_output.put_line('v_num1 is equal to v_num2');
    ELSE
        dbms_output.put_line('v_num1 is less than v_num2');
    END IF;



    IF v_num1 = 10 AND v_str1 = 'abc' THEN
        dbms_output.put_line('v_num1 is 10 AND v_str1 is abc');
    ELSE
        dbms_output.put_line('v_num1 is not 10 OR v_str1 is not abc');
    END IF;

    IF v_num1 = 10 OR v_str1 = 'xyz' THEN
        dbms_output.put_line('v_num1 is 10 OR v_str1 is xyz');
    ELSE
        dbms_output.put_line('v_num1 is not 10 AND v_str1 is not xyz');
    END IF;
END;




------------------- Task 10 -------------------
DECLARE
  v_day VARCHAR2(10) := 'Sunday';
BEGIN
  CASE v_day
    WHEN 'Monday' THEN
      dbms_output.put_line('It is Monday');
    WHEN 'Tuesday' THEN
      dbms_output.put_line('It is Tuesday');
    WHEN 'Wednesday' THEN
      dbms_output.put_line('It is Wednesday');
    WHEN 'Thursday' THEN
      dbms_output.put_line('It is Thursday');
    WHEN 'Friday' THEN
      dbms_output.put_line('It is Friday');
    WHEN 'Saturday' THEN
      dbms_output.put_line('It is Saturday');
    WHEN 'Sunday' THEN
      dbms_output.put_line('It is Sunday');
    ELSE
      dbms_output.put_line('Invalid day');
  END CASE;
END;






------------------- Task 11 -------------------
DECLARE
   i NUMBER := 1;
BEGIN
   LOOP
      EXIT WHEN i > 10;
      dbms_output.put_line('i = ' || i);
      i := i + 1;
   END LOOP;
END;

------------------- Task 12 -------------------â
DECLARE
   i NUMBER := 1;
BEGIN
   WHILE i <= 10 LOOP
      dbms_output.put_line(i);
      i := i + 1;
   END LOOP;
END;

------------------- Task 13 -------------------
DECLARE
   j NUMBER;
BEGIN
   FOR j IN 1..10 LOOP
      dbms_output.put_line(j);
   END LOOP;
END;
