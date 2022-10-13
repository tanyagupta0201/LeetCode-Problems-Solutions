# Author: Poonam Parate
# Date: 13/10/22

def maxArea(A, Len) :
	area = 0
	for i in range(Len) :
		for j in range(i + 1, Len) :
		
			# Calculating the max area as area = (j – i)* min(array[i],array[j]
			area = max(area, min(A[j], A[i]) * (j - i))
	return area

# Main Code Take a two arrays as
a = [ 1, 5, 4, 3 ]

#print the max value
len1 = len(a)
print(maxArea(a, len1))


