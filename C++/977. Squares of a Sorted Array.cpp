#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=pow(nums[i],2);
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
    
    void print(vector<int>& nums){
        for(auto i:nums){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Solution obj;
    
    vector<int> vec = {3,-1,4,0,-2};
    obj.sortedSquares(vec);
    obj.print(vec);
}
