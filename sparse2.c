#include<stdio.h>

void sparse(int sr[100][3])
{
    int i,j,k=1;
    printf("Enter rows:");
    scanf("%d",&sr[0][0]);
    printf("Enter colunms:");
    scanf("%d",&sr[0][1]);
    printf("Enter number of non zero elements:");
    scanf("%d",&sr[0][2]);
    for(i=1;i<sr[0][2]+1;i++){
        printf("Enter row coloum value :");
    for(j=0;j<3;j++){
        scanf("%d",&sr[i][j]);
    }
    }
    // Sort the elements based on the row
    for(i = 1; i<sr[0][2]; i++) {
        for(j = i + 1; j <= sr[0][2]; j++) {
            if(sr[i][0] > sr[j][0]) {
                // Swap rows i and j
                for(k = 0; k < 3; k++) {
                    int temp = sr[i][k];
                    sr[i][k] = sr[j][k];
                    sr[j][k] = temp;
                }
            }
        }
    }
        for(k=0;k<sr[0][2]+1;k++){
            for(j=0;j<3;j++){
                printf("%d ",sr[k][j]);
            }
            printf("\n");
        }
    

}

void add(int mat1[100][3],int mat2[100][3])
{
    int nz1,nz2,n=0,mat[100][3],i,j,k;
    
    if((mat1[0][0]==mat2[0][0]) && (mat1[0][1]==mat2[0][1]))
    {
        
        nz1=mat1[0][2];
        nz2=mat2[0][2];
        i=1;
        j=1;
        k=1;
        
        while ((i <= nz1) && (j <= nz2)) {
            if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
                mat[k][0] = mat1[i][0];
                mat[k][1] = mat1[i][1];
                mat[k][2] = mat1[i][2];
                i++;
                k++;
            } else if (mat1[i][0] > mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1])) {
                mat[k][0] = mat2[j][0];
                mat[k][1] = mat2[j][1];
                mat[k][2] = mat2[j][2];
                j++;
                k++;
            } else {
                mat[k][0] = mat1[i][0];
                mat[k][1] = mat1[i][1];
                mat[k][2] = mat1[i][2] + mat2[j][2];
                i++;
                j++;
                k++;
            }
        }       
         
        while(i<=nz1)
        {
            mat[k][0]=mat1[i][0];
            mat[k][1]=mat1[i][1];
            mat[k][2]=mat1[i][2];
            i++;k++; 
        }
        while(j<=nz2)
        {
            mat[k][0]=mat2[j][0];
            mat[k][1]=mat2[j][1];
            mat[k][2]=mat2[j][2];
            j++;k++;
        }
        mat[0][0]=mat1[0][0];
        mat[0][1]=mat1[0][1];
        mat[0][2]=k-1;
         for(i=0;i<k;i++)
        {
            printf("\n");
            for(j=0;j<3;j++)
            {
            
            printf("%d ",mat[i][j]);
            }
    }
    }
    else
    {
        printf("Cannot add\n");
    }
}
void main()
{
    int mat1[100][3],mat2[100][3];
    printf("Sparse Rep1\n");
    sparse(mat1);
    printf("Sparse Rep2 \n");
    sparse(mat2);
    
    printf("\nSum\n");
    add(mat1,mat2);
}
                
