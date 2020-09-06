//https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        unordered_map<string, int> gCount;
        
        string cur = A[0];
        for (int j = 0; j < cur.size(); j++) {
            gCount[string(1, cur[j])] += 1;
        }
        
        for(int i = 1; i < A.size(); i++) {
            cur = A[i];
            
            unordered_map<string, int> lCount;
            
            for (int j = 0; j < cur.size(); j++) {
                lCount[string(1, cur[j])] += 1;
            }
            
            for( const auto& kvp : gCount ) {
                if(kvp.second > lCount[kvp.first]) {
                    gCount[kvp.first] = lCount[kvp.first];
                }
            }
            
        }
        
        vector<string> res;
        for( const auto& kvp : gCount ) {
            for (int i = 0; i < kvp.second; i++) {
                res.push_back(kvp.first);
            }
        }
        
        return res;
    }
};