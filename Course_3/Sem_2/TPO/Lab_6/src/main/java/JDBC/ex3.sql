CREATE DATABASE PoetryDatabase;
USE PoetryDatabase;

CREATE TABLE poems (
    id INT AUTO_INCREMENT PRIMARY KEY,
    author VARCHAR(255),
    year INT,
    poem BLOB
);

INSERT INTO poems (author, year, poem) VALUES ('Александр Пушкин', 1823, 'BLOB_DATA_FOR_POEM_1');
INSERT INTO poems (author, year, poem) VALUES ('Лермонтов', 1831, 'Сонет. BLOB_DATA_FOR_POEM_2. алвджалылавыдж!');
INSERT INTO poems (author, year, poem) VALUES ('Анна Ахматова', 1911, 'Сонет');

select * from PoetryDatabase.poems;