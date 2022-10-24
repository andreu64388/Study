/*12*. Подсчитать количество студентов в каждой группе, на каждом факультете и всего в университете одним запросом.
  Подсчитать количество аудиторий по типам и суммарной вместимости в корпусах и всего одним запросом.*/

use UNIVER;


select  FACULTY.FACULTY, G.IDGROUP ,count(IDSTUDENT) as [Кол-во студентов]
from FACULTY full join GROUPS G on FACULTY.FACULTY = G.FACULTY
full join STUDENT S on G.IDGROUP = S.IDGROUP
group by rollup (FACULTY.FACULTY,G.IDGROUP)


select AUDITORIUM_TYPE.AUDITORIUM_TYPE , count(AUDITORIUM) as [Кол-во аудиторий],sum(AUDITORIUM_CAPACITY) as [Суммарная вместимость]
from AUDITORIUM_TYPE full join AUDITORIUM A on AUDITORIUM_TYPE.AUDITORIUM_TYPE = A.AUDITORIUM_TYPE
group by rollup (AUDITORIUM_TYPE.AUDITORIUM_TYPE)