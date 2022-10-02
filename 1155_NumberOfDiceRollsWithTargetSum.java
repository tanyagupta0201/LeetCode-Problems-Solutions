/*
NAME :  Nikhil Sharma<br>
GITHUB : github.com/NikhilCode12<br>
INSTITUTE/COMPANY : Maharaja Surajmal Institute of Technology<br>
DOMAIN/LANGUGAE : JAVA<br>
*/

class Solution {
    int mod=(int)(Math.pow(10,9))+7;
    public int numRollsToTarget(int d, int f, int target) {
        int dp[][]=new int[d+1][target+1];
        for(int arr[]:dp){
            Arrays.fill(arr,-1);
        }
        return helper(d,f,target,dp);
    }
    
    private int helper(int d,int f,int target,int dp[][]){
	
      // base condition if dice and target are zero return 1 as the output is seen 
      
      if(d==0 && target==0){
            return 1;
        }
		
      // the sum is not obtained
      
        if(target<0 || d==0){
            return 0;
        }
        if(dp[d][target]!=-1){
            return dp[d][target];
        }
        int ans=0;
        for(int i=1;i<=f;i++){
            ans=(ans%mod+helper(d-1,f,target-i,dp)%mod)%mod;
        }
        return dp[d][target]= ans;
    }
}
