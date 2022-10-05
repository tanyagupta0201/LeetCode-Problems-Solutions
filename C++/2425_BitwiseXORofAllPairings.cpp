class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int x1 = 0,x2 = 0;
        for(auto a : nums1)
            x1 = x1^a;
        
        for(auto a : nums2)
            x2 = x2^a;
        if(n1 % 2 == 0 && n2 % 2 == 0)
            return 0;
        else if(n1 % 2 == 0 && n2 % 2 == 1)
            return x1;
        else if(n1 % 2 == 1 && n2 % 2 == 0)
            return x2;
        else 
            return x1^x2;
    }
};
