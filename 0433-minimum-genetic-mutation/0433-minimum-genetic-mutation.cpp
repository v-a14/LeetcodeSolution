class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>>q;
        q.push({start, 0});
        char arr[] = {'A', 'C', 'G', 'T'};
        set<string>s;
        for(auto it:bank) s.insert(it);
        s.erase(start);
        while(!q.empty()){
            string curr = q.front().first;
            int moves = q.front().second;
            q.pop();
            if(curr==end) return moves;
            for(int i=0;i<curr.size();i++){
                string temp = curr;
                for(int j=0;j<4;j++){
                    temp[i] = arr[j];
                    if(temp==curr) continue;
                    if(s.find(temp)!=s.end()){
                        q.push({temp, moves+1});
                        s.erase(temp);
                    }
                }
            }
        }
        return -1;
    }
};