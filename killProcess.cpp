//https://leetcode.com/problems/kill-process/

class Solution {
public:
    
    unordered_map<int,vector<int>> adjList(vector<int>& pid, vector<int>& ppid){
        unordered_map<int,vector<int>> aList;
            
        for (int i = 0; i < ppid.size(); i++){
            aList[ppid[i]].push_back(pid[i]);
        }
        
        return aList;           
    }
    
    vector<int> getKids(int kill, unordered_map<int,vector<int>> aList) {
        
        vector<int> res;
        queue<int> q;
        q.push(kill);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            vector<int> curC = aList[cur];
            for (int i = 0; i < curC.size(); i++){
                q.push(curC[i]);
            }
        }
            
        return res;
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> aList = adjList(pid, ppid);
        
        vector<int> res = getKids(kill, aList);
        
        return res; 
    }
};