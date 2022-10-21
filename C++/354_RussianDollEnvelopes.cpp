// Name: Aditya Saha
// Date: 21/10/2022

/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
*/

// Using Binary Search Appoarch

class Solution {
    
    //comparator function
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sorting by height & if we encounter same height
        // sort by descending order of width
        
        sort(envelopes.begin(),envelopes.end(),cmp);
        
        /*
         e.g. -> envelopes => (3,8) (4,5) (2,1) (2,6) (7,8) (5,3) (5,7)
        sorted version => (2,6) (2,1) (3,8) (4,5) (5,7) (5,3) (7,8)
        
        Now, we only need to care about width
        So, as of now we only need to look upon v[i][1]
        [ 6, 1, 8, 5, 7, 3, 8 ]
        
        Now, we can only put envolop A in envolop B another if width of A is
        less than width of B, or we can say we need an envolop whose width
        is just greater than envolop A ( height we have already handled )
        
        */
        
        int n = envelopes.size();
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            int v=ans.size();
            int s=0,e=v-1;
            int k=v;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(ans[mid]>=envelopes[i][1]){
                    k=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            // Here if k==v i.e no element in ans is bigger envelope than current envelope
            // so we can insert the current i (i.e bigger envelope in the ans)
            if(k==v){
                ans.push_back(envelopes[i][1]);
            }
            // this is required to maintain the ans i.e width array in sorted order
            else{
                ans[k]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};