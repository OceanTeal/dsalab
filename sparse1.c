#include<stdio.h>
void repsparse(int a[100][100],int row,int col)
{
    int i,j,sr[100][3];
    int value=1;
    int zeroes=0,total=0;
    float sparsity=0;
    sr[0][0]=row;
    sr[0][1]=col;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(a[i][j]!=0)
            {
                sr[value][0]=i;
                sr[value][1]=j;
                sr[value][2]=a[i][j];
                value+=1;
            }
            else
            {
                zeroes+=1;
            }
        }
    }
    sr[0][2]=value-1;
    printf("\n");

    for(i=0;i<value;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",sr[i][j]);            
        }
        printf("\n");
    }
    total=row*col;
    sparsity=((float) zeroes / total);
    printf("Sparsity of the matrix is %f: ",sparsity);
}

void readmat(int a[100][100], int row, int col)
{    
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
    

int main()
{
    int i,j,row,col;
    int a[100][100];
    printf("Enter the number of rows");
    scanf("%d",&row);
    printf("Enter the number of columns");
    scanf("%d",&col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Enter the element at position[%d][%d]",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    readmat(a,row,col);
    printf("\nSparse representation:");
    repsparse(a,row, col);
    return 0;
}
