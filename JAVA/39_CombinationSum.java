// Name: Kumar Shanu
// Date: 04/10/2022

// The logic is absolutely simple.
// We are starting from index 0 of the array.
// Then we are including the element in found arraylist, if target value is <= element 
// and also reduce the target to target-value of element.
// Once the condition (target<=arr[indx]) is not fulfilled or the leftmost recursion is over,
// we will move to the next element by incrementing the index.
// Once the index value == length of array we will check whether the target is equal to 0 or not
// as we are decrementing the target after including it in the found list.
// If the target is 0 then add this list into list<list<Integer>> which will be our result.

class Solution {

    public void combine(int indx, int arr[], int target, List<List<Integer>> result, List<Integer> found) {

        if (indx == arr.length) {
            if (target == 0) {
                result.add(new ArrayList<>(found));
            }
            return;
        }

        // checking to evaluate so that the number target should not exceed
        if (target >= arr[indx]) {
            found.add(arr[indx]);
            combine(indx, arr, target - arr[indx], result, found);
            found.remove(found.size() - 1);
        }

        combine(indx + 1, arr, target, result, found);

    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> result = new ArrayList<>();
        combine(0, candidates, target, result, new ArrayList<>());
        return result;

    }
}
