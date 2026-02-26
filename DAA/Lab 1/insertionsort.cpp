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

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            iter++;   // comparison count
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else
                break;
        }
        a[j + 1] = key;
    }

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTotal iterations: " << iter;

    return 0;
}

