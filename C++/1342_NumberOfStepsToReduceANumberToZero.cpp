class Solution {
public:
    int numberOfSteps(int num) {
       long int count=0;
        
        while(num!=0){
            if(num%2==0){
                num=num/2;}
            else{
                num=num-1;
                }
            count=count+1;
        }
        
        return count;
    }
};
