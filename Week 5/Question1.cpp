#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
using namespace std::chrono;

void recursiveQuickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    recursiveQuickSort(arr, left, j);
    recursiveQuickSort(arr, i, right);
}

void nonRecursiveQuickSort(int arr[], int left, int right) {
    stack<int> st;
    st.push(right);
    st.push(left);
    while (!st.empty()) {
        int l = st.top();
        st.pop();
        int r = st.top();
        st.pop();
        int pivot = arr[(l + r) / 2];
        int i = l, j = r;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        if (l < j) {
            st.push(j);
            st.push(l);
        }
        if (i < r) {
            st.push(r);
            st.push(i);
        }
    }
}

void testAlgorithm(void (*algorithm)(int*, int, int), string name) {
    cout << "Testing " << name << " algorithm:" << endl;
    for (int n = 5000; n <= 50000; n += 5000) {
        int* arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }
        auto start = high_resolution_clock::now();
        algorithm(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Array size " << n << ": " << duration.count() << "ms" << endl;
        delete[] arr;
    }
    cout << endl;
}

int main() {
    testAlgorithm(recursiveQuickSort, "recursive");
    testAlgorithm(nonRecursiveQuickSort, "non-recursive");
    return 0;
}
