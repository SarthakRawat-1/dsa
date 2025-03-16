// Problem Statement :- https://www.geeksforgeeks.org/problems/leap-year0943/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include <iostream>
using namespace std;

int isLeap(int N) {
    // If the year is divisible by 400, it's a leap year
    if (N % 400 == 0) {
        return 1;
    }
    // If the year is divisible by 100 but not by 400, it's not a leap year
    else if (N % 100 == 0) {
        return 0;
    }
    // If the year is divisible by 4 but not by 100, it's a leap year
    else if (N % 4 == 0) {
        return 1;
    }
    // Otherwise, it's not a leap year
    else {
        return 0;
    }
}

int main() {
    int N = 2021; // Example input
    cout << "Is " << N << " a leap year? " << isLeap(N) << endl;
    return 0;
}
