class MinStack {

    Stack<Integer> originalStack;
    Stack<Integer> minStack;

    public MinStack() {
        this.originalStack = new Stack<>();
        this.minStack = new Stack<>();
    }
    
    public void push(int value) {
        this.originalStack.add(value);
        if(minStack.isEmpty() ||  this.minStack.peek() >= value)this.minStack.add(value);
    }
    
    public void pop() {
        int top = this.originalStack.pop();
        if(this.minStack.peek() == top)this.minStack.pop();
    }
    
    public int top() {
        return this.originalStack.peek();
    }
    
    public int getMin() {
        return this.minStack.peek();
    }
}