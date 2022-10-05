//Name : Harsh Bhatt
//Date: 05-10-2022

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr){
            m[i]++;
                        
        }
        
        int res=-1;
        for(auto i:m){
            if(i.first==i.second){
                res = max(res,i.first);
            }
            
            
        }
        return res;
    }
};