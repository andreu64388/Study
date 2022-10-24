use UNIVER;
/*8. Разработать SELECT-запрос, демон-стрирующий принцип применения 
ANY совместно с подзапросом.*/
use UNIVER
select SUBJECT, NOTE, IDSTUDENT from PROGRESS
	where NOTE =any (select NOTE from PROGRESS
		where IDSTUDENT=1019 and SUBJECT='Кг')

/*-Вывести Предмет, айди студента , который получил по этому предмету такую же отметку,как студент 1019 получил за КГ -*/

-----------------------------------
use BANK;

select Назаание_кредита ,Ставка from БАНК a
where Ставка =any (select Ставка from БАНК
where Ставка = a.Ставка) 
