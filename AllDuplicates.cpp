#https://leetcode.com/submissions/detail/389779983/

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for (int idx = 0; idx < nums.size(); idx++)
        {
            int curVal = nums[idx];
            
            if (curVal < 0)
            {
                curVal = curVal * (-1);
            }
            
            if (nums[curVal - 1] < 0)
            {
                res.push_back(curVal);
            }
            
            else
            {
                nums[curVal - 1] = nums[curVal - 1] * (-1);
            }
        }
        
        return res;
    }
};