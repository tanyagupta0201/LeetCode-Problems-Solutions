import java.util.List;

// Name: Vimu
// Date: 21/10/2022

/* 
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.

Code Explanation:

The code is fairly self explanatory. We use a counter integer: i, to track the current index of the array so we can use the necesarry calculation that also includes getting the previous value from array: res.

The if cases are based on the conditions provided in the question, and we do the required element addition or removal to/from the array, based on the condition.

Once the array is filled with the operations provided, we get the sum of the integer values inside the array, which will be our answer.
*/

class Solution {
    public int calPoints(String[] operations) {
        List<Integer> res = new ArrayList<>();
        int i = 0;
        for (String s : operations) {
            if (s.matches("^[+-]?\\d+$")) {
                res.add(Integer.parseInt(s));
                i++;
            } else if (s.equals("+") && i > 1) {
                res.add(res.get(i - 1) + res.get(i - 2));
                i++;
            } else if (s.equals("D") && i > 0) {
                res.add(res.get(i - 1) * 2);
                i++;
            } else if (s.equals("C") && i > 0) {
                res.remove(i - 1);
                i--;
            }
        }
        return res.stream().mapToInt(Integer::intValue).sum();
    }
}