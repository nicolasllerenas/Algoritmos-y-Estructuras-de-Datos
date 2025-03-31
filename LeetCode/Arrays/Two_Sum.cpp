#include <vector>
#include <unordered_map>
#include <iostream>  

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (size_t i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], static_cast<int>(i)};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Índices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No se encontró solución." << endl;
    }
    
    return 0;
}