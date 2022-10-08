// Name: Dhruv Arora
// Date: 8/10/2022

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool flag{true};
        map<int,int> m;
        for(int i{0}; i<arr.size(); ++i){
            m[arr.at(i)]++;
        }
        vector<int> count;
        for(auto val : m){
            count.push_back(val.second);
        }
        sort(count.begin(),count.end());
        for(int i{0}; i<count.size()-1; ++i){
            if(count.at(i) == count.at(i+1)){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
