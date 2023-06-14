#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;
    
        Node(int value) {
            this->value = value;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList{
    public:
    Node* head;
    Node* tail;
    int length;
    
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        
        void printList(){
            Node* temp = head;
            while(temp){
                cout<<temp -> value <<endl;
                temp = temp -> next;
            }
        }
        
        void append(int value) {
            Node* newNode = new Node(value);
            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            } else {
                tail -> next = newNode;
                newNode -> prev = tail;
                tail = newNode;
            }
            length++;
        }
        
        void delete_last() {
            if(head == NULL)
                return;
            Node* temp = tail;
            if(length == 1) {
                head = NULL;
                tail = NULL;
            }
            else {
                tail = tail -> prev;
                tail -> next = NULL;
            }
            delete temp;
            length--;
        }
        
        void prepend(int value) {
            Node* newNode = new Node(value);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode -> next = head;
                head -> prev = newNode;
                head = newNode;
            }
            length++;
        }
        
        void deleteFirst(){
            if(head == NULL)
                return;
            Node* temp = head;
            if(length == 1){
                head = NULL;
                tail = NULL;
            }
            else {
                head = head -> next;
                head -> prev = NULL;
            }
            delete temp;
            length--;
        }
        
        Node* get(int index) {
            
            if(index <0 || index >=length)
                return NULL;
            Node* temp = head;
            if(index < length/2){
                
                for(int i=0; i<index; i++)
                {
                    temp = temp -> next;
                }
            }
            else{
                temp = tail;
                for(int i = length -1; i > index; i--) {
                    temp = temp -> prev;
                }
            }
            return temp;
        }
        
        bool set(int index, int value) {
            Node* temp = get(index);
            if(temp){
                temp -> value = value;
                return true;
            } 
            return false;
        }
        
        void insert(int index, int value){
            
            if(index<0 || index>length)
                return;
            if(index == 0){
                prepend(value);
            }
            if(index == length){
                append(value);
            }
            else{
                Node* newNode = new Node(value);
                Node* temp = get(index);
                Node* temp1 = temp -> prev;
                
                temp1 -> next = newNode;
                newNode -> prev = temp1;
                newNode -> next = temp;
                temp -> prev = newNode;
                length++;
            }
        }
        
        void delete_node(int index){
            if(index < 0 || index >=length){
                return;
            }
            if(index == 0){
                deleteFirst();
            }
            if(index == length-1){
                delete_last();
            }
            else{
                Node* temp = get(index);
                temp -> next -> prev = temp -> prev;
                temp -> prev -> next = temp -> next;
                delete temp;
                length--;
            }
        }
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    
    myDLL->printList();
    
    cout<<endl<<endl;
    myDLL->append(8);
    myDLL->printList();
    
    cout<<endl;
    myDLL->delete_last();
    myDLL->printList();
    
    cout<<endl;
    myDLL->prepend(6);
    myDLL->prepend(5);
    myDLL->append(8);
    myDLL->prepend(4);
    myDLL->printList();
    
    cout<<endl;
    cout<<myDLL->get(3)->value;
    
    cout<<endl<<endl;
    myDLL->set(3, 10);
    myDLL->printList();
    
    cout<<endl;
    myDLL->insert(1,11);
    myDLL->printList();
    
    cout<<endl<<myDLL->tail->value;
    
    cout<<endl<<endl;
    myDLL->delete_node(5);
    myDLL->printList();
    
    // cout<<endl;
    // myDLL->deleteFirst();
    // myDLL->printList();
    return 0;
}
