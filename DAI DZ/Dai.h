#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Violations
{
    string violat;
    Violations* next;
};
struct Node
{
    Node* glava;
    Node* head;
    Node* tail;
    int number;
    Violations* list;
};
void Push(Violations*& node, string newStr);
void PrintList(Violations* head);
class Dai
{
private:
    int size;
    Node* root;

public:
    Dai(): root(nullptr), size(0) {}
    ~Dai();
    void Add(int value, string str);
    void Add(Node*& head, Node* glava, int value, string str);
    void PrintAll(Node* temp);
    void PrintNumber(int input);
    Node* PrintNumber(Node* node, int input);
    void PrintRangeNumber(Node* node, int min, int max);
    void PrintRangeNumber(int min, int max);
    void DeleteAll(Node* temp);
};