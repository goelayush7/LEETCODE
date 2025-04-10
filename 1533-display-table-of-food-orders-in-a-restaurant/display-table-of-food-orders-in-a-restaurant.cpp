class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
       set<string> foodItems;  // Sorted food items
    map<size_t, map<string, size_t>> ordersPerTable;  // Table → {Food → Count}

    // Populate foodItems set and ordersPerTable map
    for (const auto& order : orders)
    {
        size_t tableNb = stoi(order[1]);
        const string& foodItem = order[2];

        foodItems.insert(foodItem);
        ++ordersPerTable[tableNb][foodItem];
    }

    size_t numFoodItems = foodItems.size();
    
    // Create header row
    vector<string> headerRow(numFoodItems + 1, "");  
    headerRow[0] = "Table";

    unordered_map<string, size_t> foodIndex;
    size_t index = 1;
    for (const auto& foodItem : foodItems)
    {
        headerRow[index] = foodItem;
        foodIndex[foodItem] = index++;  // Store index for fast lookup
    }

    size_t numTables = ordersPerTable.size();
    vector<vector<string>> displayTable(numTables + 1);  
    displayTable[0] = headerRow;  // First row is header

    size_t i = 1;
    for (const auto& [tableNb, tableOrders] : ordersPerTable)
    {
        vector<string> row(numFoodItems + 1, "0");  
        row[0] = to_string(tableNb);

        // Fill food counts using precomputed index
        for (const auto& [foodItem, count] : tableOrders)
            row[foodIndex[foodItem]] = to_string(count);

        displayTable[i++] = row;
    }

    return displayTable;
    }
};