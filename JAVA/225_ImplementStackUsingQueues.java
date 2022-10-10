// Aneesh Gupta
// 10-10-2022

class MyStack {

    Queue<Integer> mainQ;
    Queue<Integer> helperQ;
    public MyStack() {
        mainQ = new ArrayDeque<>();
        helperQ = new ArrayDeque<>();
    }
    
    public void push(int x) {
        mainQ.add(x);
    }
    
    public int pop() {
        if(mainQ.size() == 0){
            return -1;
        }
        while(mainQ.size() != 1){
            helperQ.add(mainQ.remove());
        }
        int val = mainQ.remove();
        while(helperQ.size() != 0){
            mainQ.add(helperQ.remove());
        }
        return val;
    }
    
    public int top() {
        if(mainQ.size() == 0){
            return -1;
        }
        while(mainQ.size() != 1){
            helperQ.add(mainQ.remove());
        }
        int val = mainQ.peek();
        helperQ.add(mainQ.remove());
        while(helperQ.size() != 0){
            mainQ.add(helperQ.remove());
        }
        return val;
    }
    
    public boolean empty() {
        return mainQ.size() == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
