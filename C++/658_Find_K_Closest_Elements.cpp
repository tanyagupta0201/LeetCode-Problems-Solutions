// Name: Shubham Kushwaha
// Date: 22 Oct, 2022

class Solution {
  public:
    vector < int > findClosestElements(vector <int> &arr, int k, int x) {
      priority_queue <pair <int,int>> m;

      // We are taking a priority queue(max heap) because we want to find the closest elements.

      for (int i = 0; i < arr.size(); i++) {
        m.push({
          abs(arr[i] - x),
          arr[i]
        });

        // if the size of the priority queue is greater then k 
        // we pop the top element

        if (m.size() > k)
          m.pop();
      }

      vector < int > ans;
      while (m.size() > 0) {
        // Storing value in ans vector 
        ans.push_back(m.top().second);
        m.pop();
      }

      // We have to return the answer in the ascending order so we sort the ans vector

      sort(ans.begin(), ans.end());
      return ans;
    }
};