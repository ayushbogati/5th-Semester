#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int d[n + 1];
    cout << "Enter dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
        cin >> d[i];

    int C[n + 1][n + 1];   // Cost matrix
    int K[n + 1][n + 1];   // Split matrix

    // Initialize diagonal to 0
    for (int i = 1; i <= n; i++)
        C[i][i] = 0;

    // Chain length
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            C[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = C[i][k] + C[k+1][j] 
                           + d[i-1] * d[k] * d[j];

                if (cost < C[i][j]) {
                    C[i][j] = cost;
                    K[i][j] = k;   // Store split point
                }
            }
        }
    }

    // Print Cost Matrix
    cout << "\nCost Matrix (C):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < i)
                cout << setw(8) << "-";
            else
                cout << setw(8) << C[i][j];
        }
        cout << endl;
    }

    // Print K Matrix
    cout << "\nK Matrix (Split Positions):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= i)
                cout << setw(8) << "-";
            else
                cout << setw(8) << K[i][j];
        }
        cout << endl;
    }

    cout << "\nMinimum multiplication cost = " << C[1][n];

    return 0;
}
