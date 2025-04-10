class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> st;
        set<string> st1;
        map<pair<string, string>, int> myMap;
        for (auto it : orders) {
            st.insert(it[2]);
            st1.insert(it[1]);
            myMap[{it[1], it[2]}]++;
        }
        vector<vector<string>> ans;
        ans.push_back({"Table"}); // use double quotes for string
        for (const auto& it : st) {
            ans[0].push_back(it);
        }
        for (auto it : st1) {
            vector<string> temp;
            temp.push_back(it);
            for (auto it1 : st) {
                string num = to_string(myMap[{it, it1}]);
                temp.push_back(num);
            }
            ans.push_back(temp);
        }
        sort(ans.begin() + 1, ans.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 return stoi(a[0]) < stoi(b[0]);
             });
        return ans;
    }
};