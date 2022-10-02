// Name: Rohan Raju Meshram
// Date: 03-10-2022

/* 
Logic : The main idea is, if there is a negative sign. 
        You wanted to make the value to be as minimum as possible 
        when you ignore the negative sign.
*/

class Solution {
public:
    string maxValue(string n, int x) {
        int len = n.size()-1;
        int ans = len+1;
        if(n[0]=='-'){
           for(int i = len; i>=1; --i){
                if(n[i]-'0'>x)ans = i;
            }
        }
        else {
            for(int i = len; i>=0; --i){
                if(n[i]-'0'<x)ans = i;
            } 
        }
        n.insert(n.begin()+ans,x+'0');
        return n;
    }
};
