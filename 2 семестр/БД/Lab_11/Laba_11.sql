---------------- Task 1 ----------------
declare 
  faculty_rec faculty%rowtype;
begin 
  select * into faculty_rec from faculty where faculty = 'TOV';
  dbms_output.put_line(faculty_rec.faculty ||' '||faculty_rec.faculty_name);
end;

---------------- Task 2 ----------------
declare 
faculty_result faculty%rowtype;
begin
select * into faculty_result from faculty;
dbms_output.put_line(faculty_result.faculty || ' ' || faculty_result.faculty_name);
exception
when others 
then dbms_output.put_line(sqlcode||' '||sqlerrm);

end;

---------------- Task 3 ----------------
declare
    faculty_rec faculty%rowtype;
begin
    select * into faculty_rec from faculty;
    dbms_output.put_line(faculty_rec.faculty || '  ' || faculty_rec.faculty_name);
exception
    when too_many_rows
    then dbms_output.put_line('caught: ' || sqlcode || ' ' || sqlerrm );
end;



---------------- Task 4 ----------------
declare
    faculty_rec faculty%rowtype;
begin
    select * into faculty_rec from faculty where faculty='MIR';
   dbms_output.put_line(faculty_rec.faculty || '  ' || faculty_rec.faculty_name);
exception
    when no_data_found 
    then dbms_output.put_line('caught: ' || sqlcode || ' ' || sqlerrm );
end;

---------------- Task 5 ----------------

BEGIN
  INSERT INTO faculty (faculty, faculty_name)
  VALUES ('IDiP', 'Duplicate faculty');
EXCEPTION
  WHEN DUP_VAL_ON_INDEX THEN
    DBMS_OUTPUT.PUT_LINE('Error: Duplicate value');
END;

BEGIN
  DELETE FROM faculty WHERE faculty = 'LHF';
EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('Error: ' || SQLCODE || ' ' || SQLERRM);
END;


---------------- Task 6 ----------------

declare 
cursor cur is SELECT * from teacher;
c_teacher  teacher.teacher%type;
c_teacher_name teacher.teacher_name%type;
c_pulpit teacher.pulpit%type;
begin

open cur;
loop
fetch cur into c_teacher,c_teacher_name,c_pulpit;
exit when cur%notfound;
dbms_output.put_line(cur%rowcount ||' '|| c_teacher || ' ' || c_teacher_name || ' ' || c_pulpit );
end loop;
close cur;
end;

---------------- Task 7 ----------------

declare 
    cursor curs_subject is select* from subject;
    rec_subject subject%rowtype;
begin
    open curs_subject;
    dbms_output.put_line('rowcount = ' || curs_subject%rowcount);
    fetch curs_subject into rec_subject;
    while curs_subject%found
    loop
    dbms_output.put_line(' ' || curs_subject%rowcount || ' ' || rec_subject.subject || ' ' ||
                        rec_subject.subject_name || ' ' || rec_subject.pulpit);
    fetch curs_subject into rec_subject;
    end loop;
    dbms_output.put_line('rowcount = ' || curs_subject%rowcount);
    close curs_subject;
exception
      when others
        then dbms_output.put_line(sqlcode||' '||sqlerrm);   
end;
---------------- Task 8 ----------------

declare 
    cursor curs (capacity auditorium.auditorium_capacity%type, capacity1 auditorium.auditorium_capacity%type)
        is select auditorium, auditorium_capacity, auditorium_type
        from auditorium
        where auditorium_capacity >= capacity and auditorium_capacity <= capacity1;
    --aum curs%rowtype;
begin
    dbms_output.put_line('capacity < 20 :');
    for aum in curs(0,20)
    loop dbms_output.put_line(aum.auditorium||' '); 
    end loop;
     
    dbms_output.put_line('21 < capacity < 30 :');
    for aum in curs(21,30)
    loop dbms_output.put_line(aum.auditorium||' '); 
    end loop;
     
    dbms_output.put_line('31 < capacity < 60 :');
    for aum in curs(31,60)
    loop dbms_output.put_line(aum.auditorium||' '); 
    end loop;
     
    dbms_output.put_line('61 < capacity < 80 :');
    for aum in curs(61,80)
    loop dbms_output.put_line(aum.auditorium||' '); 
    end loop;
     
    dbms_output.put_line('81 < capacity:');
    for aum in curs(81,1000)
    loop dbms_output.put_line(aum.auditorium||' '); 
    end loop;
exception
      when others
        then dbms_output.put_line(sqlcode||' '||sqlerrm);
end;

---------------- Task 9 ----------------


declare
    type t_faculty is ref cursor;
    cur_faculty t_faculty;
    d_faculty faculty.faculty%type;
begin
    open cur_faculty for select faculty from faculty;
    loop
        fetch cur_faculty into d_faculty;
        exit when cur_faculty%notfound;
        dbms_output.put_line(d_faculty);
    end loop;
    close cur_faculty;
end;

---------------- Task 10 ----------------

declare 
  cursor curs_auditorium(capacity auditorium.auditorium%type, capac auditorium.auditorium%type)
    is select auditorium, auditorium_capacity
      from auditorium
      where auditorium_capacity >=capacity and AUDITORIUM_CAPACITY <= capac for update;
  aum auditorium.auditorium%type;
  cty auditorium.auditorium_capacity%type;
begin
  open curs_auditorium(40,80);
  fetch curs_auditorium into aum, cty;
  while(curs_auditorium%found)
    loop
      cty := cty * 0.9;
      update auditorium
      set auditorium_capacity = cty
      where current of curs_auditorium;
      dbms_output.put_line(' '||aum||' '||cty);
      fetch curs_auditorium into aum, cty;
    end loop;
  close curs_auditorium;
  rollback;
  exception
  when others
    then dbms_output.put_line(sqlerrm);
end;