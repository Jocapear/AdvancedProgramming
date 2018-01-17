=========================================================
Kata 0: Two Sum
========================================================

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,    Because nums[0] + nums[1] = 2 + 7 = 9,  return [0, 1].  

------------------------------------------------------------------------------------------------------------
We have to find first the constrains of the problem. On class we narrowed it, im going to write the specific
constraints we found:
-Only positive integers
-The size can be infinite
-Elements cant repeat
-It always has a solution
-The is only one solution
-It is not ordered

Now, to solve this problem first we are going to find a trivial solution. The most basic first step i can
think of is to iterate the whole array. On each element we check the elements in front of him to see if it
is the number we are looking for. The cases are these:
-¿Array size=2? Return [0,1]
-If array[i] >= target then move to next element
- target - array[i] is the number we are looking for, search it iterating in the elements in front

This whole process iterates the array completeley, that give us a O(n). For each element in the worst case
scenario we iterate the elements in front, that is n+(n-1)+(n-2)+...+1; we could reduce that to O(n). So
for an iteration iside and iteration we get a O(n**2).

We could improve the time complexity if we sacrifice memory space with a hash table. First we save each element
in the hash with a value of its index. Now to look for a number we dont need to iterate the array again, we
just have to look the number in the hash table in O(1) instead of O(n). This results in a time complexity of only
O(n) because we dont need to use a second itertion. 