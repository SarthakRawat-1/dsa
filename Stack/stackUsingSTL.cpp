// We can implement Stack using STL. It supports many methods like empty(), size(), top(), push(), and pop()

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack <int> S;

    S.push(6);
    S.push(66);
    S.push(26);

    cout << "Size of Stack is :- " << S.size() << endl;
    cout << "Top of Stack is :- " << S.top() << endl;

    S.pop();

    cout << "Is Stack Empty :- " << S.empty() << endl;

    return 0;
}