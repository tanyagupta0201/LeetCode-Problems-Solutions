class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,n=height.size();
        int mx=height[i],sm=0,area=0,z=0;
        i++;
        while(i!=n){
            if(height[i]>=mx){
                area+=sm;
                sm=0;
                mx=height[i];
                z=i;
            }
            else{
                sm+=mx-height[i];
            }
            i++;
        }
        i=n-1;
        mx=height[i];
        sm=0;
        i--;
        while(i>=z){
            if(height[i]>=mx){
                area+=sm;
                sm=0;
                mx=height[i];
            }
            else{
                sm+=mx-height[i];
            }
            i--;
        }
        return area;
        
    }
};