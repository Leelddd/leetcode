#include "alg.h"

int binarysearch(vector<int> &line, int low, int high, int val) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (line[mid] == val) return mid;
        else if (line[mid] < val) low = mid + 1;
        else if (line[mid] > val) high = mid - 1;
    }
    return low;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int low = 0, high = matrix[0].size() - 1;
    for (vector<int> &v: matrix) {
        int pos = binarysearch(v, low, high, target);
        if (pos < v.size()) {
            if (v[pos] == target) return true;
            high = pos;
        }
    }
    return false;
}

// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/
bool searchMatrix_2(vector<vector<int>> &matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;
    while (j >= 0 && i < n) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] < target) i++;
        else j--;
    }
    return false;
}


int main() {

}