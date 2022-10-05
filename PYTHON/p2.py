# Print a hollow rectangle
'''
* * * *
*     *
*     *
*     *
* * * *
'''

'''
Logic : let n = 5 (Total Numbers of rows)
By Oberving the pattern we conclude one thing that is :
if row == n then column == (n- 1)
But here space also come so 
   1  2  3  4
1  *  *  *  *
--------------
2  *        *
--------------
3  *        *
--------------
4  *        *
--------------
5  *  *  *  *

As we can see only first and last row having complete star rest rows have only first column and last column contains start else contains space.
'''

# row = int(input())
# col = int(input())
for i in range(1,6):
    for j in range(1,5):
        if (i == 1 or i == 5):
            print(j,end=" ")
        elif(j == 1 or j == 4):
            print(j,end="")
        else:
            print(" ")
    print("\n")