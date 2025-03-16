// Problem Statement :- https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

// Let's say you have this array :- [3, 2, 5, 1, 3, 4] 
// We paired 1 with 2, their sum is 3, now we want the rest 2 pairs to have the sum 3 but this is not possible because just one player (3 here, or even 4 and 5) which itself has equal skill (or more) to this pair. So, this pairing is wrong.
// Hence, we start by pairing the biggest number with the smallest number. Then we pair the second largest number with the second smallest number. And so on...
// Best way to achieve this is using sorting and use two pointer approach.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of team chemistry
int teamChemistrySum(vector<int> &skill) {
    int n = skill.size();  // Length of the skill array

    // Step 1: Create a frequency array to count occurrences of each skill value
    // We know that skill values are between 1 and 1000, so we create an array of size 1001
    vector<int> freq(1001, 0); // Skill values range from 1 to 1000

    int SUM = 0;  // Variable to store the total sum of all skill values

    // Step 2: Populate the frequency array and calculate the total sum of the skill array
    for (int &s : skill) {
        SUM += s;   // Add each skill value to the total sum
        freq[s]++;  // Increment the count of the skill value in the frequency array
    }

    int teams = n / 2;  // Number of teams (n/2, since each team has 2 players)

    // Step 3: If the total sum is not divisible by the number of teams, it is impossible
    // to form teams with equal total skill. In that case, return -1.
    if (SUM % teams != 0) {
        return -1; // Impossible to form teams with equal skill sum
    }

    int target = SUM / teams;  // Calculate the target skill sum for each team

    long long chem = 0;  // Variable to store the total chemistry sum (as it can be large)

    // Step 4: Iterate over the skills and try to form valid pairs
    for (int i = 0; i < n; i++) {  // Loop through each skill in the original array
        int currSkill = skill[i];  // Current player's skill value
        int remainSkill = target - currSkill;  // The skill needed to form a valid pair

        // If there are no remaining players with the required complementary skill, return -1
        if (freq[remainSkill] <= 0) {
            return -1;  // No valid pair found, return -1
        }

        // If the pair is valid, add the product of the skills (i.e., the chemistry of the pair)
        chem += (long long)currSkill * (long long)remainSkill;

        // Reduce the frequency of both the current skill and its complementary skill
        freq[currSkill]--;  // Decrease the count of current player's skill
        freq[remainSkill]--;  // Decrease the count of the complementary skill
    }

    // Step 5: Since we counted each pair twice, divide the chemistry sum by 2 for the correct result
    return chem / 2;
}

int main() {
    vector<int> skill1 = {3, 2, 5, 1, 3, 4};
    cout << "Total Chemistry for skill1: " << teamChemistrySum(skill1) << endl;

    vector<int> skill2 = {3, 4};
    cout << "Total Chemistry for skill2: " << teamChemistrySum(skill2) << endl;

    vector<int> skill3 = {1, 1, 2, 3};
    cout << "Total Chemistry for skill3: " << teamChemistrySum(skill3) << endl;

    return 0;
}
