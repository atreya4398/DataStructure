#include<stdio.h>
#include <stdlib.h>
#define new_node (struct node*)malloc(sizeof(struct node))

struct node
{
    int vertex;
    struct node *next;
};

int visited[10];
int adj_mat[50][50];
 int n;

void dfs(int i)
{
    int j;
	printf("%d ",i);
    visited[i]=1;

	for(j=0;j<=n;j++)
       if(!visited[j]&&adj_mat[i][j]==1)
            dfs(j);
}

int read_graph ( int adj_mat[50][50], int n )
{
    int i, j;
    int val;

    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                adj_mat[i][j] = 0;

            }
            else
            {
                printf("\n Vertices %d & %d are Adjacent ? (Y=1/N=2) :",i,j);
                scanf("%d",&val);
                if ( val==1 )
                    adj_mat[i][j] = 1;
                else
                    adj_mat[i][j] = 0;
            }

        }
    }
    return 0;
}

void undirectedGraph()
{


    int i, j,deg;
    printf("\n How Many Vertices : ");
    scanf("%d", &n);
    read_graph(adj_mat, n);
    printf("\n Vertex \t Degree ");
    for ( i = 1 ; i <= n ; i++ )
    {
        deg = 0;
        for ( j = 1 ; j <= n ; j++ )
            if ( adj_mat[i][j] == 1)
                deg++;
        printf("\n\n %d \t\t %d\n\n", i, deg);
    }
}

int read_ad_graph ( struct node *adj_list[10], int n )
{
    int i, j;
    int reply;
    struct node *p, *c;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
                continue;
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
            scanf("%d", &reply);
            if ( reply == 1 )
            {
                c = new_node;
                c -> vertex = j;
                c -> next = NULL;
                if ( adj_list[i] == NULL )
                    adj_list[i] = c;
                else
                {
                    p = adj_list[i];
                    while ( p -> next != NULL )
                        p = p -> next;
                    p -> next = c;
		}
            }
        }
    }
    return;
}


int undirgraph()
{
    struct node *adj_list[10], *p;
    int deg, i, j, n;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    for ( i = 1 ; i <= n ; i++ )
        adj_list[i] = NULL;
    read_ad_graph(adj_list, n);
    printf("\n Vertex \t Degree ");
    for ( i = 1 ; i <= n ; i++ )
    {
        deg = 0;
        p = adj_list[i];
        while( p != NULL )
	{
            deg++;
            p = p -> next;
        }
        printf("\n\n %d \t\t %d\n\n", i, deg);
    }
    return;
}

int main()
{
    int i;

    undirgraph();
    printf("\n\n");
    undirectedGraph();
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nDFS :- \n");
    dfs(1);

}


