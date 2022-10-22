// Name: Rohan Sharma
// Date: 22/10/22
class Solution {
public:
// Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. 
// If there is no answer return an empty string.
// Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.

  //https://leetcode.com/problems/largest-multiple-of-three/description/
  
  // Approach: Identify if current sum of digits give remainder 0, 1 or 2 when divided by 3.
  // If they give remainder 0, just sort the digits in descending order, append to string and return ans.
  // If the give remainder 1, try removing smallest possible number which gives remainder 1 , delete the number ,sort in descending order and return
      // If not able to find a remainder 1 number, delete 2 numbers with remainder 2 as (2+2)%3 = 1.
  //Similarily for sum%3=2, find either 1 number with remainder 2 or two numbers with remainder 1 and delete them.
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.rbegin(),digits.rend());
        int sum = 0;
      // calculating sum
        for(int  x: digits){
            sum+=x;
        }
      //trivial case
        if(sum%3  == 0){
            string ans = "";
            for(int x: digits) ans.push_back('0'+x);
            if(ans[0]=='0') return "0";
            return ans;
        }else if(sum%3 == 2){
            int ig1 = -1;
            int ig2 = -1;
            int ideal = -1;
            for(int i =digits.size()-1;i>=0;i--){
                if(digits[i]%3 == 2){
                    ideal = i;
                    break;
                }else if(digits[i]%3 == 1){
                    if(ig1 == -1) ig1 = i;
                    else if(ig2 == -1) ig2 = i;
                }
            }
            if(ig2 ==-1 && ig1 == -1 && ideal == -1) return "";
            if(ideal == -1 && (ig1 ==-1 || ig2 == -1)) return "";
            string ans = "";
            if(ideal != -1){
                for(int i = 0;i<digits.size();i++) if(ideal!=i) ans.push_back('0'+digits[i]);
                if(ans[0]=='0') return "0";
                return ans;
            }
            for(int i = 0;i<digits.size();i++) if(i != ig1 && i!=ig2) ans.push_back('0'+digits[i]);
          // Handling 0 leading digits case.
            if(ans[0]=='0') return "0";
            return ans;
        }else{
            int ig1 = -1;
            int ig2 = -1;
            int ideal = -1;
            for(int i =digits.size()-1;i>=0;i--){
                if(digits[i]%3 == 1){
                    ideal=i;
                    break;
                }else if(digits[i]%3 == 2){
                    if(ig1 == -1) ig1 = i;
                    else if(ig2 == -1)ig2 = i;
                }
            }
            if(ideal == -1 && ig2 ==-1 && ig1 == -1 ) return "";
            if(ideal == -1 && (ig1 ==-1 || ig2 == -1)) return "";
            string ans = "";
            if(ideal != -1){
                for(int i = 0;i<digits.size();i++) if(ideal!=i) ans.push_back('0'+digits[i]);
                if(ans[0]=='0') return "0";
                return ans;
            }
            for(int i = 0;i<digits.size();i++) if(i != ig1 && i!=ig2) ans.push_back('0'+digits[i]);
            if(ans[0]=='0') return "0";
            return ans;
        }
        return "";
    }
};
