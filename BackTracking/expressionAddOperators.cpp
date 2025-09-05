// Problem Statement :- https://leetcode.com/problems/expression-add-operators/

// Instead of making a separate “no-op” recursive branch, we handle it naturally by looping over all substring lengths starting at the current index.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        string expr; // temporary string to build current expression
        dfs(num, target, 0, 0, 0, expr, results);
        return results;
    }

private:
    /**
     * Recursive DFS function
     *
     * @param num           Input number string (e.g., "123")
     * @param target        Target integer value we want expressions to evaluate to
     * @param index         Current position in the string
     * @param curr_val      Running value of the expression so far
     * @param last_operand  The most recent operand used (needed for '*')
     * @param expr          Current expression string being built
     * @param results       List of valid expressions found so far
     */
    void dfs(const string &num, int target,
             int index, long long curr_val, long long last_operand,
             string &expr, vector<string> &results) 
    {
        // ✅ Base case: reached the end of the string
        if (index == num.size()) {
            // If running total == target, record the expression
            if (curr_val == target) {
                results.push_back(expr);
            }
            return;
        }

        // Try all possible "operands" starting at position index
        // For example, if num = "123" and index = 0:
        // substrings tried → "1", "12", "123"
        for (int i = index; i < num.size(); i++) {
            // 🚨 Skip numbers with leading zeros ("05", "012", etc.)
            if (i != index && num[index] == '0') break;

            // Extract current operand substring and convert to number
            string operandStr = num.substr(index, i - index + 1);
            long long operand = stoll(operandStr);

            // Store current expression length (to backtrack later)
            int lenBefore = expr.size();

            // 🟢 Case 1: This is the FIRST number (no operator before it)
            if (index == 0) {
                expr += operandStr;  // Start new expression
                dfs(num, target, i + 1, operand, operand, expr, results);
                expr.resize(lenBefore); // Backtrack (undo changes)
            } else {
                // 🟢 Case 2: Try '+' operator
                expr += "+" + operandStr;
                dfs(num, target, i + 1, curr_val + operand, operand, expr, results);
                expr.resize(lenBefore); // backtrack

                // 🟢 Case 3: Try '-' operator
                expr += "-" + operandStr;
                dfs(num, target, i + 1, curr_val - operand, -operand, expr, results);
                expr.resize(lenBefore); // backtrack

                // 🟢 Case 4: Try '*' operator
                // Multiplication has precedence → adjust running total
                // Example: "1+2*3"
                //   Before '*' we had curr_val = 3 (1+2), last_operand = 2
                //   We must "undo" the +2 → (3 - 2) = 1, then add (2*3) = 6
                //   So new curr_val = 1 + 6 = 7
                expr += "*" + operandStr;
                dfs(num, target, i + 1,
                    curr_val - last_operand + last_operand * operand, // adjust total
                    last_operand * operand,                           // update last operand
                    expr, results);
                expr.resize(lenBefore); // backtrack
            }
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    string num1 = "123";
    int target1 = 6;
    vector<string> result1 = sol.addOperators(num1, target1);
    cout << "Expressions for num=123, target=6:\n";
    for (auto &expr : result1) {
        cout << expr << endl;
    }

    // Example 2
    string num2 = "105";
    int target2 = 5;
    vector<string> result2 = sol.addOperators(num2, target2);
    cout << "\nExpressions for num=105, target=5:\n";
    for (auto &expr : result2) {
        cout << expr << endl;
    }

    return 0;
}
