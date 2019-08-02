class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, int>::iterator it;
        
        for(int i = 0; i < numCourses; ++i)
        {
            vector<int> tmp;
            adjlist.push_back(tmp);
        }
        
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            int v1 = prerequisites[i][0], v2 = prerequisites[i][1];
            adjlist[v2].push_back(v1);
            if(indegree.count(v1) > 0) indegree[v1]++;
            else indegree.insert(make_pair(v1, 1));
        }
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree.count(i) == 0) 
            {
                que.push(i);
            }
        }
        
        int cur;
        while(!que.empty())
        {
            cur = que.front();
            que.pop();
            order.push_back(cur);
            for(int i = 0; i < adjlist[cur].size(); ++i)
            {
                for(it = indegree.begin(); it != indegree.end(); ++it)
                {
                    if(it -> first == adjlist[cur][i]) 
                    {
                        it -> second = it -> second - 1; 
                        if(it -> second == 0) que.push(it -> first);
                    }
                }
            }
        }
        if(order.size() < numCourses) {order.clear();}
        return order;
    }

    
private:
    vector<vector<int> > adjlist;
    map<int, int> indegree;
    queue<int> que;
    vector<int> order;
};

// Runtime: 116 ms, faster than 5.06% of C++ online submissions for Course Schedule II.
// Memory Usage: 14.3 MB, less than 54.49% of C++ online submissions for Course Schedule II.

// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
//-----------------------------------------------------------------

// Alg:
// using node indegree 
