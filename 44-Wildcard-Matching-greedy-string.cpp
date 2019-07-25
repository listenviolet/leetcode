class Solution {
public:
    bool isMatch(string s, string p) {
        int star = -1;
        int ss = 0, i = 0, j = 0;
        while(i < s.size())
        {
            if(p[j] == '?' || s[i] == p[j]) {++i; ++j; continue;}
            if(p[j] == '*') {star = j++; ss = i; continue;}
            if(star >= 0) {j = star + 1; i = ++ss; continue;}
            return false;
        }
        
        while(p[j] == '*') {j++;}
        return j == p.size();
    }
};

// hard
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like ? or *.
// Example 1:

// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
// Example 4:

// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
// Example 5:

// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false

// Runtime: 8 ms, faster than 93.39% of C++ online submissions for Wildcard Matching.
// Memory Usage: 8.7 MB, less than 90.59% of C++ online submissions for Wildcard Matching.

// http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html

/** My summary:
**/
// ss = i marks the current s[i] matches p[j] where p[j - 1] = '*', this indicates that s[ss] is outside of *;
// star marks the current * pos;
// if the left part doesn't match, then go back let the s[ss] be inside of *

//--------------------------------------------------
/** Blogger's analysis:
**/
// For each element in s
// If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
// If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
// If not match, then we check if there is a * previously showed up,
//        if there is no *,  return false;
//        if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.

// e.g.

// abed
// ?b*d**

// a=?, go on, b=b, go on,
// e=*, save * position star=3, save s position ss = 3, p++
// e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
// d=d, go on, meet the end.
// check the rest element in p, if all are *, true, else false;

// Note that in char array, the last is NOT NULL, to check the end, use  "*p"  or "*p=='\0'".