#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&inputStack,int count, int size){
    //Base Case
    if(count == size/2){
        inputStack.pop();
        return;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
    //Recursive call
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
    solve(inputStack,count, N);
}

int main(){
    stack<int> inputStack;

    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        inputStack.push(num);
    }

    deleteMiddle(inputStack, N);

   //push all elements of stack into string
    string str = "";
    while(!inputStack.empty()){
        str += to_string(inputStack.top());
        inputStack.pop();
    }

    //create a stack
    stack<char> st;

    //push all characters of string into stack
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }

    //pop all characters of stack and print them
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}