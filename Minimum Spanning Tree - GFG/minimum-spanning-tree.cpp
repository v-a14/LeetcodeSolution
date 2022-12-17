//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<int>key(n, INT_MAX);
        vector<bool>mst(n, false);
        key[0] = 0;
        for(int count = 0; count<n; count++){
            int mini = INT_MAX;
            int index = -1;
            for(int j=0;j<n;j++){
                if(mst[j] == false && key[j]<mini){
                    mini = key[j];
                    index = j;
                }
            }
            mst[index] = true;
            for(auto it:adj[index]){
                int node = it[0];
                int weight = it[1];
                if(mst[node] == false && key[node]>weight){
                    key[node] = weight;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += key[i];
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends