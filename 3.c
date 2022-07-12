#include <stdio.h>

int Q[20], front=-1, rear=-1;

struct node
{
  int col,dist, par;
};

int Queue_empty(int Q[])
{
  if(front==-1)
    return 1;
  else
    return 0;
}

void EnQueue(int Q[], int k)
{
  if(front==-1)
  {
    front++;
    rear++;
    Q[rear]=k;
  }
  else
  {
    if((rear+1)%20==front)
      printf("Queue is full\n");
    else
    {
      rear=(rear+1)%20;
      Q[rear]=k;
    }
  }
}

int DeQueue(int Q[])
{
  if(front==-1)
  {
    printf("Queue is empty\n");
    return -1;
  }
  else
  {
    if(front==rear)
    {
      int temp=Q[front];
      front=-1;
      rear=-1;
      return temp;
    }
    else
    {
      int temp=Q[front];
      front=(front+1)%20;
      return temp;
    }
  }
}

void bfs(int g[][10], struct node*v, int start)
{
  int i,j,k;
  for(i=0;i<10;i++)
  {
    if(i!=start)
    {
      v[i].col=0;
      v[i].dist=32765;
      v[i].par=-1;
    }
  }
  v[start].col=1;
  v[start].dist=0;
  v[start].par=-1;
  EnQueue(Q,start);
  while(!Queue_empty(Q))
  {
    int u=DeQueue(Q);
    for(i=0;i<10;i++)
    {
      if(i!=u)
      {
        if(g[u][i]==1 && v[i].col==0)
        {
          v[i].col=1;
          v[i].dist=v[u].dist+1;
          v[i].par=u;
          EnQueue(Q,i);
        }
      }
    }
    v[u].col=2;
  }
}

void PrintPath(int g[][10], struct node *v, int s, int u)
{
  if(s==u)
    printf("%d  ",s);
  else if(v[u].par==-1)
    printf("No path from %d to %d\n", s, u);
  else
  {
    PrintPath(g, v, s, v[u].par);
    printf("%d  ",u);
  }
}

int main()
{
  int i, j, g[10][10]={0};
  int srcnode;
  printf("What is start node : ");
  scanf("%d",&srcnode);
  struct node v[10]={0};
  for(i=0; i<10;i++)
    for(j=0;j<10;j++)
      scanf("%d", &g[i][j]);
  bfs(g, v, srcnode);
  printf("PATHFROM SOURCE:%d to all other nodes\n",srcnode);
  for(i=0;i<10;i++)
  {
    PrintPath(g, v, srcnode, i);
    printf("\n");
  }
  return 0;
}
