Copyright © 2019 by Bental Tagor

Environment:
============

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
