// ---------------------------------------------------------------------------------------------- //
//                                          Linky Listy                                           
// A working demonstration of the use of linked lists in creating multiple data structures.Within //
// this code you will explore my thought process as well as see how I code. This was mainly made  //
// for practice, but I think reading it may provide some insight. Thanks! - Aiden Allen
// ---------------------------------------------------------------------------------------------- //

#include <iostream>
using namespace std;

// so im basically going to have some fun with linked lists
// im thinking im going to make maybe like a stack or queue IDK!
// so lets detail these thoughts. im not going to delete code or anything
// especially if its really stupid so. Just for me to think outload lol.

// alright so lets make a node. because its gotta point to something right
template <typename T> // im assuming this can cause issues because its not in the class
// but im not going to worry about it, because its an easy fix and im not going to assign a 
// int to a string or anything without attempting type conversion
struct Node{ 
    Node<T>* next; // so we need somewhere to point to because we need to know the list
    T data; // obv need some data. 
    Node(T val) : data(val), next(nullptr) {}  // defaults
    // defaults- i guess, probably unneeded, but it will make my life easier
};

// now lets make this bloody class.
template<typename T>
class LinkyListy{
private:
    // i dont normally put this at the top but it works better for explaining the order of my thoughts
    // so lets init the start and end points, not going to be doubly linked, but stack and queue will be 
    // much easier to make because of it - I know im going to have to iterate but im lazy
    // oooooo im going to add a reverse funtion for bonus points
    Node<T>* front; // first node, for some reason i always reverse this lol
    Node<T>* back; // last node, genuinely im glad im writing this down - serves as root
    // nothing more for now in private I think.... if im going to add helpers ill put them
    // in another section, but im really into recursion rn so helpers will probably be there.
    // even though a while loop would suffice

    int size;   // ---------- The Next Morning ---------- // 
                // so im going to add size into the       //
                // mix to make this a little more usable  //
                // -------------------------------------- //


public:
    LinkyListy(){
        // ummmm prob make it null to start, no default val obv
        front = nullptr; // make em null
        back = nullptr; // make it NULLLLL, go Null's btw
        size = 0; // next day addition
    }
    LinkyListy(T data){
        // lets add something because we are in nullville rn
        // will make the queue/stack implementations easier
        Node<T>* temp = new Node<T>(data); // set the data in a cool way
        // Dont ask, I forgot I was in default constructor 
        // if (front == nullptr) { // check if its empty
        // if so then add the node
        front = temp;
        back = temp;
        size++; // next day addition
        //} 

        // please dont ask why i wrote this for a default constructor
        /*else {
            // if its not empty just change the end
            back->next = temp;
            back = temp;
        }*/
    }
    // O(1) time complexity, pretty epic insertion. 
    void insertFront(T data){
        size++;
        // now for the fun stuffff
        // lets first handle if theres no items because I forget about that case
        // okay so i need to make a new node for insertion
        // basically copy paste the default
        Node<T>* temp = new Node<T>(data); // make this nodeee
        if(front == nullptr){ 
            front = temp; // make the front it
            back = temp; // make the back it
            return; // were done here boys, unneeded but i like returns sue me
        }
        else { // if it has +1 element
            temp->next = front; // the new nodes next will be the front
            front = temp; // the front will now be the new node
        }
        //  add 9 | 1 = front | 9 -> 1 -> ...
    }
    // O(1)
    void insertBack(T data){
        size++;
        Node<T>* temp = new Node<T>(data); // yoinked from above
        // STOLENNNNN
        if(front == nullptr){ 
            front = temp; // make the front it
            back = temp; // make the back it
            return; // were done here boys, unneeded but i like returns sue me
        }
        else {
            // I way overthought this. This is easy. just attach to end
            back->next = temp;  // attach
            back = temp; // back is now the back, basically the same as above
        }
    }

    void printList(){
        Node<T>* curr = front;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    // Alrighty! Im going to test this now, prob should have done sooner buttt!
    /*
    Code Tested 
    cout << "This is a test of Linky List" << endl;
    LinkyListy<int> list;

    int userInsert;
    char userOption;
    while(userInsert != 0){
        cout << "Enter 0 to stop entering" << endl;
        cin >> userInsert;
        if(userInsert == 0){break;}
        cout << "Enter 'f' for the front || 'b' for the back" << endl;
        cin >> userOption;

        if(userOption == 'f'){
            list.insertFront(userInsert);
        }
        else {
            list.insertBack(userInsert);
        }
    }
    list.printList();
    */

    // now lets add a copy constructor... oops should have done this already
    // also an assignment operator i suppose while we are at it
    LinkyListy(const LinkyListy& copyMe){ // copy the linked list
        size = copyMe.size;
        front = nullptr; // set to null
        Node<T>* current = copyMe.front;
        while (current != nullptr) {
            Node<T>* newNode = new Node<T>(current->data); // new node with the currets dataaaa
            // if the list is empty set both front and the back
            if(front == nullptr){
                front = newNode;
                back = newNode;
            }
            else {
                // link to existing nodes....
                // basically just continually pushing them
                back->next = newNode;
                back = newNode;
            }
            current = current->next; // iterate through the linkylisty
        } 
        // it could be fun to try something like this as well
        // try like setting every node in the list and stopping when its equal to the back
        // idk this is my fav way im just spittin, I really enjoy seeing problems from 
        // multiple perspectives because honestly even if its less efficent some methods
        // can be very interesting, ive seen some voodoo magic in some peoples code
        // basically all im saying is its really interesting to me peoples thought process
        // thats part of the reason im actually documenting mine right now, because
        // everyone is different, so im curious to see how my thoughts compare to others
    }
    // Enough rambling lets move onnnnn to the assignment. My least fav operator tbh. 
    // even though its pretty similar to copy, its just always on my hate list. 
    // because of this im going to prolong the assignment operator and squeeze in a clear
    // funciton because im probably going to use it in the future. Im trying not to 
    // back track on my code, so its authentic, but i may need to. Anyways I said I wouldnt ramble

    void clear() { // alright here it is the clear
        Node<T>* current = front; // so we are going to get the front
        while (current != nullptr) { // more iteration 
            Node<T>* next = current->next; // next is tecnically unnessicary i think but whatever
            // like i could probably do something like
            /*
                               Code
                ____________________________________
                Node<T>* current = front;
                while (current != nullptr) {
                    Node<T>* next = current->next;
                    delete current;
                    current = next;
                }
                front = nullptr;
                ____________________________________
            */ 
            // but thats lame so lets do this because it looks cooler

            delete current; // delete the nodeeee
            current = next; // set the curr to the next
        }
        front = nullptr;
        size = 0;
    }

    // Okay Okay lets get to the assignment already
    LinkyListy& operator=(const LinkyListy& assignMe){ // assignMe UwU
        // lets check if its already the same list
        if (this == &assignMe) { // dont want to work if i dont wanna
            return *this; // also lower bound is now O(1)
        }
        size = assignMe.size;
        clear(); // get rid of those nodes
        front = nullptr; // set the front to null
        back = nullptr; // set the back to null
        Node<T>* current = assignMe.front; // get that first node

        // alright now im going to need to basically just copy it again lol
        // i told you it was similar
        // so lets first make a while loop!!! ITERATION GALORE

        while (current != nullptr) {
            Node<T>* newNode = new Node<T>(current->data); // same old story i warned you
            if (front == nullptr) {
                front = newNode;
                back = newNode; 
            } else {
                back->next = newNode; // add to the back
                back = newNode;
            }
            // so now we move to the next node in the list
            current = current->next;
        }   
        // now we return the current obj fully assigned. 
        return *this;
    }
    
    // Alrighty then. Lets test this baddy again. I made another test!
    // This time im not going to manually input them because... IM LAZY!
    // So heres my test code... 

    /*
        LinkyListy<int> list;
        list.insertFront(3);
        list.insertFront(2);
        list.insertFront(1);
        list.insertBack(4);
        list.insertBack(5);

        cout << "Original List: ";
        list.printList();
        cout << endl;

        // Test copy constructor
        LinkyListy<int> copiedList(list);
        cout << "Copied List: ";
        copiedList.printList();
        cout << endl;

        // Test assignment operator
        LinkyListy<int> assignedList;
        assignedList = list;
        cout << "Assigned List: ";
        assignedList.printList();
        cout << endl;

        // Test clear
        list.clear();
        cout << "Cleared Original List: ";
        list.printList();
        cout << endl;

        return 0;
    */

    // Also Heres the output
    /*
        Original List: 1 2 3 4 5 
        Copied List: 1 2 3 4 5 
        Assigned List: 1 2 3 4 5 
        Cleared Original List:
    */

    // now less do removeFront, removeBack. I know i should use push_front, push_back...
    // but I dont want to. so yea.
    // anyways heres the removeFront

    Node<T>* removeFront(){ // im ngl this took literally 5 seconds
    
    // god i love linked lists. so easy
        if(front == nullptr){ // if its empty cant remove
            return nullptr; // empty return
        }
        else{
            size--;
            // return the node because why not
            Node<T>* temp = front;
            front = front->next;
            return temp;
        }
    }
    // um so it works by basically saying
    // 4 -> 3 -> 2 -> 1
    // if we want to remove 4 then
    // the front is now 3. so there is nothing chaining 4 to 3. Then we return it

    // Lets do remove back now. Im now sure if im going to remove data, or remove node, etc
    // just because its not really relavant to my applications but ill think about it
    
    Node<T>* removeBack(){
        // get this out of the way
        if (front == nullptr) {
            return nullptr;  // List is empty
        }
        size--;

        // okay so this ones going to be different because im an idiot. 
        // this is going to be O(n) because i didnt make this doubly linked. So
        // no one tell on me. a vector would honestly be faster than this but!
        // WHO CARES. Time is relative, thats what i tell myself at least

        Node<T>* temp = front; // so lets get the front again

        // if we only have one element we need to handle that
        if (front == back) {
            Node<T>* removedNode = front;
            front = nullptr;
            back = nullptr;
            return removedNode;
        }

        // now lets iterate once again
        while(temp->next != back){
            temp = temp->next; // ++
        }

        // so now we are at the element before the back
        Node<T>* removedNode = back; // init the removal
        back = temp;  // set the back to the one before
        back->next = nullptr;  // set new back to null rather than the old back element

        return removedNode; // return it
    }

    // Okay so i want to work on something more fun some im going to reverse the list. 
    // so i need to get my google internship, so lets do this. First Try???
    void reverse_that_list(){ // sounds like a chant from a gameshow 
        Node<T>* prev = nullptr; // you already know
        Node<T>* current = front;
        Node<T>* next = nullptr;

        // okay im going to be honest ive never done this so be patient
        // okay so i know all im doing is going to be this
        // 4 -> 2 -> 3
        // 4 <- 2 <- 3

        // so lets start by iterating through this bad boy
        while(current != nullptr){
            next = current->next; // so 2 = next
            current->next = prev; // 2 now points to 4
            prev = current; // so 4
            current = next; // curr is now next element
            // so this should work i think
        }
        back = front;
        front = prev;
    }

    // WORKED FIRST TRY! (okay tbf i had a syntax error. stupid templates)

    /*
        Test Code

    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);
    list.insertBack(4);
    list.insertBack(5);

    cout << "Original List: ";
    list.printList();
    cout << endl;

    // Test copy constructor
    LinkyListy<int> copiedList(list);
    cout << "Copied List: ";
    copiedList.printList();
    cout << endl;

    // Test assignment operator
    LinkyListy<int> assignedList;
    assignedList = list;
    cout << "Assigned List: ";
    assignedList.printList();
    cout << endl;

    // Test clear
    list.clear();
    cout << "Cleared Original List: ";
    list.printList();
    cout << endl;

    // Test removeFront
    LinkyListy<int> removeFrontList;
    removeFrontList.insertBack(1);
    removeFrontList.insertBack(2);
    removeFrontList.insertBack(3);
    Node<int>* removedNode = removeFrontList.removeFront();
    cout << "Removed Front Node: " << removedNode->data << endl;

    // Test removeBack
    LinkyListy<int> removeBackList;
    removeBackList.insertBack(1);
    removeBackList.insertBack(2);
    removeBackList.insertBack(3);
    removedNode = removeBackList.removeBack();
    cout << "Removed Back Node: " << removedNode->data << endl;

    // Test reverse_that_list
    LinkyListy<int> reverseList;
    reverseList.insertBack(1);
    reverseList.insertBack(2);
    reverseList.insertBack(3);
    cout << "Original List for Reverse: ";
    reverseList.printList();
    cout << endl;
    reverseList.reverse_that_list();
    cout << "Reversed List: ";
    reverseList.printList();
    cout << endl;
    */

    // um so im going to start on the stack and queue now. If i come back to this for the search, etc
    // ill add date comments and seperators etc. Until then lets get started on this stack.


    // ---------------------------------- 5 minutes later ---------------------------------- //
    // I forgot to add top and bottom so lets implement those getters
    // also i might as well make a deque later, seeing as i added back functionality

    T getFront(){
        return front->data;
    }
    T getBack(){
        return back->data;
    }

    // ----------------------------------- 8 hours later ----------------------------------- //
    // Okay so im going back to this like 8 hours later (like 2am to 10 am) because in my dreams I realized
    // I need to add more to this do its not literally a double ended queue already lol
    // so lets do that
    
    Node<T>* search(T data){
        // so we are going to return the curr node when the data is equal
        Node<T>* curr = front;    // lets make the iteration node
        while(curr != nullptr){
            if(curr->data == data){ // check if equal
                return curr;
            }
            // now iterate
            curr = curr->next;
            // Thats it.
        }
    }

    // now lets add a search remove
    Node<T>* deleteData(T data){
        Node<T>* curr = front;     // so i need curr and prev pointers
        Node<T>* prev = nullptr;

        // if the list is empty
        if(curr == nullptr){
            return nullptr;
        }

        if (curr->data == data) {
            size--;
            front = curr->next;
            if (front != nullptr) {
                back = nullptr; // If the list becomes empty
            }
            return curr;
        }   

        while(curr != nullptr){
            if(curr->data == data){ 
                size--;
                // if its at the back of the list
                if(curr->next == nullptr){
                    prev->next = nullptr;
                    back = prev;
                    return curr;
                }

                prev->next = curr->next; // set prev to next
                // essentially saying 3 -> 2 -> 4
                // would skip over the two, making 3 point directly to 4
                return curr;
            }
            prev = curr; // set previous element to current
            curr = curr->next; // iterate current
            // So basically this is saying
            // if i have 2 iterators i, j. if i do i = j; i++ then i will always be one pointer behind
            // j, inturn making it the previous element
        }
    }
    // now we have something that isnt awful! its not a deque anymore!

    // lets add the size now, because why not we need it i suppose
    int getSize(){
        return size; // well that wasnt too hard
    }

};
// okay let me first stay ik you shouldnt code like this. but i dont feel like putting in the headers
// and doing all that. I am making this to demonstrate my thought process and that is way too spread out
// to be understandable. So im going to do this. 

// so the stack first i guess LIFO 
template<typename T>
class StackityStack{
private:
    // ill add the size to the LL later. or I could do it in here....
    // int size; 
    LinkyListy<T> list;

public:
    StackityStack(){} // thats it lol

    void push(T data){
        list.insertBack(data); // im going to add it to the back and remove from the front 
        // could do this swapped, buttt i can save time because of my horrible
        // idea to make back need iteration for removal
        // so it only really makes sense to do it this way, honestly i didnt think abt 
        // this to start with, but thats the beauty of programming, ideas can pop up and 
        // revolutionize your structure.
        // anyways thats literally all the code lol
    }
    Node<T>* pop(){ // ik names, but im making my own thing here leave me be
        // this is my Data Structure no one controls me
        return list.removeFront();
    }
    
    // ... i forgot to add a top... ill brb

    T top(){
        return list.getFront();
    }

    // ill add this too because why not
    Node<T>* popData(){ 
        // just return the objects data
        Node<T> data = list.removeFront();
        return data; 
    }

    // this doesnt need to be implemented because it exists within the list
    StackityStack(const StackityStack& copyMe) : list(copyMe.list) {}

    // another easy peasy one
    StackityStack& operator=(const StackityStack& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    // I hope im kinda serving as an advocate for modularizing your code here. I mean look at how easy
    // this stack is, and how easy it will be to add deque and queue. 

    void printStack(){
        list.printList();
    }

    // easy peasy
    int size(){
        return list.getSize();
    }
};

// now lets do the queue. im really not expecting any issues with this because im essentially going to only change two lines
// from the stack class i think.
// UQUQUQU
template<typename T>
class QueueQueue{
    // SO I LEGIT COPIED THE CODE. Find and replace is epic


private:
    // ill add the size to the LL later. or I could do it in here....
    // int size; 
    LinkyListy<T> list;

public:
    QueueQueue(){} // thats it lol

    void push(T data){
        list.insertFront(data); // so lets fix this... done i think
    }

    Node<T>* pop(){ // ik names, but im making my own thing here leave me be
        // this is my Data Structure no one controls me
        return list.removeFront();
    }
    
    // ... i forgot to add a top... ill brb

    T top(){
        return list.getFront();
    }

    // ill add this too because why not
    Node<T>* popData(){ 
        Node<T>* data = list.removeFront();
        return data;  
    }

    // this doesnt need to be implemented because it exists within the list
    QueueQueue(const QueueQueue& copyMe) : list(copyMe.list) {}

    // another easy peasy one
    QueueQueue& operator=(const QueueQueue& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    // I hope im kinda serving as an advocate for modularizing your code here. I mean look at how easy
    // this stack is, and how easy it will be to add deque and queue. 

    void printQueue(){
        list.printList();
    }

    // easy peasy
    int size(){
        return list.getSize();
    }
};

// Okay we are pretty much done with this entire thing. now lets make the deque
template<typename T>
class Deque{ // normal name this time
private:
    LinkyListy<T> list; // linky listy

public:
    Deque(){} // again thats it lol

    // so im going to note what i need here
    // size - Done
    // print - Done
    // insertFront - Done
    // insertBack - Done
    // popFront - Done
    // popBack - Done
    // operator= - Done
    // for the return type im not going to do the node and all that
    // im just going to return the data, easier for the user to understand

    void push_front(T data){
        list.insertFront(data);
    }
    void push_back(T data){
        list.insertBack(data);
    }
    T pop_front(){
        T removeData = (list.removeFront())->data;
        return removeData;
    }
    T pop_back(){
        T removeData = (list.removeBack())->data;
        return removeData;
    }
    Deque& operator=(const Deque& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }
    int size(){
        return list.getSize();
    }
    void printDeque(){
        list.printList();
    }
    // basically just a smaller version of the linked list haha. pretty useless for this!
};




void TestLinkedList(){
    cout << "####################################################" << endl;
    cout << "Testing The Linked List Implementation" << endl;
    cout << "####################################################" << endl;

    LinkyListy<int> list;
    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);
    list.insertBack(4);
    list.insertBack(5);

    cout << "Original List: ";
    list.printList();
    cout << endl;

    // Test copy constructor
    LinkyListy<int> copiedList(list);
    cout << "Copied List: ";
    copiedList.printList();
    cout << endl;

    // Test assignment operator
    LinkyListy<int> assignedList;
    assignedList = list;
    cout << "Assigned List: ";
    assignedList.printList();
    cout << endl;

    // Test clear
    list.clear();
    cout << "Cleared Original List: ";
    list.printList();
    cout << endl;

    // Test removeFront
    LinkyListy<int> removeFrontList;
    removeFrontList.insertBack(1);
    removeFrontList.insertBack(2);
    removeFrontList.insertBack(3);
    Node<int>* removedNode = removeFrontList.removeFront();
    cout << "Removed Front Node: " << removedNode->data << endl;

    // Test removeBack
    LinkyListy<int> removeBackList;
    removeBackList.insertBack(1);
    removeBackList.insertBack(2);
    removeBackList.insertBack(3);
    removedNode = removeBackList.removeBack();
    cout << "Removed Back Node: " << removedNode->data << endl;

    // Test reverse_that_list
    LinkyListy<int> reverseList;
    reverseList.insertBack(1);
    reverseList.insertBack(2);
    reverseList.insertBack(3);
    cout << "Original List for Reverse: ";
    reverseList.printList();
    cout << endl;
    reverseList.reverse_that_list();
    cout << "Reversed List: ";
    reverseList.printList();

    cout << "Search Node Return Val: " << reverseList.search(1) << endl; // get the data item

    cout << "Delete Node 1: " << reverseList.deleteData(1) << endl;

    reverseList.printList();
    cout << endl;

    cout << "Current List Size" << reverseList.getSize() << endl;

    cout << endl;
    cout << endl;
}

void TestStack(){
    cout << "####################################################" << endl;
    cout << "Testing The Stack Implementation" << endl;
    cout << "####################################################" << endl;
    StackityStack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Print the initial stack
    myStack.printStack();
    cout << endl;

    // Test copy constructor
    StackityStack<int> copiedStack(myStack);
    cout << "Copied Stack (using copy constructor): " << endl;
    copiedStack.printStack();
    cout << endl;

    // Test assignment operator
    StackityStack<int> assignedStack;
    assignedStack = myStack;
    cout << "Assigned Stack (using assignment operator): " << endl;
    assignedStack.printStack(); 
    cout << endl;

    // Test popping and printing the top element
    Node<int>* poppedNode = myStack.pop();
    if (poppedNode != nullptr) {
        cout << "Popped Top Element: " << poppedNode->data << endl;
        delete poppedNode;
    }

    // Test top element without removing it
    cout << "Top Element without removal: " << myStack.top() << endl;

    cout << endl;
}

void TestQueue(){
    cout << "####################################################" << endl;
    cout << "Testing The Queue Implementation" << endl;
    cout << "####################################################" << endl;

    QueueQueue<int> myQueue;

    // Test push operation
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Test pop and top operations
    std::cout << "Top element: " << myQueue.top() << std::endl;
    Node<int>* poppedNode = myQueue.pop();
    std::cout << "Popped element: " << poppedNode->data << std::endl;

    // Test popData operation
    Node<int>* poppedDataNode = myQueue.popData();
    if (poppedDataNode != nullptr) {
        std::cout << "Popped data element: " << poppedDataNode->data << std::endl;
    } else {
        std::cout << "Queue is empty. Cannot pop data." << std::endl;
    }

    // Test size and print operations
    std::cout << "Queue size: " << myQueue.size() << std::endl;
    std::cout << "Queue contents: ";
    myQueue.printQueue();

    cout << endl;
    cout << endl;
}

void TestDeque(){
    cout << "####################################################" << endl;
    cout << "Testing The Deque Implementation" << endl;
    cout << "####################################################" << endl;
    Deque<int> deque;

    // Test push_front
    deque.push_front(1);
    std::cout << "Size after push_front: " << deque.size() << std::endl;
    std::cout << "Deque after push_front: " << endl;
    deque.printDeque();
    cout << endl;

    // Test push_back
    deque.push_back(2);
    std::cout << "Size after push_back: " << deque.size() << std::endl;
    std::cout << "Deque after push_back: " << endl;
    deque.printDeque();
    cout << endl;

    // Test pop_front
    int frontValue = deque.pop_front();
    std::cout << "Popped value from front: " << frontValue << std::endl;
    std::cout << "Size after pop_front: " << deque.size() << std::endl;
    std::cout << "Deque after pop_front: " << endl;
    deque.printDeque();
    cout << endl;

    // Test pop_back
    int backValue = deque.pop_back();
    std::cout << "Popped value from back: " << backValue << std::endl;
    std::cout << "Size after pop_back: " << deque.size() << std::endl;
    std::cout << "Deque after pop_back: ";
    deque.printDeque();
    cout << endl;

    // Test assignment operator
    Deque<int> anotherDeque;
    anotherDeque = deque;
    std::cout << "Size of anotherDeque after assignment: " << anotherDeque.size() << std::endl;
    std::cout << "anotherDeque after assignment: " << endl;
    anotherDeque.printDeque();
    cout << endl;

    std::cout << "All tests completed!" << std::endl;

    cout << endl;
    cout << endl;
}

int main(){
    TestLinkedList(); // make it a funciton call much more fun
    TestStack();
    TestQueue();
    TestDeque();
}

// Okay Thats it. I hope you enjoyed my rambling. I know this was stupid and kinda simple but its fun!
// Build Data Structures! Theyre amazing pracitice