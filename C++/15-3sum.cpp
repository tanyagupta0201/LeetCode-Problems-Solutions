class Solution {
public:
    int bSearch(vector<int>& nums,int l,int h,int k){
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==k){
                return nums[m];
            }
            if(nums[m]<k){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> x;
        int n=nums.size();
        if(n==0 || n==1 || n==2){
            return x;
        }
        sort(nums.begin(),nums.end());
        vector<int>z;
        for(int i=0;i<n-2;i++){
            if(nums[i]==nums[i+2] && nums[i]!=0){
                i++;
            }
            if(nums[i]==0 && i<n-3 && nums[i]==nums[i+3]){
                i++;
            }
            z.push_back(nums[i]);
        }
        z.push_back(nums[n-2]);
        z.push_back(nums[n-1]);
        n=z.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int a = bSearch(z,j+1,n-1,0-(z[i]+z[j]));
                if(a!=-1){
                    vector<int> y(3);
                    y[0]=z[i];
                    y[1]=z[j];
                    y[2]=a;
                    if(x.size()==0){
                        x.push_back(y);
                    }
                    else{
                        int l=1;
                        bool z=false;
                        while(x[x.size()-l][0]==y[0]){
                            if(x[x.size()-l][0]==y[0]&&x[x.size()-l][1]==y[1]){
                                z=true;
                                break;
                            }
                            if(x.size()-l==0){
                                break;
                            }
                            l++;
                        }
                        if(!z){
                            x.push_back(y);
                        }
                    }
                }
            }
        }
        return x;
    }
};