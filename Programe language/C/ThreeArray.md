```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,q;
    int ***array;
    int i,j,k;
    puts("输入一维长度");
    scanf("%d",&m);
    puts("输入二维长度");
    scanf("%d",&n);
    puts("输入三维长度");
    scanf("%d",&q);
    //第一维
    array = (int ***)malloc(m*sizeof(int**));
    for(i=0; i<m; i++)
    {
        array[i] = (int **)malloc(n*sizeof(int*));
        for (j=0; j<n; j++)
        {
            array[i][j] = (int *)malloc(q*sizeof(int));
            for (k=0; k<q; k++)
            {
                array[i][j][k] = i+j+k+1;
                printf("%d\t",array[i][j][k]);
            }
            puts("");
        }
        puts("");
    }

    for (i = 0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            //释放第三维指针
            free(array[i][j]);
        }
    }

    for (i=0; i<m; i++)
    {
        //释放第二维指针
        free(array[i]);
    }
    //释放第三维指针
    free(array);

    return 0;
}
```