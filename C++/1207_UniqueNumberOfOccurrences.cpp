class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        int a[1000] = {0};
        for(int i = 0; i < arr.size(); i++){
            int count = 0;
            if(arr[i] == 1001)  
                continue;
            
            for(int j = i+1; j < arr.size(); j++){
                if(arr[i] == arr[j]) {
                    count++;
                    arr[j] = 1001;
                }
            }
            if(a[count])  return false;
            else  a[count] = 1;
        }
        return true;
    }
};