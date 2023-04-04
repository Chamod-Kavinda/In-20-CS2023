#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void sort(int n, vector<int>& arr) {
    int last = arr[n - 1];
    int now = n - 1;

    while (now > 0 && arr[now - 1] > last) {
        arr[now] = arr[now - 1];
        now--;
    }

    arr[now] = last;
}

int main() {
    int n = 0;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr;

    int elem = 0;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        arr.push_back(elem);

        sort(i + 1, arr);

        cout << "Sorted                 Median\n";
        cout << "[ ";
        for (int j = 0; j < i + 1; j++)
            cout << arr[j] << ", ";
        cout << "]        ";

        double median = 0.0;
        int mid = (i + 1) / 2;

        if ((i + 1) % 2 != 0) {
            median = arr[mid];
        }
        else {
            median = (arr[mid - 1] + arr[mid]) / 2.0;
        }
        cout << fixed << setprecision(1);
        cout << "\t   " << median << "\n";
    }
}


