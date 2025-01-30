// https://leetcode.com/problems/valid-parentheses/description/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else
            {
                if (stack.empty())
                {
                    return false;
                }
                char top = stack.top();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};

int main()
{
    Solution solution;
    string s = "()";
    cout << solution.isValid(s) << endl;
    return 0;
}