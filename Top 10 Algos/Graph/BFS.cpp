// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int N, vector<int> graph[])
    {
        //Algo

        //adjacency list(graph)
        //visited array(for each node)

        //Queue for processing nodes ( level wise or sequence of insertion1)
        //Whenever we enque a node we mark visited
        //push root node i.e. starting of bfs
        //then take out nodes one by one from the queue.
        //and try to go to the valid nb (not visited nb )of curr node
        //whenever enque nb mark it visited

        vector<int> vis(N,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        vector<int>ans;
        while(!q.empty())
        {
            int curr = q.front();q.pop();
            ans.push_back(curr);
            for(auto nb:graph[curr])
            {
                if(!vis[nb])
                {
                    q.push(nb);
                    vis[nb]=1;
                }
            }
        }
        
        return ans;
        
        
    }
};

