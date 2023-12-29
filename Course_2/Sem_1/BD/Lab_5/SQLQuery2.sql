
/*	2. Переписать запрос пункта 1 таким образом, чтобы тот же подзапрос
                            был за-писан в конструкции INNER JOIN секции FROM внешнего запроса. 
                            При этом ре-зультат выполнения запроса должен быть аналогичным результату 
                            исходного запро-са. */
							use UNIVER;
select PULPIT.PULPIT_NAME from PULPIT
join FACULTY on  PULPIT.FACULTY = FACULTY.FACULTY
  and FACULTY.FACULTY in (select PROFESSION.FACULTY
                        from PROFESSION
                         where PROFESSION_NAME LIKE ('%технология%')
                            or PROFESSION_NAME LIKE ('%технологии%'))



--------------------------------------------------------------

use BANK;
select БАНК.Назаание_кредита ,Оформление.сумма from БАНК 
join Оформление on БАНК.id = Оформление.id
where БАНК.id = (select id from Оформление 
where сумма = 1000
)
