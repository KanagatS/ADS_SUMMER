#include <iostream>
#include <vector>

using namespace std;

void mergeHalves(int arr[], int temp[], int leftStart, int rightEnd) {
    int leftEnd = (rightEnd + leftStart) / 2;
    int rightStart = leftEnd + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while(left <= leftEnd && right <= rightEnd) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
        }
        else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while(left <= leftEnd) {
        temp[index] = arr[left];
        index++;
        left++;
    }
    while(right <= rightEnd) {
        temp[index] = arr[right];
        index++;
        right++;
    }
    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i];
    }
}

void mergesort(int arr[], int temp[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd)
        return;
    int middle = (leftStart + rightEnd) / 2;
    mergesort(arr, temp, leftStart, middle);
    mergesort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd); 
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m; cin >> m;
    int b[m];
    int sorted[n + m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int index = 0, left = 0, right = 0;
    while (left < n && right < m) {
        if (a[left] < b[right]) {
            sorted[index] = a[left];
            left++;
        }
        else {
            sorted[index] = b[right];
            right++;
        }
        index++;
    }
    while(left < n) {
        sorted[index] = a[left];
        index++; left++;
    }
    while(right < m) {
        sorted[index] = b[right];
        index++; right++;
    }
    for (int i = 0; i < n + m; i++) {
        cout << sorted[i] << " ";
    }
}