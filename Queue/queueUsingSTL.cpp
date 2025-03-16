// We can implement Queue using STL. It supports many methods like empty(), size(), front(), back(), push(), pop() etc.

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> Q;

    Q.push(10);
    Q.push(40);
    Q.push(123);

    Q.pop();

    cout << "First element in Queue is :- " << Q.front() << endl;
    cout << "Last element in Queue is :- " << Q.back() << endl;
    cout << "The size of the Queue is :- " << Q.size() << endl;
    cout << "Is the Queue empty? " << Q.empty() << endl;

    return 0;
}