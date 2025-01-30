# Solved Problems

This repository contains solutions to various coding problems, primarily focused on binary trees and other data structures. Each problem is solved in C++ and includes a main function for testing the solution.

## List of Problems

### 1. Validate Binary Search Tree
- **File**: `ValidateBST.cc`
- **Description**: Checks if a given binary tree is a valid binary search tree (BST).
- **Solution**: Uses a recursive approach to validate the BST by ensuring that each node's value falls within a valid range.

### 2. Time Needed to Inform All Employees
- **File**: `TimeToInformAllEmployees.cc`
- **Description**: Calculates the time needed to inform all employees in a company, given the manager-subordinate relationships and the time each manager takes to inform their direct subordinates.
- **Solution**: Uses both BFS and DFS approaches to traverse the hierarchy and calculate the total time required.

### 3. Maximum Depth of Binary Tree
- **File**: `MaxDepthBT.cc`
- **Description**: Finds the maximum depth of a binary tree.
- **Solution**: Uses a recursive approach to calculate the depth by traversing each node and finding the maximum depth of its subtrees.

## How to Run

1. **Compile the code**: Use a C++ compiler to compile the code files. For example, to compile `ValidateBST.cc`, use the following command:
   ```sh
   g++ -o ValidateBST ValidateBST.cc