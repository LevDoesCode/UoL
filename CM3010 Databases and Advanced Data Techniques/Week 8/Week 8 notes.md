# Read/write database applications
## Using libraries to update data in a database
### Updates
Any command can be sent through the connection, updates work like other queries.

We have to be aware of the security considerations.

And also keep track of new IDs.

### Making udpates
```JavaScript
const addActor = 
`
    INSERT INTO Actors
    VALUES
        ("Richard Gere", "Male",
        "Richard Gere",
        "1949"-08-31");
`;
```
Programmatically...

```JavaScript
const AddActor = `INSERT INTO Actors VALUES ("`
    + actor.name
    + '", "' + actor.gender
    + '", "' + actor.name
    + '", "' + actor.birthDate
    + '");';

connect.query(addActor);
```

### Security

SQL injection is possible for any user or HTTP-supplied data
* Remember Rober '; DROP TABLE Students;
* Control user privileges
* Escape user input
* Restrict possible operations

### Making secure updates
Instead of constructing the query string ourselves, we can use question marks as placeholders for values.
These values are automatically escaped before being inserted into a command, making it safer.

```JavaScript
const addActor = `
INSERT INTO Actors
VALUES
(?, ?, ?, ?));
`;
connect.query(addActor, [actor.name, actor.gender, actor.name, actor.birthdate]);
```

### Procedures
These exist on the database management side, rather than the library side.

```SQL
delimiter //
CREATE PROCEDURE addActor
    (IN name, gender, dob)
BEGIN
    INSERT INTO Actors
        VALUES (name, gender, name, dob);
END //
delimiter;
```

```JavaScript
connect.query(`CALL addActor("Richard Gere", "male", "1949-08-31");`);
```
The advantage of this we can give permission to the web user only for this procedure, making it more secure.

```SQL
GRANT EXECUTE ON addActor to webUser;
```

### New IDs
* Auto-increment IDs are useful
* INSERT commands will result in a new ID being generated
```SQL
SELECT last_insert_id();
```
In node
```JavaScript
connection.query(insertCommand,
    function(err, res, cols) {
        res.insertId}
);
```

### Python for data
* Graphing
  * Matlibplot / Pyplot
* Data analysis and ML
  * Numpy
  * Pandas
  * TensorFlow
* Web crawling and scraping
  * BeautifulSoup

### Querying
```python
curosr = conn.cursor()
cursor.execute(query)
result = cursor.fetchall()
for row in cursor:
    print(row['diameter']) # get column in row by name
```

### Transactions
auto_commit is OFF by default
Everything is considered a transaction and the changes need to be committed
```python
cursor.execute(update1)
cursor.execute(update2)
cursor.commit()
```
