#include <iostream>
using namespace std;

// // generate random number by current time
// int random_number(int max, int min)
// {
//     static default_random_engine e(time(0));
//     uniform_int_distribution<int> u(min, max);
//     return u(e);
// }

// implement merge sort
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = a[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    // input size of array
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // a[i] = random_number(1000, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        // b[i] = random_number(1000, 0);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] - b[i];
    }

    mergeSort(a, 0, n - 1);
    long long count = 0;
    int *dp = new int[n];
    // dp[0] = 0;
    int currentIndex = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            while (a[i] + a[currentIndex] > 0 && currentIndex > i)
            {
                currentIndex--;
            }
            dp[i] = n - 1 - currentIndex;
        }
        else
        {
            dp[i] = n - 1 - i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        count += dp[i];
    }
    cout << count << endl;
    delete[] a;
    delete[] b;
    delete[] dp;
    return 0;
}