class Solution {
public:
    string doSum(string a, string b)
    {
        if(a.size() < b.size())
            swap(a, b);
    
        int j = a.size()-1;
        for(int i=b.size()-1; i>=0; i--, j--)
            a[j]+=(b[i]-'0');
    
        for(int i=a.size()-1; i>0; i--){
            if(a[i] > '9'){
                int d = a[i]-'0';
                a[i-1] = ((a[i-1]-'0') + d/10) + '0';
                a[i] = (d%10)+'0';
            }
        }
        if(a[0] > '9'){
            string k;
            k+=a[0];
            a[0] = ((a[0]-'0')%10)+'0';
            k[0] = ((k[0]-'0')/10)+'0';
            a = k+a;
        }
        return a;
    }
    string multiply(string num1, string num2) {
        string t="",u="";
        int i=num1.length()-1;
        int j;
        int a,x;
        while(i>=0){
            t="";
            for(int k=i;k<num1.length()-1;k++){
                t='0'+t;
            }
            a=0;
            j=num2.length()-1;
            while(j>=0){
                x=(num2[j]-48)*(num1[i]-48)+a;
                a=0;
                if(x<10){
                    t=char(x+48)+t;
                }
                else{
                    t=char((x%10)+48)+t;
                    a=x/10;
                }
                j--;
            }
            if(a>0){
                t=char(a+48)+t;
            }
            u=doSum(t,u);
            i--;
        }
        i=0;
        while(u[i]=='0'){
            i++;
        }
        string l= "";
        while(i<u.length()){
            l=l+u[i];
            i++;
        }
        if(l==""){
            l="0";
        }
        return l;
    }
};