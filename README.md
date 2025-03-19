[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/wL-Me8AW)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=18664141)
# Binary Search Tree Constructor (and related operations)

Devise an algorithm for loading a binary search tree from a vector such that
the resulting tree is perfectly well-balanced (i.e. has a minimum depth).
In other words, your algorithm should
insert values from the vector into the tree, using *BSTree*'s *insert*
function, in an order that makes searching the tree most efficient. You
should make no assumptions about the ordering of values in the given vector.

Implement your algorithm in the header file *bstree.h* as a constructor
that takes a *vector* as a parameter. Such a constructor is included in the
code, but it simply inserts into the tree in the order in which the objects
appear in the vector, thus not guaranteeing a well-balanced tree.
This constructor appears near the end of the public section of the code;
replace the code in this constructor with your code.

The contructor has the following prototype:

```C++
BSTree(vector<T> v);
```

Note that this prototype uses a value parameter. This gives you a copy of
the supplied vector that you can manipulate as necessary.
Also, note that the
*vector* class has a built-in *sort* function should your algorithm require
that the *vector* be sorted.

Make all your *BSTree* code modifications
at the end of the class definition in *bstree.h*.
Look for the *TODO* comments. You will likely need to add one or more
helper functions. Place any additional functions below your constructor
where indicated by the comments.

*Document your code with comments!*

If you need to change any other existing code in the class, clearly document
your changes with comments, and state your reasons for doing so in the
*RESPONSES.md* document.

## Test Programs

Two test programs are provided in this repository: *main.cpp* and *test.cpp*.

*main.cpp* builds a *BSTree* object of strings and displays the tree using
the *preorder* function. You may modify this program as you see fit for
testing. How you test your code is up to you. Also, you are free to
create other test programs if you choose to do so.

*test.cpp* runs 16 individual tests of building a *BSTree* object from a
vector with a randomized arrangement of the values 1 through *N*, where *N*
is the size of the vector. Sixteen different vector sizes are chosen such that
if a perfectly balanced binary search tree is built from those vectors,
the trees will have depths of 0 through 15.
Do not modify this program, but rather use it to verify that you code
produces a perfectly balanced tree.

## Algorithm, Code Reflection, and Analysis

This is a written portion of the assignment. Include your responses to the
items below in file *RESPONSES.md*.

- *Algorithm*: Describe your algorithm for loading the binary search tree
from a vector. Ideally, this should be done before coding and serves as your
plan. Present your plan step-by-step.
- *Code Reflection*: After completing your code, write a short discussion on
your experience implementing your algorithm. Address any and all of the 
follow items that are applicable:
  - List all class members that you modified or added.
  - Discuss any difficulties you encountered and how you overcame those difficulties.
  - Discuss how you tested your code.
- *Analysis*: State the run-time of your constructor and discuss how you
arrived at this conclusion.

## Sample Program Run

If your constructor works as expected, the output from *test.cpp* should
look like this:

```
Vector Size  Expected Depth  Actual Depth  Result
-----------  --------------  ------------  ------
       1             0              0       Pass
       3             1              1       Pass
       7             2              2       Pass
      15             3              3       Pass
      31             4              4       Pass
      63             5              5       Pass
     127             6              6       Pass
     255             7              7       Pass
     511             8              8       Pass
    1023             9              9       Pass
    2047            10             10       Pass
    4095            11             11       Pass
    8191            12             12       Pass
   16383            13             13       Pass
   32767            14             14       Pass
   65535            15             15       Pass
```
