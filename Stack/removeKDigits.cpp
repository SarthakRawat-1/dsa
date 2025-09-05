// Problem Statement :- https://leetcode.com/problems/remove-k-digits/description/

// Ofc, a no is smaller is smaller digits come at big place like thousandth hundreth and bigger digits come at places like tenth place and one place.
// One thing that we can do is to delete the biggest k elements, but this won't work as place matter too. So greedy doesn't work.
// We can reprhase statement as :- If we want smallest no, try to keep digits in increasing order. For eg :- 1432219 and k = 3
// 14 is increasing order so take 14 in result, then we have 3 but now it's not increasing order so we will delete the most significant, among 43, 4 is more significant so evaporate that instead of 3.
// Now result is 13 and next comes 2, again not increasing order => delete 3, result is now 12. Then again 2, even though it's not inc, it's equal, so we let it slide.
// Result is now 122. Then comes 1, and not increasing so 2 will be deleted and ans becomes 121. And then comes 9, increasing.
// Final ans => 1219
// We can observe that for checking order we only need two elements and one of the element is existing result least significant digit at each point. 
// Perfect for a Monotonic Stack where a stack/vector/string will be holding result digits and it's top number will be compared.

// Ofc in end, if there are zeroes in prefix then you can remove them before returning answer.

// Edge Case :- If digits are in increasing order, no deletion will happen. This will result in not all k being deleted. In that case, keep popping from stack till k becomes zero.

#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
        
    string result = ""; // result will act like a stack to store digits of the final number
    int n = num.length();
    
    // Traverse each digit in the input number
    for(int i = 0; i < n; i++) {
        
        // While the last digit in result is greater than current digit
        // and we still have digits to remove (k > 0), remove it
        // This ensures we are keeping digits in increasing order (to form smallest number)
        while(result.length() > 0 && result.back() > num[i] && k > 0) {
            result.pop_back(); 
            k--;
        }
        
        // Append current digit, but avoid leading zeros
        // e.g. "0200" should not become "00200", so we only push '0' if result is not empty
        if(result.length() > 0 || num[i] != '0') {
            result.push_back(num[i]);
        }
    }
    
    // If there are still digits left to remove (k > 0),
    // remove from the back (these are the largest remaining digits at the end)
    while(result.length() > 0 && k > 0) {
        result.pop_back();
        k--;
    }

    // If result is empty after removals, the number is 0
    if(result == "") {
        return "0";
    }
    
    // Return the final smallest number as a string
    return result;
}

int main() {

}