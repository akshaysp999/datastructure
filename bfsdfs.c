#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int adj[10][10],visit[100];
int n,state[10],v;
int queue[MAX],front=-1,rear=-1;
void insert_queue(int);
int delete_queue();
int isempty_queue();
void create_graph();
void BF_Traversal();
void BFS(int);
int create_DFS();
void DFS(int);
int main()
{
	int ch;
	do
	{
	printf("\n\nCHOOSE : \n1.BREADTH FIRST SEARCH\n2.DEPTH FIRST SEARCH\n3.EXIT");
	printf("\n\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:create_graph();
			BF_Traversal();
		       break;
		case 2:create_DFS();
		       break;
		case 3:break;
	}
	}while(ch!=3);

}
void insert_queue(int v)
{
	if(rear==MAX-1)
		printf("Queue OverFlow\n");
	else
	{
		if(front==-1)
			front=0;
		rear=rear+1;
		queue[rear]=v;
	}
}

int delete_queue()
{
	int item;
	if(front==-1||front>rear)
	{
		printf("Queue UnderFlow\n");
		return 0;
	}
	item=queue[front];
	front=front+1;
	return item;
}
int isempty_queue()
{
	if(front==-1||front>rear)
		return 1;
	else
		return 0;
}
void create_graph()
{
	printf("\n----BREADTH FIRST SEARCH----\n\n");
	int i,max,origin,dest;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	max=n*(n-1);
	printf("Enter the adjacency matrix:\nPress -1 -1 to exit\n\n");
	for(i=1;i<=max;i++)
	{
		printf("Enter %d edge :\n",i);
		scanf("%d%d",&origin,&dest);
		if(origin==-1||dest==-1)
		break;
		else
		{
			adj[origin][dest]=1;//edge being created
		}
	}
}

void BF_Traversal()
{
	int i;
	for(i=0;i<n;i++)
		state[i]=initial;
	printf("Enter the starting vertex:");
	scanf("%d",&i);
	BFS(i);
}
void BFS(int v)
{
	int i;
	insert_queue(v);
	state[v]=waiting;
	while(!isempty_queue())
	{
		v=delete_queue();
		state[v]=visited;
		printf("Visited Vertex %d \n",v);
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1&&state[i]==initial)//check if edge actually exist
			{
				insert_queue(i);
				state[i]=waiting;
			}
		}
	}
}
int create_DFS()
{
	int i,j,n;
	        printf("\n----DEPTH FIRST SEARCH----\n\n");

	printf("Enter number of vertices :\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Edge Vertex %d :\n",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	for(i=0;i<n;i++) //assign all vertex as not visited
	{
		visit[i]=0;
	}
	printf("\nEnter Starting vertex :\n");
	scanf("%d",&j);
	DFS(j);
	return 0;
}
void DFS(int v)
{
	int i;
	visit[v]=1;
	printf("Visited Node %d\n",v);
	for(i=0;i<n;i++)
	{
		if(visit[i]==0&&adj[v][i]==1)
		{
			DFS(i);
		}
	}

}
