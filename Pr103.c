#include<stdio.h>

struct student
{
	int sroll;
	char sname[10];
	int subject[5];
}s[5];
void addelement(struct student st[], int n,int m);
void display(struct student st[], int n,int m);
int main()
{
	int num,sub;
	printf("Enter size: ");
	scanf("%d", &num);
	printf("Enter number of subjects:");
	scanf("%d",&sub);
	addelement(s, num,sub);
	display(s, num,sub);
}
void addelement(struct student stu[], int n,int m)
{
	int i,j;

	for (i = 0; i < n; i++)
	{
	    printf("Enter roll no: ");
		scanf("%d", &stu[i].sroll);
		printf("enter name: ");
		scanf("%s", stu[i].sname);

	}
	for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Enter marks of student %d for subject %d:",i+1,j+1);
            scanf("%d",&stu[i].subject[j]);
        }

    }
}
void display(struct student stu[], int n,int m)
{
	int i,total[n],j;
	float percent[n];
	for (i = 0; i < n; i++)
	{
		printf("roll no of student %d is %d\n", i + 1, stu[i].sroll);
		printf("name of student %d is %s\n", i + 1, stu[i].sname);
	}
	for(i=0;i<n;i++)
    {
        total[i]=0;
        percent[i]=0;
    }
	for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            total[i]+=stu[i].subject[j];
        }

    }
    for(i=0;i<n;i++)
    {
            percent[i]=total[i]/m;
    }
    for(i=0;i<n;i++)
    {
        printf("Total for student %d: %d\n",i+1,total[i]);
        printf("Percentage for student %d: %f\n",i+1,percent[i]);
    }


}
