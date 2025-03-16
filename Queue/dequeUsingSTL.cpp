// We can implement Deque using STL. It supports many methods like push_front(), push_back(), pop_front(), pop_back(), front(), back() etc.

#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> D;
    D.push_back(5);
    D.push_front(8);
    
    cout << "First element in Dequeue is :- " << D.front() << endl;
    cout << "Last element in Dequeue is :- " << D.back() << endl;

    D.pop_front();
    D.pop_back();
}