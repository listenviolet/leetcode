class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // cout << s << endl;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(s.empty()) return 0;
        map<char, int> d;
        map<char, int>::iterator it;
        int start = 0;
        int count = 0;
        int maxlength = INT_MIN;
        for(int i = 0; i < s.size();++i)
        {
            it = d.find(s[i]);
            if(it != d.end() && it->second >= start)
            {
                count = i - it->second;
                start = it->second + 1;
            }
            else count++;
            d[s[i]] = i;
            if(count > maxlength)
            {
                maxlength = count;
            }
        } 
        return maxlength;
    }
};

// Runtime: 32 ms, faster than 55.28% of C++ online submissions 
// Memory Usage: 10.7 MB, less than 98.92% of C++ online submissions

// After add:
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// Runtime: 16 ms, faster than 95.32% of C++ online submissions 
// Memory Usage: 10.8 MB, less than 98.81% of C++ online submissions

// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, 
//              "pwke" is a subsequence and not a substring.
