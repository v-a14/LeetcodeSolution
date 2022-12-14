class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int res = INT_MIN;
        int sum_L = accumulate(A.begin(),A.begin()+L,0);
        for(int i = 0 ; i < A.size()-L-M;i++){
            if(i != 0) 
				sum_L += A[i+L-1] - A[i-1]; // any possible coding to avoid if(i != 0)?
            int sum_M = accumulate(A.begin()+i+L,A.begin()+i+M+L,0);
            for(int j = i + L ; j <= A.size()-M;j++){
                if(j != i + L) sum_M += A[j+M-1] - A[j-1];
                res = max(res,sum_L+sum_M);
            }
        }
        sum_L = accumulate(A.begin()+A.size()-L,A.end(),0);
        for(int i = A.size()-L ; i >= M ; i--){
            if(i != A.size()-L) 
				sum_L += A[i] - A[i+L]; // any possible coding to avoid if(i != A.size()-L)?
            int sum_M = accumulate(A.begin()+i-M,A.begin()+i,0);
            for(int j = i-M ; j >= 0 ; j--){
                if(j != i-M) 
					sum_M += A[j] - A[j+M];
                res = max(res,sum_L+sum_M);
            }
        }
        return res;
    }
};
