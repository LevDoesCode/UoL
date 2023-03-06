# Advanced RDBMS topics

## Speeding things up
Using binary search on a sorted table:
* Average case - O(log n)
* Worst case - O(log n)

* As fast as tree indexes
* Use no extra space
* Can only sort in one order (column)

## Using indexes
Usually one of:
* B-tree
* Hash table

May also be spatial/geometric

May be held in memory, because it's much smaller than the table.

May optimize for disk structure

## B-trees (balanced trees)
* O(log n) in typical and worst case
* Supports ranges (because we know the limits)
* Support (some) approximate searching

## Hash tables
* O(1) in typical case
* Don't scale with the size of the data
* O(n) in (unusual) worst case
* Hash algorithm may be expensive
* Depending on the size of the dataset, B-trees may be fast enough even with worst O's
* No approximation
* No range-based retrieval - 
Things that are similar are placed in different places throughout the hash table (locality, sensitive hashing)

# Query efficiency
The order of the statements in the query is important. This is normally done automatically by the DBMS.

## Optimizing actions

Indexes and sorted tables can save on copying, searching and sorting.

Query strategy has a huge impact
* Order of operations
* Use of indexes
* Making fresh indexes
* Copying or reading data

How do we optimize? Let's see an example.

```SQL
SELECT *
FROM MOvieLocation,
     Actors
WHERE Actor1=Name;
```

We can use the keyword `EXPLAIN`:
```SQL
SELECT *
FROM MovieLocation,
     Actors
WHERE Actor1=Name;
```
Tells us which operations on which tables and on which order.
1. MovieLocations
   select_type: SIMPLE
   possible_keys: NULL (Actor Name is not the complete Key)
   rows: 1819
   filtered: 100 (100% of the data needs to be looked at)
2. Actors
   select_type: SIMPLE
   possible_keys: NULL
   rows: 39175
   filtered: 10
   Extra: Using where; Using hash join

About 50ms

Making a change, creating an index on the MovieLocations table. How does it change things?

```SQL
CREATE INDEX LocAct1
    ON  MovieLocations(Actor1);
```

Running EXPLAIN again:

1. Actors
   select_type: SIMPLE
   possible_keys: NULL
   rows: 39175
   filtered: 100
   Extra: Using where
2. MovieLocations
   select_type: SIMPLE
   possible_keys: LocAct1
   rows: 7
   filtered: 100
   Extra: NULL

About 60ms

It goes to the Actors table first and only 7 rows.

Let's add an index to the Actors table:
```SQL
CREATE INDEX ActorNames
    ON  Actors(Name);
```

Now runnign EXPLAIN
```SQL
EXPLAIN SELECT *
FROM  MovieLocations,
      Actors
WHERE Actor1=Name;
```
It reverts to the original order:
1. MovieLocations
   select_type: SIMPLE
   possible_keys: LocAct1
   rows: 1819
   filtered: 100
   Extra: Using where
2. Actors
   select_type: simple
   possible_keys: ActorNames
   rows: 1819
   filtered: 100
   Extra: NULL

About 5ms

There is also a `EXPLAIN ANALYZE` version of the command.

# Removing the safety net - Denormalization

What is normalizaiton bias?

Normalization:
* Can reduce disk reads
* Can reduce integrity checks
* Reduces storage use
* Increases use of joins

We can denormalize
Denormalization:
* Merge tables to reduce joins
* Effectively caches a joined SELECT
* Reduces use of joins
* Only sometimes faster

Example of denormalized table
```SQL
CREATE TABLE MovieActors
(PRIMARY KEY
    (Title, Year, Location))
AS
SELECT Title, Year, Location, Name,
        DoB, Gender
FROM MovieLocations
     LEFT JOIN
     Actors
     ON Actor1=Name
```
* Risky for very dynamic data. Duplicated data takes time and is risky.

For these issues, we can create a view:

Alternative cache:

```SQL
CREATE VIEW SFMoviesAndActors
AS
SELECT Title, Year, Location, Name, Dob, Gender
FROM MovieLocations
    LEFT JOIN
    Actors
    ON Actor1=Name;
```

The views are dynamic, making queries on the view also expensive

## Caching views
* SQL standard: SNAPSHOW
* aka Embovied or Materialized Views, are saved views.
* Can update when data changes
* We can treat the view as a table, add rows, etc. Set permissions to the view. When the parent table is update, it regenerates the view.
* Not implemented in MySQL

Denormalizing
* Databases are fast
* Keyed based joins are optimized
* Evaluate speed and efficiency before trying to optmize.

## Conclusions
Relations Databases are:
* powerful
* fast
* grounded in theory
* adaptable
* mature
* based on standards(often)
* best with tabular data
* initially confusing
