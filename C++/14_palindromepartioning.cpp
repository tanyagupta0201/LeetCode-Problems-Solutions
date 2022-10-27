#include<iostream>
#include<queue>
using namespace std;
bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
void solve(string s, vector<string>out, int idx){
    if(idx==s.size()){
        for(auto it:out){
            cout<<it<<",";
        }
        cout<<endl;
        return;
    }
    for(int i=idx;i<s.size();i++){
        if(isPalindrome(s,idx,i)){
            out.push_back(s.substr(idx, i-idx+1));  
            solve(s,out,idx+1);
            out.pop_back();
        }
    }
}
int main(){
    string s = "aabb";
    vector<string>out;
    int idx=0;
    solve(s,out,idx);

}