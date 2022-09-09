class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    bool search(int *arr,int i,int n,int x){
        if(arr[i]>x)
            return true;
        return false;
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        int prefix[n];
        sort(arr.begin(),arr.end(),cmp);
        prefix[n-1] = arr[n-1][1];
        for(int i=n-2;i>=0;i--){
            prefix[i] = max(arr[i][1],prefix[i+1]);
        }
        // for(int i=0;i<n;i++)
        //     cout << prefix[i] << " ";
        int count = 0;
        for(int i=0;i<n-1;i++){
            // cout << endl << arr[i][0] << " " << arr[i][1] << endl;
            int j = i;
            while(j<n && arr[j][0]==arr[i][0]){
                j++;
            }
            // cout << endl << j;
            if(j==n)
                break;
            if(search(prefix,j,n,arr[i][1])){
                count++;
                // cout << "increased" << endl;
            }
        }
        return count;
        
    }
};