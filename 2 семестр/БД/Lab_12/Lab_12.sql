--------------- Task 1 ---------------

select * from teacher;
alter table teacher add (birthday date, salary int);



update teacher set birthday = to_date('19.01.2000', 'DD.MM.YYYY'),
                    salary = 10
                    where pulpit like 'P%';

update teacher set birthday = to_date('10.01.1000', 'DD.MM.YYYY'),
                    salary = 100000
                    where pulpit like 'IS%';

update teacher set birthday = to_date('11.01.2001', 'DD.MM.YYYY'),
                    salary = 1
                    where pulpit like 'O%';
                    
update teacher set birthday = to_date('11.01.1993', 'DD.MM.YYYY'),
                    salary = 13
                    where pulpit like 'T%';

update teacher set birthday = to_date('11.12.1986', 'DD.MM.YYYY'),
                    salary = 17
                    where salary is null and birthday is null;
commit;


--------------- Task 2 ---------------
select 
 TEACHER
from 
  teacher
where 
  to_char(birthday, 'D') = '1';

--------------- Task 3 ---------------
CREATE OR REPLACE VIEW teachers_next_month_birthdays AS
SELECT 
  teacher_name, 
  TO_CHAR(birthday, 'DD/MM/YYYY') AS birthday 
FROM 
  teacher 
WHERE 
  TO_CHAR(birthday, 'MM') = TO_CHAR(ADD_MONTHS(SYSDATE, 1), 'MM');

SELECT * FROM teachers_next_month_birthdays;

--------------- Task 4 ---------------

CREATE OR REPLACE VIEW teachers_birthdays_per_month AS
SELECT 
  TO_CHAR(birthday, 'Month') AS month_name, 
  COUNT(*) AS num_teachers 
FROM 
  teacher 
GROUP BY 
  TO_CHAR(birthday, 'Month');
  
  
select * from teachers_birthdays_per_month


--------------- Task 5 ---------------

DECLARE
  CURSOR c_birthday_anniversary IS
    SELECT teacher_name, birthday
    FROM teacher
    WHERE birthday >= SYSDATE AND birthday < ADD_MONTHS(TRUNC(SYSDATE, 'YEAR'), 12) 
      AND ADD_MONTHS(birthday, 60) >= ADD_MONTHS(SYSDATE, 12) AND ADD_MONTHS(birthday, 60) < ADD_MONTHS(TRUNC(SYSDATE, 'YEAR'), 24); -- юбилеи в следующем году

  v_name teacher.teacher_name%TYPE;
  v_birthday teacher.birthday%TYPE;
  v_anniversary_age NUMBER;
BEGIN
  FOR c IN c_birthday_anniversary LOOP
    v_anniversary_age := EXTRACT(YEAR FROM ADD_MONTHS(c.birthday, 60)) - EXTRACT(YEAR FROM c.birthday);

  
    DBMS_OUTPUT.PUT_LINE(c.teacher_name || ' исполнится ' || TO_CHAR(v_anniversary_age) || ' лет на юбилее в ' || TO_CHAR(ADD_MONTHS(c.birthday, 60), 'YYYY-MM-DD'));
  END LOOP;
END;
--------------- Task 6 ---------------
declare
    cursor c_pulp is select pulpit, faculty from pulpit;
    cursor c_fac is select faculty from faculty;
    avgsal number(6);
begin
    dbms_output.put_line('pulpits:');
    for r_pulp in c_pulp
    loop
        select floor(avg(salary)) into avgsal from teacher where pulpit = r_pulp.pulpit;
        dbms_output.put_line(rpad(r_pulp.pulpit, 20) || ' ' || avgsal);
    end loop;
    
    dbms_output.put_line('faculties:');
    for r_fac in c_fac
    loop
        select floor(avg(salary)) into avgsal from teacher where pulpit in (select pulpit from pulpit where faculty = r_fac.faculty);
        dbms_output.put_line(rpad(r_fac.faculty, 20) || ' ' || avgsal);
    end loop;
    
    select floor(avg(salary)) into avgsal from teacher;
    dbms_output.put_line(rpad('all', 20) || avgsal);
end;



--------------- Task 7 ---------------
DECLARE
  v_dividend NUMBER := 10;
  v_divisor NUMBER := 0;
  v_result NUMBER;
BEGIN
    v_result := v_dividend / v_divisor;
    DBMS_OUTPUT.PUT_LINE('Result: ' || v_result);
  EXCEPTION
    WHEN ZERO_DIVIDE THEN
      DBMS_OUTPUT.PUT_LINE('Error: division by zero');
      v_result := NULL; 
  
END;

--------------- Task 8 ---------------
DECLARE
  v_teacher_name VARCHAR2(100);
  v_teacher NUMBER := 123; -- заданный код преподавателя
BEGIN
  SELECT teacher_name INTO v_teacher_name FROM teacher WHERE teacher= v_teacher;
  
  DBMS_OUTPUT.PUT_LINE('Преподаватель: ' || v_teacher_name);
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Преподаватель не найден!');
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Произошла ошибка: ' || SQLERRM);
END;
--------------- Task 9---------------
DECLARE
  ex_custom EXCEPTION;
BEGIN
  DBMS_OUTPUT.PUT_LINE('Main block start');
  
  DECLARE
    ex_nested EXCEPTION;
    PRAGMA EXCEPTION_INIT(ex_nested, -20001);
  BEGIN
    DBMS_OUTPUT.PUT_LINE('Nested block start');
    RAISE ex_nested;
    DBMS_OUTPUT.PUT_LINE('This line will not be executed');
  EXCEPTION
    WHEN ex_nested THEN
      DBMS_OUTPUT.PUT_LINE('Nested block exception handled');
  END;

  DBMS_OUTPUT.PUT_LINE('Main block end');
EXCEPTION
  WHEN ex_custom THEN
    DBMS_OUTPUT.PUT_LINE('Custom exception handled');
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Unhandled exception: ' || SQLERRM);
END;
--------------- Task 10 ---------------
DECLARE
  max_capacity NUMBER;
BEGIN
  SELECT MAX(auditorium_capacity) INTO max_capacity FROM AUDITORIUM;
  DBMS_OUTPUT.PUT_LINE('Max capacity: ' || max_capacity);
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('No data found');
END;

