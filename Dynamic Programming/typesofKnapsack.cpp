// The Knapsack Problem is a classic optimization problem in computer science and mathematics. It involves selecting a subset of items to maximize the total value while staying within a given capacity.
// Think of a Knapsack as a bag, we will be given some items as inputs. Each of the items, has a value and a weight (all values and weights are contained in an array). We are also given knapsack capacity W, which is the maximum total weight the knapsack can hold.
// The goal is to determine the maximum value that can be achieved by selecting items such that their total weight is less than or equal to W.

// Types of Knapsack Problems:

// 0/1 Knapsack Problem:
// Each item can either be included or excluded (picked once or not at all).
// Items: [(Value: 60, Weight: 10), (Value: 100, Weight: 20), (Value: 120, Weight: 30)]
// Knapsack capacity: W = 50
// Max Value: 220 (Items 2 and 3)

// Fractional Knapsack Problem:
// Items can be divided, allowing fractional quantities.
// Greedy algorithms solve this efficiently by sorting items based on value/weight ratio and picking fractions until capacity is filled.

// Unbounded Knapsack Problem:
// Items can be included multiple times (unlimited supply).