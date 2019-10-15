#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
struct Edge 
{ 
    int src, dest, weight; 
};  
struct Graph 
{  int V, E; 
  struct Edge* edge; 
}; 
struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
 struct subset 
{ 
    int parent; 
    int rank; 
}; 
int find(struct subset subsets[], int i) 
{  
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 

void Union(struct subset subsets[], int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
   
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
  
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 
int myComp(const void* a, const void* b) 
{ 
    struct Edge* a1 = (struct Edge*)a; 
    struct Edge* b1 = (struct Edge*)b; 
    return a1->weight > b1->weight; 
} 
void KruskalMST(struct Graph* graph) 
{ 
    int V = graph->V; 
    struct Edge result[V]; 
    int e = 0; 
    int i = 0;  
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 
  
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) ); 
  
    for (int v = 0; v < V; ++v) 
    { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    }  
    while (e < V - 1) 
    { 
        struct Edge next_edge = graph->edge[i++]; 
        int x = find(subsets, next_edge.src); 
        int y = find(subsets, next_edge.dest); 
 
        if (x != y) 
        { 
            result[e++] = next_edge; 
            Union(subsets, x, y); 
        }  
    } 
    printf("Following are the edges in the constructed MST\n"); 
    for (i = 0; i < e; ++i) 
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,result[i].weight); 
    return; 
}  
int main() 
{
    int V ; 
    int E ; 
    printf("Enter the No. of vertices and edges in your graph respectively ?\n");
    scanf("%d %d",&V,&E);
    struct Graph* graph = createGraph(V, E);
    int i; 
  for(i=0;i<E;i++)
  { 
    printf("Enter the source node key for the edge you want to add in the graph ?\n"); 
    scanf("%d",&graph->edge[i].src) ; 
    printf("\nEnter the destination node key for the edge you want to add in the graph ?\n"); 
    scanf("%d",&graph->edge[i].dest) ;
    printf("Enter the weight for the edge you want to add in the graph ?\n");  
    scanf("%d",&graph->edge[i].weight) ;
  }
  
    KruskalMST(graph); 
  
    return 0; 
} 

