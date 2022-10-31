// Name-Ishita Agrawal
// Date: 29/10/2022

class Solution {

public:
    bool isPowerOfFour(int n) {
        int i;
        for(i=0;i<16;i++){
            int ans=pow(4,i);
            if(ans==n)
                return true;
        }
        return false;
    }
};