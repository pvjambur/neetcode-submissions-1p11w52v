class Solution {
public:
    int maxSubArray(vector<int>& nums) {
 int res = nums[0];
  

  	for(int i = 0; i < nums.size(); i++) {
    	int currSum = 0;
      
       
        for(int j = i; j < nums.size(); j++) {
        	currSum = currSum + nums[j];
          
           
            res = max(res, currSum);
        }
    }
    return res;
    }
};
