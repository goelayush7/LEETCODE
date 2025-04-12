
class Solution {
public:
    int maxDiff(int num) {
        string nums = to_string(num);
        string cpy = nums;
        char start;
        int i = 0;
        while (nums[i] == '9') {
            i++;
        }
        start = nums[i];
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] == start) {
                nums[j] = '9';
            }
        }
        int a = stoi(nums);
        i = 0;
        while (cpy[i] == '1' | cpy[i]=='0') {
            i++;
        }
        start = cpy[i];
        bool takezero = false;
        if (i != 0) {
            takezero = true;
        }

        for (int j = i; j < cpy.size(); j++) {
            if (cpy[j] == start && takezero) {
                cpy[j] = '0';
            } else if (cpy[j] == start) {
                cpy[j] = '1';
            }
        }
        int b = stoi(cpy);
        return a - b;
    }
};