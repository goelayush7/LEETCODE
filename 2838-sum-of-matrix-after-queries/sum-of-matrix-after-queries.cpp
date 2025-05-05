class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;
        int m = queries.size();
        long long sum = 0;
        for(int i = m-1;i>=0;i--){
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];
            if(type==0){
                if(rows.find(index)==rows.end()){
                    rows[index]++;
                    sum += (n-cols.size())*val;
                }
            }
            else if(type==1){
                if(cols.find(index)==cols.end()){
                    cols[index]++;
                    sum+=(n-rows.size())*val;
                }
            }
        }
        return sum;
    }
};