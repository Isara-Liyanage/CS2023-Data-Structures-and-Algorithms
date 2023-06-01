#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

int minDistance(int distance[], bool Tset[]) // finding minimum distance for a index
{
    int minimum=INT_MAX;
    int index=0;
              
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            index=k;
        }
    }
    return index;
}

void DijkstraAlgo(int graph[6][6],int src) 
{
    int distance[6]; // // array to calculate the minimum distance for each node                             
    bool visited[6];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        visited[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<6; k++)                           
    {
        int m=minDistance(distance,visited); 
        visited[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!visited[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<6; k++)                      
    { 
        cout<<"City "<<k<<"                 "<<distance[k]<<endl;
    }
}

int main()
{
    int graph[6][6]={{0,10,0,0,15,5},
                 {10,0,10,30,0,0},
                 {0,10,0,12,5,0},
                 {0,30,12,0,0,20},
                 {15,0,5,0,0,0},
                 {5,0,0,20,0,0}};
    DijkstraAlgo(graph,4);
    return 0;                           
}