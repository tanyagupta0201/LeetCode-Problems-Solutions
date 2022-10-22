// Name: Chamod Nugekotuwa
// Date: 15/10/2022

/* 
Problem Statement:

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

Implementation:

When we traverse through the array, we must check for 3 cases.
1st case - the current element we compare is the fruit that we just picked
2nd case - the current element we compare is the fruit we picked previously, and hence, that element becomes the newly picked fruit.
3rd case - the current element we compare haven't neither been picked at all, therefore, that element becomes the newly picked fruit.

The currentBasketTotal increments each time a fruit of same type is found. We compare this with highestBasketTotal so only the fruit type with higher occurences gets selected ultimately.
*/

class Solution {
    public int totalFruit(int[] tree) {
        int previousFruit = -1;
        int currentFruit = -1;
        int currentFruitCount = 0;

        int currentBasketTotal = 0;
        int highestBasketTotal = 0;

        for (int fruit : tree) {
            if (fruit == currentFruit) {
                currentBasketTotal++;
                currentFruitCount++;
            } else if (fruit == previousFruit) {
                previousFruit = currentFruit;
                currentFruit = fruit;
                currentBasketTotal++;
                currentFruitCount = 1;
            } else {
                previousFruit = currentFruit;
                currentBasketTotal = currentFruitCount + 1;
                currentFruit = fruit;
                currentFruitCount = 1;
            }
            highestBasketTotal = Math.max(highestBasketTotal, currentBasketTotal);
        }
        return highestBasketTotal;
    }
}