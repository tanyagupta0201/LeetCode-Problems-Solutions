// Name: Adarsh Gupta
// Date: 02/10/2022
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int mcnt = 0;
        int len = 0;
        int ar[26] = {0};
        int win_start = 0;
        for(int win_end = 0; win_end<n; win_end++)
        {
            ar[s[win_end]-'A']++;
            int x = ar[s[win_end]-'A'];
            mcnt = max(mcnt, x);
            
            if(win_end - win_start - mcnt + 1 > k)
            {
                ar[s[win_start]-'A']--;
                win_start++;
            }
            
            len = max(len, win_end - win_start + 1);
        }
        return len;
    }
};
