#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

void insertion_sort(int A[], int n)
{
    int i, j, key;
    for (j = 2; j <= n; j++) {
        key = A[j];
        i = j-1;
        while (i > 0 && A[i] > key) {
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

int main()
{
    int A[100], i, n = 20;
    for (i = 1; i <= n; i++)
        A[i] = rand()%50;
    cout << "Before sorting:\n";
    for (i = 1; i <= n; i++)
        cout << A[i] << " ";

    insertion_sort(A, n);

    cout << "\n\nAfter sorting:\n";
    for (i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
