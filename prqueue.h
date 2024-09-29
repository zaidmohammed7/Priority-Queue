/// @file prqueue.h
/// @author 
/// @date October 20, 2023
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Fall 2023

/****************************
 * Project 4: Priority Queue
 *
 * Course: CS 251, Fall 2023
 * System: WindowsOS using VSCode
 * Program Language: C++
 * Student Author: Zaid Khan Mohammed
 * *** **********************/

#pragma once
#include <iostream>
#include <sstream>
#include <set>
#include <string>
using namespace std;

template<typename T>
class prqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;       // stored data for the p-queue
        bool dup;      // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;    // links to linked list of NODES with duplicate priorities
        NODE* left;    // links to left child
        NODE* right;   // links to right child
    };
    NODE* root; // pointer to root node of the BST
    int sz;     // # of elements in the prqueue
    NODE* curr; // pointer to next item in prqueue (see begin and next)
    
    
    // function to convert the template variable to string and return the string
    string templateToString(T variable){
        ostringstream stream;
        stream<<variable; // passing template variable to stringstream
        return stream.str(); // returning string
    }


    // helper function to traverse the tree and return a string
    string stringRecursive(NODE* cur){
        string str="";
        if (cur==nullptr){ //stop when cur reaches nullptr
            return str;
        }
        // using in-order traversal
        str+=stringRecursive(cur->left);
        str+=to_string(cur->priority); // converting int priority to string
        str+=" value: ";
        str+=templateToString(cur->value);
        str+="\n";
        str+=stringRecursive(cur->link);
        str+=stringRecursive(cur->right);
        
        return str; // return string so far
    }


    // helper function to delete nodes recursively
    void deleteNode(NODE* cur){
        if (cur == nullptr) { // stop when cur reaches nullptr
            return;
        }
    // recursively delete the left, right and link
        deleteNode(cur->left);
        deleteNode(cur->right);
        deleteNode(cur->link);
        delete cur;
        --sz;
    }


    // helper function to traverse and recursively copy nodes from another tree. takes other node and parent node as parameters. returns pointer to a node
    NODE* copyNode(NODE* otherNode,NODE* parent){
        if (otherNode==nullptr){
            return nullptr; // stop when cur reaches nullptr
        }
        NODE* node=new NODE(); // create new node
        // setting value, priority and dup since those are the same 
        node->value=otherNode->value;
        node->priority=otherNode->priority;
        node->dup=otherNode->dup;
        node->parent=parent;
        // copying in post-order
        node->link=copyNode(otherNode->link,node);
        node->left=copyNode(otherNode->left,node);
        node->right=copyNode(otherNode->right,node);
        return node;
    }


    // helper function to recursively check if two nodes are equal in value and priority, for the entire tree
    bool checkEqual(NODE* node, NODE* otherNode) const {
        if (node == nullptr && otherNode == nullptr) {
            return true; //if both are null then both are equal
        }
        else if (node == nullptr || otherNode == nullptr) {
            return false; // because one is null and other is not
        }
        else if (node->priority != otherNode->priority || node->value != otherNode->value) {
            return false; // bacause one is null and other is not
        }
        
        // return true if node equals other node and left and right children are same, and link is also the same (recursively)
        return  checkEqual(node->link,otherNode->link) && checkEqual(node->left, otherNode->left) && checkEqual(node->right, otherNode->right);
    }

public:

    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    prqueue() {
        // setting default values of the tree
        root=nullptr;
        sz=0;
        curr=nullptr;    
    }
    

    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    prqueue& operator=(const prqueue& other) {
        clear(); // clearing tree to start copying
        if (other.root==nullptr){
            // dont copy anything if other tree is empty
            root=nullptr;
            sz=0;
        }
        else {
            // use helper function to copy tree
            root=copyNode(other.root,nullptr);
            sz=other.sz; // sz should have updated already... just making sure
        }
        return *this;
    }
    

    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() {
        deleteNode(root); // using helper function and passing the root to delete entire tree
        root=nullptr;
        sz=0; // just making sure
    }
    

    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~prqueue() {
        clear(); // clear tree at end of program
    }
    

    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    void enqueue(T value, int priority) {
        NODE* node=new NODE(); // create new node to add
        // initializing value, priority, and dup
        node->priority=priority;
        node->value=value;
        node->dup=false;
        // using prev ad cur pointers to find parent
        NODE* prev=nullptr;
        NODE* cur=root;
        while (cur!=nullptr){ // traverse tree according to priority
            if (priority==cur->priority){ // if priority already exists, add to link
                node->dup=true; 
                while (cur->link){ // add to end of linked list
                    cur=cur->link;
                }
                cur->link=node;
                node->parent=cur;
                // just added node, so it cant have its own link, left or right children
                node->link=nullptr;
                node->left=nullptr;
                node->right=nullptr;
                ++sz;
                return;
            }
            if (priority<cur->priority){ // move left if priority is less than cur priority
                prev=cur;
                cur=cur->left;
            }
            else{ // move right if priority is greater than cur priority
                prev=cur;
                cur=cur->right;
            }
        }
        if (prev==nullptr){
            root=node;
        }
        // deciding if node is left or right child of parent
        else if(priority<prev->priority){
            prev->left=node;
        }
        else{
            prev->right=node;
        }
        node->parent=prev;
        // just added node, so it cant have its own link, left or right children
        node->left=nullptr;
        node->right=nullptr;
        ++sz;
    }


    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T dequeue() {
        T valueOut;
        if (root==nullptr){
            // dont do anything
        }
        else{
            NODE* cur=root;
            while (cur->left){
                cur=cur->left; // find min node
            }
            if (cur->link){ // updating tree values accordingly if node to delete is a duplicate priority
                valueOut=cur->value;
                cur->link->dup=false;
                cur->link->parent=cur->parent; // resetting next node's parent 
                if (cur->link->link){
                    cur->link->link->parent=cur->link; // resetting next's next's parent if it exists
                }
                cur->link->right=cur->right;
                if (cur->right){
                    cur->right->parent=cur->link; // updating parent of right child only cuz we already travered to left-most child
                }
                if (cur->parent==nullptr){root=cur->link;}
                else{
                    if (cur==cur->parent->left){
                        cur->parent->left=cur->link; // updating parent's left if cur is a left child
                    }
                    else {cur->parent->right=cur->link;} // updating parent's right if cur is a right child
                }
                delete cur;
                --sz;
                return valueOut;
            }
            if (cur==root){ // if tree has one node, reset root
                if (cur->left==nullptr && cur->right==nullptr){ // set to nullptr if root has no children
                    root=nullptr; 
                    valueOut=cur->value;
                    delete cur;
                    --sz;
                    return valueOut;
                }
                root=cur->right; // new root becomes old root's right child, because left child can't exist (we would have deleted THAT if it did)
                root->parent=nullptr;
                valueOut=cur->value;
                delete cur;
                --sz;
                return valueOut;
            }
            else{ // if we reached here, it means cur has no left, link, and is not the root.
                cur->parent->left=cur->right;
                if (cur->right){cur->right->parent=cur->parent;} // update child's parent if it exists
                valueOut=cur->value;
                delete cur;
                --sz;
                return valueOut;
            }
        }
    }
    

    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int size() {
        return sz; // simply return the size :)
    }
    

    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        if (root==nullptr){ // curr is nullptr is theres no tree
            curr=nullptr;
            return;
        }
        curr=root; // initialize curr before traversal to smallest node
        while (curr->left){ // smallest node will be leftmost node
            curr=curr->left;
        }
    }
    

    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // advance the internal state in anticipation of future calls.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal. True is returned in all other cases as the inertnal
    // state has not reached the end of the priority queue. 
    //
    // Therefore, when another thing exists for future next() calls, 
    // true would be returned, when future next() calls would be invalid.
    // false would be returned.
    //
    // O(?) - hard to say.  But approximately O(logn + m).  Definitely not O(n).
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
        if (curr==nullptr){
            return false; // no next node available
        }
        value=curr->value;
        priority=curr->priority;
        if (curr->link){ // go to next node in linked list, if link exists
            curr=curr->link;
            return true;
        }
        while (curr->dup){ // reset to start of linked list (because start of linked list has dup==false)
            curr=curr->parent;
        }
        if (curr->right){ // go one step to the right then left-most node
            curr=curr->right;
            while (curr->left){
                curr=curr->left;
            }
            return true;
        }
        while (curr->parent){ // if no right subtree, keep climbing through parents till we find a node with a higher priority
            curr=curr->parent;
            if (curr->priority>priority){
                return true;
            }
        }
        // if we reached here, then theres no right subtree, and theres no parents with a higher priority, so no next node
        curr=nullptr;
        return false; 
    }
    

    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {
        string str = "";
        str=stringRecursive(root); // using helper function to recursive put tree into a string
        return str;
    }
    

    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number 
    // of duplicate priorities
    //
    T peek() {
        T valueOut;
        if (root==nullptr){ 
            // no tree
        }
        else{
            // traverse to min done
            NODE* cur=root;
            while (cur->left){
                cur=cur->left;
            }
            valueOut=cur->value;
            return valueOut;
        }  
    }
    

    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const prqueue& other) const {
        return checkEqual(root, other.root); // using helper function to recursively compare size, shape and nodes of 2 trees
    }
    

    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};