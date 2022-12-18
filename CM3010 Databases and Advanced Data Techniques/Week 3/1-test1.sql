SHOW DATABASES;
CREATE DATABASE degree;
USE degree
CREATE TABLE lecturers (
    Name VARCHAR(255),
    DateOfBirth DATE,
    DateJoined DATE,
    PRIMARY KEY (Name, DateOfBirth)
);

SHOW TABLES;
DESCRIBE lecturers;
INSERT INTO lecturers VALUES ('David Lewis', '1955-10-09', '1985-03-05');
SELECT Name FROM lecturers;
SELECT * FROM lecturers;
