class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> ans(k);
        for(auto &x:points){
            int a=x[0];
            int b=x[1];
            int dist=a*a+b*b;
            pq.push({dist,x});
            if(pq.size()>k) pq.pop();
        }
        int x=0;
        while(!pq.empty()){
            ans[x++]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};