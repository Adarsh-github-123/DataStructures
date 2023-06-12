#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    
        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class LinkedList{
    Node* head;
    Node* tail;
    int length;
    
    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        
        void printList(){
            Node* temp = head;
            while(temp){
                cout << " " << temp -> value <<endl;
                temp = temp->next;
            }
        }
        
        void getHead(){
            cout << "Head: " <<head -> value <<endl;
        }
        
        void getTail(){
            cout<< "Tail: " <<tail -> value <<endl;
        }
        
        void getLength(){
            cout<<" The length of the list is: " <<length <<endl;
        }
        
        void append(int value) {
            Node* newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            } else {
                tail -> next = newNode;
                tail = newNode;
            }
            length++;
        }
        
        void delete_last(){
            if(head == NULL){
                return;
            }
            else {
                Node* temp = head;
                Node* pre;
                
                while(temp->next){
                    pre = temp;
                    temp = temp -> next;
                }
                
                tail = pre;
                tail -> next = NULL;
                length--;
                if(length == 0) {
                    head = NULL;
                    tail = NULL;
                }
            }
        }
        
        void prepend(int value) {
            Node* newNode = new Node(value);
            
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else{
                newNode -> next = head;
                head = newNode;
            }
            length++;
        }
        
        void delete_first() {
            if(head == NULL)
                return;
            if(length == 1) {
                head = NULL;
                tail = NULL;
            }
            else {
                Node* temp = head;
                head = head -> next;
                delete temp;
            }
            length--;
        }
        
        Node* get(int index) {
            Node* temp = head;
            if(index < 0 || index >= length) 
                return NULL;
            else {
                for(int i=0; i<index; i++)
                {
                    temp = temp -> next;
                }
            }
            return temp;
        }
        
        bool set(int index, int value) {
            Node* temp;
            temp = get(index);
            if(temp){
                temp -> value = value;
                return true;
            }
            return false;
        }
        
        bool insert_node(int index, int value){
            Node* newNode = new Node(value);
            if(index<0 || index>length)
                return false;
            if(index == 0){
                append(value);
                return true;
            }
            
            if(index == length){
                prepend(value);
                return true;
            }
            
            Node* temp = get(index-1);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            length++;
            return true;
        }
        
        void deleteNode(int index) {
            if(index < 0 || index >= length)
                return;
            if(index == 0)
                return delete_first();
            if(index == length-1)
                return delete_last();
                
            Node* prev = get(index-1);
            Node* temp = prev -> next;
            
            prev -> next = temp -> next;
            delete temp;
            length--;
        }
        
        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;
            
            Node* prev = NULL;
            Node* after = temp -> next;
            
            for(int i=0; i<length; i++) {
                after = temp -> next;
                temp -> next = prev;
                prev = temp;
                temp = after;
                
            }
        }
};


int main()
{
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->append(5);
    myLinkedList->printList();
    
    //myLinkedList->delete_last();
    
    //cout<<endl<<endl;
    //myLinkedList->printList();
    
    cout<<endl;
    myLinkedList->prepend(6);
    myLinkedList->printList();
    
    cout<<endl;
    myLinkedList->delete_first();
    myLinkedList->printList();
    
    cout<<endl;
    cout<<"Node at index 1 is: "<<myLinkedList->get(1)->value;
    
    cout<<endl;
    myLinkedList->set(1,8);
    myLinkedList->printList();
    cout<<"Node at index 1 is: "<<myLinkedList->get(1)->value;
    
    cout<<endl;
    myLinkedList->insert_node(1,9);
    myLinkedList->printList();
    
    cout<<endl;
    myLinkedList->deleteNode(1);
    myLinkedList->printList();
    
    cout<<endl;
    myLinkedList->prepend(2);
    myLinkedList->prepend(5);
    myLinkedList->printList();
    
    cout<<endl;
    myLinkedList->reverse();
    myLinkedList->printList();
    // myLinkedList->getHead();
    // myLinkedList->getTail();
    // myLinkedList->getLength();
    
    return 0;
}
