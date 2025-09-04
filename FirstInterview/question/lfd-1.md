3. 这是bug吗？
```c
这是怎么回事？有什么解决办法
int main()
{
    double d1 = 0.1, d2 = 0.2;
    printf("0.1 + 0.2 == 0.3 is %s\n", (d1 + d2 == 0.3) ? "true" : "false");
    float big = 1e8f;
    float small = 1.0f;
    printf("(1e8 + 1.0) - 1e8 == 1.0 is %s\n", ((big + small) - big == small) ? "true" : "false");
}
```
|出题人|鲁樊栋  |
|--|--|
| 知识点 |浮点数精度  |

Q1：说出输出结果以及为什么

Q2：解决办法

A1:
```c
0.1 + 0.2 == 0.3 is false
(1e8 + 1.0) - 1e8 == 1.0 is false
```
1.第一个问题：0.1 + 0.2 == 0.3​​
•解释：在二进制浮点数表示中，0.1 和 0.2 都是无限循环小数。因此，当它们相加时，结果在计算机中存储的并不是精确的0.3，而是接近0.3的值（比如0.30000000000000004）。同样，直接写0.3的字面值也会被转换为一个近似值。所以，直接比较两个浮点数是否相等通常是不可靠的。在这个例子中，比较操作的结果可能是false。

2.​​第二个问题：大数加小数​​
•解释：这里有一个很大的数（1e8，即100000000）和一个小数（1.0）。当我们将大数和小数相加时，由于浮点数的精度有限（单精度float只有约7位有效数字），1e8的精度远大于1.0，所以当1.0被加到1e8上时，它可能会因为精度不够而被忽略（因为1e8的整数部分有9位，而float的有效位数只有7位，所以在加法中1.0可能被舍入而消失）。因此，计算结果可能等于1e8，那么再减去1e8就会得到0，而不是1.0，所以比较结果可能为false。

A2:

解决方案1：使用误差容忍范围比较

```c
#include <stdio.h>
#include <math.h>
#include <float.h> // 包含浮点数精度常量

int main() {
    double d1 = 0.1, d2 = 0.2;
    double sum = d1 + d2;
    double expected = 0.3;
    
    // 设置合理的误差容忍范围
    double tolerance = 1e-9; // 10^-9
    
    // 比较浮点数差值是否在容忍范围内
    int isEqual = fabs(sum - expected) < tolerance;
    
    printf("0.1 + 0.2 ≈ 0.3 is %s\n", isEqual ? "true" : "false");
    
    // 使用系统定义的精度常量
    double big = 1e8;
    double small = 1.0;
    double result = (big + small) - big;
    
    // 使用相对误差比较
    double relativeError = fabs(result - small) / fabs(small);
    int isEqual2 = relativeError < DBL_EPSILON * 10;
    
    printf("(1e8 + 1.0) - 1e8 ≈ 1.0 is %s\n", isEqual2 ? "true" : "false");
    
    return 0;
}
```
解决方案2：使用高精度数学库（如GMP）
```c
#include <stdio.h>
#include <gmp.h>

int main() {
    // 初始化高精度浮点数
    mpf_t d1, d2, sum, expected;
    mpf_init_set_d(d1, 0.1);
    mpf_init_set_d(d2, 0.2);
    mpf_init_set_d(sum, 0.0);
    mpf_init_set_d(expected, 0.3);
    
    // 计算和比较
    mpf_add(sum, d1, d2);
    int isEqual = mpf_cmp(sum, expected) == 0;
    
    printf("0.1 + 0.2 == 0.3 is %s\n", isEqual ? "true" : "false");
    
    // 清理内存
    mpf_clear(d1);
    mpf_clear(d2);
    mpf_clear(sum);
    mpf_clear(expected);
    
    // 第二个问题
    mpf_t big, small, result;
    mpf_init_set_d(big, 1e8);
    mpf_init_set_d(small, 1.0);
    mpf_init(result);
    
    // 计算 (big + small) - big
    mpf_add(result, big, small);
    mpf_sub(result, result, big);
    
    int isEqual2 = mpf_cmp(result, small) == 0;
    printf("(1e8 + 1.0) - 1e8 == 1.0 is %s\n", isEqual2 ? "true" : "false");
    
    // 清理内存
    mpf_clear(big);
    mpf_clear(small);
    mpf_clear(result);
    
    return 0;
}
```









