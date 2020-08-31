#https://leetcode.com/submissions/detail/388830796/

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> hmap(10, 0);
        
        int b, c;
        b = 0;
        c = 0;
        
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                b++;
            
            else
                hmap[secret[i] -'0']++;
        }
        
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] != guess[i])
            {
                if (hmap[guess[i] - '0'] > 0)
                {
                    c++;
                    hmap[guess[i] - '0'] --;
                }
            }
        }
        
        return to_string(b)+"A"+to_string(c)+"B";
    }
};