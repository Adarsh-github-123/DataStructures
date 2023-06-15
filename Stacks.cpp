#include <iostream>
//#include <limits.h>

using namespace std;


class Node { 
    public: 
        int value;
        Node* next;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};


class Stack {
    private:
        Node* top;
        int height;

    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        ~Stack() {
            Node* temp = top;
            while (top) {
                top = top->next;
                delete temp;
                temp = top;
            }
        }

        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        int getTop() {
            if (top == nullptr) {
                return INT_MIN;
            } else {
                return top->value;
            }
        }
        
        int getHeight() {
            return height;
        }

        // WRITE PUSH MEMBER FUCTION HERE //
        void push(int value){
            Node* newNode = new Node(value);
            newNode -> next = top;
            top = newNode;
            height++;
        }
        
        // WRITE POP MEMBER FUCTION HERE //
        int pop(){
            if(top == NULL)
                return INT_MIN;
            
            Node* temp = top;
            int poppedValue = temp -> value;
            top = top -> next;
            delete temp;
            height--;
            return poppedValue;   
        }
        
};