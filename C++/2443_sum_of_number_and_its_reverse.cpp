class Solution {
public:
    bool sumOfNumberAndReverse(int n) {
        int i;
        if(n==0)
            return 1;
        for(i=1;i<=n;i++)
        {
            int d,r=0,p=i;
            while(p>0)
            {
                d=p%10;
                r=r*10+d;
                p=p/10;
            }
            if((r+i)==n)
                return 1;
        }
        return 0;
    }
};
