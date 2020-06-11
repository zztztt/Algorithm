/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 */
 
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        int n;
        n = num / 1000;
        if (n > 0) {
            num = num % 1000;
            result += cal(n, "", "", "M");
        }
        n = num / 100;
        if (n > 0) {
            num = num % 100;
            result += cal(n, "M", "D", "C");
        }
        n = num / 10;
        if (n > 0) {
            num = num % 10;
            result += cal(n, "C", "L", "X");
        }
        result += cal(num, "X", "V", "I");

        return result;
    }
private:
    string cal(int n, string x10, string x5, string x1) {
        if (n == 9) return x1 + x10;
        if (n == 4) return x1 + x5;
        string r;
        if (n / 5 > 0) {
            n = n - 5;
            r = x5;
        }
        for (int i = 0; i < n; ++i) {
            r += x1;
        }
        return r;
    }
};

int main() {
    Solution s;
    string result = s.intToRoman(1994);
    printf("result is %s\n", result.c_str());
    return 0;
}
