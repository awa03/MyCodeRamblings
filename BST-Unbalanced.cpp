#include <iostream>
using namespace std;




template <typename T>
class Tree
{
private:
// node structure
    struct Node
    {
        int data; // val held
        Node *left; // left child < 
        Node *right; // right child >
        Node(T val) : data(val), left(nullptr), right(nullptr) {}  // defaults
    };

public:
    Tree() // default
    {
        root = NULL;
    }

    // Destructor
    ~Tree()
    {
        clear(root);
    }
    
    // assignment
    Tree &operator=(const Tree &other)
    {
        if (this != &other) // Avoid self-assignment
        {
            clear(root);         // Clear the existing content
            root = copyTree(other.root); // Copy the other tree
        }
        return *this;
    }

    Tree(const Tree& copy){ // copy constructor
        root = copyTree(copy.root);
    }

    void insert(T data){ // insertion 
        Node * temp = new Node(data); // int to null to start
        if(root == nullptr){
            root = temp;
            return;
        }
        else {
            findPos(temp, root); // recursive call
        }
        return; // end function

    }

    bool remove(T data)
    {
        return remove(data, root); // remove data
    }

    void inOrderPrint() const {
        inOrderPrint(root);
        cout << endl;
    }

private:
    Node *root;
    int size;

    void findPos(Node* newNode, Node*& curr){
        // base case
        if(curr == nullptr){
            // add new node to empty pos
            curr = newNode;
            return; 
        }
        else {
            if(newNode->data > curr->data){
                // if more
                findPos(newNode, curr->right);
            }
            else if(newNode->data < curr->data){
                // if less
                findPos(newNode, curr->left);
            }
            else {
                return; // if node is equal dont add
            }
        }
    }
    void inOrderPrint(Node* node) const {
        if (node != nullptr) {
            inOrderPrint(node->left);
            cout << node->data << " ";
            inOrderPrint(node->right);
        }
    }
    bool remove(T data, Node *&curr)
    {
        if (curr == nullptr)
        {
            return false; // Node with data not found
        }

        if (data < curr->data)
        {
            return remove(data, curr->left);
        }
        else if (data > curr->data)
        {
            return remove(data, curr->right);
        }
        else
        {
            // Node with data found, perform removal
            Node *temp = curr;

            if (curr->left == nullptr)
            {
                curr = curr->right;
            }
            else if (curr->right == nullptr)
            {
                curr = curr->left;
            }
            else
            {
                // Node has two children
                Node *minRightSubtree = findMin(curr->right);
                curr->data = minRightSubtree->data;
                remove(minRightSubtree->data, curr->right);
            }

            delete temp;
            return true; // Node with data removed
        }
    }
    Node *findMin(Node *node)
    {
        while (node->left != nullptr) 
        {
            node = node->left; // go to farthest left pos
        }
        return node;
    }

    Node* copyTree(Node* curr){
        if(curr == nullptr){ // if the node isnt null
            return nullptr;
        }
        Node* newNode = new Node(curr->data); // make a new node and set the structs data to it
        newNode->left = copyTree(curr->left); // copy the left node
        newNode->right = copyTree(curr->right); // copy the right node
        return newNode;
    }

    // clear tree
    void clear(Node *node)
    {
        if (node != nullptr) // if node is not blank clear it!
        {
            clear(node->left); // check left child of each node
            clear(node->right); // then right child of each node 
            delete node; // delete node
        }
    }

};


int main()
{
    Tree<int> t;
    
    // add elements
    t.insert(19);
    t.insert(1);
    t.insert(191);
    t.insert(11);

    t.remove(1);   // check
    t.remove(2);   // shouldnt work
    t.remove(191); // check

    t.insert(19);
    t.insert(1);
    t.insert(191);
    t.insert(11);

    // ---------------------------- // 
    // Should be {1 11 19 191}
    //           1
    //          / \
    //       null  11
    //              \
    //               19
    //                \
    //                191
    // ---------------------------- // 

    t.inOrderPrint();

    // Test Assignment
    Tree<int> j = t;
    // should be same tree
    j.inOrderPrint();

    return 0;
}
