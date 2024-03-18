#include <iostream>
using namespace std;

class Stack{
    public:
        int size = 0;
        int top = -1;
        char *items;

        Stack(int stackSize){ //constructor
            size = stackSize;
            items = new char[size];
        }

        void push(char item){
            if(top==size-1){
                cout << "Stack Overflow, stack is full" << endl;
            }else{
                top++;
                items[top] = item;
            }
        }

        char pop(){
            char item;
            if(top==-1){
                cout << "Stack is empty" << endl;
            }else{
                item = items[top];
                top--; 
            }
            return item;
        }
};

int main(){
    cout << "hello world" << endl;

    Stack kantong1(5); //misalkan

    kantong1.push('A');
    kantong1.push('B');
    kantong1.push('C');
    kantong1.push('Z');
    kantong1.push('Y');

    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
}