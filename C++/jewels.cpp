// Name : Mohd Quamar Tyagi
//Date : 4 oct 2022
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        //sort(jewels.begin(),jewels.end());
       // sort(stones.begin(),stones.end());
  //      int count=0;
    //  for(int i=0;i<jewels.size();i++){
      //    for(int j=0;j<stones.size();j++){
        //      if(jewels[i]==stones[j]);
//              count++;
  //        }
    //  }
      //return count;
   // }
            int count=0;
    for(int i=0;i<jewels.size();i++)
    {
        for(int j=0;j<stones.size();j++)
        {
            if(jewels[i]==stones[j])
                count++;
        }
    }
    
    return count;
        }
};