# MongoDB


## The Basics
MongoDb is a document based database which stores which can store data in the form of **json**. Json is a simple human readable data exchange format which stores data as a set of key-value pairs. You can think of it as an object and it is exactly that - an object, since it stands for JavaScript Object Notation. It is best explained by an example:

```json
{
  "first name": "Hammad",
  "last name": "Ali",
  "department": "Computer Science",
  "semester": 5,
  "age": 23
}
```

In SQL, we have tables where each row represents a record. Similarly here, instead of tables, we have collections and instead of records, there are documents.

Here is an example mongodb query to insert several documents into a collection (note that you would need to create the collection first)

```js
db.student.insertMany([
  {
    "first name": "Hammad",
    "last name": "Ali",
    department: "Computer Science",
    semester: 5,
    age: 23,
  },
  {
    "first name": "Raveed",
    "last name": "Ullah Usmani",
    department: "Computer Science",
    semester: 5,
    age: 20,
  },
  {
    "first name": "Zoraz",
    "last name": "Javaid",
    department: "Computer Science",
    semester: 5,
    age: 21,
  },
]);
```

After running this command, the mongodb shell outputs the following:

```json
{
  acknowledged: true,
  insertedIds: {
    '0': ObjectId("6562150db67b4eb4a4c29a1d"),
    '1': ObjectId("6562150db67b4eb4a4c29a1e"),
    '2': ObjectId("6562150db67b4eb4a4c29a1f")
  }
}
```

You can see that mongodb has assigned unique IDs to each document in our collection. Let's query the database for a document and see what is returned.

Query:

```js
db.student.find({
  age: { $gt: 20 },
});
```

Result:
```js
[
  {
    _id: ObjectId("6562150db67b4eb4a4c29a1d"),
    'first name': 'Hammad',
    'last name': 'Ali',
    department: 'Computer Science',
    semester: 5,
    age: 23
  },
  {
    _id: ObjectId("6562150db67b4eb4a4c29a1f"),
    'first name': 'Zoraz',
    'last name': 'Javaid',
    department: 'Computer Science',
    semester: 5,
    age: 21
  }
]
```

Which returns an array of all the students that were strictly older than 20. Notice that mongodb attached another field `_id` on its own and this holds a value of the `ObjectId` datatype. This is what your B-Tree will use by default as a key to search for documents but most queries aren't done with `_id` but rather, a field such as an email. So, you will create something called an index on different fields which means the B-tree will be able to use the values in those fields as keys making the queries for those fields faster. Queries on fields that are not indexed will run in linear time since B-tree will not organized according to them.

## BSON

As you may have noticed, json stores data as characters. BSON is an encoding format that stores `json` data in binary format. You can read more about BSON [here](https://www.mongodb.com/basics/bson).

Here is a breakdown of the bson representation of a json object.

```json
{"BSON": ["awesome", 5.05, 1986]}
```

The resulting bson is:
```text
\x31\x00\x00\x00
 \x04BSON\x00
 \x26\x00\x00\x00
 \x02\x30\x00\x08\x00\x00\x00awesome\x00
 \x01\x31\x00\x33\x33\x33\x33\x33\x33\x14\x40
 \x10\x32\x00\xc2\x07\x00\x00
 \x00
 \x00
```

Let us break this complex binary down:<br>
Each token of the form `\x**` represents a byte written as two hexadecimal digits since each hexadecimal digit needs 4-bits. `\x` is just there to tell us that this is hexadecimal.<br>
Disclaimer: The line breaks are added for explanatory purposes only and there are no actual line breaks in binary files by default.

These bytes are written in the little endian order which is what your computer probably uses by default. Meaning, the first four bytes in our data `\x31\x00\x00\x00` have `\x31` as the least significant byte. We can use Python to see what these mean by one simple line of code.

```python
int.from_bytes('\x31\x00\x00\x00'.encode(), byteorder='little')
```
which outputs `49`. Most systems use little endian byte ordering by default meaning if you read these 4 bytes into an integer in C++ and print it, you will get 49 without needing to perform any conversion.

Here is the file format of BSON:

1. The first 4 bytes represent the size of the document. which is 49 in this case.
2. After that, we are going to encounter fields (keys) one by one.
3. The next byte, if non-zero, means that we have encountered a field and that byte will indicate the datatype of the value of that field. Note that all fields or keys are strings so the datatypes are for the values. You can find a table for all datatypes on [this page](https://www.mongodb.com/docs/manual/reference/bson-types/). In our case, the byte is `\x04` which is 4 and from the table, this means an array.
4. After the datatype byte, we have a null-terminated string of characters. You know when to stop when you encounter the null byte `\x00`.
5. After that, we have the next 4-bytes describing the size of our value which is an array in our case and the size is `\x26\x00\x00\x00` or 38-bytes.
6. The next byte `\x02` defines the datatype of this element of the array which is a String if we look at the datatype reference table.
7. The next byte is `\x30` which is 48 and this 48 is the ascii value for the character '0'. You can think of this as the index of that item in the array. Note that is stored as a character and not an integer so it is null-terminated that is why you see `\x30\x00`
8. The next 4 bytes define the length of the string we are going to encounter including the null-terminator so `awesome\0` which are eight characters in total.
9. Once null character has been encountered for a String field, it ends.
10. Then we can see `\x01` which is the data type of a double (8 byte floating point).
11. Again, `\x31` means 49 which is the ascii value of '1' and this index of field number, is null-terminated which means `\x31\x30` would mean '10' in this context.
12. We pick the next 8 bytes without hesitation since we know the datatype is double and `\x33\x33\x33\x33\x33\x33\x14\x40` means `5.5` in little endian format.
13. The next field is simply a a 32-bit integer and the rest of the stuff is self explanatory.
14. Since the next byte is `\x00` this indicates that there is no other item in this array since there's no datatype that has the code 0 assigned to it. This means we can now end this array.
15. Now we are out of the array scope and back into the object scope (you can maintain these using stacks) and the next there's a null byte which means that there is no field afterwards so this marks the end of an object. Note that a BSON file can contain multiple objects/documents like a BSON of an entire collection.