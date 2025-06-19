#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, bool> feedbacks;
        for (const string& feedback : positive_feedback) feedbacks[feedback] = true;
        for (const string& feedback : negative_feedback) feedbacks[feedback] = false;

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> students(cmp);

        for (int i = 0; i < report.size(); ++i) {
            int feedbackCount = 0;
            stringstream ss(report[i]);
            string word;
            while (ss >> word) {
                if (feedbacks.contains(word)) {
                    if (feedbacks[word]) feedbackCount += 3;
                    else feedbackCount--;
                }
            }
            students.push({feedbackCount, student_id[i]});
        }

        vector<int> result;
        while (k-- && !students.empty()) {
            result.push_back(students.top().second);
            students.pop();
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<string> positive_feedback = {"smart", "brilliant", "studious"};
    vector<string> negative_feedback = {"not"};
    vector<string> report = {"this student is studious", "the student is smart"};
    vector<int> student_id = {1, 2};
    int k = 2;

    vector<int> result = solution.topStudents(positive_feedback, negative_feedback, report, student_id, k);

    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
