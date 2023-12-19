#include <stdio.h>
#include <stdlib.h>
#define MAX 10


int main() {

    int a[MAX][MAX], b[MAX][MAX], C[MAX][3];
    int row, cols;
    printf("Enter the number of rows and columns in the matrix:\n");
    scanf("%d %d", &row, &cols);
    printf("Enter the matrix\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    b[0][0] = row;
    b[0][1] = cols;
    int k = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }

    }
    b[0][2] = k - 1;
    for (int i = 0; i <= b[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    //transpose function
    int transpose[MAX][MAX];
    transpose[0][0] = b[0][1], transpose[0][1] = b[0][0], transpose[0][2] = b[0][2];
    int t = 1, m = b[0][1], n = b[0][2];
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[j][1] == i) {
                transpose[t][0] = b[j][1];
                transpose[t][1] = b[j][0];
                transpose[t][2] = b[j][2];
                t++;
            }
        }
    }
    printf("transpose of the matrix\n");
    for (int i = 0; i <= transpose[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
    int flag = 0;
//To check the symmetricity
    for (int i = 0; i <= b[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            if (b[i][j] != transpose[i][j]) {
                flag = 1;
            }
        }
    }

    if (flag == 0) {
        printf("symmetric matrix\n");
    } else {
        printf("non-symmetric matrix");
    }
}