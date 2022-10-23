// Name: Shradha Verma
// Dtae: 23 October 2022

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();
        
        if(n>m){
            return false;       // If length of ransomNote is greater than length of magazine return false.
        }
        
        map<char,int>m1;        // Create a map to store the frequencies of each character of string magazine.
        
        for(int i=0; i<m; i++){
            m1[magazine[i]]++;      // Store the frequencies of string.
        }
    
        for(int i =0; i<n; i++){
            if(m1[ransomNote[i]]>0){        // If character of ransomeNote is present in map, then deduct the frequency of character.
                m1[ransomNote[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};