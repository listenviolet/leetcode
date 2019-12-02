class Solution {
public:
    void computeLPSArray(string pat, int M, int *lps)
    {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < M)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            
            else
            {
                if(len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        int M = needle.size();
        int N = haystack.size();
        
        if(needle.empty() || M == 0) return 0;
        int lps[M];
        
        computeLPSArray(needle, M, lps);
        
        int i = 0, j = 0;
        while(i < N)
        {
            if(haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            
            if(j == M)
            {
                return i - M;
            }
            
            if(i < N && haystack[i] != needle[j])
            {
                if(j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        
        return -1;
    }
    
};

// Alg:
// KMP
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

// Runtime: 4 ms, faster than 90.57% of C++ online submissions for Implement strStr().
// Memory Usage: 9.2 MB, less than 51.43% of C++ online submissions for Implement strStr().

// Description

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().