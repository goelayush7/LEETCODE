class Cashier {
public:
    int disc = 0;
    int count = 0;
    int n1 = 0;
    unordered_map<int, int> maps;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        disc = discount;
        n1 = n;
        for (int i = 0; i < products.size(); i++) {
            maps[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        double total = 0;
        count++;
        for (int i = 0; i < product.size(); i++) {
            int count = amount[i];
            total += count * maps[product[i]];
        }
        if (count % n1 == 0) {
            return total * ((100 - disc) / 100.0);
        }

        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */