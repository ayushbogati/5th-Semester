#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
using namespace std;

int iter = 0;   // count comparisons

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        iter++;   // comparison count
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Random pivot selection
int randomPartition(int a[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(a[random], a[high]);   // move random pivot to end
    return partition(a, low, high);
}

void randomizedQuickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(a, low, high);
        randomizedQuickSort(a, low, pi - 1);
        randomizedQuickSort(a, pi + 1, high);
    }
}

int main() {
    int n, a[100];

    srand(time(0));   // seed random number

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    randomizedQuickSort(a, 0, n - 1);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\nTotal iterations: " << iter;

    return 0;
}

