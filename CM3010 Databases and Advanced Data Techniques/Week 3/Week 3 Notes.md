# Relational Database
A relational database implements the relational model.

A **model** is a way of abstracting complex real-world data into structures we can understand, talk about, manipulate and represent.

A **relation** is the definition of a table and the values stored in it as well as the rules on manipulating the rules.

**Relational** refers to tables and the relation tables have between each other.

## Relational Databases - some rules
Everything is a relation:
* All operations use the relational model
* All data is represented and accessed as relations
* Table and database structure is accessed and altered as relations

The system is unaffected by its implementation:
* If the hardware changes
* If the operating system changes
* If the disks are replaced
* If data is distributed

## Relational model ≠ Entity-relationship model

An ER model helps model concepts, often as part of relational database design

## Relational model ≠ SQL ≠ Most RDBMS implementations

# Drawing a database
**Entity**

It's a thing we want to model and can be uniquely identified.

**Attribute**

Information that describes an aspect of an entity.

**Relationship**

A connection or dependency between two entities.

## Entity-Relationship Diagrams

__Entities__ are drawn in a box (quadrilateral).

__Attributes__ are drawn inside an ellipse.

__Relationships__ are drawn in a rhombus.

# Speaking to databases
## Basic SQL
```SQL
SELECT
INSERT
UPDATE
DELETE
```
`SELECT PlanetName FROM Planets`
SELECT keyword introduces/starts a query
After the SELECT we specify the columns we want in the result (table).
The FROM keyword tells us where to look.

```SQL
SELECT PlanetName FROM Planets WHERE DayLength > 200;
```
Here the constraint for the field DayLength is 200. We'll see the PlanetName only for the rows which comply with the constraint.

```SQL
CREATE TABLE Planets (
    PlanetName CHAR(8),
    DayLength INT,
    YearLength INT,
    PRIMARY KEY (PlanetName)
);
```
We use this to create a table with 3 field, one with character values up to 8 in length and two fields with integer values

In the relational model, every row has to be unique, this is done via the primary key in SQL.

