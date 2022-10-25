// Name: Tanisha Garg
// Date: 25-10-2022

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // word pointers
        int i = 0, j = 0; 
        // char pointers
        int m = 0, n = 0; 
        // iteration over both string arrays simultaneously
        while (i < word1.size() and j < word2.size()) {  
            // if letter is not equal return false
            if (word1[i][m++] != word2[j][n++])
                return false;
            
            if (m >= word1[i].size())
                i++, m = 0;
            
            if (n >= word2[j].size())
                j++, n = 0;
        }
        // return true if both array size is same
        return i == word1.size() and j == word2.size();
    }
};
