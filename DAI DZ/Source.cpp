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

void Push(Violations*& node,string newStr)
{
    Violations* tmp = new Violations;
    tmp->violat = newStr;
    tmp->next = nullptr;
    if (node == nullptr)
    {
        node = tmp;
    }
    else
    {
        tmp->next = node;
        node = tmp;
    }
}

void PrintList(Violations* head)
{
    Violations* curr = head;
    while (curr)
    {
        cout << curr->violat << endl;
        curr = curr->next;
    }
}

class database
{
private:
    int size;
    Node* root;

public:
    database()
    {
        root = nullptr;
        size = 0;
    }
    ~database()
    {
        DeleteAll(root);
    }
    void Add(int value, string str)
    {
        Add(root, nullptr, value, str);
    }
    void Add(Node*& head, Node* glava, int value,string str)
    {
        Node* temp = new Node;
        temp->number = value;
        temp->list = nullptr;
        temp->head = temp->tail = temp->glava = nullptr;

        if (!head)
        {
            head = temp;
            Push(head->list, str);
        }
        else
        {
            if (value == head->number)
                Push(head->list, str);
            else if (value < head->number)
                Add(head->head, head, value, str);
            else
                Add(head->tail, head, value, str);
        }
    }
    void PrintAll(Node* temp)
    {
        if (temp)
        {
            PrintAll(temp->head);
            cout << "Number of car: " << temp->number << endl;
            cout << "Violations: ";
            PrintList(temp->list);
            PrintAll(temp->tail);
        }
    }
    void PrintNumber(int input)
    {
        Node* node = PrintNumber(root, input);
        if (node == nullptr)
        {
            cout << "Not found." << endl;
        }
        else
        {
            cout << "Number of car: " << node->number << endl;
            cout << "Violations: " << endl;
            PrintList(node->list);
        }
        cout << "^~-~^~-~-~^~-~^~-~^~-~^~-~^~-~^~-~^~-~^~" << endl;
    }
    Node* PrintNumber(Node* node, int input)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (input == node->number)
        {
            return node;
        }
        else if (input < node->number)
        {
            return  PrintNumber(node->head, input);
        }
        else
        {
            return  PrintNumber(node->tail, input);
        }

    }
    void PrintRangeNumber(Node* node, int min, int max)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->number > min)
        {
            PrintRangeNumber(node->head, min, max);
        }
        if (node->number >= min && node->number <= max)
        {
            cout << "Number of car: " << node->number << endl;
            cout << "Violations: " << endl;
            PrintList(node->list);
            cout << "^~-~^~-~-~^~-~^~-~^~-~^~-~^~-~^~-~^~-~^~" << endl;
        }
        if (node->number < max)
        {

            PrintRangeNumber(node->tail, min, max);
        }

    }
    void PrintRangeNumber(int min, int max)
    {
        PrintRangeNumber(root, min, max);
    }
    void DeleteAll(Node* temp)
    {
        if (temp)
        {
            DeleteAll(temp->head);
            DeleteAll(temp->tail);
            delete temp;
        }
    }
};

int main()
{
    database bd;

    bd.Add(9999, "Over speed");
    bd.Add(9999, "Drive red traffic light");
    bd.Add(2993, "Lack of license plates");
    bd.Add(9999, "Parking in the wrong place");
    bd.Add(6666, "Participation in illegal racing");
    

    bd.PrintRangeNumber(1000, 10000);
    bd.PrintNumber(2993);


    return 0;
}