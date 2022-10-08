class Solution {
public:
    bool isHappy(int n) {
        int x=n;
        int sum=0;
        while(x){
           // sum=0;
            int h=x%10;
            sum+=h*h;
            x=x/10;
        }
        if(sum==1||sum==7)
            return true;
        else if(sum<10)
            return false;
        else
            return isHappy(sum);
        
    }
};
