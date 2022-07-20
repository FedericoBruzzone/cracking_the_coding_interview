# Chapter 1 - Arrays and Strings


**1.1 Is Unique**: 
Implement and algorithm to determine if a string has all unique characters. What if you cannot use additional data structure?

[Solution 1.1](cracking_the_coding_interview\chapter_1\1.1_is_unique.cpp)

---

**1.2 Check Permutation**: 
Given two strings, write a method to decide if one is a permutation of the other.

[Solution 1.2](cracking_the_coding_interview\chapter_1\1.2_check_permutation.cpp)

---

**1.3 URLify**: 
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. 

EXAMPLE

Input:   "Mr John Smith       ", 13

Output:  "Mr%20John%20Smith"

[Solution 1.3](cracking_the_coding_interview\chapter_1\1.3_URLify.cpp)

---

**1.4 Palindrome Permutation**: 
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. You can ignore casing and non-letter characters.

EXAMPLE

Input:   Tact Coa

Output:  True (permutation: "taco cat", "atco cta", etc.)

[Solution 1.4](cracking_the_coding_interview\chapter_1\1.4_palindrome_permutation.cpp)

---

**1.5 One Away**: 
There are three types of edits that can be performed on strings: insert a character, remove a character. ot replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

EXAMPLE

pale,  ple  -> true

pales, pale -> true

pale,  bale -> true

pale,  bake -> false

[Solution 1.5](cracking_the_coding_interview\chapter_1\1.2_check_permutation.cpp)

---

**1.6 String Compression**: 
Implement a method to perform basic string compression using the counts of repeated characters. For example, the string 'aabcccccaa' would become 'a2b1c5a3'. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a-z).

[Solution 1.6](cracking_the_coding_interview\chapter_1\1.6_string_compression.cpp)

---

**1.7 Rotate Matrix**: 
Given an image represented by an N x M matrix, where each pixel in the image is represented by an integer, write a method to rotate the image by 90 degrees. Can you do this in place?

[Solution 1.7](cracking_the_coding_interview\chapter_1\1.7_rotate_matrix.cpp)

---

**1.8 Zero Matrix**: 
Werite an algorithm such that if an element in an M x N matrix is 0, its entire row and column are set to 0.

[Solution 1.8](cracking_the_coding_interview\chapter_1\1.8_zero_matrix.cpp)

---

**1.9 String Rotation**:
Assume you have method 'isSubstring' which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").

[Solution 1.9](cracking_the_coding_interview\chapter_1\1.9_is_rotation.cpp)


# Chapter 2 - Linked Lists

**2.1 Remove Dups**:
Write code to remove duplicates from an unsorted linked list

FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?

[Solution 2.1](cracking_the_coding_interview\chapter_2\2.1_remove_dups.cpp)