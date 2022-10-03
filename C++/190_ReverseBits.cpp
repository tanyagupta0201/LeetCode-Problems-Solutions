// Name : Simarprit Singh Virdi
// Date : Date: 03/10/2022

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=1;i<=32;i++) //iterate till length of the number here len= 32 bit
        {
            ans<<=1;
            ans=ans|(n&1);//adding 1/0 as needed to reverse bit
            n>>=1; //shifting the original number for accessing each bit
        }
        return ans;
    }
};
