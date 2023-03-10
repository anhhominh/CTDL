
#include <iostream>
using namespace std;

int a[100001];
int l[100001];

int moneyChange(int a[], int n, int x)
{
    l[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        l[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        l[a[i]] = 1;
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i > j)
            {
                if (l[i] > l[i - j] + l[j] || l[i] == 0)
                {
                    l[i] = l[i - j] + l[j];
                }
            }
        }
    }

    return l[x];
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> x;
    cout << moneyChange(a, n, x);
    return 0;
}