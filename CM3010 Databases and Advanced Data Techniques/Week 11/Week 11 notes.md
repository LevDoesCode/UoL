# Distributed databases and alternative database models

The gains from generic structures in a relational database work against the losses from having generic structures in an unreliable database.

## Distributing data
The user should not be aware the database is distributed

## Why distribute?
* Parallelize operations
* No single point of failure
* Divide large dataset
* Data already partitioned (different departments in the company)

## Approaches to distributing RDBMS
### Local autonomy
* Sites operate independently
* One site cannot interfere with another
* No site should relay on another for its operation

### No centralization
* No single site conrols transactions
* No single site failure breaks the system

### Continuous operation
* The system is available most of the time
* The system is reliable - it fails rearely and recovers quickly (and gracefully)

### Location independence
* User need not know where any data might be located
* Data may be moved without changing functionality

### Particion independence
* User need not know how the data is partitioned
* Data may be repartitioned without changing functionality

Note: Optimization can still benefit from Partition structure

### Distributed queries
* Execute queries close to the data

### X independence
* Distribution making no difference to the user means:
  * Hardware independence
  * OS independence
  * Network independence

### DBMS independence
* Distribution over different DBMS implementations

## Concepts
### Partitioning
* How will you divide your data?
* We divide the data as well as the processing
* Also called fragmentation
* Vertical partitioning
  * Divide table by columns
  * Normalization is a type of partitioning
* Horizontal partitioning
  * Divide the table by rows

### Catalog Management
Relations are not just the column but the definition of the table.
* How is information about the data distributed?
* It should be distributed in a manner that maintains integrity and consistency of the DB

### Recovery control
* Transaction usually use 'two-phase protocol'
* This required one site to act as a co-ordinator in any give transaction

### Brewer's Conjecture
Three goals (CAP) in tension:
* Consistency: All parts of the database should converge on a consistent state
* Availability: Every request should result in a response (eventually)
* Partition tolerance: If a network flaw breaks the network into separate subnets, the database should run and recover

## Key/Value databases and MapReduce
> If distributing databases is complex, simplify your data structures.

### Key-value
* Associative array/dictionary
* No explicit connection between entries
* Processing either
  * Retrieval by key
  * Exhaustive exploration
* Easy parallel processing
* Easy partition
* Partition is always horizontal
* Processing should happen near the data where possible

### MapReduce
'MapReduce' is an example, of key-value processing.

This is based on the observation that the query has two stages:
* Gathering and processing information form base tables
* Processing and summarizing the result

```SQL
SELECT Actor1, COUNT(Title) --- Map phase
FROM    MovieLocations -- Reduce phase
        INNER JOIN Actors
        ON Actor1=Name
WHERE   DataOfBirth > "1950-01-01"
GROUP BY Actor1; --- Map phase
```

### Map phase
* Carried out with direct access to the data
* Peration usually loops over all data
* Output is a new key-value set

### Reduce phase
It doesn't need to happen close to the data
* Carried out by reducer workers
* Summarize data based on key
* Because we know that the data is based on the key, we can assign the data to workers based on key
* Output is collated and setn to the users

### Why use MapReduce?
* Simple
* Easy for distributed data
* Easy for distributed processing
* Move the data you need, not the data  you have
* Can recover form failure of all but co-ordinating node easily
* 