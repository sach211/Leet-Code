#https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string S) {        
        int i = 0;
        int d = S.size();
        
        vector<int> result(d + 1);
        
        for( int strIdx = 0; strIdx < S.size(); strIdx++)
        {
            if(S[strIdx] == 'I')
            {
                result[strIdx] = i;
                i++;
            }
            
            else
            {
                result[strIdx] = d;
                d--;
            }
        }
        
        result[S.size()] = d;
        
        return result;
    }
};