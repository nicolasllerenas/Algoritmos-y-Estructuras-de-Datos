#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {

    vector<int> nums1 = {4, 5, 8, 2};
    KthLargest kth1(3, nums1);
    cout << "Test Case 1:" << endl;
    cout << "add(3) → " << kth1.add(3) << endl;   // Debe retornar 4
    cout << "add(5) → " << kth1.add(5) << endl;   // Debe retornar 5
    cout << "add(10) → " << kth1.add(10) << endl; // Debe retornar 5
    cout << "add(9) → " << kth1.add(9) << endl;   // Debe retornar 8
    cout << "add(4) → " << kth1.add(4) << endl;   // Debe retornar 8


    vector<int> nums2 = {7, 7, 7, 7, 8, 3};
    KthLargest kth2(4, nums2);
    cout << "\nTest Case 2:" << endl;
    cout << "add(2) → " << kth2.add(2) << endl;   // Debe retornar 7
    cout << "add(10) → " << kth2.add(10) << endl; // Debe retornar 7
    cout << "add(9) → " << kth2.add(9) << endl;   // Debe retornar 7
    cout << "add(9) → " << kth2.add(9) << endl;   // Debe retornar 8


    return 0;
}