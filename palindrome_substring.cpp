#include <iostream>

using namespace std;

/*
Useful code for some palindrome questions

dp[i][j] = True if substr(i,j) is a palindrome

Better than that every index expansion code I used before

We want to build up our dp by the length of palidnromes. A palindrome of length 5
requires a palindrome of length 3 inside it. We can re-use the previous 
recalculation. Honestly, it is kinda similar to the self expansion code. Where
if we don't find a palindrom of length 3, we can't find a palindrom of length 5

Questions you can solve with this:
- Maximum non-overlapping palindromes of atleast length k
    - Whenever you add a new palindrome, if it's atleast lenght k chuck it into
    a vector. Then you have palindrome intervals and it's just a greedy max
    interval question by sorting the end points
- Protein folding question
    - I don't quite remember the question but I think we're counting palindromes
    that can be folded on top of itself. This is basically only possible if one
    of the ends (or both) are touching the ends. This solution might even be
    a bit too overkill. But the same idea of dp applies to that question
*/

bool dp[1005][1005];

void palindrome_substrings(string s)
{

    // For palindromes of length l
    for (int l = 1; l <= s.size(); ++l)
    {
        // Starting at i
        for (int i = 0; i <= s.size() - l; ++i)
        {

            // If the length is less than 2, we only have to compare once
            if (l <= 2)
            {
                if (s[i] == s[i + l - 1])
                    dp[i][i + l - 1] = true;
            }
            else if (s[i] == s[i + l - 1])
            {
                dp[i][i + l - 1] = dp[i + 1][i + l - 2];
            }
        }
    }
}