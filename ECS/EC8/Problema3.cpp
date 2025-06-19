#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
    Solution() {
        srand(time(0));
    }

    bool isGreater(const string &a, const string &b) {
        if (a.length() != b.length()) {
            return a.length() > b.length();
        }
        return a > b;
    }

    int randomPartition(vector<string>& nums, int left, int right) {
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        string pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (isGreater(nums[j], pivot)) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    string quickSelect(vector<string>& nums, int left, int right, int k) {
        if (left == right) return nums[left];

        int pivotIndex = randomPartition(nums, left, right);

        if (pivotIndex == k) {
            return nums[pivotIndex];
        } else if (pivotIndex < k) {
            return quickSelect(nums, pivotIndex + 1, right, k);
        } else {
            return quickSelect(nums, left, pivotIndex - 1, k);
        }
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, k - 1);
    }
};

int main() {
    Solution solution;
    vector<string> nums = {"5555555555", "5555555555", "555", "55"};
    int k = 2;
    cout << solution.kthLargestNumber(nums, k) << endl;
    return 0;
}