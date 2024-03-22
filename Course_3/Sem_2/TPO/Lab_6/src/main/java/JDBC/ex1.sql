create database DictionaryDatabase;

create table DictionaryDatabase.dictionary (
	word varchar(50),
	translate varchar(50)
);
INSERT INTO DictionaryDatabase.dictionary (word, translate) VALUES ('apple', 'яблоко');

-- Вставка нескольких записей в одном запросе
INSERT INTO DictionaryDatabase.dictionary (word, translate) VALUES
    ('car', 'машина'),
    ('book', 'книга'),
    ('table', 'стол'),
	('стол', 'table');
    
select * from DictionaryDatabase.dictionary;