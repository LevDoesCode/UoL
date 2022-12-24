# Using Relational Databases

**SELECT FROM WHERE**
```SQL
SELECT *
FROM Planets
WHERE diameter > 5;
```

**Aproximate matching**

```SQL
SELECT *
FROM Planets
WHERE name LIKE '%er';
```
where '%er' is a wildcard, it's case insensite, it could be '%ER'

**UPDATE**

```SQL
UPDATE *
SET name = 'Mars'
WHERE anem = 'Mers';
```

**INSERT**

```SQL
INSERT INTO Planets (name, diameter)
VALUES
    ('Gethen', 9483),
    ('Athshe', 8210)
```
```SQL
INSERT INTO Planets (name)
SELECT DISTINCT name
    FROM Moons;
```
Here we have a subquery and we insert the result of this query into the Planets table.

**DELETE**

```SQL
DELETE FROM Planets
WHERE diameter < 2500;
```

**DROP**
```SQL
DROP TABLE Planets;
```

**TRUNCATE**
```SQL
TRUNCATE TABLE Planets;
```
Removes all entries but leaves the structure.

**CREATE**
```SQL
CREATE DATABASE Planets;
CREATE TABLE Planets (
    PlanetName CHAR(8),
    dayLength INT,
    YearLength INT,
    PRIMARY KEY (PlanetName)
);
```

**ALTER**
```SQL
ALTER TABLE Planets
ADD COLUMN
    Diameter INT;
```

## Data exchange
```SQL
SELECT *
FROM Planets
INTO OUTPUTFILE 'Planets.txt';
```

```SQL
LOAD DATA INFILE 'Planets.txt'
    INTO TABLE Planets;
```

## Agregate functions

![Diagram](Files/Image1.png)
We identify who they are for and we group them together

![Diagram](Files/Image2.png)

![Diagram](Files/Image3.png)

We then summarize the information by adding up the price.

![Diagram](Files/Image4.png)

This translates to SQL as:

```SQL
SELECT *
    FROM Shopping
    WHERE
    BoughtFor = 'Mum';
```

```SQL
<SOMETHING>
    FROM Shopping
    GROUP BY BoughtFor;
```
```SQL
SELECT BoughtFor,
    SUM(Price)
    FROM Shopping
    GROUP BY BoughtFor;
```
This gives us the sum of groups

We also have
* SUM
* AVG
* STD (deviation)
* VARIANCE
* MAX (Also works on other data types such as dates, most recent)
* MIN (least recent or oldest)
* COUNT
* COUNT(DISTINCT)
* GROUP_CONCAT (for strings)

```SQL
SELECT Gender, COUNT(*) FROM Locations JOIN Actors ON Actor1 = ENName
GROUP BY Gender;
```
```SQL
SELECT Gender, COUNT(*) FROM Locations JOIN Actors ON Actor2 = ENName
GROUP BY Gender;
```
```SQL
SELECT Gender, COUNT(*) FROM Locations JOIN Actors ON Actor3 = ENName
GROUP BY Gender;
```
```SQL
SELECT Actor1, COUNT(*) AS Appearances FROM Locations GROUP BY Actor1 ORDER BY Appearances DESC LIMIT 20;
```
(ASC/DESC)

In the Lab
```SQL
LOAD DATA
    INFILE '/home/coder/project/SF_film_locations.csv'
    REPLACE
    INTO TABLE Locations
    FIELDS
        TERMINATED BY ','
        OPTIONALLY ENCLOSED BY '"'
        ESCAPED BY '"'
    IGNORE 1 ROWS;
```
```SQL
LOAD DATA
    INFILE '/home/coder/project/wikidata-film-actors.csv'
    REPLACE
    INTO TABLE Locations
    FIELDS
        TERMINATED BY ','
        OPTIONALLY ENCLOSED BY '"'
        ESCAPED BY '"'
    IGNORE 1 ROWS;
```
```SQL
LOAD DATA
    INFILE '/home/coder/project/wikidata-film-composers.csv'
    REPLACE
    INTO TABLE Locations
    FIELDS
        TERMINATED BY ','
        OPTIONALLY ENCLOSED BY '"'
        ESCAPED BY '"'
    IGNORE 1 ROWS;
```

Age of Actor1
```SQL
SELECT DISTINCT Actor1, Year, DOB, FLOOR(DATEDIFF(MakeDate(Year, 1), DOB)/365) AS Age, Title AS Movie FROM Locations JOIN Actors ON Actor1 = ENName LIMIT 20;
```

Update the age of Charles Chaplin
``` SQL
UPDATE Actors SET DOB = '1889-04-16' WHERE ENName = 'Charles Chaplin';
```

## Database libraries
* Create a (persistent) connection
* Send commands
* Receive (and structure) response

## Create a (persistent) connection
`conn <- newCnnection(host, username, password, database)`
`conn.connect()`

Or both steps in one

`conn <- connect(host, username, password, database)`

## Sending commands
`resource <- conn.execute(query)`
`resource.fetchData()`

Or

`result <- conn.query(query)`

## Receive response
The result will usually be iterable.

Each row may be an object or an array.

## Using PHP SQL libraries

```PHP
$db = new mysqli(host, user, pwd, db);
```

```PHP
$result = $db->query("SELECT * FROM Planets");
```
Returns a mysqli_result object

We can iterate through this response
```PHP
foreach ($result as $moon) {
    echo $moon['radius'];
}
```
or treat it as a 2D array
```PHP
$moons = $result->fetch_all();
echo $moons[5][2];
```
or provide an option to use keys
```PHP
$moons = $result->fetch_all(MYSQL_ASSOC);
echo $moons[5]['radius'];
```
