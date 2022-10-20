//My Understandble Code

class Solution {
    public int countOdds(int low, int high) {
        int numberOfOdd = 0;
        // for odd checking only
        if (low % 2 == 1 || high % 2 == 1) {
            // use this formula
            numberOfOdd = (high - low) / 2 + 1;

        } else {
            // in case of high and low both is even then,
            // use this formula
            numberOfOdd = (high - low) / 2;

        }
        return numberOfOdd;

    }
}
    