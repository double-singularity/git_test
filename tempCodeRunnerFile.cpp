#include <iostream>
#include <vector>
using namespace std;

void randomize(vector<int> &v, int n) {
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 100);
    }
}

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(vector<int> &v, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = v[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    quicksort(v, left, j);
    quicksort(v, i, right);
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    randomize(v, n);
    print(v);
    quicksort(v, 0, v.size() - 1);
    print(v);
    return 0;
}