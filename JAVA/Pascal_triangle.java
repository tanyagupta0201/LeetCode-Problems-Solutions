
/*
Name : Charu Dhingra
Date :  02.10.2022
*/
import java.util.ArrayList;
import java.util.List;

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:
// 1
// 1 2 1
// 1 3 3 1
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> rowArray = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> colArray = new ArrayList<>();

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    // Every Column's First and Last Element are filled with 1
                    colArray.add(1);
                } else {
                    // Addition of previous Row's First two elements then second two elements , and
                    // so on
                    colArray.add(j, rowArray.get(i - 1).get(j - 1) + rowArray.get(i - 1).get(j));
                }
            }

            rowArray.add(colArray);
        }
        return rowArray;
    }
}