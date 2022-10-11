class Solution {
public:
    string updateOnA(string s, int a){
        for(int i=1;i<s.size();i+=2){
            s[i] = char(((s[i]-'0') + a)%10 + '0');
        }
        return s;
    }
    string rotateOnB(string s, int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+b);
        reverse(s.begin()+b, s.end());
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        queue<string>q;
        unordered_set<string>st;
        st.insert(s);
        q.push(s);
        string ans = s;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            ans = min(ans, curr);
            string x = updateOnA(curr, a);
            string y = rotateOnB(curr, b);
            // cout << curr <<  " " << x << " " << y << " " << endl; 
            if(st.find(x) == st.end()){
                q.push(x);
                st.insert(x);
            }
            if(st.find(y) == st.end()){
                q.push(y);
                st.insert(y);
            }
        }
        return ans;
    }
};