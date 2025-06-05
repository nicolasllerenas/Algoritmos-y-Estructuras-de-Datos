#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int count;
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            count = 0;
        }
    };
    
    TrieNode* root;
    
    void insert(const string& word) {
        TrieNode* current = root;
        
        for (char c : word) {
            int index = c - 'a';
            
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            
            current = current->children[index];
            current->count++;
        }
    }
    
    int calculatePrefixSum(const string& word) {
        TrieNode* current = root;
        int totalScore = 0;
        
        for (char c : word) {
            int index = c - 'a';
            current = current->children[index];
            totalScore += current->count;
        }
        
        return totalScore;
    }
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new TrieNode();
        
        for (const string& word : words) {
            insert(word);
        }
        
        vector<int> result;
        for (const string& word : words) {
            result.push_back(calculatePrefixSum(word));
        }
        
        return result;
    }
};
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    cout << "Test Case 1:" << endl;
    cout << "Input: words = [\"abc\",\"ab\",\"bc\",\"b\"]" << endl;
    vector<string> words1 = {"abc", "ab", "bc", "b"};
    vector<int> result1 = solution.sumPrefixScores(words1);
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [5,4,3,2]" << endl;
    cout << endl;
    
    cout << "Test Case 2:" << endl;
    cout << "Input: words = [\"abcd\"]" << endl;
    vector<string> words2 = {"abcd"};
    vector<int> result2 = solution.sumPrefixScores(words2);
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    cout << "Resultado esperado: [4]" << endl;
    cout << endl;
    
 
    return 0;
}