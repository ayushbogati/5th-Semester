#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    float profit[100], weight[100], ratio[100];
    float maxProfit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i] >> weight[i];
        ratio[i] = profit[i] / weight[i];  
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            maxProfit += profit[i];
        } else {
            maxProfit += ratio[i] * capacity;
            break;
        }
    }

    cout << "\nMaximum Profit = " << maxProfit;

    return 0;
}


