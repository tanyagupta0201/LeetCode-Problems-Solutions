// Name: Jyotideep Acharjee
// Date: 18/10/2022

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(palindrome.size()<=1) return "";
        
        string s = palindrome;
        int f = 0;
        for(int i=0;i<n/2;i++){
            //replave non - a char with a :
            if(s[i] != 'a'){
                f = 1;
                s[i] = 'a';
                return s;
            }
        }
        
        //if there are all 'a's then replace last with 'b' :
        if(!f) s[n-1] = 'b';
        return s;
    }
};
