/*
Imagine a stack of plates. If the stack gets too high, it might topple. Therefore,
in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should
be composed of several stacks and should create a new stack once the previous one exceeds
capacity.
*/
class SetOfStacks{
private:
    vector<stack<int>> stacks;
    int current_stack;
    int capacity;
public:
    SetOfStacks(int cap)
    {
        stacks.push_back(stack<int>());
        current_stack = 0;
        capacity = cap;
    }
    void push(int val)
    {
        if(stacks[current_stack].size() >= capacity)
        {
            stacks.push_back(stack<int>());
            current_stack++;
        }
        stacks[current_stack].push(val);
    }
    void pop()
    {
        if(stacks[current_stack].empty()) current_stack--;
        stacks[current_stack].pop();
    }
    bool empty()
    {
        return current_stack == 0 && stacks[current_stack].empty();
    }
    int top()
    {
        return stacks[current_stack].top();
    }
    
};

int main() {
    SetOfStacks stacks(2);
    stacks.push(1);
    stacks.push(2);
    stacks.push(3);
    stacks.push(4);
    stacks.push(5);
    stacks.pop();
    stacks.pop();
    stacks.pop();
    stacks.pop();
    
    while(!stacks.empty())
    {
        cout << stacks.top() << "\n";
        stacks.pop();
    }
    return 0;
}