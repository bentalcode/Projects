Copyright © 2019 by Bental Tagor

Problem:
========
Design a solution for determining an alphabetical order of a given list of words sorted in alphabetical order. 
The alphabet can be part of any language. Can you determine the ordering of the alphabet?

Design:
=======
Following is the algorithm for determining the alphabetical order of the words:
1. Create a Trie data structure and insert to it each input word.
2. Create a dependency graph for the characters in the language by performing an inorder traversal of the Trie.
    2.1 For each visited node do: 
    2.2 Iterate over the children, and for each following children if they differs, include them as an edge
        in the dependency graph.
3. Perform a topological search on the dependency graph for determining the final alphabetical order of the characters.

Background:
-----------

Trie:
-----
Trie is an efficient information retrieval data structure. 
Using Trie, search complexities can be brought to optimal limit (key length). 
If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N, 
where M is maximum string length and N is number of keys in tree. 
Using Trie, we can search the key in O(M) time. 
However, the penalty is on Trie storage requirements (Please refer Applications of Trie for more details).

The Trie data structure is implemented by the following structure:

public final class TrieNode<TKey extends Comparable<TKey>, TValue> implements ITrieNode<TKey, TValue> {
    private final TKey key;
    private TValue value;
    private final LinkedHashMap<TKey, ITrieNode<TKey, TValue>> children = new LinkedHashMap<>();
    private final IBinaryComparator<TKey> keyComparator;
}

Topological Search:
-------------------
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed 
edge uv, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a Directed Acyclic Graph.

Topological Sorting Algorithm:
We can modify DFS to find Topological Sorting of a graph. 
In DFS, we start from a vertex, we first process it and then recursively call DFS for its adjacent vertices.
In topological sorting, we use a temporary stack. We don’t process the vertex immediately, 
we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
Finally, processing the contents of stack. 
Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) 
are already in stack.

Overview:
---------
The solution is implemented by using data command for reading strings from resource file.
The Alphabetical Order Command scans the input resource file word by word, and update the input list of words.
Then, the Alphabetical Order Calculator is invoked for calculating the desired alphabetical order, and the
command is displaying the results in the console.   

Code References:
----------------
The main entry to the alphabetical order command module is:
DevEnvironment/AlphabeticalOrderCommand/src/main/java/alphabeticalordercommand/Main.java

The interface of alphabetical order command is:
DevEnvironment/AlphabeticalOrderCommand/src/main/java/alphabeticalordercommand/interfaces/IAlphabeticalOrderCommand.java

The interface of the alphabetical order results is: 
DevEnvironment/AlphabeticalOrderCommand/src/main/java/alphabeticalordercommand/interfaces/IAlphabeticalOrderResults.java

The core logic of the alphabetical order calculator is:
DevEnvironment/AlphabeticalOrderCommand/src/main/java/alphabeticalordercommand/core/AlphabeticalOrderCalculator.java

Parameters:
-----------
The Data Command receives the following set of input parameters:
dataPath - A path to an input resource which contains records for processing.

Implementation:
===============
The following libraries are supporting the solution:

Alphabetical Order Command Library:
-----------------------------------
The Alphabetical Order Command library exposes commands for processing data and calculating results.

The code is defined at: 
DevEnvironment/AlphabeticalOrderCommand

Data Structures Library:
------------------------
The Data Structures library defines and implements various data structures, specifically, a Trie and a Graph.

The code is defined at: 
DevEnvironment/DataStructures

Base Library:
------------- 
The base library implements basic logic for any project in Java and provides complimentary functionality.
This library includes basic classes such as EqualBuilder for calculating equality of objects, CompareToBuilder for
comparing objects, Comparators, DestructorHandler for registering objects for invoking their destructors automatically
 after usage and etc.    

The code is defined at:
DevEnvironment/DataStructures

Testing:
--------
I have implemented unit tests for validating the functionality of the alphabetical order calculator.

The code is defined at: 
DevEnvironment/AlphabeticalOrderCommand/src/test/java/alphabeticalordercommand/core/AlphabeticalOrderTest.java
