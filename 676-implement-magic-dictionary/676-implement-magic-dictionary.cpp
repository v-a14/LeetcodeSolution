class Trie{
    public:
    vector<Trie*>arr;
    bool isLeaf;
    Trie(){
        for(int i=0;i<26;i++)arr.push_back(NULL);
        isLeaf = false;
    }
};
class MagicDictionary {
public:
    Trie *newTrie;
    MagicDictionary() {
        newTrie = new Trie();
    }
    bool helper(Trie *root, int i, string &str){
        for(int k=i;k<str.size();k++){
            int val = str[k] - 'a';
            if(!root->arr[val]){
                return false;
            }
            root = root->arr[val];
        }
        return root->isLeaf;
    }
    bool TrieSearch(Trie *root, string &str){
        for(int i=0;i<str.size();i++){
            int val = str[i] - 'a';
            if(!root->arr[val]){
                for(int j=0;j<26;j++){
                    if(root->arr[j]){
                        if(helper(root->arr[j], i+1, str)) return true;
                    }
                }
                return false;
            }else{
               for(int j=0;j<26;j++){
                    if(j == val) continue;
                    if(root->arr[j]){
                        if(helper(root->arr[j], i+1, str)) return true;
                    }
                }
                root = root->arr[val];
            }
            
        }
        return false;
    }
    void insertTrie(Trie *root, string str){
        for(int i=0;i<str.size();i++){
            int val = str[i] - 'a';
            if(!root->arr[val]){
                root->arr[val] = new Trie();
            }
            root = root->arr[val];
        }
        root->isLeaf = true;
        return;
    }
    
    void buildDict(vector<string>arr) {
        for(int i=0;i<arr.size();i++){
            insertTrie(newTrie, arr[i]);
        }
    }
    bool search(string searchWord) {
        return TrieSearch(newTrie, searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */