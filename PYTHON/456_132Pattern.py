# Authon: Dushyant Lavania (github: Dushyant100)
# Date: 30/10/22

def find132pattern(self, nums: List[int]) -> bool:
    currentMin = nums[0]
    s = [] # monotonically decreasing stack, pair [num, minleft]

    for m in nums[1:]:
        while s and m >= s[-1][0]: # stack is not empty, pop values which are on top of stack and are smaller than m
            s.pop()
        if s and m > s[-1][1]: # stack is not empty, check that m is greater than the min value that came before the 2nd index
            return True
        s.append([m, currentMin]) # append the current value of m and its currentMin
        currentMin = min(currentMin, m) # update the currentMin value
    return False