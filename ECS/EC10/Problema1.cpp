#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = "";

        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return prefix;
                }
            }
            prefix += c;
        }

        return prefix;
    }
};

int main() {
    Solution solution;

    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"interspecies", "interstellar", "interstate"};
    vector<string> strs4 = {};

    cout << "Test 1: " << solution.longestCommonPrefix(strs1) << endl; // Output: "fl"
    cout << "Test 2: " << solution.longestCommonPrefix(strs2) << endl; // Output: ""
    cout << "Test 3: " << solution.longestCommonPrefix(strs3) << endl; // Output: "inters"
    cout << "Test 4: " << solution.longestCommonPrefix(strs4) << endl; // Output: ""

    return 0;
}
