# Document databases and MongoDB
This is a middleground between key-value DB's and RDB's.

* Documents structres:
  * less strict
  * nested
  * repeated
  * order-sensitive

* Less interlinking - When we treat the documents as a database, any link between documents is not relevant for retrieval, at first.
* ... or linking less importan for retrieval.

### Document formats
* Markup languages for text
* Markup languages for other data
* Bespoke formats
* JSON (JavaScript Object Notation)

### JSON differences
* Simple expresison of standar data structures
* Useful for:
  * Data persistence (serialization)
  * Data exchange

* Very similar to JavaScript:
* Data types are similar (number, string, decimal)
* We can't name variables and reuse them
* In JSON, keys require quotes, in JS it's optional
* No named structure/cross reference
* Object keys take quotes in JSON

## MongoDB
* Document-oriented model
* Distributed (by sharding, horizontal partitions)
* Open-ish Source... (copyleft)
* Operates on objects
  e.g.
  ```JS
  movieData = [{title: "Ant-Man", year: 2015, actors: ["John", "Bob"]},
  {title: "..."}]
  ```
  It's not a prescribed structure, but it's ok with MongoDB

### MongoDB: INSERT
`db.movies.insert(movieData)`

### MongoDB: SELECT
`db.movies.find({year: 2015});`

`db.movies.find({title: /*Man/});`

`db.movies.find({title: /*Man/, year:{$lt: 2010}});` less than 2010

### MongoDB UPDATE
`db.movies.update(
    {title: "Ant-Man"}, <- find
    {$set: {year: 2015}} <- update
);`

Or update many entries

`db.movies.updateMany(
    {actors: "Elvis Presley"},
    {"actors.$": "Elvos Proslee"}
);`

Add an actor:

`db.movies.update(
    {title: "Ant-Man"},
    {$push: {actors: "Michael John"}}
);`

### MongoDB
* Fairly SQL-like
* Reduces joins in treelike data
* Integrates well into code
* Has suffered security and reliability issues
