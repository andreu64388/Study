USE master


USE Salary
CREATE TABLE Зарплата
(  [ФИО] nvarchar(50)  NOT NULL DEFAULT ('---'), 
   [Должность] nvarchar(50) NOT NULL DEFAULT ('---'), 
   [Стаж, лет] int NOT NULL DEFAULT ((0)), 
   [Оклад, руб] float NOT NULL DEFAULT ((0)), 
   [Премия, руб] float NOT NULL DEFAULT ((0)), 
   [Надбавка за стаж, руб] float NOT NULL DEFAULT ((0)), 
   [Итого, руб] float NOT NULL DEFAULT ((0)), 
   [Налоги, руб] float NOT NULL DEFAULT ((0)), 
   [Получить, руб] float NOT NULL DEFAULT ((0)) 
) 

INSERT into Зарплата (ФИО, Должность, [Стаж, лет], [Оклад, руб], [Премия, руб])
  Values('Афанасьева А.И.', 'Генеральный директор', 16, 3000, 105),
	      ('Дудин Е.А.', 'Директор отдела маркетинга', 9, 2180, 300),
	      ('Ковалев Д.М.', 'HR-менеджер', 5, 1200, 100),
	      ('Кежар В.П.', 'Инспектор по кадрам', 20, 2500, 200),
	      ('Ивицкая Н.И.', 'Главный бухгалтер', 12, 1700, 655)

