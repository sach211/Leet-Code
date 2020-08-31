#https://leetcode.com/submissions/detail/388777177/

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0)
        {
            return 0;
        }
        
        bool cat = catCheck(m, n);
        
        if(!cat)
        {
            return 0;
        }
        else
        {
            int base = pow(2, int(log2(m)));
            return base + rangeBitwiseAnd(m - base, n - base);
        }
    }
    
    bool catCheck(int m, int n) {
        if (int(log2(m)) == int(log2(n)))
        {
            return true;
        }
        return false;
    }
};