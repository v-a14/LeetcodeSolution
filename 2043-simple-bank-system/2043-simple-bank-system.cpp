#define ll long long 
class Bank {
public:
    vector<ll>arr;
    int n;
    Bank(vector<long long>& balance) {
        for(int i=0;i<balance.size();i++){
            arr.push_back(balance[i]);
        }
        n = arr.size();
    }
    bool transfer(int account1, int account2, long long money) {
        if(account1<=0 || account1>n || account2<=0 || account2>n || arr[account1-1]<money) 
            return false;
        arr[account1-1] -= money;
        arr[account2-1] += money;
        return true;
    }
    bool deposit(int account, long long money) {
        if(account<=0 || account>n) return false;
        arr[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=0 || account>n || arr[account-1]<money) return false;
        arr[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */