#include<stdio.h>



int a[10][3];
int b[10][3];
int c[10][3];
int row;
void read(int matrix[10][3]){


    printf("Enter the row:\n");

    scanf("%d",&row);






    printf("Enter the normal matrix:\n");

    for(int i=0;i<=row;i++){

        for(int j = 0;j<3;j++){

            scanf("%d",&matrix[i][j]);

        }
    }


}


void sparseAdd(int a[][3],int b[][3],int c[][3]){

    int r1,r2,c1,c2;
    int k,n,m;

    r1 = a[0][0];
    r2 = b[0][0];
    c1 = a[0][1];
    c2 = b[0][1];
    if(r1!=r2 && c1!=c2){
        printf("Error in matrix\n");
    }
    else{
        c[0][0]=a[0][0];
        c[0][1]=a[0][1];
        k=1;
        m=1;
        n=1;
        for (int i =0;i<r1;i++){
            for(int j =0;j<c1;j++){
                if(a[m][0]==i && a[m][1]==j && b[n][0]==i && b[n][1]==j){
                    c[k][0]=a[m][0];
                    c[k][1]=a[m][1];
                    c[k][2]=a[m][2]+b[n][2];
                    k++;
                    m++;
                    n++;
                }
                else if(a[m][0]==i&&a[m][1]==j){
                    c[k][0]=a[m][0];
                    c[k][1]=a[m][1];
                    c[k][2]=a[m][2];
                    k++;
                    m++;
                }
                else if(b[n][0]==i&&b[n][1]==j){
                    c[k][0]=b[n][0];
                    c[k][1]=b[n][1];
                    c[k][2]=b[n][2];
                    k++;
                    n++;
                }

            }

        }
        c[0][2]=k-1;

        for(int i=0;i<k;i++){

            printf("\n");

            for(int j = 0;j<3;j++){

                printf("%d\t",c[i][j]);

            }
        }



    }
}


void display(int c[][3]){




    printf("The added sparse:\n");

    for(int i=0;i<row;i++){
        printf("\n");

        for(int j = 0;j<3;j++){

            printf("%d\t",c[i][j]);

        }
    }


}




int main(){
    printf("Enter the two sparse representaion:\n");
    read(a);
    read(b);

    sparseAdd(a,b,c);


}