#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout;
    fout.open("z1.txt");

    fout << "Hello India\n";
    fout << "Hello Sarthak\n";
    fout << "Hello Shogun\n";

    fout.close();
    
    // Now we want to read all this infromation from the file at the same time.
    ifstream fin;
    fin.open("z1.txt");

    // Since we want to read multiple lines of data each line will be a string.
    string line;

    // use the getline method
    while (getline(fin, line)) {
        // Now this loop will read a line at a time from fin and store it in line variable.
        cout << line <<  endl;
        // This loop will execute till your file does not end i.e. no more data is left to read.
    }

    fin.close();
}