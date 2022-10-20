class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>res;
        map<string,vector<string>>mp;
        for(int i=0;i<str.size();i++)
        {
            string s = str[i];
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end())
            {
              mp[s].push_back(str[i]);
            }
            else
            {
              mp.insert({s,{str[i]}});
            }
        }
        for(auto i:mp)
        {
          res.push_back(i.second);
        }
      return res;
    }
};
