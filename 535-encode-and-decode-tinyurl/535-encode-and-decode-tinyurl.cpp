class Solution {
public:
    unordered_map<string, string>mp;
    Solution(){
        srand(time(0));
    }
    // Encodes a URL to a shortened URL.
    string helper(string &temp){
        string encoded = "";
        for(int i=0;i<=10;i++){
            if(i%2 == 0){
                int num = rand()%10;
                encoded += to_string(num);
            }else{
                int num = rand()%26;
                encoded += char(num+'a');
            }
        }
        return encoded;
    }
    string encode(string longUrl) {
        while(1){
            string geneRate = helper(longUrl);
            if(mp.find(geneRate) == mp.end()){
                mp[geneRate] = longUrl;
                return geneRate;
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));