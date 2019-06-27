class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        }
    };
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int,int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
        for(auto b:barcodes) m[b]++;
        for(auto b:m) q.push({b.first, b.second});
        int p1 = 0, p2 = 1;
        while(!q.empty()){
            int i = q.top().first, j = q.top().second;
            q.pop();
            while(p1 < n && j > 0){
                barcodes[p1] = i;
                j--;
                p1 += 2;
            }
            while(p2 < n && j > 0){
                barcodes[p2] = i;
                j--;
                p2 += 2;
            }
        }
        return barcodes;
    }
};