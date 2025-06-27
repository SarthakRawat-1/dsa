// Problem Statement :- https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-16

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        // Max value: replace first non-9 with 9
        int idx = str1.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        // Min value:
        // Case 1: if first digit is not '1', replace it with '1'
        if (str2[0] != '1') {
            char ch = str2[0];
            replace(begin(str2), end(str2), ch, '1');
        } else {
            // Case 2: replace first digit (not 0 or 1) after the first digit with '0'
            for (int i = 1; i < str2.size(); i++) {
                if (str2[i] != '0' && str2[i] != '1') {
                    char ch = str2[i];
                    replace(begin(str2), end(str2), ch, '0');
                    break;
                }
            }
        }

        return stoi(str1) - stoi(str2);
    }
};

int main() {

}