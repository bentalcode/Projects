Copyright © 2019 by Bental Tagor

Solution:
=========

This solution is based on data structure: B+ Tree for aggregating data in memory.

Overview:
---------
B+ Tree is an extension of B Tree which allows efficient insertion, deletion and search operations in log(N). 
In B Tree, keys and records both can be stored in the internal as well as leaf nodes. Whereas, in B+ tree, 
records (data) can only be stored on the leaf nodes while internal nodes can only store the key values. 
The leaf nodes of a B+ tree are linked together in the form of a singly linked lists to make the search queries 
more efficient. 
B+ Trees are used to store the large amount of data which can not be stored in the main memory. 
Due to the fact that, size of main memory is always limited, the internal nodes (keys to access records) 
of the B+ tree are stored in the main memory whereas, leaf nodes are stored in the secondary memory.
The internal nodes of B+ tree are often called index nodes.

Advantages of B+ Tree: 
1. Records can be fetched in equal number of disk accesses. 
2. Height of the tree remains balanced and less as compare to B tree. 
3. We can access the data stored in a B+ tree sequentially as well as directly. 
4. Keys are used for indexing. 
5. Faster search queries as the data is stored only on the leaf nodes.


Design:
=======

Overview:
---------
The solution is implemented by using data command for reading records from resource file and aggregating 
the results in main memory and secondary memory (disk).
The Data Command scans the input resource file record by record, and updates the aggregation results data structure.
For each record, either the matching entry is updated or a new record is appended.
After each record update, in case the aggregation results are in the memory intensity zone 
(has result of data size growth), the data structure is reduced in memory to the configured reduction size and 
the remaining of it's data is getting serialized to disk.

Code References:
----------------
The main entry to the Data Command module is:
DevEnvironment\DataCommand\src\main\java\datacommand\core\Main.java

The interface of a data command is:
DevEnvironment\DataCommand\src\main\java\datacommand\interfaces\IDataCommand.java

The interface of an aggregation results is: 
DevEnvironment\DataCommand\src\main\java\datacommand\interfaces\IAggregationResults.java

Parameters:
-----------
The Data Command receives the following set of input parameters:
dataPath - A path to an input resource which contains records for processing.
aggregationResultsProperties - These properties define configuration and settings for accumulating the 
aggregation results in main memory and secondary memory.

Configuration:
--------------
The solution is configured by using the following settings:

Aggregation Results Properties:
-------------------------------
dataStructureType - BPlusTree, Map.
keyMaxSizeInBytes - The max size of a key in bytes. The default value is 32 bytes.
aggregationResultMaxSize - The max size of an aggregation result in bytes. The default value is 100 bytes.
cacheProperties - The properties of a generic cache to be applied on the aggregation results.

Cache Properties:
-----------------
sizeInBytes - The maximum size of a cache. The default value is: 1MB
intensityFactor - The factor for determining whether a cache is in an intensity zone. The default value is: 0.8, 
which means that once the aggregation results will reach 838861 bytes (1MB* 0.8), the cache size will
 get reduced in the main memory.
reductionFactor - The factor for reducing the size of a cache once it reaches an intensity zone. 
The default value is: 0.4, which means that once the aggregation results will reach 838861 bytes, the cache size will 
get reduced in the main memory to: 335544 bytes (838861 * 0.4) and the remaining bytes will get serialized to the 
secondary memory (disk).

Implementation:
===============
The following libraries are supporting the solution:

DataCommand Library:
--------------------
The Data Command library exposes data commands for processing data and calculating aggregation results.

The code is defined at: DevEnvironment\DataCommand

Data Structures Library:
------------------------
The Data Structures library defines and implements various data structures, specifically, a BPlusTree.

The library includes the following modules:

BPlusTree:
----------
The BPlusTree module implements logic for inserting, deleting, iterating and calculating metrics for data in B+ trees.

BlockTree:
----------
The BlockTree module implements logic for handling trees with internal nodes such as B+ or B trees.

Tree:
----- 
The Tree module implements logic for handling generic trees.

Base Library:
------------- 
The base library implements basic logic for any project in Java and provides complimentary functionality.
This library includes basic classes such as EqualBuilder for calculating equality of objects, CompareToBuilder for
comparing objects, Comparators, DestructorHandler for registering objects for invoking their destructors automatically
 after usage and etc.    

The code is defined at: DevEnvironment\Base

Testing:
--------
I have implemented unit tests for validating the functionality of the BPlus trees.
Those tests validates insertion, iteration, and calculated metrics of those B+ trees.

The code is defined at: 
DevEnvironment\DataStructures\src\test\java\datastructures\plustree\core\BPlusTreeTest.java

Missing Functionality:
======================
The serialization logic of the B+ trees to the secondary memory were not implemented.
To be continued:-)
