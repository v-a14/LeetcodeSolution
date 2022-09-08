class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        if(n==0) return true;
        stringstream s(preorder);
        string str;
        int currSpace = 1;
        while(!s.eof()){
            getline(s, str, ',');
            if(currSpace<=0) return false;
            if(str == "#"){
                currSpace--;
            }else{
                currSpace += 1;
            }
        }
        return currSpace == 0;
        
    }
};