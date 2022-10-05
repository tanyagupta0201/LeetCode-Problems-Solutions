# Print a solid rectangle
'''
* * * *
* * * *
* * * *
* * * *
* * * *
'''

'''
Logic : let n = 5 (Total Numbers of rows)
By Oberving the pattern we conclude one thing that is :
if row == n then column == (n- 1)
so Loop for row => 1 to n
   Loop for col => 1 to n-1
'''

row = int(input())
for i in range(1,row+1):
    for j in range(1,row):
        print("*",end=" ")
    print("\n")