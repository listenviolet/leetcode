class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v{1};
        int k2 = 0, k3 = 0, k5 = 0;
        while(--n)
        {
            int val = min(v[k2] * 2, min(v[k3] * 3, v[k5] * 5));
            v.push_back(val);
            while(v[k2] * 2 <= val) k2++;
            while(v[k3] * 3 <= val) k3++;
            while(v[k5] * 5 <= val) k5++;
        }
        
        return v.back();
    }
};

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:  

// 1 is typically treated as an ugly number.
// n does not exceed 1690.

// Runtime: 20 ms, faster than 30.75% of C++ online submissions for Ugly Number II.
// Memory Usage: 11.9 MB, less than 63.16% of C++ online submissions for Ugly Number II.
