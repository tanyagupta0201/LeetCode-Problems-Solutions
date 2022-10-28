// Name: Souvik Sen
// Date: 29/10/2022

/*
Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

Example 1:
Input: s = "banana"
Output: "ana"

Example 2:
Input: s = "abcd"
Output: ""
*/

#define ll unsigned long long

class Solution {
   private:
    int s_size = 0;
    int p = 31;
    int m = 1e9 + 9;
    string ans = "";

    bool helper(int len, string& s, ll po) {
        unordered_set<ll> memo;
        int l = 0;
        // calculate the first hash of [0--len]
        ll current_hash = 0;
        for (int i = 0; i < len; ++i) {
            current_hash = (current_hash * p) + s[i];
        }
        memo.insert(current_hash);

        // fast rolling hash move-forward
        for (int i = len; i < s_size; ++i) {
            current_hash -= po * s[l];
            current_hash = current_hash * p + s[i];
            ++l;

            if (memo.find(current_hash) != memo.end()) {
                string pick_string = s.substr(l, len);
                if (ans.size() < pick_string.size()) ans = pick_string;
                return true;
            }
            memo.insert(current_hash);
        }
        return false;
    }

   public:
    string longestDupSubstring(string s) {
        s_size = s.size();
        // build power table
        vector<ll> power(s_size, 1);
        for (int i = 1; i < s_size; ++i) power[i] = power[i - 1] * p;

        // binary search on the end index
        int l = 0, r = s_size - 1, mid = 0;
        for (; l <= r; mid = l + (r - l) / 2) {
            if (helper(mid + 1, s, power[mid]))
                l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
};
