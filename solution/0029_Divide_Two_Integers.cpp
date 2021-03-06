#include "alg.h"

// abandon
int divide(int dividend, int divisor) {
    if (dividend == INT32_MIN && divisor == -1)return INT32_MAX;
    int reverse = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
    dividend = dividend >= 0 ? -dividend : dividend;
    divisor = divisor >= 0 ? -divisor : divisor;
    int i = 0;
    while (dividend <= divisor) {
        int minuend = divisor;
        int cnt = 1;
        while (dividend <= (minuend + minuend)) {
            minuend += minuend;
            cnt += cnt;
        }
        dividend -= minuend;
        i += cnt;
    }
    return reverse ? -i : i;
}

// https://leetcode.com/problems/divide-two-integers/discuss/13407/C%2B%2B-bit-manipulations
// use long directly
int divide_2(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    long l = abs(dividend), r = abs(divisor);
    long ans = 0;
    while (r <= l) {
        long base = r, cnt = 1;
        while (l >= (base << 1)) {
            base <<= 1;
            cnt <<= 1;
        }
        l -= base;
        ans += cnt;
    }

    return (dividend > 0) == (divisor > 0) ? ans : -ans;
}


int main() {
//    cout << divide(10, 3) << ',' << divide(7, -3) << ',' << divide(INT32_MIN, -1) << "," << divide(INT32_MAX, 2) << endl;
//    cout << divide(INT32_MIN, 1);
    cout << INT32_MIN + INT32_MIN;
}