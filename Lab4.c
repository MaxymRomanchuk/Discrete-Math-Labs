#include <stdio.h>
#define a_rebr 18
#define a_top 11
#define c_1 4
#define c_2 2

int main (void)
{
	int i,j,k,a;
    int rebro [a_rebr][c_1] =
    {
        {1, 2, 4, 0}, //point_from, point_to, weight, +/- in tree
        {1, 3, 3, 0},
        {1, 4, 1, 0},
        {2, 5, 2, 0},
        {2, 7, 1, 0},
        {3, 5, 7, 0},
        {3, 6, 7, 0},
        {4, 6, 2, 0},
        {4, 7, 2, 0},
        {5, 8, 4, 0},
        {5, 9, 4, 0},
        {6, 8, 4, 0},
        {6, 10, 5, 0},
        {7, 9, 3, 0},
        {7, 10, 3, 0},
        {8, 11, 7, 0},
        {9, 11, 6, 0},
        {10, 11, 5, 0}
    };

    int top [a_top][c_2] =
    {
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0},
        {7, 0},
        {8, 0},
        {9, 0},
        {10, 0},
        {11, 0}
    };

    //sort
    for (i = 0; i < a_rebr; i++)
    {
        for (j = 0; j < a_rebr - i - 1; j++)
        {
            if (rebro [j][2] > rebro [j + 1][2])
            {
                for (k = 0, a = 0; k < c_1; k++)
                {
                    a = rebro [j + 1][k];
                    rebro [j + 1][k] = rebro [j][k];
                    rebro [j][k] = a;
                }
            }
        }
    }

    int count = 1;
    for (i = 0; i < a_rebr; i++) {
        if (top [rebro[i][0] - 1][1] != top [rebro[i][1] - 1][1]) {
            rebro [i][3] = 1;
            if (top [rebro[i][0] - 1][1] == 0 && top [rebro[i][1] - 1][1] != 0) {
                top [rebro[i][0] - 1][1] = top [rebro[i][1] - 1][1];
    		}
            if (top [rebro[i][0] - 1][1] != 0 && top [rebro[i][1] - 1][1] == 0) {
                top [rebro[i][1] - 1][1] = top [rebro[i][0] - 1][1];
            }
            if (top [rebro[i][0] - 1][1] != 0 && top [rebro[i][1] - 1][1] != 0) {
                //поміняти всі знач з цбого ж дерева 
                for (j = 0; j < a_top; j++)
                {
                    if (top [j][1] == top [rebro[i][1] - 1][1])
                    {
                        top [j][1] = top [rebro[i][0] - 1][1];
                    }
                }
            }
        }
        if (top [rebro[i][0] - 1][1] == 0 && top [rebro[i][1] - 1][1] == 0)
        {
            rebro [i][3] = 1;
            top [rebro[i][0] - 1][1] = count;
            top [rebro[i][1] - 1][1] = count;
            count++;
        }
    }

    for (i = 0; i < c_rebr; i++)
    {
        if (rebro[i][3] == 1)
        {
            printf ("%i - %i (%i)\n", rebro[i][0], rebro[i][1], rebro [i][2]);
        }
    }

    return 0;
}
