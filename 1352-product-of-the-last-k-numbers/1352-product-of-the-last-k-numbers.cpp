class ProductOfNumbers {
public:
    vector<int> v, zero, multi;
    int mul, cnt;

    ProductOfNumbers() : mul(1), cnt(0) {} 

    void add(int num) {
        v.push_back(num);
        if (num == 0) {
            multi.push_back(0);
            cnt++;
            mul = 1;
        } else {
            mul *= num;
            multi.push_back(mul); 
        }
        zero.push_back(cnt);
    }

    int getProduct(int k) {
        
        int n = v.size();
        if( n == k){
            return zero[n-1] == 0?multi[n-1]:0;
        }
        // cout<<multi[n-1]<<" ";
   
        if(zero[n - k - 1] - zero[n-1] == 0){
            if(multi[n-k-1] == 0){
                return multi[n-1];
            }
            return multi[n-1]/multi[n-k-1];
        }
       else  return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */