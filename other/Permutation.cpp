#include<iostream>

using namespace std;

// 交换list中i和j位置的元素
void swap(int list[], int i, int j) {
    int t = list[i];
    list[i] = list[j];
    list[j] = t;
}

// 输出list中m到n的全排列
void permutation(int list[], int m, int n) {
    if (m == n) {
        // 输出0-n的一个排列
        for (int i = 0; i <= n; i++)
            cout << list[i];
        cout << endl;
    } else {
        for (int i = m; i <= n; i++) {
            // 把第i个和第一个(此时是m)交换
            swap(list, m, i);
            // 余下的继续递归
            permutation(list, m + 1, n);
            // 将第i个放回原处
            swap(list, m, i);
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4};
    permutation(a, 0, 3);
    return 0;
}
