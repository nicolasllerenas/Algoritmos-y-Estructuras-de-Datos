#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sToT[256];
        int tToS[256];

        for (int i = 0; i < 256; i++) {
            sToT[i] = -1;
            tToS[i] = -1;
        }

        for (int i = 0; s[i] != '\0'; i++) {
            char sC = s[i];
            char tC = t[i];

            if ((sToT[(unsigned char)sC] != -1 && sToT[(unsigned char)sC] != tC) ||
                (tToS[(unsigned char)tC] != -1 && tToS[(unsigned char)tC] != sC)) {
                return false;
            }

            sToT[(unsigned char)sC] = tC;
            tToS[(unsigned char)tC] = sC;
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Ejemplo 1
    string s1 = "egg";
    string t1 = "add";
    cout << "Ejemplo 1 (\"egg\", \"add\"): " << (sol.isIsomorphic(s1, t1) ? "true" : "false") << endl;

    // Ejemplo 2
    string s2 = "foo";
    string t2 = "bar";
    cout << "Ejemplo 2 (\"foo\", \"bar\"): " << (sol.isIsomorphic(s2, t2) ? "true" : "false") << endl;

    return 0;
}
