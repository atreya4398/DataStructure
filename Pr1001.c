
#include<stdio.h>


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
    return;
}

int main()
{
    int adj_mat[50][50];
    int n;
    int i, j,deg;
    printf("\n How Many Vertices ? : ");
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
    return;
}

