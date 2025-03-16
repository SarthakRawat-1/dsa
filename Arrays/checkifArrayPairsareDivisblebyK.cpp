// Problem Statement :- https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01

// NOTE :- If any pair, say (a, b) is divisble by k, then if we find r1 and r2, such that a % k = r1 and b % k = r2, then sum of r1 and r2 should be equal to k
// So first we can store remainder of each element in the given array in a hash map.
// For eg :- Consider this array {1, 2, 8, 9} and k = 5, so corresponding remainders are now {1, 2, 3, 4} which we have stored in a hash map. The hash map index will represent the elements, and it's elements will represent the count of remainders present in the array. So fro eg, if we are getting two 1 remainders, then in hash map index 1 we will have stored 2.
// From here this is pretty much like a two sum problem. We select 1, then we can search if 5 - 1 = 4 is present in the has map or not. It is present. Now go to 2, we also have 5 - 2 = 3 present in our hash map. You can check that we need not check for the rest of elements, because they already have come in 5 - 3 and 5 - 4, so we now know that we only have to check for elements lesser than or equal to k / 2.  All elements are exhausted now in our hash map. Hence, our array can be divided into pairs.
// Then how do we know the size of Hash map? Well we know that if we use do a % k, then no matter the a, the answer will always be less than k. So to implement hashing, we can just declare an array of size k.
// Edge Case :- Consider array {10, 15, 20, 30} and k = 5, as all of these are divisble by 5 so for all their remainder will be 0. Hence, we will have 0 index as count 4 in our Hash map. So now we want k - 0 in our hash map which is 5 itself, which is not avaliable. Hence, in this case, we can just check if 0th index holds an even number or not.

#include <iostream>
#include <vector>
using namespace std;

bool canArrange(vector<int>& arr, int k) {
    // Step 1: Create a frequency map of remainders, initialize it with size k (since remainder % k can only be between 0 and k-1)
    vector<int> mp(k, 0);

    // Step 2: Populate the frequency map with the remainders of each element
    for (int &num : arr) {
        // Calculate remainder of num % k. Handle negative remainders by adding k and taking mod k again to ensure positive remainder.
        int rem = (num % k + k) % k;
        mp[rem]++;
    }

    // Step 3: Handle edge case for elements that are divisible by k (i.e., remainder 0)
    // If there are elements fully divisible by k (remainder 0), we must ensure they can be paired with each other
    // Hence, count of remainder 0 elements must be even
    if (mp[0] % 2 != 0) {
        // If the count of numbers with remainder 0 is odd, return false as they can't be perfectly paired
        return false;
    }

    // Step 4: Iterate through possible remainders and check if they can be paired properly
    for (int rem = 1; rem <= k / 2; rem++) {
        // Find the complement remainder for current remainder rem (i.e., k - rem)
        int counterHalf = k - rem;
        
        // Check if the frequency of the current remainder matches the frequency of its complement
        // If not, return false because pairing is not possible
        if (mp[rem] != mp[counterHalf]) {
            return false;
        }
    }

    // Step 5: If all checks passed, the array can be arranged in pairs divisible by k
    return true;
}

int main() {
    vector <int> v = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int k = 10;

    cout << canArrange(v, k) << endl;
}
