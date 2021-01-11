# IMDB-Database-Project

This program replicates the database used to access, modify, delete, and generally analyze the
Golden Globe award nominations, in terms of the actors and actress as well as the pictures. This program uses a
binary search tree as the main structure, in which nodes that include all the actor/actress and picture data, are entered.
These nodes can be deleted, searched for, and modified by the user and the user can additionally add in more nodes.
In terms of searching, the user is able to simply search and modify a node as well as do a partial search or complete search.
The user is also able to call functions that sort the current information in a tree by a certain variable; the variables differ
depending on which file/data is being read.

Name:  main.cpp
   Main program.  This is the driver program calls the functions from the functions.cpp, which
   has two trees made to accordingly modify the actor information and picture information.

Name:  Node.h
   This file has two structs of ActorData and PictureData; the ActorData variables are used to set the actor information
   as the user calls them and the PictureData variables are used to set the actor information as the user calls them.
   With the exception of the structs, the definitions of the class Node are given by the professor and is taken
   straight from: https://ucdenver.instructure.com/courses/397001/files/8564913?module_item_id=1796922

Name: BSTree.h
   This file contains the definitions for many of the functions that will be used to modify the binary search tree. Each private
   function also has a public function, for which the parameters differ; while the public function takes in the user's entry,
   the private function of that same process is called in the public function's implementation with the user's entry as a parameter.
   Additionally, there are several function definitions in this file that came straight from the same powerpoint that was used
   to get the Node.h information.

Name: BSTree.hpp
    This file implements several of the functions from the BSTree.h, the majority of which include the function
    definitions that were provided by the professor. There are some function implementations in this file that were provided by the
    professor, including the addNode( ) function and the beginning of the freeNode( ) function. The deleteNode( ) function
    was implemented after referring to http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete.html

Name: functions.cpp
    This file implements the functions were not implemented in BSTree.hpp but are crucial to meet the majority
    of the requirements of the assignment. This includes the readfromFile() functions, as well as the
     functions for outputting, removing a node, editing a node, adding a node, and both complete and partial search.

Name: actor-actress.csv
    File contains actor/actress information; is read into tree

Name: pictures.csv
    File contains picture information; is read into tree
