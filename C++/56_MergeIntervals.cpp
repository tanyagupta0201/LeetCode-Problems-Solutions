// Name: Shradha Verma
// Date: 22 October 2022

class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2)
    {
        return v1[0] < v2[0];   // Sort intervals array in increasing order.
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        
        sort(intervals.begin(), intervals.end(), cmp);   // Sort according to cmp function.

        for(int i = 0; i < intervals.size(); ++i){
            vector<int> res = intervals[i];
            while(i + 1 < intervals.size() && intervals[i + 1][0] <= res[1]) {     // Check which intervals are lapping.
                if(intervals[i + 1][1] > res[1]) {
                        res[1] = intervals[i + 1][1];     // Merge the overlapping intervals.
                }
                 ++i;
            }
            v.push_back(res);   // Push the overlapped intervals to resultant vector.
        }
        
        return v;
    }
};
