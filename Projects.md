# Data Structures & Algorithms Fall 2023

## Overview of Projects:

- `Redis`, an in-memory key-value store. You can learn more about it here: [Redis in 100 Seconds](https://www.youtube.com/watch?v=G1rOthIU-uo)

- `SQLite`, a relational SQL database where data is modelled as tables. `SQLite` is an `SQL` database represented as one single file. You can learn more about `SQL` here: [SQL Explained in 100 Seconds](https://www.youtube.com/watch?v=zsjvFFKOm3c).
- `Neo4j`, a graph based database with a query language called `CypherQL`. These kinds of databases are useful in representing data in social media networks like Facebook. You can learn more about it here: [Neo4j in 100 Seconds](https://www.youtube.com/watch?v=T6L9EoBy8Zk)
- `MongoDB`, a document based database which stores data as `BSON` objects. `BSON` is just a way to represent the human readable `JSON` as binary data. You can learn more about it here: [MongoDB in 100 Seconds](https://www.youtube.com/watch?v=-bt_y4Loofg).



## Details:

### Redis:
This is the simplest database on the list. It simply stores *key-value* pairs. For example:
```bash
127.0.0.1:6379> SET hello world
OK
```
This stores a value of "world" against a key "hello". The redis client displays `OK` as a message for a successful write.

If we want to get the value using the key, we can use `GET`

```bash
127.0.0.1:6379> GET hello
"world"
```
Redis also supports a lot of other things like storing `Hashes` with is storing a list of fields against a key with each field having a values. Kind of like `JSON`. Here's an example:
```bash
127.0.0.1:6379> HSET batman power_level 15 stealth 100 intelligence 95
(integer) 3
127.0.0.1:6379> HGET batman intelligence
"95"
127.0.0.1:6379> HGET batman power_level
"15"
127.0.0.1:6379> HGET batman identity
(nil)
```
Redis supports a large list of data types but you'll be asked to implement only the following:

- Strings
- Lists
- Sets
- Hashes
- Sorted Sets
- Bitmaps
- Bitfields

You can find their details [here](https://redis.io/docs/data-types/) in the redis docs. <br>
Your are not expected to implement every API that redis provides with the above listed data types so, implement as many as you can you'll be graded relative to how many APIs others building the same project implemented.

We said that Redis is an in-memory database but it's also persistent. Meaning, it writes data to disk as a backup so that in case of a crash, data isn't lost. You'll also be required to implement this durability mechanism which can be toggled on or off or tweaked. For simplicity, you'll only be required the implement the `RDB` persistence mechanism which you can read about [here](https://redis.io/docs/management/persistence/).

Remember that `Redis` stands for REmote DIctionary Server. So it should be implemented as a server that receives commands as strings.


### SQlite:
