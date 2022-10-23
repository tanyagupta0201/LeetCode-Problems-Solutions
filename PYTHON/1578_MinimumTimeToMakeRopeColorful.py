# NAME : Shubham Arora
# DATE : 23/Oct/2022
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        t = neededTime[0]
        s = 0
        for i in range(1 , len(colors)):
            # finding the maximum of the needed time for both the elements in case they are equal
            if colors[i] == colors[i - 1]:
                t=  max(t , neededTime[i])
            else:
                # adding it to the sum if the elements are not equal
                s += t
                # reinitializing t after every iteration
                t = neededTime[i]
        # adding the time for last element in the sum
        s += t
        # returning the final answer
        return sum(neededTime) - s
