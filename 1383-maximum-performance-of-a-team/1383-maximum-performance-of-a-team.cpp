#define ll long long 
class Solution {
public:
    static bool cmp(pair<int,int>&x, pair<int,int>&y){
        return x.first > y.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i].first = efficiency[i];
            arr[i].second = speed[i];
        }
        sort(arr.begin(), arr.end(), cmp);
        ll ans = 0;
        ll sum = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i].second);
            if(pq.size()<=k){
                sum += arr[i].second;
            }else{
                sum -= pq.top();
                pq.pop();
                sum += arr[i].second;
            }
            ans = max((ll)ans, (ll)sum*arr[i].first);
        }
        return ans%1000000007;
    }
};