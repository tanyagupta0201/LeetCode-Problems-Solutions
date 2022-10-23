// Name: Shradha Verma
// Date: 23 October 2022

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        stack<int>s;
        vector<int>:: iterator it;
        vector<int>result;

        for(int i = nums2.size()-1; i >= 0; i--){

            if(s.size() == 0){
                v.push_back(-1);    // if stack is empty push -1.
            }

            else if(s.size() > 0 && s.top() > nums2[i]){
                v.push_back(s.top());   // push the top element if the top element is less than nums2 vector element.
            }

            else{
                while(s.size() != 0 && s.top() <= nums2[i]){
                    s.pop();        // pop the elements from stack till the top element is less than nums2 vector element.
                }

                // if stack becomes empty after popping, push -1 otherwise push the top most element. 
                if(s.size() == 0){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top());
                }
            }
            s.push(nums2[i]);
        }
        
        reverse(v.begin(), v.end());
        
        for(int j = 0; j < nums1.size(); j++){
            
            int no = nums1[j];
            it = find(nums2.begin(), nums2.end(), no);      // check if element of nums1 is present in nums2.
            int res = it - nums2.begin();
            result.push_back(v[res]);
            
        }
        return result;
    }
};