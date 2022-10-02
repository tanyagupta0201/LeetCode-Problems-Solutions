//Name: Anikalp Jaiswal
// Date: 02/10/2022

 class Solution {
public:
    int jump(vector<int>& N) {
        int len = N.size() - 1, curr = -1, next = 0, ans = 0;
        for (int i = 0; next < len; i++) {
            if (i > curr) ans++, curr = next;
            next = max(next, N[i] + i);
        };
        return ans;
    }
};
        
