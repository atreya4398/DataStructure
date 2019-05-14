#include<stdio.h>
#include<stdlib.h>


int merge(int *a1,int *a2,int s1,int s2)
{
    int i,j;
    int *array3,s3;
    array3=(int *)calloc(s1+s2,sizeof(int));
    s3=s1+s2;
    for(i=0;i<s1;i++)
    {
        array3[i]=a1[i];
    }
    j=s1;
    for(i=0;i<s2;i++)
    {
            array3[j]=a2[i];
            j++;
    }

     printf("\nMerged array is : - \n");
    for(i=0;i<s3;i++)
    {
        if(i<s3-1)
            printf("%d , ",array3[i]);
        else
            printf("%d",array3[i]);
    }
    return 0;

}
int main()
{
    int i,*arr1,*arr2;

    int size1,size2;

    printf("Enter size for array1: ");
    scanf("%d",&size1);
    printf("Enter size for array2: ");
    scanf("%d",&size2);

    arr1=(int *)calloc(size1,sizeof(int));
    arr2=(int *)calloc(size2,sizeof(int));

    for(i=0;i<size1;i++)
    {
        printf("enter elements for first array %d: ",i+1);
        scanf("%d",&arr1[i]);
    }

    for(i=0;i<size2;i++)
    {
        printf("enter elements for second array %d: ",i+1);
        scanf("%d",&arr2[i]);
    }

    merge(arr1,arr2,size1,size2);
    //size3=(int *)calloc(size1+size2,sizeof(int));



}
