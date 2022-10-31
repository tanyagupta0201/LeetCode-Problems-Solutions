class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Take length of both the strings in n1 and n2
        int n1 = version1.length();
        int n2  = version2.length();
        
        // Take two variables i and j for running a loop though both the strings.
        int i = 0, j = 0;
        
        // Take sum1 and sum2 for storing the summation of string(Converted to integers)
        int sum1 = 0, sum2 = 0;
        
        // Run while loop until any one of the string is having, length not equals to zero. 
        while(i < n1 || j < n2){
            
            // Calculate sum1 from version1 until '.' character.
            while(i < n1 && version1[i] != '.'){
                sum1 = sum1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Calculate sum2 from version2 until '.' character.
            while(j < n2 && version2[j] != '.'){
                sum2 = sum2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // Compair sum1 and sum2
            if(sum1 > sum2){
                return 1;
            }else if(sum1 < sum2){
                return -1;
            }
            
            // Re initialise sum1 and sum2 with zero for calulating next part of version.
            sum1 = 0; 
            sum2 = 0;
            
            // Increment i and j
            i++; 
            j++;
        }
        return 0;
    }
};
