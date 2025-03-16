#include <iostream>
using namespace std;

// Checking if a string is palindrome using Recursion. We need to pass the string, the start which intially points to first letter of string and end, which initially points to last letter of string.
bool checkPalindrome(string str, int start, int end) {
    // Base condition. If start and end becomes equal (when number of letters are odd) or start becomes greater than end (when number of letters are even) , then the string is palindrome.
    // Greater than is also need because it reduces redundancy. If the letters are same for every combination of start and end till they cross path, obv they will be same, even after.
    if (start >= end) {
        return 1;
    }

    // If the elements at start and end are not same, they can't be a palindrome.
    if (str[start] != str[end]) {
        return 0;
    }

    // If they are same, then increase start by one and decrease end by one. So, we can check the next set of letters.
    return checkPalindrome(str, start + 1, end - 1);
    // This return statement will return a 1 if the string is palindrome. 0 is returned by our condition check above.
}

// Counting the number of vowels present in string using Recursion. We need to pass the string and index to help traverse the array. The index initially points to last element of string.
int countVowels(string str, int index) {
    // Base class. If index becomes -1, we know that there are no more elements in the string. So, we return 0 because it means no more vowels are present.
    if (index == -1) {
        return 0;
    }

    // If the element at index is vowel, we return 1 + countVowels(str, index - 1). 1 because we are counting number of vowels and we have found a vowel. And then decrease index by 1. 
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u')  {
        return 1 + countVowels(str, index - 1);
    }

    // If the element at index is not vowel, we return 0 + countVowels(str, index - 1) which is same as countVowels(str, index - 1)
    return countVowels(str, index - 1);
}

// Reversing a string using Recursion. We need to pass the string, the start which intially points to first letter of string and end, which initially points to last letter of string. We will use start and end to swap letters.
// Now when we pass the string, we have to give pass it by reference not just by value, otherwise the changes that we are making will not be reflected in our original string.
void reverseString(string &str, int start, int end) {
    // Base condition. If start and end becomes equal or start becomes greater than end, then there is no need to swap the letter. So just return
    if (start >= end) {
        return;
    }

    // Swap the letters present at start and end indexes.
    char c = str[start];
    str[start] = str[end];
    str[end] = c;

    // Call the function again, but now start will be incremented by 1 and end decremented by 1
    // We don't need to use the & sign before str in the recursive call because the function parameter str is already passed by reference when the function is defined.
    reverseString(str, start + 1, end - 1);
    // The & symbol is only needed when defining the function to specify that you want to pass by reference, not when calling the function.
}

// Lower case to Upper case using Recursion.We need to pass the string by reference and index to help traverse the array. The index initially points to last element of string.
void toUpperCase(string &str, int index) {
    // Base case. When index becomes -1, we know that there are no more elements in the string. So, we return.
    if (index == -1) {
        return;
    }

    // The expression 'A' + (str[index] - 'a') works because it shifts the ASCII value of a lowercase letter to its corresponding uppercase letter. This works because it checks the difference between 'a' and the character to be converted to uppercase. Then we add the difference to 'A'.
    str[index] = 'A' + str[index] - 'a';
    // This only works if the character is guaranteed to be lowercase, which this implementation assumes. 

    // After converting the letter at index to Uppercase, we call the function again with index decremented.
    toUpperCase(str, index - 1);
}

int main() {
    string str = "sarthak";
    cout << checkPalindrome(str, 0, 6) << endl;
    cout << countVowels(str, 6) << endl;
    reverseString(str, 0, 6);
    cout << str << endl;
    toUpperCase(str, 6);
    cout << str;
    return 0;
}