/* 
   Author Name: Ashutosh Datt Sharma
   Date: 5 October 2022
*/

class Solution {
  public:
    vector < vector < int >> merge(vector < vector < int >> & intervals) {
      vector < vector < int >> res;
      if (intervals.size() == 0) {
        return res;
      }
      sort(intervals.begin(), intervals.end());
      vector < int > tmp = intervals[0];
      for (auto a: intervals) {
        if (a[0] <= tmp[1]) {
          tmp[1] = max(a[1], tmp[1]);
        } else {
          res.push_back(tmp);
          tmp = a;
        }
      }
      res.push_back(tmp);
      return res;
    }
};