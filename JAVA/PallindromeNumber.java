class Solution {
    public boolean isPalindrome(int x) {
          if(x<0){
		        return false;
		    }
        int temp = x;
        int remain = 0;
        int rev = 0;
        while(temp!=0){
            remain=temp%10;
            rev=(rev*10)+remain;
            temp = temp / 10;
        }
        if(rev==x) return true;
        else return false;
    }
}