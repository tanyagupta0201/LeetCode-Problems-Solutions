#Author : Manvi Goyal
#Program : To find maximum subarray sum 

def kadane(arr):
    local_max, global_max = (0,0)
    for i in range(1,len(arr)):
        local_max = max(arr[i], local_max + arr[i])
        if local_max > global_max:
            global_max = local_max
    return global_max

arr=[-4,2,4,-1,6]    
print("The sum is :",kadane(arr)) 