#https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = true;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            
            if (nums[i] > nums[i + 1]) {
                if (!flag)
                    return false;
                
                flag = false;
                
                if((i > 0 && nums[i-1] <= nums[i+1]) || i == 0) {
                    nums[i] = nums[i+1];
                }
                else if ((i+2 < nums.size() && nums[i] <= nums[i+2]) || i+2 == nums.size()) {
                    nums[i + 1] = nums[i];
                }
                else
                    return false;
            }
        }
        return true;
    }
};