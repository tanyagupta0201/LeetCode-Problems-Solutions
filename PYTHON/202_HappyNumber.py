# Name: Srikar MK
# Date: 08/10/2022

class Solution:
    def isHappy(self, n: int) -> bool:
        def nextNum(n):         #function to calculate the sum of the digits and return sum
            total =0
            while n>0:
                t=n%10
                total+=t*t
                n=n//10
            return total 
        
        hashset=set()            #hashset to check for repeated numbers - false if found
        while n!=1 and n not in hashset:
            hashset.add(n)       #adding elements to hashset
            n=nextNum(n)
        return n==1               
