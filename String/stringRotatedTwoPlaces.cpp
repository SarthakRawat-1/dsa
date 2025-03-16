// Problem Statement :- https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

// Now first we will make two string variables clockwise and antiClockwise to store the rotated string in both the cases. We initialize both of them to the correct string intially i.e. string which is not rotated. Let's call that string 1.
// Now we will make two functions for both directions which will rotate the string by 1 place. 
// Then check if any of the two resultant strings are equal to the rotated string to be checked, which we can call String 2.
// Logic to rotate string is same as that of rotate by one place in array. Store the element that is going to be out of bounds when rotated. Rotate the rest of string elements using a loop. Then insert the copied element to it's appropriate place.

#include <bits/stdc++.h>
using namespace std;

// Function to rotate the string by one position in clockwise direction
void rotateClockwise(string & str) {
    // Save the last character of the string as it will be shifted out
    char c = str[str.size() - 1];

    // Start from the second last character and shift each character to the right
    int index = str.size() - 2;

    // Shift each character one position to the right
    while(index >= 0) {
        str[index + 1] = str[index];
        index--;
    }

    // Place the last character (saved earlier) at the first position
    str[0] = c;
}

// Function to rotate the string by one position in anti-clockwise direction
void rotateAntiClockwise(string & str) {
    // Save the first character of the string as it will be shifted out
    char c = str[0];

    // Start from the second character and shift each character to the left
    int index = 1;

    // Shift each character one position to the left
    while(index < str.size()) {
        str[index - 1] = str[index];
        index++;
    }

    // Place the first character (saved earlier) at the last position
    str[str.size() - 1] = c;
}

int main() {
    string str1 = "abc", str2 = "cab";
    string clockwise = str1;

    rotateClockwise(clockwise);
    rotateClockwise(clockwise);

    if (clockwise == str2) {
        cout << "Yes the string is rotated Clockwise";
    }

    string antiClockwise = str1;

    rotateAntiClockwise(antiClockwise);
    rotateAntiClockwise(antiClockwise);

    if (antiClockwise == str2) {
        cout << "Yes the string is rotated AntiClockwise";
    }

}