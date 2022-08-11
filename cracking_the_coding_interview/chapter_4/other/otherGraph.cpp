#include "../../ALL_H_FILES.h"

// =============================================================

// using namespace std;

// // stores adjacency list items
// struct adjNode {
//     int val, cost;
//     adjNode* next;
// };

// // structure to store edges
// struct graphEdge {
//     int start_ver, end_ver, weight;
// };

// class DiaGraph{
//     // insert new nodes into adjacency list from given graph
//     adjNode* getAdjListNode(int value, int weight, adjNode* head)   {
//         adjNode* newNode = new adjNode;
//         newNode->val = value;
//         newNode->cost = weight;
         
//         newNode->next = head;   // point new node to current head
//         return newNode;
//     }
//     int N;  // number of nodes in the graph
// public:
//     adjNode **head;                //adjacency list as array of pointers
//     // Constructor
//     DiaGraph(graphEdge edges[], int n, int N)  {
//         // allocate new node
//         head = new adjNode*[N]();
//         this->N = N;
//         // initialize head pointer for all vertices
//         for (int i = 0; i < N; ++i)
//             head[i] = nullptr;
//         // construct directed graph by adding edges to it
//         for (unsigned i = 0; i < n; i++)  {
//             int start_ver = edges[i].start_ver;
//             int end_ver = edges[i].end_ver;
//             int weight = edges[i].weight;
//             // insert in the beginning
//             adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
             
//                         // point head pointer to new node
//             head[start_ver] = newNode;
//              }
//     }
//       // Destructor
//      ~DiaGraph() {
//     for (int i = 0; i < N; i++)
//         delete[] head[i];
//         delete[] head;
//      }
// };

// // print all adjacent vertices of given vertex
// void display_AdjList(adjNode* ptr, int i)
// {
//     while (ptr != nullptr) {
//         cout << "(" << i << ", " << ptr->val
//             << ", " << ptr->cost << ") ";
//         ptr = ptr->next;
//     }
//     cout << endl;
// }

// // graph implementation
// int main()
// {
//     // graph edges array.
//     graphEdge edges[] = {
//         // (x, y, w) -> edge from x to y with weight w
//         {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
//     };
//     int N = 6;      // Number of vertices in the graph
//     // calculate number of edges
//     int n = sizeof(edges)/sizeof(edges[0]);
//     // construct graph
//     DiaGraph diagraph(edges, n, N);
//     // print adjacency list representation of graph
//     cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
//     for (int i = 0; i < N; i++)
//     {
//         // display adjacent vertices of vertex i
//         display_AdjList(diagraph.head[i], i);
//     }
//     return 0;
// }

using namespace std;

class Graph
{
    int V; // start vertice 
    map<pair<string,string>,int> city ;
    vector<string> city1;
    vector<string> city2;
    public:
    Graph(int start_V)
    {
        V = start_V;
    }
    void addEdge(string start,string end,int wt);
    void display();
};
void Graph::addEdge(string start,string end,int wt)
{   
   city[make_pair(start,end)] = wt;
}
void Graph::display()
{   
    int flag=0;
    for(auto it:city)
    {
        city1.push_back(it.first.first);
        city2.push_back(it.first.second);
    }

    sort(city1.begin(), city1.end()); 
    auto last = unique(city1.begin(), city1.end());
    city1.erase(last, city1.end());

    sort(city2.begin(), city2.end()); 
    auto last2 = unique(city2.begin(), city2.end());
    city2.erase(last2, city2.end());

    for(auto col:city2)
    {
        cout<<"\t"<<col;
    }
    cout<<"\n";

    for(auto row:city1)
    {
    int flag =0;   //for printing row for once 
    for(auto col:city2)
    {
        if (!flag)
            cout<<row;
        cout<<"\t"<<city[make_pair(row,col)];
        flag = 1;
    }

    cout<<"\n";
    }

}
int main()
{
    Graph g(2);

    g.addEdge("A","B",1);
    g.addEdge("C","A",5);
    g.addEdge("D","E",7);
    g.addEdge("E","A",5);
    g.addEdge("D","B",7);
    g.addEdge("D","L",7);
    g.addEdge("W","L",7);
    g.display();
    return 0;
}