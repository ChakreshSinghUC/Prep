// https://leetcode.com/problems/min-stack/description/

#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    private:
    stack<int> s;
    stack<int> minStack;

    public:
    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int val)
    {
        s.push(val);
        if(minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if(s.top() == minStack.top())
        {
            minStack.pop();
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};
int main()
{
    MinStack *obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    return 0;
}

// Example 1:
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */