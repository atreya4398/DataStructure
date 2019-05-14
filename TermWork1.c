#include <stdio.h>
#define MAX 100
int relation[MAX][MAX] = {0}, visited[MAX] = {0}, queue[MAX] = {0}, friends[MAX] = {0};
float popularity[MAX][2] = {0.0};
int friendsInfo[MAX][4] = {0};
void DFS(int nodes, int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < nodes; j++)
    {
        if (!visited[j] && relation[i][j] != 0)
        {
            DFS(nodes, j);
        }
    }
}
void DFSUN(int nodes, int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < nodes; j++)
    {
        if (!visited[j] && relation[i][j] != 0)
        {
            DFSUN(nodes, j);
        }
    }
    for (j = 0; j < nodes; j++)
    {
        if (!visited[j] && relation[j][i] != 0)
        {
            DFSUN(nodes, j);
        }
    }
}
void BFS(int nodes, int i, int queueHead, int queueRear)
{
    printf("%d ", i);
    int j;
    for (j = 0; j < nodes; j++)
    {
        if (relation[i][j] != 0 && visited[j] == 0)
        {
            queue[++queueRear] = j;
        }
    }
    if (queueHead <= queueRear && visited[queue[queueHead]] == 0)
    {
        visited[queue[queueHead]] = 1;
        queueHead++;
        BFS(nodes, queue[queueHead - 1], queueHead, queueRear);
    }
}
int queuePresence(int j, int queueHead, int queueRear)
{
    int i;
    for (i = queueHead; i <= queueRear; i++)
    {
        if (queue[i] == j)
        {
            return (1);
        }
    }
    return (0);
}
void BFSUN(int nodes, int i, int queueHead, int queueRear)
{
    printf("%d ", i);
    int j, k;
    /*for (j = queueHead; j <= queueRear; j++)
    {
        printf("%d ", queue[j]);
    }
    printf("\t");
    for (j = 0; j <= nodes; j++)
    {
        printf("%d ", visited[j]);
    }
    printf("\n");*/
    for (j = 0; j < nodes; j++)
    {
        if ((relation[i][j] != 0 || relation[j][i] != 0) && !queuePresence(j, queueHead, queueRear) && !visited[j])
        {
            queue[++queueRear] = j;
        }
    }
    if (queueHead <= queueRear && visited[queue[queueHead]] == 0)
    {
        visited[queue[queueHead]] = 1;
        queueHead++;
        BFSUN(nodes, queue[queueHead - 1], queueHead, queueRear);
    }
}
void readDirected(FILE *fp, int nodes, int edges)
{
    int i, j;
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            relation[i][j] = 0;
        }
    }
    int from, to;
    for (i = 0; i < edges; i++)
    {
        fgetc(fp);
        fgetc(fp);
        fscanf(fp, "%d %d", &from, &to);
        relation[from][to] = 1;
    }

    printf("DFS Traversion:");
    DFS(nodes, 0);
    printf("\nBFS Traversion:");
    for (i = 0; i < nodes; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    BFS(nodes, 0, 0, -1);
}
void readUndirected(FILE *fp, int nodes, int edges)
{
    int i, j;
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            relation[i][j] = 0;
        }
    }
    int from, to, distance;
    for (i = 0; i < edges; i++)
    {
        fgetc(fp);
        fgetc(fp);
        fscanf(fp, "%d %d %d", &from, &to, &distance);
        relation[from][to] = distance;
    }

    printf("DFS Traversion:");
    DFSUN(nodes, 0);
    printf("\nBFS Traversion:");
    for (i = 0; i < nodes; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    BFSUN(nodes, 0, 0, -1);
}
void createPopularity(int nodes)
{
    int i, j;
    float followers = 0.0, follows = 0.0;
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            if (relation[i][j] == 1)
            {
                follows += 1.0;
            }
            if (relation[j][i] == 1)
            {
                followers += 1.0;
            }
        }
        popularity[i][0] = followers;
        popularity[i][1] = follows;
        follows = 0;
        followers = 0;
    }
}
void printPopularity(int nodes)
{
    int i;
    for (i = 0; i < nodes; i++)
    {
        printf("Person %d ", i);
        if (popularity[i][1] == 0)
        {
            if (popularity[i][0] < 3)
            {
                printf("is NOT Popular.");
            }
            else
            {
                printf("IS Popular.");
            }
        }
        else
        {
            if (popularity[i][0] / popularity[i][1] >= 2)
            {
                printf("IS Popular.");
            }
            else
            {
                printf("is NOT Popular.");
            }
            printf("Popularity score:%.1f .", popularity[i][0] / popularity[i][1]);
        }
        printf("Followed by: %.0f Follows %.0f\n", popularity[i][0], popularity[i][1]);
    }
}
int friendsPresence(int j, int nodes)
{
    int i;
    for (i = 0; i < nodes; i++)
    {
        if (friends[i] == j)
        {
            /*printf("Check for %d :",i);
            for (l = 0; l < nodes; l++)
                printf("%d ", friends[l]);
            printf("\n");*/
            return (1);
        }
    }
    return (0);
}
void calculateFriends(int nodes)
{
    int i, j, k;
    //int l;
    int justfriends;
    int current;
    for (i = 0; i < nodes; i++)
    {
        //printf("Calculation of person %d\n",i);
        current = 0;
        for (j = 0; j < nodes; j++)
        {
            friends[j] = -1;
        }
        justfriends = 0;
        for (j = 0; j < nodes; j++)
        {
            if (relation[i][j] != 0 || relation[j][i] != 0)
            {
                /*if (j == 0 && i == 1)
                    printf("Her");*/
                justfriends++;
                /*if (!friendsPresence(j, nodes))
                {
                    if (j == 0 && i == 1)
                        printf("Here");
                    friends[current++] = j;
                }*/
                for (k = 0; k < nodes; k++)
                {
                    //printf("check for %d %d\n",j,k);
                    if ((relation[j][k] || relation[k][j]) && !friendsPresence(k, nodes) && i != k)
                    {
                        friends[current++] = k;
                        /*for (l = 0; l < nodes; l++)
                            printf("%d ", friends[l]);
                        printf("\n");*/
                    }
                }
            }
        }
        friendsInfo[i][0] = justfriends;
        friendsInfo[i][1] = current;
    }
}
void printFriends(int nodes)
{
    int i;
    for (i = 0; i < nodes; i++)
    {
        printf("Person %d has %d friends and %d FOF's\n", i, friendsInfo[i][0], friendsInfo[i][1]);
    }
}
int main()
{
    int isDirected, isWeighted;
    FILE *fp;
    int i, j;
    int num, nodes, edges;
    char filename[20];
    printf("Enter the name of a social media graph file (EXIT when finished):");
    scanf("%s", filename);
    while (filename[0] != 'E' && filename[1] != 'X' && filename[2] != 'I' && filename[3] != 'T')
    {
        fp = fopen(filename, "r");
        if (fp != NULL)
        {
            printf("Using file: %s\n", filename);
            fscanf(fp, "%d %d", &isDirected, &isWeighted);
            printf("Graph is ");
            isDirected ? printf("directed, ") : printf("undirected, ");
            isWeighted ? printf("weighted ") : printf("unweighted ");
            fgetc(fp);
            fgetc(fp);
            fscanf(fp, "%d %d", &nodes, &edges);
            printf("and has %d nodes and %d edges.\n", nodes, edges);
            if (isDirected && !isWeighted)
            {
                readDirected(fp, nodes, edges);
                createPopularity(nodes);
                printf("\n");
                printPopularity(nodes);
            }
            else if (!isDirected && isWeighted)
            {
                readUndirected(fp, nodes, edges);
                printf("\n");
                calculateFriends(nodes);
                printFriends(nodes);
            }
            /*printf("\n");
        for (i = 0; i < nodes; i++)
        {
            for (j = 0; j < nodes; j++)
            {
                printf("%d\t", relation[i][j]);
            }
            printf("\n");
        }*/
        }
        else
        {
            printf("File not found.\n");
        }
        printf("Enter the name of a social media graph file (EXIT when finished):");
        scanf("%s", filename);
    }
}