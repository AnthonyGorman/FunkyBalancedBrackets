# Funky Balanced Brackets
By Anthony Gorman
## Overview
Funky Balanced Brackets is an incredibly fun and unconventional solution to the [Balanced Brackets](https://www.hackerrank.com/challenges/balanced-brackets/problem) problem. Typically, the problem is solved using a stack in $O(n)$ time. However, in this implementation I sought to solve the problem recursively while still maintaining $O(n)$ time.
## Approach
Solving this problem recursively usually takes $O(n^2)$
time if it is brute forced. However, in my solution, I double the utility of the return value in order to avoid visiting every bracket n times. The returned integer of the recursive method "funkyBalanced" is the distance to its possible matched bracket. If the final returned distance is odd, then the brackets are balanced. Otherwise, an even distance to brackets is unbalanced. 

In the base case, the left bracket's matching right bracket is one address in memory away, return 1. In the case that the left and right brackets do not match, return 0 indicating that there is no matching bracket. 

If the next bracket is another leftside bracket push it onto the stack frame (call the function recursively). However, at the same time add 2 to its returned distance (effectively popping all of the inside brackets).

Finally, test the next set of brackets if there are any. (adding one to the returned distance maintains parity)

There are many edge cases that return a failure. These can be seen in the implementation.

## Final thoughts
This method should be seen as a fun and unconventional solution to solving a stack problem with the stack frame. It is not an indicator of how I would approach software engineering in a professional setting.
