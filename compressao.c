#include <stdio.h>

#define MAX_LIN 12
#define MAX_COL 36

int main()
{
    char codigo[3];
    int i, j, nlin, c, intensidade, matriz[MAX_LIN][MAX_COL];

    scanf("%s %d %d %d", codigo, &nlin, &c, &intensidade);

    int ncol = 3 * c;

    for (i = 0; i < nlin; i++)
    {
        for (j = 0; j < ncol; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int cores[nlin][5];

    for (i = 0; i < nlin; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cores[i][j] = 0;
        }
    }

    //ATRIBUIÇÃO DAS CORES
    int C0 = 0, C1 = 0, C2 = 0, C3 = 0, C4 = 0;
    int p, q;

    for (p = 0; p < nlin; p++)
    {
        for (q = 0; q < ncol; q = q + 3)
        {
            if ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0))
            {
                cores[p][0]++;
                C0++;
            }
            else if ((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0))
            {
                cores[p][1]++;
                C1++;
            }
            else if ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0))
            {
                cores[p][2]++;
                C2++;
            }
            else if ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255))
            {
                cores[p][3]++;
                C3++;
            }
            else if ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0))
            {
                cores[p][4]++;
                C4++;
            }
        }
    }

    //MATRIZ DAS CORES
    int x, y;

    for (x = 0; x < nlin; x++)
    {
        for (y = 0; y < 5; y++)
        {
            printf("%d ", cores[x][y]);
        }
        printf("\n");
    }

    //COR PREDOMINANTE
    if ((C0 > C1) && (C0 > C2) && (C0 > C3) && (C0 > C4))
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0))
                {
                    printf("0 0 0 ");
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if ((C1 > C0) && (C1 > C2) && (C1 > C3) && (C1 > C4))
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if ((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0))
                {
                    printf("0 0 0 ");
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if ((C2 > C0) && (C2 > C1) && (C2 > C3) && (C2 > C4))
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0))
                {
                    printf("0 0 0 ");
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if ((C3 > C0) && (C3 > C1) && (C3 > C2) && (C3 > C4))
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255))
                {
                    printf("0 0 0 ");
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if ((C4 > C0) && (C4 > C1) && (C4 > C2) && (C4 > C3))
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0))
                {
                    printf("0 0 0 ");
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }

    //EMPATE TRIPLO
    else if (C0 == C1 && C1 == C2 && C0 > C3 && C0 > C4)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C0 == C1 && C1 == C3 && C0 > C2 && C0 > C4)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C0 == C1 && C1 == C4 && C0 > C2 && C0 > C3)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C0 == C2 && C2 == C3 && C0 > C1 && C0 > C4)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C0 == C2 && C2 == C4 && C0 > C1 && C0 > C3)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C0 == C3 && C3 == C4 && C0 > C1 && C0 > C2)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C1 == C2 && C2 == C3 && C1 > C0 && C1 > C4)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C1 == C2 && C2 == C4 && C1 > C0 && C1 > C3)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C1 == C3 && C3 == C4 && C1 > C0 && C1 > C2)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 255) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }
    else if (C2 == C3 && C3 == C4 && C2 > C0 && C2 > C1)
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q = q + 3)
            {
                if (((matriz[p][q] == 0) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)) || ((matriz[p][q] == 0) && (matriz[p][q + 1] == 0) && (matriz[p][q + 2] == 255)) || ((matriz[p][q] == 255) && (matriz[p][q + 1] == 255) && (matriz[p][q + 2] == 0)))
                {
                    printf("%d %d %d ", matriz[p][q], matriz[p][q+1], matriz[p][q+2]);
                }
                else
                {
                    printf("255 255 255 ");
                }
            }
            printf("\n");
        }
    }

    //EMPATE QUINTÚPLO
    else if ((C0 == C1) && (C0 == C2) && (C0 == C3) && (C0 == C4))
    {
        for (p = 0; p < nlin; p++)
        {
            for (q = 0; q < ncol; q++)
            {
                printf("%d ", matriz[p][q]);
            }
            printf("\n");
        }
    }
    
    printf("\n");

    return 0;
}