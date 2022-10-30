class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> x(numRows,"");
        int i=0,n=s.length(),flag=0,j=0;
        while(i!=s.length()){
            if(j==-1){
                j=1;
                flag=0;
            }
            else if(j==numRows){
                j=numRows-2;
                flag=1;
            }
            x[j]+=s[i];
            if(flag) j--;
            else j++;
            i++;
        }
        string e="";
        for(int i=0;i<numRows;i++){
            e+=x[i];
        }
        return e;
    }
};