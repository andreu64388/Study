

/*3. Написать два SELECT-запроса, форми-рующих результирующие наборы аналогич-ные запросам из заданий 1 и 2, но без приме-нения INNER JOIN. */
use UNIVER;

select AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
from AUDITORIUM_TYPE,
     AUDITORIUM
where AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE;

select T2.AUDITORIUM, T1.AUDITORIUM_TYPENAME
from AUDITORIUM_TYPE As T1,
     AUDITORIUM As T2
where T1.AUDITORIUM_TYPE = T2.AUDITORIUM_TYPE
  And T1.AUDITORIUM_TYPENAME Like '%компьютер%';

---------------------------------------------------
use BANK;
select БАНК.Назаание_кредита ,Оформление.сумма from БАНК , Оформление
where БАНК.id = Оформление.id
and  БАНК.Назаание_кредита  Like '%'
