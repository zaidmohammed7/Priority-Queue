/// @file tests.cpp
/// @author 
/// @date October 20, 2023

/// 
/// TODO Update the file header with the appropriate information.
///

/// Provided testing file to implement framework based tests in. The examples
/// below demonstrates a basic empty test in each framework with a single
/// assertion. The version uses the supplied catch.hpp file in starter code.
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Fall 2023

// Catch 2.x - Single Include Framework Testing
#define CATCH_CONFIG_MAIN

#include "prqueue.h"
#include "catch.hpp"
#include <map>

using namespace std;

template<typename T>
string templateToString(T variable){
    ostringstream stream;
    stream<<variable; // passing template variable to stringstream
    return stream.str(); // returning string
}

template<typename T>
string mapToString(map<int,vector<T>> mp){
    stringstream ss;
    for (const auto &e: mp) {
        int priority = e.first;
        vector <T> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    return ss.str();
}

template<typename T>
void mapDequeue(map<int,vector<T>>& mp){
    auto e=mp.begin();
    if (e->second.size()==1){
        mp.erase(e);
    }
    else {
        e->second.erase(e->second.begin());
    }
}

// This is a basic test case example with sections.
// Requires: <no oter functions>
TEST_CASE("Test 0: The Null Test") 
{
    // In this section we test Scenario 1.
    SECTION("Test 0: Empty Truths")
    {
        REQUIRE(true == true);
    }

    // In this section we test Scenario 2.
    SECTION("Test 0: Empty Falsehoods")
    {
        REQUIRE(false == false);
    }
}

TEST_CASE("Test 1: testing prqueue")
{
    SECTION("default constructor when using int value")
    {
        prqueue<int> myQueue;
        REQUIRE(myQueue.toString()=="");
    }
    SECTION("default constructor when using float value")
    {
        prqueue<float> myQueue;
        REQUIRE(myQueue.toString()=="");
    }
    SECTION("default constructor when using char value")
    {
        prqueue<char> myQueue;
        REQUIRE(myQueue.toString()=="");
    }
    SECTION("default constructor when using string value")
    {
        prqueue<string> myQueue;
        REQUIRE(myQueue.toString()=="");
    }
}

TEST_CASE("Test 2: testing operator=")
{
    SECTION("operator= when using int value")
    {
        // assigning empty queue
        prqueue<int> myQueue;
        prqueue<int> newQueue;
        newQueue=myQueue;
        REQUIRE(newQueue.toString()=="");
        
        // assigning queue with only one node
        myQueue.enqueue(1,1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()=="1 value: 1\n");

        // assigning queue with multiple nodes with unique priorities
        myQueue.enqueue(5,5);
        myQueue.enqueue(3,3);
        myQueue.enqueue(4,4);
        myQueue.enqueue(2,2);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates in root
        myQueue.enqueue(6,1);
        myQueue.enqueue(7,1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates elsewhere
        myQueue.enqueue(8,3);
        myQueue.enqueue(9,3);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // making sure newQueue is a deep copy and does not change when other queue is deleted
        string str=newQueue.toString();
        myQueue.clear();
        REQUIRE(newQueue.toString()==str);
    }

    SECTION("operator= when using float value")
    {
        // assigning empty queue
        prqueue<float> myQueue;
        prqueue<float> newQueue;
        newQueue=myQueue;
        REQUIRE(newQueue.toString()=="");
        
        // assigning queue with only one node
        myQueue.enqueue(1.1,1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with unique priorities
        myQueue.enqueue(5.5,5);
        myQueue.enqueue(3.3,3);
        myQueue.enqueue(4.4,4);
        myQueue.enqueue(2.2,2);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates in root
        myQueue.enqueue(6.6,1);
        myQueue.enqueue(7.7,1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates elsewhere
        myQueue.enqueue(8.8,3);
        myQueue.enqueue(9.9,3);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // making sure newQueue is a deep copy and does not change when other queue is deleted
        string str=newQueue.toString();
        myQueue.clear();
        REQUIRE(newQueue.toString()==str);
    }
    SECTION("operator= when using char value")
    {
        // assigning empty queue
        prqueue<char> myQueue;
        prqueue<char> newQueue;
        newQueue=myQueue;
        REQUIRE(newQueue.toString()=="");
        
        // assigning queue with only one node
        myQueue.enqueue('a',1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with unique priorities
        myQueue.enqueue('b',5);
        myQueue.enqueue('c',3);
        myQueue.enqueue('d',4);
        myQueue.enqueue('e',2);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates in root
        myQueue.enqueue('f',1);
        myQueue.enqueue('g',1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates elsewhere
        myQueue.enqueue('h',3);
        myQueue.enqueue('i',3);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // making sure newQueue is a deep copy and does not change when other queue is deleted
        string str=newQueue.toString();
        myQueue.clear();
        REQUIRE(newQueue.toString()==str);
    }
    SECTION("operator= when using string value")
    {
        // assigning empty queue
        prqueue<string> myQueue;
        prqueue<string> newQueue;
        newQueue=myQueue;
        REQUIRE(newQueue.toString()=="");
        
        // assigning queue with only one node
        myQueue.enqueue("aaa",1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with unique priorities
        myQueue.enqueue("bbb",5);
        myQueue.enqueue("ccc",3);
        myQueue.enqueue("ddd",4);
        myQueue.enqueue("eee",2);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates in root
        myQueue.enqueue("fff",1);
        myQueue.enqueue("ggg",1);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // assigning queue with multiple nodes with duplicates elsewhere
        myQueue.enqueue("hhh",3);
        myQueue.enqueue("iii",3);
        newQueue=myQueue;
        REQUIRE(newQueue.toString()==myQueue.toString());

        // making sure newQueue is a deep copy and does not change when other queue is deleted
        string str=newQueue.toString();
        myQueue.clear();
        REQUIRE(newQueue.toString()==str);
    }
}

TEST_CASE("Test 3: testing clear()")
{
    SECTION("clear() when using int value")
    {
        // clear for empty queue
        prqueue<int> myQueue;
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node
        myQueue.enqueue(1,1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node (duplicate priorities)
        myQueue.enqueue(1,1);
        myQueue.enqueue(2,1);
        myQueue.enqueue(3,1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
        
        // clear queue with multiple nodes
        myQueue.enqueue(1,1);
        myQueue.enqueue(5,5);
        myQueue.enqueue(3,3);
        myQueue.enqueue(4,4);
        myQueue.enqueue(2,2);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with multiple nodes and duplicate priorites
        myQueue.enqueue(1,1);
        myQueue.enqueue(2,1);
        myQueue.enqueue(3,1);
        myQueue.enqueue(4,5);
        myQueue.enqueue(5,3);
        myQueue.enqueue(6,4);
        myQueue.enqueue(7,3);
        myQueue.enqueue(8,2);
        myQueue.enqueue(9,3);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
    }

    SECTION("clear() when using float value")
    {
        // clear for empty queue
        prqueue<float> myQueue;
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node
        myQueue.enqueue(1.1,1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node (duplicate priorities)
        myQueue.enqueue(1.1,1);
        myQueue.enqueue(2.1,1);
        myQueue.enqueue(3.1,1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
        
        // clear queue with multiple nodes
        myQueue.enqueue(1.1,1);
        myQueue.enqueue(5.1,5);
        myQueue.enqueue(3.1,3);
        myQueue.enqueue(4.1,4);
        myQueue.enqueue(2.1,2);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with multiple nodes and duplicate priorites
        myQueue.enqueue(1.1,1);
        myQueue.enqueue(2.1,1);
        myQueue.enqueue(3.1,1);
        myQueue.enqueue(4.1,5);
        myQueue.enqueue(5.1,3);
        myQueue.enqueue(6.1,4);
        myQueue.enqueue(7.1,3);
        myQueue.enqueue(8.1,2);
        myQueue.enqueue(9.1,3);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
    }

    SECTION("clear() when using char value")
    {
        // clear for empty queue
        prqueue<char> myQueue;
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node
        myQueue.enqueue('a',1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node (duplicate priorities)
        myQueue.enqueue('a',1);
        myQueue.enqueue('b',1);
        myQueue.enqueue('c',1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
        
        // clear queue with multiple nodes
        myQueue.enqueue('a',1);
        myQueue.enqueue('b',5);
        myQueue.enqueue('c',3);
        myQueue.enqueue('d',4);
        myQueue.enqueue('e',2);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with multiple nodes and duplicate priorites
        myQueue.enqueue('a',1);
        myQueue.enqueue('b',1);
        myQueue.enqueue('c',1);
        myQueue.enqueue('d',5);
        myQueue.enqueue('e',3);
        myQueue.enqueue('f',4);
        myQueue.enqueue('g',3);
        myQueue.enqueue('h',2);
        myQueue.enqueue('i',3);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
    }

    SECTION("clear() when using string value")
    {
        // clear for empty queue
        prqueue<string> myQueue;
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node
        myQueue.enqueue("aaa",1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with one node (duplicate priorities)
        myQueue.enqueue("aaa",1);
        myQueue.enqueue("bbb",1);
        myQueue.enqueue("ccc",1);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
        
        // clear queue with multiple nodes
        myQueue.enqueue("aaa",1);
        myQueue.enqueue("bbb",5);
        myQueue.enqueue("ccc",3);
        myQueue.enqueue("ddd",4);
        myQueue.enqueue("eee",2);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");

        // clear queue with multiple nodes and duplicate priorites
        myQueue.enqueue("aaa",1);
        myQueue.enqueue("bbb",1);
        myQueue.enqueue("ccc",1);
        myQueue.enqueue("ddd",5);
        myQueue.enqueue("eee",3);
        myQueue.enqueue("fff",4);
        myQueue.enqueue("ggg",3);
        myQueue.enqueue("hhh",2);
        myQueue.enqueue("iii",3);
        myQueue.clear();
        REQUIRE(myQueue.toString()=="");
    }
}

TEST_CASE("Test 4: testing enqueue")
{
    SECTION("enqueue with int value"){
        // adding root
        prqueue<int> myQueue;
        myQueue.enqueue(1,1);
        map<int,vector<int>> mp;
        mp[1].push_back(1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates
        myQueue.enqueue(2,1);
        myQueue.enqueue(3,1);
        mp[1].push_back(2);
        mp[1].push_back(3);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding multiple nodes
        myQueue.enqueue(4,5);
        myQueue.enqueue(5,3);
        myQueue.enqueue(6,4);
        myQueue.enqueue(7,2);
        mp[5].push_back(4);
        mp[3].push_back(5);
        mp[4].push_back(6);
        mp[2].push_back(7);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates elsewhere
        myQueue.enqueue(8,5);
        myQueue.enqueue(9,5);
        mp[5].push_back(8);
        mp[5].push_back(9);
        REQUIRE(myQueue.toString()==mapToString(mp));
    }

    SECTION("enqueue with float value"){
        // adding root
        prqueue<float> myQueue;
        myQueue.enqueue(1.1,1);
        map<int,vector<float>> mp;
        mp[1].push_back(1.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates
        myQueue.enqueue(2.1,1);
        myQueue.enqueue(3.1,1);
        mp[1].push_back(2.1);
        mp[1].push_back(3.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding multiple nodes
        myQueue.enqueue(4.1,5);
        myQueue.enqueue(5.1,3);
        myQueue.enqueue(6.1,4);
        myQueue.enqueue(7.1,2);
        mp[5].push_back(4.1);
        mp[3].push_back(5.1);
        mp[4].push_back(6.1);
        mp[2].push_back(7.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates elsewhere
        myQueue.enqueue(8.1,5);
        myQueue.enqueue(9.1,5);
        mp[5].push_back(8.1);
        mp[5].push_back(9.1);
        REQUIRE(myQueue.toString()==mapToString(mp));
    }

    SECTION("enqueue with char value"){
        // adding root
        prqueue<char> myQueue;
        myQueue.enqueue('a',1);
        map<int,vector<char>> mp;
        mp[1].push_back('a');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates
        myQueue.enqueue('b',1);
        myQueue.enqueue('c',1);
        mp[1].push_back('b');
        mp[1].push_back('c');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding multiple nodes
        myQueue.enqueue('d',5);
        myQueue.enqueue('e',3);
        myQueue.enqueue('f',4);
        myQueue.enqueue('g',2);
        mp[5].push_back('d');
        mp[3].push_back('e');
        mp[4].push_back('f');
        mp[2].push_back('g');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates elsewhere
        myQueue.enqueue('h',5);
        myQueue.enqueue('i',5);
        mp[5].push_back('h');
        mp[5].push_back('i');
        REQUIRE(myQueue.toString()==mapToString(mp));
    }

    SECTION("enqueue with string value"){
        // adding root
        prqueue<string> myQueue;
        myQueue.enqueue("aaa",1);
        map<int,vector<string>> mp;
        mp[1].push_back("aaa");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates
        myQueue.enqueue("bbb",1);
        myQueue.enqueue("ccc",1);
        mp[1].push_back("bbb");
        mp[1].push_back("ccc");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding multiple nodes
        myQueue.enqueue("ddd",5);
        myQueue.enqueue("eee",3);
        myQueue.enqueue("fff",4);
        myQueue.enqueue("ggg",2);
        mp[5].push_back("ddd");
        mp[3].push_back("eee");
        mp[4].push_back("fff");
        mp[2].push_back("ggg");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // adding duplicates elsewhere
        myQueue.enqueue("hhh",5);
        myQueue.enqueue("iii",5);
        mp[5].push_back("hhh");
        mp[5].push_back("iii");
        REQUIRE(myQueue.toString()==mapToString(mp));
    }
}

TEST_CASE("Test 5: testing dequeue")
{
    SECTION("dequeue with int value"){
        // adding root
        prqueue<int> myQueue;
        myQueue.enqueue(1,1);
        map<int,vector<int>> mp;
        mp[1].push_back(1);
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates
        myQueue.enqueue(1,1);
        myQueue.enqueue(2,1);
        myQueue.enqueue(3,1);
        mp[1].push_back(1);
        mp[1].push_back(2);
        mp[1].push_back(3);
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding multiple nodes
        myQueue.enqueue(1,1);
        myQueue.enqueue(2,5);
        myQueue.enqueue(3,3);
        myQueue.enqueue(4,2);
        mp[1].push_back(1);
        mp[5].push_back(2);
        mp[3].push_back(3);
        mp[2].push_back(4);
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates elsewhere
        myQueue.enqueue(1,1);
        myQueue.enqueue(2,5);
        myQueue.enqueue(3,5);
        myQueue.enqueue(4,5);
        mp[1].push_back(1);
        mp[5].push_back(2);
        mp[5].push_back(3);
        mp[5].push_back(4);
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }

    SECTION("dequeue with float value"){
        // adding root
        prqueue<float> myQueue;
        myQueue.enqueue(1.1,1);
        map<int,vector<float>> mp;
        mp[1].push_back(1.1);
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates
        myQueue.enqueue(1.1,1);
        myQueue.enqueue(2.1,1);
        myQueue.enqueue(3.1,1);
        mp[1].push_back(1.1);
        mp[1].push_back(2.1);
        mp[1].push_back(3.1);
        REQUIRE(myQueue.toString()==mapToString(mp));
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding multiple nodes
        myQueue.enqueue(1.1,1);
        myQueue.enqueue(2.1,5);
        myQueue.enqueue(3.1,3);
        myQueue.enqueue(4.1,2);
        mp[1].push_back(1.1);
        mp[5].push_back(2.1);
        mp[3].push_back(3.1);
        mp[2].push_back(4.1);
        REQUIRE(myQueue.toString()==mapToString(mp));
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates elsewhere
        myQueue.enqueue(1.1,1);
        myQueue.enqueue(2.1,5);
        myQueue.enqueue(3.1,5);
        myQueue.enqueue(4.1,5);
        mp[1].push_back(1.1);
        mp[5].push_back(2.1);
        mp[5].push_back(3.1);
        mp[5].push_back(4.1);
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }

    SECTION("dequeue with char value"){
        // adding root
        prqueue<char> myQueue;
        myQueue.enqueue('a',1);
        map<int,vector<char>> mp;
        mp[1].push_back('a');
        REQUIRE(myQueue.toString()==mapToString(mp));
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
        
        // adding duplicates
        myQueue.enqueue('a',1);
        myQueue.enqueue('b',1);
        myQueue.enqueue('c',1);
        mp[1].push_back('a');
        mp[1].push_back('b');
        mp[1].push_back('c');
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding multiple nodes
        myQueue.enqueue('a',1);
        myQueue.enqueue('b',5);
        myQueue.enqueue('c',3);
        myQueue.enqueue('d',2);
        mp[1].push_back('a');
        mp[5].push_back('b');
        mp[3].push_back('c');
        mp[2].push_back('d');
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates elsewhere
        myQueue.enqueue('a',1);
        myQueue.enqueue('b',5);
        myQueue.enqueue('c',5);
        myQueue.enqueue('d',5);
        mp[1].push_back('a');
        mp[5].push_back('b');
        mp[5].push_back('c');
        mp[5].push_back('d');
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }

    SECTION("dequeue with string value"){
        // adding root
        prqueue<string> myQueue;
        myQueue.enqueue("aaa",1);
        map<int,vector<string>> mp;
        mp[1].push_back("aaa");
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates
        myQueue.enqueue("aaa",1);
        myQueue.enqueue("bbb",1);
        myQueue.enqueue("ccc",1);
        mp[1].push_back("aaa");
        mp[1].push_back("bbb");
        mp[1].push_back("ccc");
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding multiple nodes
        myQueue.enqueue("aaa",1);
        myQueue.enqueue("bbb",5);
        myQueue.enqueue("ccc",3);
        myQueue.enqueue("ddd",2);
        mp[1].push_back("aaa");
        mp[5].push_back("bbb");
        mp[3].push_back("ccc");
        mp[2].push_back("ddd");
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }

        // adding duplicates elsewhere
        myQueue.enqueue("aaa",1);
        myQueue.enqueue("bbb",5);
        myQueue.enqueue("ccc",5);
        myQueue.enqueue("ddd",5);
        mp[1].push_back("aaa");
        mp[5].push_back("bbb");
        mp[5].push_back("ccc");
        mp[5].push_back("ddd");
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }
}

TEST_CASE("Test 6: size")
{
    SECTION("size of queue with int value")
    {
        // empty queue
        prqueue<int> myQueue;
        REQUIRE(myQueue.size()==0);

        // single node
        myQueue.enqueue(1,1);
        REQUIRE(myQueue.size()==1);

        // single node with duplicates
        myQueue.enqueue(2,1);
        myQueue.enqueue(3,1);
        REQUIRE(myQueue.size()==3);

        // multiple nodes
        myQueue.enqueue(4,5);
        myQueue.enqueue(5,3);
        myQueue.enqueue(6,4);
        myQueue.enqueue(7,2);
        REQUIRE(myQueue.size()==7);

        // duplicate nodes elsewhere
        myQueue.enqueue(8,3);
        myQueue.enqueue(9,3);
        REQUIRE(myQueue.size()==9);
    }

    SECTION("size of queue with float value")
    {
        // empty queue
        prqueue<float> myQueue;
        REQUIRE(myQueue.size()==0);

        // single node
        myQueue.enqueue(1.1,1);
        REQUIRE(myQueue.size()==1);

        // single node with duplicates
        myQueue.enqueue(2.1,1);
        myQueue.enqueue(3.1,1);
        REQUIRE(myQueue.size()==3);

        // multiple nodes
        myQueue.enqueue(4.1,5);
        myQueue.enqueue(5.1,3);
        myQueue.enqueue(6.1,4);
        myQueue.enqueue(7.1,2);
        REQUIRE(myQueue.size()==7);

        // duplicate nodes elsewhere
        myQueue.enqueue(8.1,3);
        myQueue.enqueue(9.1,3);
        REQUIRE(myQueue.size()==9);
    }

    SECTION("size of queue with char value")
    {
        // empty queue
        prqueue<char> myQueue;
        REQUIRE(myQueue.size()==0);

        // single node
        myQueue.enqueue('a',1);
        REQUIRE(myQueue.size()==1);

        // single node with duplicates
        myQueue.enqueue('b',1);
        myQueue.enqueue('c',1);
        REQUIRE(myQueue.size()==3);

        // multiple nodes
        myQueue.enqueue('d',5);
        myQueue.enqueue('e',3);
        myQueue.enqueue('f',4);
        myQueue.enqueue('g',2);
        REQUIRE(myQueue.size()==7);

        // duplicate nodes elsewhere
        myQueue.enqueue('h',3);
        myQueue.enqueue('i',3);
        REQUIRE(myQueue.size()==9);
    }

    SECTION("size of queue with string value")
    {
        // empty queue
        prqueue<string> myQueue;
        REQUIRE(myQueue.size()==0);

        // single node
        myQueue.enqueue("aaa",1);
        REQUIRE(myQueue.size()==1);

        // single node with duplicates
        myQueue.enqueue("bbb",1);
        myQueue.enqueue("ccc",1);
        REQUIRE(myQueue.size()==3);

        // multiple nodes
        myQueue.enqueue("ddd",5);
        myQueue.enqueue("eee",3);
        myQueue.enqueue("fff",4);
        myQueue.enqueue("ggg",2);
        REQUIRE(myQueue.size()==7);

        // duplicate nodes elsewhere
        myQueue.enqueue("hhh",3);
        myQueue.enqueue("iii",3);
        REQUIRE(myQueue.size()==9);
    }
}

TEST_CASE("Test 7: testing toString()")
{
    SECTION("toString for int value")
    {
        // empty queue
        prqueue<int> myQueue;
        REQUIRE(myQueue.toString()=="");

        // single node
        myQueue.enqueue(1,1);
        map<int,vector<int>> mp;
        mp[1].push_back(1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // single node with duplicates
        myQueue.enqueue(2,1);
        myQueue.enqueue(3,1);
        mp[1].push_back(2);
        mp[1].push_back(3);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // multiple nodes
        myQueue.enqueue(4,5);
        myQueue.enqueue(5,3);
        myQueue.enqueue(6,4);
        myQueue.enqueue(7,2);
        mp[5].push_back(4);
        mp[3].push_back(5);
        mp[4].push_back(6);
        mp[2].push_back(7);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // duplicates elsewhere
        myQueue.enqueue(8,3);
        myQueue.enqueue(9,3);
        mp[3].push_back(8);
        mp[3].push_back(9);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // check after dequeueing multiple times
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }

    SECTION("toString for float value")
    {
        // empty queue
        prqueue<float> myQueue;
        REQUIRE(myQueue.toString()=="");

        // single node
        myQueue.enqueue(1.1,1);
        map<int,vector<float>> mp;
        mp[1].push_back(1.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // single node with duplicates
        myQueue.enqueue(2.1,1);
        myQueue.enqueue(3.1,1);
        mp[1].push_back(2.1);
        mp[1].push_back(3.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // multiple nodes
        myQueue.enqueue(4.1,5);
        myQueue.enqueue(5.1,3);
        myQueue.enqueue(6.1,4);
        myQueue.enqueue(7.1,2);
        mp[5].push_back(4.1);
        mp[3].push_back(5.1);
        mp[4].push_back(6.1);
        mp[2].push_back(7.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // duplicates elsewhere
        myQueue.enqueue(8.1,3);
        myQueue.enqueue(9.1,3);
        mp[3].push_back(8.1);
        mp[3].push_back(9.1);
        REQUIRE(myQueue.toString()==mapToString(mp));

        // check after dequeueing multiple times
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }

    SECTION("toString for char value")
    {
        // empty queue
        prqueue<char> myQueue;
        REQUIRE(myQueue.toString()=="");

        // single node
        myQueue.enqueue('a',1);
        map<int,vector<char>> mp;
        mp[1].push_back('a');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // single node with duplicates
        myQueue.enqueue('b',1);
        myQueue.enqueue('c',1);
        mp[1].push_back('b');
        mp[1].push_back('c');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // multiple nodes
        myQueue.enqueue('d',5);
        myQueue.enqueue('e',3);
        myQueue.enqueue('f',4);
        myQueue.enqueue('g',2);
        mp[5].push_back('d');
        mp[3].push_back('e');
        mp[4].push_back('f');
        mp[2].push_back('g');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // duplicates elsewhere
        myQueue.enqueue('h',3);
        myQueue.enqueue('i',3);
        mp[3].push_back('h');
        mp[3].push_back('i');
        REQUIRE(myQueue.toString()==mapToString(mp));

        // check after dequeueing multiple times
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }

    SECTION("toString for string value")
    {
        // empty queue
        prqueue<string> myQueue;
        REQUIRE(myQueue.toString()=="");

        // single node
        myQueue.enqueue("aaa",1);
        map<int,vector<string>> mp;
        mp[1].push_back("aaa");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // single node with duplicates
        myQueue.enqueue("bbb",1);
        myQueue.enqueue("ccc",1);
        mp[1].push_back("bbb");
        mp[1].push_back("ccc");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // multiple nodes
        myQueue.enqueue("ddd",5);
        myQueue.enqueue("eee",3);
        myQueue.enqueue("fff",4);
        myQueue.enqueue("ggg",2);
        mp[5].push_back("ddd");
        mp[3].push_back("eee");
        mp[4].push_back("fff");
        mp[2].push_back("ggg");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // duplicates elsewhere
        myQueue.enqueue("hhh",3);
        myQueue.enqueue("iii",3);
        mp[3].push_back("hhh");
        mp[3].push_back("iii");
        REQUIRE(myQueue.toString()==mapToString(mp));

        // check after dequeueing multiple times
        while (myQueue.getRoot()){
            myQueue.dequeue();
            mapDequeue(mp);
            REQUIRE(myQueue.toString()==mapToString(mp));
        }
    }
}

TEST_CASE("Test 8: testing peek()")
{
    SECTION("peek with int value"){
        // empty list
        prqueue<int> myQueue;
        REQUIRE(myQueue.peek()==NULL);

        // single node
        myQueue.enqueue(1,5);
        REQUIRE(myQueue.peek()==1);

        // single node with duplicates
        myQueue.enqueue(2,5);
        myQueue.enqueue(3,5);
        REQUIRE(myQueue.peek()==1);

        // multiple nodes
        myQueue.enqueue(4,9);
        myQueue.enqueue(5,3);
        myQueue.enqueue(6,4);
        myQueue.enqueue(7,1);
        REQUIRE(myQueue.peek()==7);

        // duplicates elsewhere
        myQueue.enqueue(8,3);
        myQueue.enqueue(9,3);
        REQUIRE(myQueue.peek()==7);
    }

    SECTION("peek with float value"){
        prqueue<float> myQueue;
        
        // single node
        myQueue.enqueue(1.1,5);
        REQUIRE(myQueue.peek()==1.1f);

        // single node with duplicates
        myQueue.enqueue(2.1,5);
        myQueue.enqueue(3.1,5);
        REQUIRE(myQueue.peek()==1.1f);

        // multiple nodes
        myQueue.enqueue(4.1,9);
        myQueue.enqueue(5.1,3);
        myQueue.enqueue(6.1,4);
        myQueue.enqueue(7.1,1);
        REQUIRE(myQueue.peek()==7.1f);

        // duplicates elsewhere
        myQueue.enqueue(8.1,3);
        myQueue.enqueue(9.1,3);
        REQUIRE(myQueue.peek()==7.1f);
    }

    SECTION("peek with char value"){
        // empty list
        prqueue<char> myQueue;
        REQUIRE(myQueue.peek()==NULL);

        // single node
        myQueue.enqueue('a',5);
        REQUIRE(myQueue.peek()=='a');

        // single node with duplicates
        myQueue.enqueue('b',5);
        myQueue.enqueue('c',5);
        REQUIRE(myQueue.peek()=='a');

        // multiple nodes
        myQueue.enqueue('d',9);
        myQueue.enqueue('e',3);
        myQueue.enqueue('f',4);
        myQueue.enqueue('g',1);
        REQUIRE(myQueue.peek()=='g');

        // duplicates elsewhere
        myQueue.enqueue('h',3);
        myQueue.enqueue('i',3);
        REQUIRE(myQueue.peek()=='g');
    }

    SECTION("peek with string value"){
        // empty list
        prqueue<string> myQueue;
        REQUIRE(myQueue.peek()=="");

        // single node
        myQueue.enqueue("aaa",5);
        REQUIRE(myQueue.peek()=="aaa");

        // single node with duplicates
        myQueue.enqueue("bbb",5);
        myQueue.enqueue("ccc",5);
        REQUIRE(myQueue.peek()=="aaa");

        // multiple nodes
        myQueue.enqueue("ddd",9);
        myQueue.enqueue("eee",3);
        myQueue.enqueue("fff",4);
        myQueue.enqueue("ggg",1);
        REQUIRE(myQueue.peek()=="ggg");

        // duplicates elsewhere
        myQueue.enqueue("hhh",3);
        myQueue.enqueue("iii",3);
        REQUIRE(myQueue.peek()=="ggg");
    }
}

TEST_CASE("Test 9: testing operator==")
{
    SECTION("two queues with int values")
    {
        // empty queues
        prqueue<int> queue1;
        prqueue<int> queue2;
        REQUIRE(queue1==queue2);

        // one empty, one not
        queue1.enqueue(1,1);
        REQUIRE(queue1!=queue2);

        // single nodes equal
        queue2.enqueue(1,1);
        REQUIRE(queue1==queue2);

        // single nodes different values
        queue1.clear();
        queue1.enqueue(2,1);
        REQUIRE(queue1!=queue2);

        // single nodes different priorities
        queue1.clear();
        queue1.enqueue(1,2);
        REQUIRE(queue1!=queue2);

        // single nodes, equal duplicates
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,1);
        queue1.enqueue(3,1);
        queue2.enqueue(1,1);
        queue2.enqueue(2,1);
        queue2.enqueue(3,1);
        REQUIRE(queue1==queue2);

        // single nodes, different duplicates
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,1);
        queue1.enqueue(3,1);
        queue2.enqueue(1,1);
        queue2.enqueue(2,1);
        queue2.enqueue(3,2);
        REQUIRE(queue1!=queue2);

        // single nodes, same duplicates, different sizes
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,1);
        queue1.enqueue(3,1);
        queue2.enqueue(1,1);
        queue2.enqueue(2,1);
        REQUIRE(queue1!=queue2);

        // multiple nodes, no duplicates, equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,5);
        queue1.enqueue(3,3);
        queue1.enqueue(4,4);
        queue1.enqueue(5,2);
        queue2.enqueue(1,1);
        queue2.enqueue(2,5);
        queue2.enqueue(3,3);
        queue2.enqueue(4,4);
        queue2.enqueue(5,2);
        REQUIRE(queue1==queue2);

        // multiple nodes, no duplicates, not equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,5);
        queue1.enqueue(3,3);
        queue1.enqueue(4,4);
        queue1.enqueue(5,2);
        queue2.enqueue(1,1);
        queue2.enqueue(2,5);
        queue2.enqueue(3,3);
        queue2.enqueue(3,4); // different
        queue2.enqueue(5,2);
        REQUIRE(queue1!=queue2);

        // multiple nodes, duplicates, equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,5);
        queue1.enqueue(3,3);
        queue1.enqueue(4,4);
        queue1.enqueue(5,3);
        queue1.enqueue(6,2);
        queue1.enqueue(7,3);
        queue2.enqueue(1,1);
        queue2.enqueue(2,5);
        queue2.enqueue(3,3);
        queue2.enqueue(4,4);
        queue2.enqueue(5,3);
        queue2.enqueue(6,2);
        queue2.enqueue(7,3);
        REQUIRE(queue1==queue2);

        // multiple nodes, duplicates, not equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1,1);
        queue1.enqueue(2,5);
        queue1.enqueue(3,3);
        queue1.enqueue(4,4);
        queue1.enqueue(5,3);
        queue1.enqueue(6,2);
        queue1.enqueue(7,3);
        queue2.enqueue(1,1);
        queue2.enqueue(2,5);
        queue2.enqueue(3,3);
        queue2.enqueue(3,4); // different
        queue2.enqueue(5,3);
        queue2.enqueue(6,2);
        queue2.enqueue(7,3);
        REQUIRE(queue1!=queue2);
    }

    SECTION("two queues with float values")
    {
        // empty queues
        prqueue<float> queue1;
        prqueue<float> queue2;
        REQUIRE(queue1==queue2);

        // one empty, one not
        queue1.enqueue(1.1,1);
        REQUIRE(queue1!=queue2);

        // single nodes equal
        queue2.enqueue(1.1,1);
        REQUIRE(queue1==queue2);

        // single nodes different values
        queue1.clear();
        queue1.enqueue(2.1,1);
        REQUIRE(queue1!=queue2);

        // single nodes different priorities
        queue1.clear();
        queue1.enqueue(1.1,2);
        REQUIRE(queue1!=queue2);

        // single nodes, equal duplicates
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,1);
        queue1.enqueue(3.1,1);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,1);
        queue2.enqueue(3.1,1);
        REQUIRE(queue1==queue2);

        // single nodes, different duplicates
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,1);
        queue1.enqueue(3.1,1);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,1);
        queue2.enqueue(3.1,2);
        REQUIRE(queue1!=queue2);

        // single nodes, same duplicates, different sizes
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,1);
        queue1.enqueue(3.1,1);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,1);
        REQUIRE(queue1!=queue2);

        // multiple nodes, no duplicates, equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,5);
        queue1.enqueue(3.1,3);
        queue1.enqueue(4.1,4);
        queue1.enqueue(5.1,2);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,5);
        queue2.enqueue(3.1,3);
        queue2.enqueue(4.1,4);
        queue2.enqueue(5.1,2);
        REQUIRE(queue1==queue2);

        // multiple nodes, no duplicates, not equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,5);
        queue1.enqueue(3.1,3);
        queue1.enqueue(4.1,4);
        queue1.enqueue(5.1,2);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,5);
        queue2.enqueue(3.1,3);
        queue2.enqueue(3.1,4); // different
        queue2.enqueue(5.1,2);
        REQUIRE(queue1!=queue2);

        // multiple nodes, duplicates, equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,5);
        queue1.enqueue(3.1,3);
        queue1.enqueue(4.1,4);
        queue1.enqueue(5.1,3);
        queue1.enqueue(6.1,2);
        queue1.enqueue(7.1,3);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,5);
        queue2.enqueue(3.1,3);
        queue2.enqueue(4.1,4);
        queue2.enqueue(5.1,3);
        queue2.enqueue(6.1,2);
        queue2.enqueue(7.1,3);
        REQUIRE(queue1==queue2);

        // multiple nodes, duplicates, not equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue(1.1,1);
        queue1.enqueue(2.1,5);
        queue1.enqueue(3.1,3);
        queue1.enqueue(4.1,4);
        queue1.enqueue(5.1,3);
        queue1.enqueue(6.1,2);
        queue1.enqueue(7.1,3);
        queue2.enqueue(1.1,1);
        queue2.enqueue(2.1,5);
        queue2.enqueue(3.1,3);
        queue2.enqueue(3.1,4); // different
        queue2.enqueue(5.1,3);
        queue2.enqueue(6.1,2);
        queue2.enqueue(7.1,3);
        REQUIRE(queue1!=queue2);
    }

    SECTION("two queues with char values")
    {
        // empty queues
        prqueue<char> queue1;
        prqueue<char> queue2;
        REQUIRE(queue1==queue2);

        // one empty, one not
        queue1.enqueue('a',1);
        REQUIRE(queue1!=queue2);

        // single nodes equal
        queue2.enqueue('a',1);
        REQUIRE(queue1==queue2);

        // single nodes different values
        queue1.clear();
        queue1.enqueue('b',1);
        REQUIRE(queue1!=queue2);

        // single nodes different priorities
        queue1.clear();
        queue1.enqueue('a',2);
        REQUIRE(queue1!=queue2);

        // single nodes, equal duplicates
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',1);
        queue1.enqueue('c',1);
        queue2.enqueue('a',1);
        queue2.enqueue('b',1);
        queue2.enqueue('c',1);
        REQUIRE(queue1==queue2);

        // single nodes, different duplicates
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',1);
        queue1.enqueue('c',1);
        queue2.enqueue('a',1);
        queue2.enqueue('b',1);
        queue2.enqueue('c',2);
        REQUIRE(queue1!=queue2);

        // single nodes, same duplicates, different sizes
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',1);
        queue1.enqueue('c',1);
        queue2.enqueue('1',1);
        queue2.enqueue('2',1);
        REQUIRE(queue1!=queue2);

        // multiple nodes, no duplicates, equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',5);
        queue1.enqueue('c',3);
        queue1.enqueue('d',4);
        queue1.enqueue('e',2);
        queue2.enqueue('a',1);
        queue2.enqueue('b',5);
        queue2.enqueue('c',3);
        queue2.enqueue('d',4);
        queue2.enqueue('e',2);
        REQUIRE(queue1==queue2);

        // multiple nodes, no duplicates, not equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',5);
        queue1.enqueue('c',3);
        queue1.enqueue('d',4);
        queue1.enqueue('e',2);
        queue2.enqueue('a',1);
        queue2.enqueue('b',5);
        queue2.enqueue('c',3);
        queue2.enqueue('c',4); // differnet
        queue2.enqueue('e',2);
        REQUIRE(queue1!=queue2);

        // multiple nodes, duplicates, equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',5);
        queue1.enqueue('c',3);
        queue1.enqueue('d',4);
        queue1.enqueue('e',3);
        queue1.enqueue('f',2);
        queue1.enqueue('g',3);
        queue2.enqueue('a',1);
        queue2.enqueue('b',5);
        queue2.enqueue('c',3);
        queue2.enqueue('d',4);
        queue2.enqueue('e',3);
        queue2.enqueue('f',2);
        queue2.enqueue('g',3);
        REQUIRE(queue1==queue2);

        // multiple nodes, duplicates, not equal;
        queue1.clear();
        queue2.clear();
        queue1.enqueue('a',1);
        queue1.enqueue('b',5);
        queue1.enqueue('c',3);
        queue1.enqueue('d',4);
        queue1.enqueue('e',3);
        queue1.enqueue('f',2);
        queue1.enqueue('g',3);
        queue2.enqueue('a',1);
        queue2.enqueue('b',5);
        queue2.enqueue('c',3);
        queue2.enqueue('c',4); // different
        queue2.enqueue('e',3);
        queue2.enqueue('f',2);
        queue2.enqueue('g',3);
        REQUIRE(queue1!=queue2);
    }
}