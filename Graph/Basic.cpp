
/*
    What is a graph?

    Graph is a collection of  verices (objects) and edges (relationships) 
    Graph

    {A,B,C,D,E} :Vertices

    {{A,B}, {B,C}} //Edges


    A---B----C  D E
    Above is a Graph

*/

/*
    No. of edges in A Graph

    1.Complete graph = N^2 ->vertices square
    2.Connected graph -> all nodes are connected to each other
    3.Tree N-1 edges

*/

/*
    Degree -> incoming edges ->indegree
    -> outgoing edges ->outdegree

    Path -> A to B following edges

    subgraph is a part of graph

    Connected componenet in which each node has a path to the other node

    Tree is a graph without cycle
    dfs and bfs form a tree

    and if multiple components then they form forest of trees

    Minimum Spanning of Tree

    
*/

/*
    Undirected - bidirectional
    Directed - unidirectional
    Weighted Graph

*/

//How to store graph?
//Adjacency List
//Edge List

/*
    1.Adjacency Matrix (M)
    vector<vector<int>> M(V,vector<int>(V,0));
    V*V matrix where V is no of vertices
    M[u][v] ->gives true if there is a edge between u to v
    if we want to look up edge / weight between two nodes u and v in O(1) gives true if present else flase
    Takes linear O(N) time to find neighbours
    Memory inefficient

    2.Using Adjacency List:

    1. n vertices from 0 ton n-1
    vector<int> adj[n];


    i->node
    adj[i] ->gives a neighbour of i 
            ->there is a edge from i to  each adj[i]
            ->we can go there from curr node i
            ->outdegree of ith node is size of that adj[i]

    Memory efficient and easily find neighbours
    -- ----------
    | 0 |  1 2   |
    | 1 |  3 0 2 |
    | 2 |  1 0   |
    | 3 |  1     |
    | . |        |
    | n-1|       | 
    -------------


//Using Map:

//Map<key,vector<int>> graph;


//Edge List 
vector<pair<T,T>> edgeList;


*/