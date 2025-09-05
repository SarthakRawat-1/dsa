// A strobogrammatic number is a number that looks the same when rotated 180 degrees (turned upside down).

#include <bits/stdc++.h>
using namespace std;

// bool isStrobogrammatic(string num) {
//     // Mapping of digits to their rotated equivalents
//     unordered_map<char, char> mapping = {
//         {'0', '0'},
//         {'1', '1'},
//         {'6', '9'},
//         {'8', '8'},
//         {'9', '6'}
//     };
    
//     int left = 0, right = num.size() - 1; // Two pointers: start and end
    
//     // Check pairs of digits from both ends
//     while (left <= right) {
//         // If current digit cannot be rotated -> invalid number
//         if (mapping.find(num[left]) == mapping.end()) {
//             return false;
//         }
//         // If rotated left digit doesn't match the right digit -> invalid
//         if (mapping[num[left]] != num[right]) {
//             return false;
//         }
        
//         left++;   // move forward
//         right--;  // move backward
//     }
    
//     // If all checks passed, number is strobogrammatic
//     return true;
// }

bool isStrobogrammatic(string num) {
    int left = 0, right = num.size() - 1;
    
    while (left <= right) {
        char l = num[left], r = num[right];
        
        // Only valid strobogrammatic pairs:
        if (!((l == '0' && r == '0') ||
                (l == '1' && r == '1') ||
                (l == '6' && r == '9') ||
                (l == '9' && r == '6') ||
                (l == '8' && r == '8'))) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

int main() {
    
}

