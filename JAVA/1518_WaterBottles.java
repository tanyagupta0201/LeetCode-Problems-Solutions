// Name: Vimu
// Date: 24/10/2022

/* 
There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

Example 1:

Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.

Example 2:

Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.

Code Explanation:

At the start, the maximum number of bottles that can be drunk will be the numBottles, and once drunk, there will be the same amount of emptyBottles (which is maxBottles) and remainingBottles will be 0.

Now we have to loop until there will be atleast 1 empty bottle since:
2 <= numExchange <=100

Inside the loop, the first thing we do is getting full water bottles in exchange empty ones.

Then, the remaining number of bottles will be the remainder of emptyBottles divided by the numExchange. Now we can sum the values of maxBottles with maxBottles + numBottles.

Finally, the number of empty bottles will be the remaining amount of bottles plus the number of full bottles.

Once the empty bottles becomes 0, we'll have the total amount of bottles.
*/

class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int maxBottles = numBottles;
        int emptyBottles = maxBottles;
        int remainingBottles = 0;

        while (emptyBottles / numExchange >= 1) {
            numBottles = emptyBottles / numExchange;
            remainingBottles = emptyBottles % numExchange;
            maxBottles += numBottles;
            emptyBottles = remainingBottles + numBottles;
        }

        return maxBottles;
    }
}