class Cashier {
public:
    int count = 0;
    map<int,int>mp;
    int discount = 0,n;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0;i<products.size();i++){
            mp[products[i]] = prices[i];
        }
        this->discount = discount;
        this->n = n;
    }
    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0.0;
        for(int i=0;i<product.size();i++){
            ans += (mp[product[i]]*amount[i]);
        }
        count++;
        if(count % n == 0){
            return ans*((100.0 - discount))/100.00;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */