
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
    int in_deg, out_deg, i, j;
    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);
    read_graph(adj_mat, n);
    printf("\n Vertex \t In_Degree \t Out_Degree \t Total_Degree ");
    for (i = 1; i <= n ; i++ )
    {
        in_deg = out_deg = 0;
	for ( j = 1 ; j <= n ; j++ )
	{
            if ( adj_mat[j][i] == 1 )
                in_deg++;
	}
        for ( j = 1 ; j <= n ; j++ )
            if (adj_mat[i][j] == 1 )
                out_deg++;
            printf("\n\n %d\t\t\t%d\t\t%d\t\t%d\n\n",i,in_deg,out_deg,in_deg+out_deg);
    }
    return;
}

