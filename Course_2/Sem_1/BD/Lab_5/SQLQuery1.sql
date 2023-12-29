
/*1. На основе таблиц FACULTY, PUL-PIT и PROFESSION сформировать спи-сок
и выполняется для каждой строки результирующего набора
наименований кафедр (столбец PUL-PIT_NAME), которые находятся на фа-культете 
(таблица FACULTY), обеспечи-вающем подготовку по специальности, в наименовании
(столбец PROFESSION_ NAME) которого содержится слово тех-нология или технологии.
Примечание: использовать в секции WHERE предикат IN c некоррелированным подзапросом
его выполнения подставляется в каждую строку результирующего набора. 
к таблице PROFESSION. */
use UNIVER;
select PULPIT_NAME from PULPIT, FACULTY 
where PULPIT.FACULTY = FACULTY.FACULTY
  and FACULTY.FACULTY in (select PROFESSION.FACULTY
                         from PROFESSION
                         where PROFESSION_NAME LIKE ('%технология%')
                            or PROFESSION_NAME LIKE ('%технологии%'))

		

--------------------------------------------------
use BANK;
select БАНК.Назаание_кредита ,Оформление.сумма from БАНК ,Оформление
where БАНК.id = Оформление.id
and БАНК.id = (select id from Оформление 
where сумма = 1000
)


