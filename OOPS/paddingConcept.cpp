#include <iostream>
using namespace std;

// If we only had int b inside class a, the size of an object of class a will come as 4. If we have int b and int c both then size will come out to be 8.
class a {
    // But let's say you had one int say int b and one char say char c. This time also size will come as 8 instead of the expected 5. Even if you place char c above int b the size will comme as 8.
    // This happens because of the concept of Padding. Let's consider the same example.
    // Now the char require 1 byte and the int required 4 bytes. But because our OS is either 32 bit or 64 bit, then at one time it reads 4 bytes from the memory. So it starts making segments of your memory. Now when we run multiple cycles to read these segments of 4 bytes, it will take time, so we can sacrifice some memory for time saving.
    // So, now if we had char c before int b, the first memory location will store char c, the next three location will be padded. And after this, our int will be stored in 4 bytes. And hence, it takes 8 bytees. In this way, it can read entire int b in one time as each byte of int b is present in the same segment.
    int b;
    // int c;
    char c;

};

// So how we can guess the memory allocation? Use this general rule :-
// Dataype which take 1 byte in memory, will take memory starting from location which are multiple of 1. Dataype which take 2 byte in memory, will take memory starting from location which are multiple of 2. Similarly for 4 byte, 8 byte and so on. Remember, that memory location starts from 0.
// Eg :- Let's say we had char a then char b and then int c. In this case memory alloted will be 8. Because, memory starts from 0. 0 is a multiple of 1, so char a is stored in that, after that 1 is also a multiple of 1 so char b is stored in that. 2 and 3 are not multiple of 4 so they are padded. 4 is multiple of 4 so int c is stored starting from 4, and it takes 4 locations so, 4 5 6 7. Total memory locations occupied :- 8 i.e. from 0 to 7.
// Now let's say we had char a then int b and then char c again. In this case, memory allocated will be 12. Using the same logic, char a is stored in 0 location. Next 3 locations are padded. 4 to 7 stores int b and 8 stores char c. The reason why it takes 12 bytes instead of the expected 9 bytes is because of another rule. The biggest datatype out of all which in this case is 4, this should divide the total memory location, which in our case is 9, 4 does not divide 9. In this case, take the smallest number after the total memory location, which can be divided, which is 12 in our case.
// With this eg, you can now understand, how much order of declaration matters in spcae management.
// We ccan use Greedy arrangement, which means first declare those datatypes which are the largest.

// An empty class like this, has the size of 1 instead of 0.
class emptyClass {

};
// This happens because of Unique Address Requirement, Object Identity and Alignment and Memory Management.

int main() {
 a obj;
 emptyClass meow;
 cout << sizeof(meow) << endl;
 cout << sizeof(obj) << endl;
}