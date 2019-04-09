class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map_exist;
        map<int, int>::iterator it;
        
        vector<int> ret;
        for(int i = 0; i < nums.size(); ++i)
        {
            it = map_exist.find(target - nums[i]);
            if(it != map_exist.end()) 
            {
                ret.push_back(map_exist[target - nums[i]]);
                ret.push_back(i);
                return ret;
            }
            
            else
            {
                map_exist.insert(pair<int, int>(nums[i], i));
            }
        }
        return ret;
    }
};

// Runtime: 12 ms, faster than 91.00% of C++ online submissions for Two Sum.
// Memory Usage: 10.2 MB, less than 49.66% of C++ online submissions for Two Sum.

// Given an array of integers, return indices of the two numbers 
// such that they add up to a specific target.

// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].