#include <iostream>
using namespace std;

int iter = 0;   // count comparisons

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        iter++;
        if (a[l] > a[largest])
            largest = l;
    }

    if (r < n) {
        iter++;
        if (a[r] > a[largest])
            largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int n, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    heapSort(a, n);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTotal iterations: " << iter;

    return 0;
}

