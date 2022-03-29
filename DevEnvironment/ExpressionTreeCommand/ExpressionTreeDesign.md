Copyright © 2019 by Bental Tagor

Design:
=======

This design is based on expression tree for calculating expressions.

Overview:
---------
Expression tree is a binary tree in which each internal node corresponds to operator and each leaf node corresponds
to operand, so for example expression tree for 3 + ((5+9)*2) would be:

        +
    3       *
        +       2
    5       9


Construction of an Expression Tree:
-----------------------------------
1. Transform an infix expression to a postfix expression.
2. Now For constructing expression tree we use a stack.
   We loop through input expression and do following for every token.
   1) If the current token is an operand, then simply add it to the stack.
   2) If the current token is a unary operator, then pop the operand from the stack,
      create a unary operator and push it back to the stack.
   3) If the current token is a binary operator, then pop two operands from the stack,
      create a binary operator and push it back to the stack.

   At end, the top element of stack will be root of expression tree.

Transformation of Infix Expression to Postfix Expression:
---------------------------------------------------------
1. Set infix = Input list of tokens.
   Set result = Initialize an empty list of tokens.
2. Set operatorStack - Initialize an empty stack.
3. Push '(' to the operator stack and add ')' to the end of the infix token list.

4. Scan the infix expression from left to right:
   For each token do:
     4.1 If the current encountered token is an operand, then append it to the result.
     4.2 If the current encountered token is an open parentheses, then push it to the stack.
     4.3 If the current encountered token is a close parentheses, then pop from the stack all operators
         up to the corresponding open parentheses and append all those operators to the result.
         Remove the open parentheses from the stack.
     4.4 If the current encountered token is an operator, then pop from the stack all operators,
         which has the same precedence or higher than the current encountered operator, and append
         those operators to the result.
         Add the current encountered operator to the stack.

5. Append all remainder operators in the stack to the result.

Evaluation of an Expression Tree:
---------------------------------
The evaluation of an expression tree is implemented simply by performing a post-order traversal
of a binary tree and calculating the current expression for each tree-node.

Implementation:
===============
The following libraries are supporting the solution:

ExpressionTreeCommand Library:
------------------------------
The Expression Command library exposes commands for processing data and calculating the expressions results.

The code is defined at: DevEnvironment\ExpressionTreeCommand

Data Structures Library:
------------------------
The Data Structures library defines and implements various data structures, specifically, an expression tree.

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

Expression Tree:
----------------
The Expression Tree module implements logic for handling expression trees.

Base Library:
------------- 
The base library implements basic logic for any project in Java and provides complimentary functionality.
This library includes basic classes such as EqualBuilder for calculating equality of objects, CompareToBuilder for
comparing objects, Comparators, DestructorHandler for registering objects for invoking their destructors automatically
 after usage etc.    

The code is defined at: DevEnvironment\Base

Usage:
======
ExpressionTreeCommand <DataPath>
ExpressionTreeCommand .\DevEnvironment\ExpressionTreeCommand\src\main\resources\data.txt
