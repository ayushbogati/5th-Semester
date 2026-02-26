#include <iostream>
using namespace std;

int iter = 0;   // count comparisons

int main() {
    int n, a[100];
    int min, max;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    min = max = a[0];

    for (int i = 1; i < n; i++) {
        iter++;
        if (a[i] > max)
            max = a[i];

        iter++;
        if (a[i] < min)
            min = a[i];
    }

    cout << "\nMinimum element: " << min;
    cout << "\nMaximum element: " << max;
    cout << "\nTotal iterations: " << iter;

    return 0;
}

