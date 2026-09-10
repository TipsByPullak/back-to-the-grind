class MinStack {
public:
    stack<int> elements;
    stack<int> minElements;
    MinStack() {
        
    }
    
    void push(int val) {
        elements.push(val);

        if (minElements.empty() || val <= minElements.top())
        {
            minElements.push(val);
        }
    }
    
    void pop() {
        int element = elements.top();
        elements.pop();

        int minElement = minElements.top();
        if (element == minElement) minElements.pop();
    }
    
    int top() {
        if (!elements.empty())
            return elements.top();

        return -1;
    }
    
    int getMin() {
        if (!minElements.empty())
            return minElements.top();

        return -1;
    }
};
