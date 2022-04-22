#include <bits/stdc++.h>
#define mode 1000000007
#define ll long long int
using namespace std;
#define N 101

int ar[N][N], I[N][N];

void mul(int A[][N], int B[][N], int dim)
{
    int res[dim + 1][dim + 1];
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for (int k = 1; k <= dim; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "This is new A:" << endl;

    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            A[i][j] = res[i][j];
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void print(int A[][N], int dim)
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void power(int A[][N], int dim, int n)
{
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            if (i == j)
            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     mul(I, A, dim);
    // }

    while (n)
    {
        if (n % 2 == 1)
        {
            // I = I * A;
            mul(I, A, dim);
            n--;
        }
        else
        {
            // A = A * A;
            mul(A, A, dim);
            n = n / 2;
        }
    }
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            A[i][j] = I[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int dim, n;

    cin >> dim >> n;
    for (int i = 1; i <= dim; i++)
    {
        for (int j = 1; j <= dim; j++)
        {
            cin >> ar[i][j];
        }
    }
    power(ar, dim, n);
    cout << "ans" << endl;
    print(ar, dim);
    return 0;
}

// time_complexity = dim * logn;