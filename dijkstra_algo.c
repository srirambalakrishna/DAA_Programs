#include<stdio.h>
#include<stdlib.h>

#define INFINITY 999
#define SIZE 10

void dijkstra(int cost[SIZE][SIZE] , int dist[SIZE] , int visited[SIZE] , int n, int source )
{
	int i,j,min,index;
	
	visited[source] = 1;
	for(i=1; i<=n; i++)
	{
		min = INFINITY;
		for(j=1; j<=n; j++)
		{
			if(visited[j] == 0 && dist[j] < min)
			{
				min = dist[j];
				index = j;
			}
		}
		
		visited[index] = 1;

		for(j=1; j<=n; j++)
		{
			if( visited[j] == 0 && dist[j] > (dist[index] + cost[index][j]) )
				dist[j] = dist[index] + cost[index][j];
		}
	}
	
}

int main()
{
	int n, visited[SIZE], dist[SIZE], cost[SIZE][SIZE];
	int source , i, j;
	
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	printf("Enter the cost matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	
	printf("Enter the source node: ");
	scanf("%d",&source);
	
	for(i=1; i<=n; i++)
	{
		dist[i] = cost[source][i];
		visited[i] = 0;
	}
	
	dijkstra(cost, dist, visited , n, source);
	
	for(i =1; i<=n ; i++)
	{
		printf("%d to %d total distance = %d\n", source, i, dist[i]);
	}
	
}
