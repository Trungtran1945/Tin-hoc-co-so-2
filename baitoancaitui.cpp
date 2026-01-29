#include <iostream>

#include <stdio.h>

#include <conio.h>

#define MAX 100

int A[MAX], C[MAX], F[MAX][MAX];

int XOPT(MAX), X[MAX];

int n, b, ind;

float W, FOPT = -32000, cost, weight = 0;

FILE *fp;

void Init(void)
{

    fp = fopen("caituil.in", "r");

    fscanf(fp, "%d%d", &n, &b);

    cout << "\n So luong do vat:" << n;

    cout << "\n Trong luong tui:" << b;

    for (int i = 1; i <= n; i++)

        fscanf(fp, "%d%d", &A[i], &C[i]);

    cout << "\n Vector trong luong:";
    for (i = 1; i <= n; i++)

        cout << A[i] << " ";

    cout << "\n Vector gia tri su dung:";
    for (i = 1; i <= n; i++)
        cout << C[i] << " ";

    fclose(fp);
}

void Result(void)
{

    cout << "\n Ket qua toi uu:" << FOPT :

        cout
         << "\n Phuong an toi uu:";
    for (int i = 1; i <= n; i++)

        cout << XOPT[i] << " ";
}

void Branch_And_Bound(int i)
{

    int j, t = (b - weight) / A[i];

    for (j = t; j >= 0; j--)
    {
        X[i] = j;

        weight = weight + A[i] * X[i];

        cost = cost + C[i] * X[i];

        if (i == n)
            Update_Kyluc();

        else if (cost + C[i + 1] * (b - weight) / A[i + 1] > FOPT)

            Branch_And_Bound(i + 1);

        weight = weight - A[i] X[i];

        cost = cost C[i] X[i];
    }
}

void main(void)
{

    Init();

    Branch_And_Bound(1);

    Result();
}