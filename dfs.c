#include <stdio.h>

int adj[20][20];

void DFS(int n,int visited[],int x){
    printf("%d  ",x);
    visited[x]=1;
    int i;
    for(i=0;i<n;i++){
        if(adj[x][i]==1&&visited[i]==0){
            DFS(n,visited,i);
        }
    }
    return;
}

int main(){
    int n,i,j;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    // int adj[n][n];
    printf("Enter Adjacency matrix:\n\n\t");
    for(i=0;i<n;i++) printf("%d ",i);
    printf("\n\n");

    for(i=0;i<n;i++){
        printf("%d\t",i);
        for(j=0;j<n;j++) scanf("%d",&adj[i][j]);
    }
    int visited[n];
    for(i=0;i<n;i++) visited[i]=0;

    int comp_count=0;
    for(i=0;i<n;i++){
        if(visited[i]==0) {
            printf("\nG%d: ",comp_count+1);
            DFS(n,visited,i);
            comp_count++;
        }
    }
    printf("\n\n");
    printf("Number of Components: %d\n\n",comp_count);
    return 0;
}

