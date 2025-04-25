#include <iostream>

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int N = 1 << 20;
        bool seen[N] = {false};
        bool added[N] = {false};
        vector<string> result;

        int bits[26] = {};
        bits['A' - 'A'] = 0;
        bits['C' - 'A'] = 1;
        bits['G' - 'A'] = 2;
        bits['T' - 'A'] = 3;

        int hash = 0;
        int mask = (1 << 20) - 1;

        for (int i = 0; i < s.length(); ++i) {
            hash = ((hash << 2) | bits[s[i] - 'A']) & mask;

            if (i < 9) continue;

            if (seen[hash]) {
                if (!added[hash]) {
                    result.push_back(s.substr(i - 9, 10));
                    added[hash] = true;
                }
            } else {
                seen[hash] = true;
            }
        }

        return result;
    }
};