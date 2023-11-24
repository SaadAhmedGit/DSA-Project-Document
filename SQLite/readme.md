### SQLite:
To get comfortable, I would suggest you to install SQLite on your system first. SQLite is just an SQL db that operates on a single file. So, you can have a single file called `my_db.sqlite` and you're free to use that as your SQL Database instead of creating an SQL server and then having user credentials to access databases. A `*.sqlite` is enough and fully contains the database.

Let's start by looking at how SQLite stores data.
In this repo, you can find a file `./SQLite/example_db.sqlite`. I will be adding something data to it now.

Here, I have opened the file which is also our db, from SQLite CLI tool. You will need to make a similar CLI tool too to interact with your DB. You can use any language to build it.
![Alt text](sqlite-cli.png)

Now let us first create a table in our database.
```sql
CREATE TABLE students (
    student_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    age INT
);
```
Now, let us insert a student into our newly created table:
```sql
INSERT INTO students (student_id, first_name, last_name, age) VALUES (1, 'Muhammad', 'Sumbul', 3);
```

Here's what my terminal looks like after this:
![Alt text](sqlite-insertion.png)

If we now open the `example-db.sqlite` from a text editor, we will see something like this:
![Alt text](example-db-kwrite.png)

This is a binary file. You might see characters in this and think that this is a text file but this is because the text editor tries to interpret each byte as a character.