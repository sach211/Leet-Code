//https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    
    unordered_map<float, vector<vector<int>>> returnDistanceMap(vector<vector<int>>& points){
        
        unordered_map<float, vector<vector<int>>> distMap;
        
        for (int i = 0; i < points.size(); i++){
            float d = sqrt(pow(points[i][0], 2)+pow(points[i][1], 2));
            distMap[d].push_back(points[i]);
        }
        
        return distMap;
    }
    
    vector<float> returnDistances(vector<vector<int>>& points){
        vector<float> dist;
        
        for (int i = 0; i < points.size(); i++){
            float d = sqrt(pow(points[i][0], 2)+pow(points[i][1], 2));
            dist.push_back(d);
        }
        
        return dist;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<float> dist = returnDistances(points);
        unordered_map<float, vector<vector<int>>> distMap = returnDistanceMap(points);
        
        /*vector<float> heapVec;
        for (int i = 0; i < K; i++){
            heapVec.push_back(dist[i]);
        }
        
        make_heap(heapVec.begin(), heapVec.end());
        
        for (int i = K; i < dist.size(); i++){
            float curVal = dist[i];
            if (curVal < heapVec.front()){
                heapVec.erase(heapVec.begin());
                
                heapVec.push_back(curVal);
                make_heap(heapVec.begin(), heapVec.end());
            }
        }*/
        
        sort(dist.begin(), dist.end());
        
        
        vector<vector<int>> res;
        
        for (int i = 0; i < K; i++) {
            vector<vector<int>> curPoints = distMap[dist[i]];
            res.push_back(curPoints.front());
            curPoints.erase(curPoints.begin());
            distMap.erase(dist[i]);
            distMap[dist[i]] = curPoints;
        }
        
        /*for (int i = 0; i < heapVec.size(); i++) {
            vector<vector<int>> curPoints = distMap[heapVec[i]];
            res.push_back(curPoints.front());
            curPoints.erase(curPoints.begin());
            distMap.erase(heapVec[i]);
            distMap[heapVec[i]] = curPoints;
        }*/
        
        return res;
    }
};