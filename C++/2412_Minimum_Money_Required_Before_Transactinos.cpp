 long long minimumMoney(vector<vector<int>>& A) {
        long long res = 0; int v = 0;
        for (auto& a : A) {
            v = max(v, min(a[0], a[1]));
            res += max(a[0] - a[1], 0);
        }
        return res + v;
    }
