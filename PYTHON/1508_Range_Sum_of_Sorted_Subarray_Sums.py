# Author: Atharv Patil
# Date: 18.10.22


def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
    l = []
    n = len(nums)
    for i in range(1, n+1):
        for j in range(n-i+1):
            l.append(sum(nums[j:j+i]))
    l.sort()
    for i in range(1, len(l)):
        l[i] += l[i-1]

    if left == 1:
        return (l[right-1]) % (10**9+7)
    else:
        return (l[right-1]-l[left-2]) % (10**9+7)
