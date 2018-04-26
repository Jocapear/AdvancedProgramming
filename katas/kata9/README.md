###Kata 9: UTF-8 Validation
=================================================================================================

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

    For 1-byte character, the first bit is a 0, followed by its unicode code.
    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range|UTF-8 octet sequence (hexadecimal)|(binary) 0000 0000-0000 007F | 0xxxxxxx     0000 0080-0000 07FF | 110xxxxx 10xxxxxx     0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx     0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.    Return true.  It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.  

Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.    Return false.  The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.  The next byte is a continuation byte which starts with 10 and that's correct.  But the second continuation byte does not start with 10, so it is invalid.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

First, I have to tranform the three numbers into octets of bits. To do that I'm going to have a function a receives a number and returns an array of 8 integers that are only 1 and 0.
To do this function I'm going to create an empty integer array with 8 positions and iterate through it, an accumulator is going to reduce each time it fits into the position number
that is equal to 2^(7-i), if it doesn't fit then I'm going to fill that cell with 0. Each time it fits its filled with a 1 and the accumulator reduced by that value.
The next thing to do is to follow the order accordingly the number of bits, the rules tells me where I can have any number and where I need to have 10's. The rules are the following:
0000 0000-0000 007F | 0xxxxxxx
0000 0080-0000 07FF | 110xxxxx 10xxxxxx     
0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx     
0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  

Depending on each case, I need to check for the starter positions of each array.

Complexity:
The complexity of this solution is O(n) because I only iterate through the whole array.

