// Name: Tanya Nema
// Date: 31/10/22
class Solution {
  public:
    int hIndex(vector < int > & ct) {
      sort(ct.begin(), ct.end()); // Sort the vector, it becomes 0 1 3 5 6

      int res = 0;

      for (int i = ct.size() - 1; i >= 0; i--) // Start a reverse for loop
      {
        if (res >= ct[i]) // Is 6 less than res = 0 , NO , similarly check for 5
          return res;
        else // in case of 6 and 5 res is incremented.
          res++;
        // But as we reach 3 . 3 >= 3, so return res which is 3
      }

      return res; // This will execute if least number of citations, that is first element of sorted array is h-index 
    }
};