class Solution {
public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        s.erase(remove_if (s.begin(), s.end(), static_cast<int(*)(int)>(&ispunct) ), s.end());
        
        s.erase(remove_if(s.begin(), s.end(), static_cast<int(*)(int)>(&isspace) ), s.end());
        
        for(auto &c : s)
        {
            c = tolower(c);
        }
        
        for(int i = 0; i < s.size() / 2; ++i)
        {
            if(s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }
};

// Given a string, determine if it is a palindrome, 
// considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, 
// we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false