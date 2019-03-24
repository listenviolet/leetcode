class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int, int> Event; 
        // events,  x,   h
        vector<Event> es;        
        hs_.clear();
        
        for (const auto& b : buildings) {
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }
        
        // Sort events by x
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2){
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });
        
        vector<pair<int, int>> ans;
        
        // Process all the events
        for (const auto& e: es) {            
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);
            
            if (entering) {                
                if (h > this->maxHeight()) 
                    ans.emplace_back(x, h);
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if (h > this->maxHeight())
                    ans.emplace_back(x, this->maxHeight());
            }            
        }
        
        return ans;
    }
private:
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }
    multiset<int> hs_;
};

// Question
// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).


// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

// Notes:

// The number of buildings in any input list is guaranteed to be in the range [0, 10000].
// The input list is already sorted in ascending order by the left x position Li.
// The output list must be sorted by the x position.
// There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]

// Solution:
// http://zxi.mytechroad.com/blog/tree/leetcode-218-the-skyline-problem/
// 采用扫描线的方法，对于event，分为进入和退出两种类型
// 进入时，扫描线扫到当前event的height比最高的高时
// 将其放入height中，并将进入点作为标记点
// 退出时，将该event的height从hs中移除，
// 将第二高的（也就是删去height后最高的）作为标记点的高度

// 这里注意两种特殊情况
// 即y1 = x2和 (x1 = x2 && y1 = y2)
// 对于y1 = x2，在sort函数中做了处理，
// 即若相等，则首先处理进入边，再处理退出边
// 避免退出时，将第二小height = 0作为标记点高度

// 对于(x1 = x2 || y1 = y2)
// x1 = x2时，先处理进入边中height最高的
// y1 = y2时，先处理退出边中height最低的

// Beats: 81.84%
// Runtime: 26ms
// hard
