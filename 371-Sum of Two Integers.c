int getSum(int a, int b) {
    if(b == 0) return a;
    while(b)
    {
        int c = a ^ b;
        b = (int)((unsigned)(a & b) << 1);
        a = c;
    }
    return a;
}

// Description:
// Calculate the sum of two integers a and b, 
// but you are not allowed to use the operator + and -.

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = -2, b = 3
// Output: 1

// Runtime: 0 ms, faster than 100.00% of C online submissions for Sum of Two Integers.
// Memory Usage: 6.4 MB, less than 95.24% of C online submissions for Sum of Two Integers.

// Alg:
// a ^ b : 按位相与，不考虑进位
// (a & b) << 1 : 计算进位
// 之后将进位与之前所求和 相加。

// Notice:
// b = (int)((unsigned)(a & b) << 1);
// 需要进行格式转换，
// 否则有 runtime error: left shift of negative value的报错