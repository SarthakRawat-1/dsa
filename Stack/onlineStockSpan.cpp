// Problem Statement :- https://leetcode.com/problems/online-stock-span/description/

// Brute Force :- For every stock, use a for loop to traverse backwards from there and check if the price is smaller or equal to the element. Then you can store count of such elements in an array.

// Optimal Approach :- Consider {100, 80, 60, 70, 60, 75, 85} Start from 100, obv it's span will be 1. So, store (100, 1). Then comes 80, 80 will see that 100 is greater than 80, so it will also store as (80, 1). Now 60 is smaller than 80, so 60 will also be stored as (60, 1). Then comes 70, which is greater than 60, so 1 span which is for 70 itself and it will also add span of 60 (which is also 1), hence 70 span is 2. Add (70, 2) to stack but first remove (60, 1) from stack as it was used already.
// Then comes 60 again, it's own span is 1. It is less than 70. So, add (60, 1) to stack. Then comes 75, it's span is 1 and it is greater than 60. Pop (60, 1) from stack. Then comes (70, 2) which is also lesser tahn 75. So pop this as well. But now 80 appears in stack, which is bigger, sos top here. Add (75, 1 + 1 + 2) = (75, 4) to stack. Then comes 85, it's span is 1. It is greater than 75. So pop 75 from stack. 85 is greater than 80 as well, so pop 80 also. Finally add (85, 1 + 4 + 1) = (85, 6) to stack.
// Make an array out of all elements's span, this will be our answer.

#include <bits/stdc++.h>
using namespace std;

// Make stack persistent by declaring it outside the next() function
stack <pair<int, int>> S;

int next(int price) {
    // Initialize the span for the current price
    int span = 1;

    // While stack is not empty and the top element's price is less than or equal to current price
    while(!S.empty() && S.top().first <= price) {
        // Add the span of the top element to the current span
        span += S.top().second;
        // Pop the element from the stack since it's no longer useful
        S.pop();
    }

    // Push the current price and its calculated span onto the stack
    S.push({price, span});

    // Return the span for the current price
    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for (int price : prices) {
        cout << next(price) << " ";
    }

    return 0;
}
