use UNIVER;

/*7. Разработать SELECT-запрос, демон-стрирующий принцип применения
ALL совместно с подзапросом.*/


select [SUBJECT], IDSTUDENT , NOTE from PROGRESS a
	where NOTE >=all (select NOTE from PROGRESS
		where [SUBJECT] = a.[SUBJECT] )



-----------------------------------
use BANK;

select Назаание_кредита ,Ставка from БАНК a
where Ставка >= all (select Ставка from БАНК
where Ставка = a.Ставка) 