class Solution {
private : 
    /*      Please Upvote if it Helped... :)
    
    Explanation :  
    1.Firstly, Sort the array. 
    2.Now fix two pointers, and so our new target will be : req = t - (v[i] + v[j]). 
    3.Now int the rest of the array ahead, we can fix two-pointers, low and high, and use a two-pointer to find the remaining two numbers of the quadruplet. 
    4.To avoid duplicates, we can skip the same elements by running a loop. 
    5.we jump the duplicates, because taking duplicates will result in repeating quadruplets. 
    */
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        vector<vector<int>> ans;
        int n = v.size();
        sort(v.begin(), v.end());
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long long req = (long long)t - (v[i] + v[j]);
                int low = j+1, high = n-1;
                
                while(low < high) {
                    int curr = v[low] + v[high];
                    if(curr > req) high--;
                    else if(curr < req) low++;
                    else {
                        ans.push_back({v[i], v[j], v[low], v[high]});
                        
                        while(low < high && v[low] == ans.back()[2]) ++low;
                        while(low < high && v[high] == ans.back()[3]) --high;
                    }
                }
                
                while(j+1<n && v[j] == v[j+1]) ++j;
                
            }
            
            while(i+1<n && v[i] == v[i+1]) ++i;
        }
        
        return ans;
    }
};