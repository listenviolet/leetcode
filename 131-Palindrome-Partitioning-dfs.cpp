class Solution {
public:
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> path;
        helper(s, 0, path);
        return allRes;
    } 
    
    void helper(string s, int pos, vector<string> &path)
    {
        if(pos == s.size()) allRes.push_back(path);
        string tmp;
        for(int i = pos; i < s.size(); ++i)
        {
            tmp = s.substr(pos, i - pos + 1);
            if(isPalindrome(tmp))
            {
                path.push_back(tmp);
                helper(s, i + 1, path);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s)
    {
        for(int i = 0; i < s.size() / 2; ++i)
        {
            if(s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }
    
private:
    vector<vector<string> > allRes;
};

// Runtime: 68 ms, faster than 34.01% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 26.7 MB, less than 41.57% of C++ online submissions for Palindrome Partitioning.

// Description:
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// Example:

// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

// alg:
// 对于上面的”aab”作为输入，可以这么寻找回文： 
// “a”+”ab”构成的回文串 
// “aa”+”b”构成的回文串 
// “aab”不是回文，所以直接退出。

// 如果前pos个字符串本身是个回文字符，那么只需要求解后面的子字符的回文串即可