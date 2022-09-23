# Cracking the Coding Interview


[![License](https://img.shields.io/badge/License-MIT-blue)](https://github.com/FedericoBruzzone/shimmer_effect_audio/edit/master/License)
[![c++Make with](https://img.shields.io/badge/C%2B%2B-v12.1.0-orange)](https://en.wikipedia.org/wiki/C%2B%2B)

In this repository there are implementations of `Cracking the Coding interview` question.
In addition, there are implementations of `data scructure` in c++.

# Chapter 1 - Arrays and Strings


**1.1 Is Unique**: 

Implement and algorithm to determine if a string has all unique characters. What if you cannot use additional data structure?

[Solution 1.1](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.1_is_unique.cpp)

---

**1.2 Check Permutation**: 

Given two strings, write a method to decide if one is a permutation of the other.

[Solution 1.2](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.2_check_permutation.cpp)

---

**1.3 URLify**: 

Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. 

EXAMPLE

Input:   
- "Mr John Smith       ", 13

Output:  
- "Mr%20John%20Smith"

[Solution 1.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.3_URLify.cpp)

---

**1.4 Palindrome Permutation**: 

Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. You can ignore casing and non-letter characters.

EXAMPLE

Input:   
- Tact Coa

Output:  
- True (permutation: "taco cat", "atco cta", etc.)

[Solution 1.4](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.4_palindrome_permutation.cpp)

---

**1.5 One Away**: 

There are three types of edits that can be performed on strings: insert a character, remove a character. ot replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

EXAMPLE

pale,  ple  -> true

pales, pale -> true

pale,  bale -> true

pale,  bake -> false

[Solution 1.5](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.5_one_away.cpp)

---

**1.6 String Compression**: 

Implement a method to perform basic string compression using the counts of repeated characters. For example, the string 'aabcccccaa' would become 'a2b1c5a3'. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a-z).

[Solution 1.6](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.6_string_compression.cpp)

---

**1.7 Rotate Matrix**: 

Given an image represented by an N x M matrix, where each pixel in the image is represented by an integer, write a method to rotate the image by 90 degrees. Can you do this in place?

[Solution 1.7](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.7_rotate_matrix.cpp)

---

**1.8 Zero Matrix**: 

Werite an algorithm such that if an element in an M x N matrix is 0, its entire row and column are set to 0.

[Solution 1.8](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.8_zero_matrix.cpp)

---

**1.9 String Rotation**:

Assume you have method 'isSubstring' which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").

[Solution 1.9](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.9_is_rotation.cpp)


# Chapter 2 - Linked Lists

**2.1 Remove Dups**:

Write code to remove duplicates from an unsorted linked list

FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed?

[Solution 2.1](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.1_remove_dups.cpp)

---

**2.2 Return Kth to Last**:

Implement an algorithm to find the kth to last element of a singly linked list.

[Solution 2.2](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.2_return_kth_to_last.cpp)

---

**2.3 Delete Middle Node**:

Implement an algorithm to delete a node in the middle (i.e. any node but the first and the last node, not necessary the exact the middle) of a singly linked list, given only access to that node.

EXAMPLE

Input: 
- the node c from the linked list a -> b -> c -> d -> e -> f

Result: 
- nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

[Solution 2.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.3_delete_middle_node.cpp)

--- 

**2.4 Partition**:

Write code to partition a linked list around a value x, such that all node less than x come before all node greater than or equal to x. (IMPORTANT: The partition element x can appear anywhere in the "right position"; it does not need to appear between the left and the right partition. The additional spacing in the example blow indicates the partition. Yes, the output below is one of many valid outputs!)

EXAMPLE

Input: 
- 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]

Output: 
- 3 -> 1 -> 2    ->    10 -> 5 -> 5 -> 8

[Solution 2.4](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.4_partition.cpp)

--- 

**2.5 Sum List**:

You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list. (You are not allowed to "cheat" and just convert the linked list to an integer.)

EXAMPLE
Input: 
- (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.

Output 
- 2 -> 1 -> 9. That is, 912.

FOLLOW UP 
Suppose the digits are stored in forward order. Repeat the above problem.

EXAMPLE

Input: 
- (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.

Output 
- 9 -> 1 -> 2. That is, 912.

[Solution 2.5](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.5_sum_list.cpp)

--- 

**2.6 Palindrome**:

Implement a function to check if a linked list is a palindrome.

[Solution 2.6](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.6_palindrome.cpp)

--- 

**2.7 Intersection**:

Given two (singly) linked list, determine if the two lists intersect. Retrun the intersecting node. Noto that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact the node (by reference) as the jth node of the second linked list, than thay are intersecting.

[Solution 2.7](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.7_intersection.cpp)

--- 

**2.8 Loop Detection**:

Given a linkedlist which might contain a loop, implement an algorithm that returns the node at the beginning of the loop (if one exists).

EXAMPLE

Input: 
- A -> B -> C -> D -> E -> C (the same C as earlier)

Output C

[Solution 2.8](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.8_loop_detection.cpp)


# Chapter 3 - Stacks and Queues

**3.1 Three in One**:

Describe how you could use a single array to implement three stacks.

[Solution 3.1](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_3/3.1_three_in_one.cpp)

---

**3.2 Stack Min**:

How would you design a stack which, in addition to `push` and `pop`, has a function `min` which returns the minimum element? `push`, `pop` 
and `min` should all operate in O(1) time.

[Solution 3.2](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_3/3.2_stack_min.cpp)

---

**3.3 Stack of Plates**:

Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack
when the previous stack exceeds some threshold. Implement a data structure `SetOfStack` that mimics this. `SetOfStack` should be composed of 
several stack and should create a new stack once the previous one exceed capacity. `SetOfStack.push()` and `SetOfStack.pop()` should behave 
identically to a single stack (that is, `pop()` should return the same values as it would ig there were just a single stack).

FOLLOW UP

Implement a function `popAt(int index)` which performs a pop operations on a specific sub-stack.

[Solution 3.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_3/3.3_stack_of_plates.cpp)

---

**3.4 Queue via Stacks**:

Implement MyQueue class which implements a queue using two stacks.

[Solution 3.4](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_3/3.4_queue_via_stacks.cpp)

---

**3.5 Sort Stack**:

Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: `push`, `pop`, `peek` and `isEmpty`. 


[Solution 3.5](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_3/3.5_sort_stack.cpp)

---

**3.6 Animal Shelter**:

An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. People must adopt either the "oldest"
(based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive
the oldest animal of that type). They cannot select which specific animal thay would like. Create the data strctures to mantain this system
and implement operations such as `enqueue`, `dequeueAny`, `dequeueDog` and `dequeueCat`. You may use the built-in `LinkedList` data structure.


[Solution 3.6](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_3/3.6_animal_shelter.cpp)


# Chapter 4 - Trees and Graphs

**4.1 Route Between Nodes**:

Given a directed graph and two nodes (S and E), design an algorithm to find whether there is a route from S to E.

[Solution 4.1](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.1_route_between_nodes.cpp)

---

**4.2 Minimal Tree**:

Given a sorted (increase oreder) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.

[Solution 4.2](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.2_minimal_tree.cpp)

---

**4.3 List of Depths**:

Given a binary tree, design an algorithm which created a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, tou will have D linked list)

[Solution 4.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.3_list_of_depths.cpp)

---

**4.4 Check Balanced**:

Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.

[Solution 4.4](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.4_check_balanced.cpp)

---

**4.5 Validate BST**:

Implement a function to check if a binary tree is a binary search tree.

[Solution 4.5](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.5_validate_bst.cpp)

---

**4.6 Successor**:

Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent. 

[Solution 4.6](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.6_successor.cpp.cpp)

---

**4.7 Build Order**:

You are given a list of projects and a list of dependencies (which is a list of pairs of project, where the second projects is dependent on the first proect). All of a project's dependencies must be before the project is. Find a build order that will allow the projects to be built. If there is no valid build oreder, return an error.

EXAMPLE

Input:
- projects: a, b, c, d, e, f
- dependecies: (a, d), (f, b), (b, d), (f, a), (d, c)

Output: 
- f, e, a, b, d, c 

[Solution 4.7](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.7_build_order.cpp)

---

**4.8 First Common Ancestor**:

Design an algorithm and write code to find the first common ancestor of teo nodes in a binary tree. Avoid storing additional nodes in a data strcture. 

NOTE: This is not necessarily a binary search tree.

[Solution 4.8](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.8_first_common_ancestor.cpp)

---

**4.9 BST Sequences**:

A binary search tree was created by traversing through an array from left to right and instering each element. Given a binary search tree with distinct elements, print all possibile arrays that could have led to this tree.

Input:

bst => 2: [1, 3]

Output:

{2, 1, 3}, {2, 3, 1}

[Solution 4.9](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.9_bst_sequences.cpp)

---

**4.10 Check Subtree**:

T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.

A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2.

That is, if you cut off the tree at node n, the two trees would be identical.

[Solution 4.10](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.10_check_subtree.cpp)

---

**4.11 Random Node**:

You are implementing a binary search tree class from scratch which, in addition to inster, find and delete, has a method `getRandomNode()` which returns a random node from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm for `getRandomNode`, and explain how you would implement the rest of the methods.


[Solution 4.11](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.11_random_node.cpp)

---

**4.12 Paths with Sum**:

You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end ar the root or leaf, but it must go downwards (traveling only from parent nodes to child nodes).

[Solution 4.12](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/4.12_paths_with_sum.cpp)


# Chapter 5 - Bit Manipulation

**5.1 Insertion**:

You are given two 32-bit numbers, N and M, and two bit position, i and j. Write a method to insert M into N such that M start at bit j and ends at bit i.
You can assume that the bit j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.

EXAMPLE

Input: N = 10000000000, M = 10011, i = 2, j = 6

Output: N = 10001001100

[Solution 5.1](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.1_insertion.cpp)

--- 

**5.2 Binary to String**

Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR."

[Solution 5.2](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.2_binary_to_string.cpp)

--- 

**5.3 Flip Bit to Win**

You have an integer and you can flip exaclt one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.

EXAMPLE

Input: 1775 (or: 11011101111)

Output: 8

[Solution 5.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.3_flip_bit_to_win.cpp)

--- 

**5.4 Flip Bit to Win**

Given a positive integer, print the next smallest and the next largest number that have the same number of 1 in their binary representation.

[Solution 5.4](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.4_next_number.cpp)

---

**5.5 Debugger**

Explain what the following code does: ((n & (n-1)) == 0).

[Solution 5.5](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.5_debugger.cpp)

---

**5.6 Conversion**

Write a function to determine the number of bits you would need to flip to convert interger A to integer B.

EXAMPLE:

Input: 29 (or: 11101), 15 (or: 01111)

Output: 2

[Solution 5.6](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.6_conversion.cpp)

---

**5.7 Pairwise Swap**

Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped and so on)

[Solution 5.7](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.7_pairwise_swap.cpp)

---

**5.8 Draw Line**

A monochrome screen is stored as a single array of bytes, allowing wight consecutive pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (x1, y) to (x2, y).

The method signature should look something like:

`drawLine(byte[] screen, int width, int x1, int x2, int y)`

[Solution 5.8](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_4/5.8_draw_line.cpp)