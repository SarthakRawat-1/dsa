// We have many classes to read and write into file.

#include <iostream>
// This is the header file containing the functions to read and write into file.
#include <fstream>
using namespace std;

int main() {
    // Creating an object of class ofstream, this class allows us to write into files.
    ofstream fout;
    // This can be used to open the file.
    fout.open("zoom.txt");
    // This will create the file if the file is not present at the path and then will open it. If it is present there already, then it will simply open it

    // Now we can write into that file. Obviously, you can write much more than just strings. For eg :- You can loop through and write a vector elements in the file also.
    fout << "Sarthak Rawat";

    // This will close the file and release resources.
    fout.close();

    // Creating an object of class ifstream, this class allows us to read from files.
    ifstream fin;

    // This is used to open the file
    fin.open("zoom.txt");

    // This will read from the file
    char c;
    // fin >> c; // If you use this to read, it will not read whitespace characters. You can use get() to read instead.
    c = fin.get();
    // eof() function finds the end of file. If it is at the end, it will return 1 or true and if it is not then it will return 0 or false.
    while (!fin.eof()) {
        cout << c;
        // fin >> c;
        c = fin.get();
    }

    // This will close the file and release resources.
    fin.close();
}