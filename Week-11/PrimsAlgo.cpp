#include <cstring>
#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX;


void primsAlgo(int Graph[6][6], int selected[6],int V){
    int edge_no=0;  // number of edge
     int x=0;  //  row number
     int y=0;  //  col number

    while (edge_no < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && Graph[i][j]) {  // not in selected and there is an edge
            if (min > Graph[i][j]) {
              min = Graph[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << Graph[x][y];
    cout << endl;
    selected[y] = true;
    edge_no++;
}
}
int main() {
  int start_vetex = 0;

  int Graph[6][6] = {
  {0, 3, 0, 0, 0, 1},
  {3, 0, 2, 1, 10, 0},
  {0, 2, 0, 3, 0, 5},
  {0, 1, 3, 0, 5, 0},
  {0, 10, 0, 5, 0, 4},
  {1, 0, 5, 0, 4, 0}};

  // Array to track the selected vertex.
  int selected[6];
  for (int i=0; i<6; i++){
    selected[i] = false;
  }

  selected[start_vetex] = true;

  // print for edge and weight
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  
  
    primsAlgo(Graph,selected,6);

  return 0;
}