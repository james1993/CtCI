/*
How would you design a stack which, in addition to push and pop, has a function
min which returns the minimum element all in O(1) time?
*/
class MinStack {
private:
    stack<int> basic_stack;
    stack<int> min_stack;
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        basic_stack.push(val);
        if(min_stack.empty()) min_stack.push(val);
        else if(val < min_stack.top()) min_stack.push(val);
        else min_stack.push(min_stack.top());
    }
    
    void pop() {
        basic_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return basic_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};