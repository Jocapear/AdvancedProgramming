=========================================================
Kata 1: 760. Find Anagram Mappings
========================================================

Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]  B = [50, 12, 32, 46, 28]  

We should return

[1, 4, 3, 2, 0]  

as  P[0] = 1 because the  0th element of  A appears at  B[1], and  P[1] = 4 because the  1st element of  A appears at  B[4], and so on.

Note:

    A, B have equal lengths in range [1, 100].
    A[i], B[i] are integers in range [0, 10^5].


------------------------------------------------------------------------------------------------------------
Constrains:
- The same element can be repeated
- Only numbers
- The output is an array
- There is at least one solution

Now i'm going to try to find the easiest solution. As we return the index in B of the element in A I think it's logic to iterate at
A first, then look for the same item in B and save the index in the same poistion as the item in A. This basic search iterates each
array one time in the worst case scenario.

This solves the most basic case but now I have to think as if there where repeated elements. In the past solution as the search
starts at the beginning of the array the repeated elements are going to return the same index, where the element is found in B first.
A = [12, 28, 12, 32, 50]  B = [50, 12, 32, 12, 28]  <-- Example with repeated elements
A very basic reasoning would be to check in the resulting array if the index is repeating itself; if it is, then is a repeated element
and it should resume the search at B, if it is not, then it is the first time it appears and we can stop looking. Comparing this
solution to the last one, this solution just adds another O(n) search because of the iteration in the result array. That give us
a very inneficient algorithm of O(n**3).

We can find a better solution if we use a hash table that knows the index in B of every value. To do that we first have to initialize
the hash table, we iterate all B and for every value used as a key we store in the value of the hash table the index. For repeated
elements we just have to store multiple values in the same index of the hash table. The initialization cost O(n) because we iterate
all the B array. Now all we have to do is for each element in A, we look its index in the hash table with cost of O(1) and put it in
the result array. To avoid repeating the same index each time we get an index in the hashing table we can delete it, that way we can 
handle repeated elements. We need to iterate again A and that costs another O(n). For the whole program we get O(n)+O(n), thus we get
only a O(n) complexity.

**Unfortunately, I don´t know how to implement a hashing table in C yet, so my code solution is going to be for the second aproach.  





