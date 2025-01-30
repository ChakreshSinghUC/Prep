// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
    private:
    stack<int> s1;
    stack<int> s2;

    public:
    /** Initialize your data structure here. */
    MyQueue()
    {

    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int val = s1.top();
        s1.pop();
        return val;
    }

    /** Get the front element. */
    int peek()
    {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
    return 0;
}