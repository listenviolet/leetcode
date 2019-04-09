class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(candidates, target, tmp);
        return allRes;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& tmp)
    {
        if(target == 0) 
        {
            allRes.push_back(tmp);
        }
        
        for(int i = 0; i < candidates.size(); ++i)
        {
            if(target >= candidates[i])
            {
                tmp.push_back(candidates[i]);
                vector<int> copy_candidates;
                copy_candidates.assign(candidates.begin() + i, candidates.end());
                dfs(copy_candidates, target - candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
private:
    vector<vector<int>> allRes;
};

// Runtime: 20 ms, faster than 62.47% of C++ online submissions for Combination Sum.
// Memory Usage: 11.8 MB, less than 48.38% of C++ online submissions for Combination Sum.

// Given a set of candidate numbers (candidates) (without duplicates) 
// and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]