class ProductOfNumbers {
    vector<int>product;
    int size=0;
public:
    ProductOfNumbers() {
        product.push_back(1);
        size=0;
    }
    
    void add(int num) {
        if(num==0){
            size=0;
            product={1};
        }
        else{
            product.push_back(product[size]*num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k>size)return 0;
        else return product[size]/product[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */