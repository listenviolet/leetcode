const int maxn = 1000;
struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
};

struct VNode
{
    int data;
    ArcNode *firstarc;
};
struct Graph
{
    vector<VNode> adjlist;
    int n, e;
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph G;
        G.n = numCourses;
        G.e = prerequisites.size();
        for(int i = 0; i < numCourses; ++i)
        {
            VNode *node = new VNode();
            node -> data = i;
            node -> firstarc = nullptr;
            G.adjlist.push_back(*node);
        }
        
        for(int i = 0; i < prerequisites.size(); ++i)
        {
            int v1 = prerequisites[i][0], v2 = prerequisites[i][1];
            ArcNode *arcnode = new ArcNode();
            arcnode -> adjvex = v1;
            arcnode -> nextarc = G.adjlist[v2].firstarc;
            G.adjlist[v2].firstarc = arcnode;
        }
        

        for(int i = 0; i < numCourses; ++i)
        {
            visit.push_back(0);
        }
        
        int flag = 1;
        for(int i = 0; i < numCourses; ++i)
        {
            flag = dfs(&G, i);
            if(flag == 0) return order;
        }
        
        while(!st.empty())
        {
            int cur = st.top();
            st.pop();
            order.push_back(cur);
        }
        
        return order;
        
    }
    
    int dfs(Graph *G, int v)
    {
        if(visit[v] > 0) return 1;
        
        ArcNode *arcnode = nullptr;
        visit[v] = 1;
        
        arcnode = G -> adjlist[v].firstarc;
        int flag = 1;
        while(arcnode != NULL)
        {
            if(visit[arcnode -> adjvex] == 0){ flag = dfs(G, arcnode -> adjvex); if(flag == 0) return flag;}
            if(visit[arcnode -> adjvex] == 1) return 0;
            arcnode = arcnode -> nextarc;
        }
        
        visit[v] = 2;
        st.push(v);
        return flag;
    }
    
private:
    stack<int> st;
    vector<int> visit;
    vector<int> order;
};

// Runtime: 20 ms, faster than 96.52% of C++ online submissions for Course Schedule II.
// Memory Usage: 14.1 MB, less than 61.80% of C++ online submissions for Course Schedule II.

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
// dfs
// not visited: 0
// in process: 1
// all of its neighs have been visited: 2 and push to stack
// the order of stack popping is the result.
// input (v1, v2) means the order has to be: v2 -> v1
// the adjacency list:
// source -> target1 -> target2 -> ,,,
// if all the arcnodes have been processed (means the neighbors have been in stack), then push source to stack; 
// as "last in first out", the source will be popped first -> will be processed first.

// Notice:
// the judgement for cyclic graph is arcnode's visit is 1
// Time complexity: O(n)
// Space complsxity: O(n)