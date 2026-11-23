class ProductOfNumbers {
public:
    vector<int>stream;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int pdt=1;
        int cnt=0;
        for(int i=stream.size()-1;i>=0;i--){
            if(cnt==k) break;
            pdt*=stream[i];
            cnt++;
        }
        return pdt;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */