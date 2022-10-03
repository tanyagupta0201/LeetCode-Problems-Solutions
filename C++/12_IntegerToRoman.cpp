// Name: Adarsh Gupta
// Date: 03/10/2022

class Solution {
public:
    string intToRoman(int n) {
 string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string ans = "";
for (int i = 0; i < 13; ++i)
{
    while(n-nums[i]>=0)
    {
        ans = ans + romans[i];
        n = n - nums[i];
    }
}
return ans;
    }
};
