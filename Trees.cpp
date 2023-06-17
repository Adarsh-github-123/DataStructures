/*

Algorithm for insert

create newNode
if root == nullptr then root = newNode
temp = root
while loop
    if newNode == temp return false
    if < left else > right 
    if nullptr insert newNode else move to next

------------------------------------------------------------

Algorithm for contain

if root == nullptr return false
temp = root
while temp != nullptr
    if < left
    else if > right
    else == return true
return false

*/

#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Below is a helper function used by the destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode->left) destroy(currentNode->left);
            if (currentNode->right) destroy(currentNode->right);
            delete currentNode;
        }

        ~BinarySearchTree() { destroy(root); }
 

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }

        // WRITE CONTAINS MEMBER FUCTION HERE //
        bool contains(int value){
            if(root == NULL) return false;
            Node* temp = root;
            while(temp){
                if(value < temp -> value){
                    temp = temp -> left;
                }
                else if(value > temp -> value){
                    temp = temp -> right;
                }
                else{
                    return true;
                }
            }
            return false;
        }    
        
};