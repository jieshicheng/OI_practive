#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> master_stack;
    stack<int> min_stack;
    
    /** initialize your data structure here. */
    MinStack() {
        master_stack = stack<int>();
        min_stack = stack<int>();
    }
    
    void push(int x) {
        master_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }
    
    void pop() {
        if (master_stack.empty()) {
            return ;
        }

        if (master_stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        master_stack.pop();
    }
    
    int top() {
        return master_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main() {
    MinStack obj = MinStack();
    obj.push(10);
    obj.push(12);
    obj.push(1);
    obj.push(2);
    cout << obj.top() << endl;
    cout << obj.getMin() << endl;
    return 0;
}
