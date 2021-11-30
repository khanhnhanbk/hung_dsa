#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // aj - ai = floor((i+1)^1.5) + ceil((j+1)^0.5)
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[j] - a[i] == floor(pow(i+1, 1.5)) + ceil(pow(j+1, 0.5)))
            {
                count++;
            }
        }
    }
    cout << count;

    delete[] a;
    return 0;
}