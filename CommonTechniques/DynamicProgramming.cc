/*
Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable when the problem can be divided into overlapping subproblems that can be solved independently. DP is particularly useful for optimization problems where we want to find the best solution among many possible solutions.

Key Concepts:
Overlapping Subproblems: The problem can be broken down into smaller, overlapping subproblems.
Optimal Substructure: The optimal solution to the problem can be constructed from the optimal solutions of its subproblems.
Memoization: Store the results of subproblems to avoid redundant computations (top-down approach).
Tabulation: Solve subproblems iteratively and store the results in a table (bottom-up approach).
Example Problem: Fibonacci Sequence
The Fibonacci sequence is a classic example of a problem that can be solved using dynamic programming. The nth Fibonacci number is defined as:

F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1
Dynamic Programming Solution (Bottom-Up Approach)
Here is a C++ implementation of the Fibonacci sequence using dynamic programming:

Explanation:
Initialization: The function fibonacci takes an integer n as input and returns the nth Fibonacci number.
Base Cases: If n is 0 or 1, return n.
DP Table: Create a vector dp of size n + 1 to store the Fibonacci numbers.
Fill the DP Table: Use a for loop to fill the table from dp[2] to dp[n] using the relation dp[i] = dp[i - 1] + dp[i - 2].
Return the Result: Return dp[n], which contains the nth Fibonacci number.
Dynamic Programming Solution (Top-Down Approach with Memoization)
Here is a C++ implementation of the Fibonacci sequence using memoization:

Explanation:
Initialization: The function fibonacci initializes a memoization table memo with size n + 1 and all elements set to -1.
Helper Function: The function fibonacciHelper calculates the nth Fibonacci number using recursion and memoization.
Base Cases: If n is 0 or 1, return n.
Memoization Check: If memo[n] is not -1, return the stored result.
Recursive Calculation: Calculate memo[n] as the sum of the results of the subproblems fibonacciHelper(n - 1, memo) and fibonacciHelper(n - 2, memo).
Return the Result: Return memo[n], which contains the nth Fibonacci number.
Dynamic programming is a powerful technique that can be applied to a wide range of problems, including but not limited to:

Longest Common Subsequence
Knapsack Problem
Coin Change Problem
Matrix Chain Multiplication
Edit Distance
By breaking down problems into smaller subproblems and storing the results, dynamic programming helps to optimize the solution and reduce the time complexity.

Similar code found with 1 license type - View matches
*/
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the nth Fibonacci number using dynamic programming
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n = 10;
    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;
    return 0;
}