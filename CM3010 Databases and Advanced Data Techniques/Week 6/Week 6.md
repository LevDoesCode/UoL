## ACID and transactions
Imagine we want to transfer money from A to B, we need to complete these stages successfully to determine the transaction was successful.

![Diagram](Files/Image1.png)

If we miss the last step, we could be removing money from A and not transferring to B, due to a black out, for example.

## ACID properties

* Atomicity
* Consistency
* Isolation
* Durability

* Atomicity
A set of operations that only make sense as a group should be treated as a group.

Groups of operations are all performed or none are.

* Consistency
The database is never in an inconsistent state as a result of groups of operations being processed.

If we're in the middle of changing the database, they data should not be available for other operations.

* Isolation
If two or more groups of operations affect the same data, they can only be performed one at a time.

* Durability
A completed operation or group of operations will have its changes physically committed. (and prevent loss of data as it may happen in data stored in RAM)

## Transactions

* Data definition Language (changing tables in the database) can cause problems, these changes may not be able to be rolled back.
* Checkpoints (to disk) may not be as frequent as transactions.
* Table locking is not absolute

## Inconsistent analysis
Two transactions access the same data. One has multiple queries which give inconsistent information.

To avoid an inconsistent analysis, we should implement a locking system where we can deny write access to other transactions while one is being run on a set of data.

While one transaction is reading, no other transaction should be able to write to that data.

Another option is to make a copy of the last known good state at the beginning of the transaction, while another transaction may be writing to the same data.

## Serializability

Interleaved execution of transactions is serializable if it produces the same result as non-interleaved execution of the same transactions.

If we can guarantee that the result of performing interleaved transactions is the same as if some ordering of those transactions one at a time, then we can say that it's a consistent and allowed process.

Operations on different data are serializable.

Operations which are all SELECTs are serializable.

ACID can be satisfied y a combination of:
* Transactions
* Locking strategy
* Failure recovery strategy

## Malice and accidental damage
![Diagram](Files/Image2.png)
* SQL injection puts malicious code into normal operations.
* Malicious agent gains direct access to the database.
* User error.
* Confidential data shared inappropriately.

## Security and user policies with SQL
The user who is expected only to add data to it should not be able to restructure (delete) a table.

Users in SQL can
* Create, edit users
* Create, edit, use databases
* Create, edit, use tables
* Create, edit, use data

Define user policy in advance.

Consider whether a user needs separate roles.

We can use the command GRANT (ability) ON (table) TO (user)
e.g.
```SQL
GRANT SELECT ON Planets, Moons TO BobUser
GRANT SELECT, INSERT ON Planets, Moons, TO BobUser
GRANT SELECT, INSERT, DROP ON Planets, Moons, TO BobUser
```
We create a user like this
```SQL
CREATE USER BobUser IDENTIFIED BY 'BobsPass123' PASSWORD EXPIRE;
```
Grant the ability to grant privileges up to the same privileges it has.

```SQL
GRANT SELECT ON Planets, Moons TO BobUser WITH GRANT OPTION;
```

Revoke privileges

```SQL
REVOKE ALL ON Planets, Moons FROM BobUser;
```

### Roles

```SQL
CREATE ROLE Astronomer;
GRANT INSERT, SELECT ON Planets, Moons TO Astronomer;
GRANT Astronomer to BobUser;
```

We want to minimize user privileges to reduce the impact of error or malice.

## Sources of error
* Bad data coming in
* Poor application logic
* Failed database operations
* Malicious user activity

