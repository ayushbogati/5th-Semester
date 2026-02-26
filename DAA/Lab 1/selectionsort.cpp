#include <iostream>
using namespace std;

int iter = 0;   // count comparisons

int main() {
    int n, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            iter++;   // comparison count
            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
            swap(a[i], a[min]);
    }

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTotal iterations: " << iter;

    return 0;
}

