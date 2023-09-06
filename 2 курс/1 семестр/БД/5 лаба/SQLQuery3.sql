use UNIVER
/*3. Переписать запрос, реализующий 1 пункт без использования подзапроса.
Примечание: использовать соединение INNER JOIN трех таблиц. */
	   select  distinct PULPIT_NAME from PULPIT
	 join FACULTY 
               on PULPIT.FACULTY = FACULTY.FACULTY
			 join PROFESSION 
			   on   FACULTY.FACULTY  = PROFESSION.FACULTY 
		where PROFESSION_NAME LIKE '%технологи%'
								
                         
--------------------------------------------------
use BANK;
select БАНК.Назаание_кредита ,Оформление.сумма from БАНК 
join Оформление on БАНК.id = Оформление.id
where сумма = 1000

