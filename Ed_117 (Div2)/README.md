## Educational Codeforces Round 117 (Rated for Div. 2)

### A
This question gives you a point (x,y) and asks if you can find a point D that lies half way between (x,y) and the origin using manhattan distance.

As our co-ordinates are integers, if the point (x,y) is odd, we will not have a solution.

Manhattan distance does not treat x and y distances differently so to find a point at the half way point we simply subtract x and y until we've subtracted away half of the original distance (x + y).

### B

The wording of this question is a bit strange but the actual problem is not too difficult. Given two numbers a and b, can we find n / 2 - 1 numbers that are larger and smaller respectively. If there are, we print them out as a permutation. 

Only edge case is the case where the other number takes away from the possible numbers in which the coniditon is you need ot find n / 2 numbers.

### C

This question is once again another math question. First case is the case where the entire triangle can be printed. We can find how many emotes are needed to print the triangle using arithmetic summation (a + b) * n / 2. For the entire triangle it would take sum(k) + sum(k-1) emotes. If our condition is greater than this, we can just print out the triangle.

If our condition is less than sum(k), we can only print a portion of the first half of the triangle. We can find the largest triangle we can print using a binary search.

If our condition is greater than sum(k), we subtract away sum(k) and do another binary search but reversed to find how much of the second half of the triangle we can type.