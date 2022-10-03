/*Name -:Jai Sinha
  Date-:03-10-2022 */

//Question
//to convert one string to another by deleting,updating,replacing the characters of  the first string in minimum moves


#include<bits/stdc++.h>
using namespace std;
int editDistance(string str1, string str2)
{
    //doing space optimization
    int n=str1.length();
    int m=str2.length();
    vector<int> pre(m+1,0);         //creating a pre vector
    for(int i=0;i<=m;i++)
        pre[i]=i;            //initializing the pre vector by i
    for(int i=1;i<=n;i++)
    {
        vector<int> temp(m+1,0);     //making a temperorary vector
        temp[0]=i;                
        for(int j=1;j<=m;j++)
        {
          if(str1[i-1]==str2[j-1])  //if the previous elements are equal
           temp[j]= pre[j-1];       store the value
            else
          temp[j]=1+min(pre[j],min(temp[j-1],pre[j-1]));  //else store the minimum of the elements 
        }
        pre=temp;  //now==>previous vector becomes temp vector
    }
    return pre[m];
}
//main function
int main()
{
  string s;
  cin>>s;
 string s2;
 cin>>s2;
  return editDistance(s,s2);   //calling function
}

