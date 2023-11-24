### Neo4j:
Neo4j is a graph database that uses nodes and edges to represent relationship between different types of data. You can watch the following crash course to understand how it works: [Neo4j-CrashCourse](https://www.youtube.com/watch?v=8jNPelugC2s&t=475s)

In a graph database, each entity type corresponds to a specific node, with each node comprising a set of attributes. These attributes encompasses the inherent properties of the entity. For instance, envision creating an online store with buyers, products, and sellers. In the case of products, their properties would encompass details such as price, type, and availability status. Similarly, the graph database uses a list of edges to define relation between these entities. For example, there would exist multiple edges between a seller and all the product he sells. Just like nodes, each edge has a set of properties assigned to it. In this case, the name of our edge would be 'sells' since the seller sells the product. Then there would be the type of the relation it is, whether it is directional or bidirectional, one to one or many to one and so on. So in this way, Neo4j uses nodes and edges to keep track of entities and relationships within the database.

Neo4J, in general, is a collection of various types of graphs. Unlike other databases on the list, it doesn't use a ton of data structures to operate; instead, it utilizes graphs in various ways. So, your focus won't be on creating data structures; it will be on developing functionalities with different variations of graphs. While each of these functionalities can be implemented straightforwardly, you'll need to explore or study algorithms to optimize them. Here, we'll list some of the basic functionalities offered by Neo4j.

Create: The job of the create feature is to take information from a CSV (comma separated values) file and use it to create specific type of nodes. The first line in the CSV file tells us how many attributes each node has and what we should call those attributes. After that, each line in the file tells us about the attributes of one node. Imagine we're keeping track of employees in a company. Our CSV might look like this:

```plaintext
employeeId,Name,Company
1,Bob Smith,1
2,Joe Jones,3
3,Susan Scott,2
4,Karen White,1
```

Your task is to read this file and create nodes for that particular type, loading the data from the CSV. The user would provide you with the label he is going to give to these type of nodes, e.g in this case the nodes are of employee type, and the path to the csv file from which you should load the nodes.

Merge: Merge would take the label of two type of nodes and the relation that exist between them along with the attribute it exists on the basis of and would add an edge between the two given type of nodes. For example to state that Dhawan plays for India, we can do the following: 

```cypher
CREATE (Dhawan:player{name: "Shikar Dhawan", YOB: 1985, POB: "Delhi"}) 
CREATE (Ind:Country {name: "India"})
CREATE (Dhawan)-[r:BATSMAN_OF]->(Ind) 
```

As you can see, you can use merge through the create command as well. Now since the graph has been created, we can move onto the functionalities the graph would have.

Property Based Query: This is a basic functionality in Neo4j. When we talk about querying, it simply means asking for information from the graph. It could be about the whole graph, a part of it, a certain type of graph, or a specific node inside it. To make this work, you'll create different versions of a function in your database. These functions will take the type of node as an input and return all nodes of that type across the entire database. For example, if you want to know all the sellers in your store, your database should give you a list of nodes that represent sellers. Importantly, you can also make a query that doesn't specify the type of node. This means you want to see all the data from all types of nodes, essentially everything in the database. This way, you're setting up a system for users to ask different questions about the entities in your database. Additionally, for each type of entity, you'll need a function that prints out its properties.

Filter Functionality: The filter function involves searching for nodes based on specific attributes. It is designed for each possible property a node might have. This means the user can specify the filter criteria and indicate which property they want to apply it to. For instance, if a user wants to find all the products in our store with prices ranging from 1000 to 10000 Rs, the database would compare the "price" attribute within each product type node against the specified filter. The result would be a list or array of nodes that meet the filter criteria. To achieve this, you need to implement various filter/comparison properties such as less than, equal to, greater than, and others for each type of entity in your database.

Relational Query: You can also conduct queries based on the relationship of an attribute. For instance, if you want your database to retrieve all the types of shoes made by BATA, you'll initiate a filter on sellers to identify the seller named BATA. Subsequently, you'll access BATA's relational attributes and iterate through each type of product it sells. Following this, you'll perform a property-based query on those products and return those that are shoes. This approach allows you to implement relational queries for each type of relation/edge present in your graphs.