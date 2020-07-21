Copyright © 2020 by Bental Tagor

Design:
=======
This design is for a uri reader command for reading html and providing word-related statistics.

Following is the flow of the design:

UriReaderCommand: 
-----------------
Input: String uri, int mostlyUsedWords, Set<String> excludedWords

1. Read the uri and calculate statistics.
   HtmlStatistics statistics = readUri(uri, mostlyUsedWords, excludedWords);
      
2. Display the output as a table.
   displayOutput(statistics);

ReadUri: 
--------
Input: String uri, int mostlyUsedWords, Set<String> excludedWords

1. Create a paragraph parser.
   HtmlParagraphParser paragraphParser(mostlyUsedWords, excludedWords);

2. Read the paragraphs from the html uri, and process each paragraph.            
   List<Paragraph> paragraphs = HtmlParagraphReader.readParagraphs(uri);
   for (Paragraph paragraph : paragraphs) {
       paragraphParser.processParagraph(paragraph);
   }
    
HtmlParagraphParser.processParagraph:
-------------------------------------
Input: String content

1. Create a line reader, and process each line in the paragraph.
   LineReader lineReader(content);
   for (String line : paragraph) {
       processLine(line);
   }

HtmlParagraphParser.processLine:
--------------------------------
Input: String line

1. Split the line by spaces.
   String separatorRegex = "[( )]";
   String[] tokens = line.split(separatorRegex);
   
HtmlParagraphParser.processToken:
---------------------------------
Input: String token

1. Split token by special token.
    char specialToken = 65533;
    String subTokenSeparator = "[" + "(" + specialToken + ")" + "]";
    String[] subTokens = token.split(subTokenSeparator);

2. Process each sub token.
    for (String subToken : subTokens) {
        processSubToken(subToken);
    }
    
HtmlParagraphParser.processSubToken:
------------------------------------
Input: String token

1. Parse a word from the token.
    String word = parseWord(token);
    
2. Process a word.
    processWord(word);
    
HtmlParagraphParser.parseWord:
------------------------------
Input: String token

1. Remove outer parentheses. Parentheses are: {(), [], {}}
    String resultantToken = removeParentheses(token);

2. Remove an end reference. A reference expression is: (\[[0-9]+\]).
    String resultantToken = removeParentheses(resultantToken);

3. Remove sentence separators from front and end. Sentence separators are: {',', '.', ';'}
   resultantToken = this.removeSentenceSeparators(resultantToken);
   
4. Remove outer parentheses. Parentheses are: {(), [], {}}
    String resultantToken = removeParentheses(token);
    
5. Remove quotation marks. Quotation marks are: {', ""}
    resultantToken = Strings.removeQuotationMarks(resultantToken)
    
HtmlParagraphParser.processWord:
--------------------------------
Input: String word

1. Have a mostly used word priority queue.  
    IPriorityQueue<IDoublet<String, Integer>> updateMostlyUsedWordsPriorityQueue = 
    Heap.createMinHeap(
        IDoublet.class,
        mostlyUsedWordsCapacity,
        new MostlyUsedWordComparator());
            
2. Update the word counter map.
    int wordCounter = this.updateWordCounter(word);
    
3. Update the priority queue of mostly-used words.
    updateMostlyUsedWordsPriorityQueue(word, wordCounter);
    
HtmlParagraphParser.updateWordCounter:
--------------------------------------
Input: String word

1. int wordCounter = wordCounterMap.getOrDefault(word, 0);
   ++wordCounter;
   wordCounterMap.put(word, wordCounter);
    
HtmlParagraphParser.updateMostlyUsedWordsPriorityQueue:
--------------------------------------
Input: String word, int wordCounter

1. Check whether to update the priority queue of mostly used words.
    updatePriorityQueue = 
        (mostlyUsedWordsPriorityQueue.size() < mostlyUsedWordsCapacity) ||
        (!mostlyUsedWordsPriorityQueue.empty() && 
         wordCounter > mostlyUsedWordsPriorityQueue.peek().wordCounter);
         
2. Update the priority queue of mostly used words.
    2a. Find the index of the element in the priority queue.
        int index = mostlyUsedWordsPriorityQueue.find(word);
    2b. If the element is not in the priority queue, then add the element to the priority queue.
        If the priority queue has reached its max capacity, remove the top element and
        then insert the new one.
        if (mostlyUsedWordsPriorityQueue.size() >= this.mostlyUsedWordsCapacity) {
            mostlyUsedWordsPriorityQueue.poll();
        }

        mostlyUsedWordsPriorityQueue.offer(newWordCounter);
    2c. If the element is in the priority queue, then update it's current value, and 
        perform a hypify down.
        mostlyUsedWordsPriorityQueue.updateAndHypifyDown(index, newWordCounter)   
 

Implementation:
===============
The following executable/libraries are supporting the solution:

Uri Reader Command:
-------------------
The URI command executable reads an input html and provides word-related statistics.
The command displays the most common words in the input uri.  

Code: DevEnvironment\UriReaderCommand

Command Library:
----------------
The Command library implements the framework and interfaces for implementing command-line tools. 
The command library defines a manifest scheme for defining input parameters of a command-line and provides 
the basic parsing functionality of those parameters.
The library is a place holder for new and updated command features to be defined and implemented.

Code: DevEnvironment\Command

Data Structures Library:
------------------------
The Data Structures library defines and implements customized data structures.
 
The Data Structures library defines and implements customized data structures and provides simple, creative,  
and efficient implementation and interfaces.
The library includes data structures such as an array, bit array, cache, linked-list, doubly linked list, 
expression tree, graph, hash-map, map, matrix, multi-level, doubly linked list, priority queue, stack, tree,  
trie, etc.

Code: DevEnvironment\DataStructures

Basic IO:
---------
The BasicIO library implements basic IO functionality for implementing readers and writers of resources, 
files or, other source objects. 
An example of this functionality is the FileLineReader class which reads lines from a file, resource, 
or a String object, or the FileLineReverseReader class which reads lines from a resource from top to bottom. 
Another example is the HtmlParagraphParser class which parses words of an Html paragraph and 
provides word-related statistics.

Code: DevEnvironment\BasicIO

Json Library:
-------------
The Json library implements the logic for serializing and de-serializing Json objects.
The library implements an efficient and customizable serialization story for small Json objects by taking dependency 
only on open source tokenizer from com.fasterxml.jackson.core.   

Code: DevEnvironment\Json

Algorithm Library:
------------------ 
The algorithm library implements basic algorithms. Currently, the library provides only basic sorting algorithms.
The library is a place holder for implementing customized algorithms.    

Code: DevEnvironment\Algorithms

Base Test Library:
------------------ 
The Base Test library implements basic test functionality and test units to be-used across my unit tests 
and test projects.
This library includes generic test classes for testing iteration, Json object streaming, unit-tests rules, etc.   

Code: DevEnvironment\BaseTest

Base Library:
------------- 
The Base library implements basic logic for any project in Java and provides complimentary functionality.
This library includes basic classes such as EqualBuilder for calculating equality of objects, CompareToBuilder for
comparing objects, Comparators, DestructorHandler for registering objects for invoking their destructors dynamically  
after usage and other base classes and interfaces.    

Code: DevEnvironment\Base

Usage:
======
UriReaderCommand -help
UriReaderCommand <uri> 
UriReaderCommand -uri:=<uri> 
UriReaderCommand -uri:=<uri> -mostlyUsed:=<mostlyUsed> -excludedWords:=<word1, word2, ... wordN>
