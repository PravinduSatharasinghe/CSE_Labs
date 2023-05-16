#include <iostream>
#include <list>
using namespace std;

struct Node 
{
    int label;
    Node* next;
};

struct Graph 
{
    int n;
    Node* nodes;

    Graph(int n) 
    {
        this->n = n;
        nodes = new Node[n];
    }

    void initializeNodes() 
    {
        for (int i = 0; i < n; i++) 
        {
            nodes[i].label = i;
            nodes[i].next = nullptr;
        }
    }

    void addEdge(int u, int v) 
    {
        // Create a new node for v and make it the head of u's list
        Node* newNode = new Node;
newNode->label = v;
        newNode->next = nodes[u].next;
        nodes[u].next = newNode;

        // Create a new node for u and make it the head of v's list
        newNode = new Node;
        newNode->label = u;
        newNode->next = nodes[v].next;
        nodes[v].next = newNode;
    }

    void print() 
    {
        for (int i = 1; i < n+1; i++) 
        {
            cout << "Neighbors of " << i << " Node: ";
            Node* curr = nodes[i].next;
            while (curr) 
            {
                cout << curr->label << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main() 
{
    int n = 8;
    Graph* g = new Graph(n);
    g->initializeNodes();
 // Add edges for the graph
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    // Print the graph adjacency list
    g->print();
    
    return 0;
}