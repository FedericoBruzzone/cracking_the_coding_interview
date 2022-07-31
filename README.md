# Cracking the Coding Interview


[![License](https://img.shields.io/badge/License-MIT-blue)](https://github.com/FedericoBruzzone/shimmer_effect_audio/edit/master/License)

In this repository there are implementations of `Cracking the Coding interview` question.
In addition, there are the implementation of `data scructure` in c++.

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

Input:   "Mr John Smith       ", 13

Output:  "Mr%20John%20Smith"

[Solution 1.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_1/1.3_URLify.cpp)

---

**1.4 Palindrome Permutation**: 
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. You can ignore casing and non-letter characters.

EXAMPLE

Input:   Tact Coa

Output:  True (permutation: "taco cat", "atco cta", etc.)

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

Input: the node c from the linked list a -> b -> c -> d -> e -> f

Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

[Solution 2.3](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.3_delete_middle_node.cpp)

--- 

**2.4 Partition**:
Write code to partition a linked list around a value x, such that all node less than x come before all node greater than or equal to x. (IMPORTANT: The partition element x can appear anywhere in the "right position"; it does not need to appear between the left and the right partition. The additional spacing in the example blow indicates the partition. Yes, the output below is one of many valid outputs!)

EXAMPLE

Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]

Output: 3 -> 1 -> 2    ->    10 -> 5 -> 5 -> 8

[Solution 2.4](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.4_partition.cpp)

--- 

**2.5 Sum List**:
You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list. (You are not allowed to "cheat" and just convert the linked list to an integer.)

EXAMPLE
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.

Output 2 -> 1 -> 9. That is, 912.

FOLLOW UP 
Suppose the digits are stored in forward order. Repeat the above problem.

EXAMPLE

Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.

Output 9 -> 1 -> 2. That is, 912.

[Solution 2.5](https://github.com/FedericoBruzzone/data_structure_CCI/blob/master/cracking_the_coding_interview/chapter_2/2.5_sum_list.cpp)
