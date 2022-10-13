class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [&](vector<int>&x, vector<int>&y){
            return abs(x[0]-x[1]) < abs(y[0]-y[1]);
        };
        sort(costs.begin(), costs.end(), cmp);
        // for(auto it:costs) cout << it[0] << " " << it[1] << " " << abs(it[1]-it[0]) << endl;
        // cout << endl;
        int n = costs.size();
        int city1 = 0, city2 = 0;
        int cost=0;
        for(int i=n-1;i>=0;i--){
            if(costs[i][0] > costs[i][1]){
                if(city2<n/2){
                    city2++;
                    cost += costs[i][1];
                }else{
                    city1++;
                    // cout << cost << endl;
                    // cout << costs[i][0] << endl;
                    cost += costs[i][0];
                    // cout << cost << endl;
                }
            }else{
                if(city1<n/2){
                    city1++;
                    cost += costs[i][0];
                }else{
                    city2++;
                    cost += costs[i][1];
                }
            }
            // cout << cost << endl;
        }
        return cost;
    }
};