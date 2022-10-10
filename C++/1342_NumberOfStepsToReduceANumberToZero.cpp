//Name: Arshya Garg
//Date: 10-10-2022

//This problems states to return the number of steps to reduce it to zero. In one step, if the if the current number is even, it has to be divided by 2, otherwise,it should be subtracted by 1.
// Here a public function named numberOfSteps is created in class which returns an integer
class Solution {
public:
    int numberOfSteps(int num) {
       long int count=0;
        // here long int is taken since steps can range from 0 to 10^6.
        while(num!=0){
            if(num%2==0){                 //% sign gives the remainder when two numbers are divided and for even number, when it is divided by 2 , it gives 0 as remainder
                num=num/2;}
            else{                  // when odd number is divided by 2, it gives 1 as remainder 
                num=num-1;
                }
            count=count+1;      // here count is added by 1 since the last step where num becomes zero cannot be satisfied in above conditions.
        }
        
        return count;     // int is returned
    }
};
