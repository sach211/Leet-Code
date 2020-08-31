#https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
        
        int gap = 1;
        for (int i = nums.size() - 2; i > 0; i--)
        {
            if( nums[i] >= gap)
            {
                gap = 1;
            }
            else
            {
                gap++;
            }
        }
        
        if (nums[0] >= gap)
            return true;
        return false;
    }
};