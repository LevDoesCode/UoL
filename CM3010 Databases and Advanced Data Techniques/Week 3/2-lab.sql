CREATE DATABASE Astronomy;
USE Astronomy;
CREATE TABLE Planets ( 
    PlanetName VARCHAR(50),
    DayLength INT,
    YearLength INT,
    PRIMARY KEY (PlanetName)
);

INSERT INTO planets VALUES ('Mercury', 4223, 88);
INSERT INTO planets VALUES ('Venus', 2802, 225);
INSERT INTO planets VALUES ('Earth', 24, 365);
INSERT INTO planets VALUES ('Mars', 25, 687);
INSERT INTO planets VALUES ('Jupiter', 10, 4331);
INSERT INTO planets VALUES ('Saturn', 11, 10747);
INSERT INTO planets VALUES ('Uranus', 17, 30589);
INSERT INTO planets VALUES ('Neptune', 16, 59800);

SELECT PlanetName FROM planets WHERE DayLength > 24;


CREATE TABLE Moons (
	MoonName VARCHAR(50),
	PlanetName VARCHAR(50),
    HasLiquidWater BOOL,
    PRIMARY KEY (MoonName, PlanetName)
);

INSERT INTO moons VALUES ('Moon', 'Earth', FALSE);
INSERT INTO moons VALUES ('Phobos', 'Mars', FALSE);
INSERT INTO moons VALUES ('Europa', 'Jupiter', TRUE);
INSERT INTO moons VALUES ('Titan', 'Saturn', FALSE);
INSERT INTO moons VALUES ('Enceladus', 'Saturn', TRUE);
INSERT INTO moons VALUES ('Oberon', 'Uranus', FALSE);

SELECT MoonName FROM Moons, Planets WHERE Moons.PlanetName=Planets.PlanetName AND HasLiquidWater = TRUE AND DayLength < 11;