#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c;

    scanf("%d %d",&r,&c);

    int ints[r][c];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&ints[i][j]);
        }
    }

    int max=ints[0][0];
    int x,y;

    for(int j=0;j<c;j++)
    {
        max=max>ints[0][j]?max:ints[0][j];
    }
    for(int j=0;j<c;j++)
    {
        if(max==ints[0][j])
        {
            y=j;
        }
    }

    int min=max;

    for(int i=0;i<r;i++)
    {
        min=min<ints[i][y]?min:ints[i][y];
    }

    if(min==max)
    {
        for(int i=0;i<r;i++)
        {
            if(min==ints[i][y])
            {
                x=i;
            }
        }
        printf("%d %d %d\n",min,x,y);
    }
    else
    {
         printf("NO");
    }

    return 0;
}

