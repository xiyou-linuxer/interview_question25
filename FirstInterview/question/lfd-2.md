9. 神奇的宏
>感受宏的魅力，猜一猜结果
```c
#define SQUARE(x) x * x
#define CONCAT(a, b) a##b
#define APPLY(f, x) f(x)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SUM(n) ((n) * ((n) + 1) / 2)
#define print() printf("SUM(10) = %d\n",SUM(10));
int main() {
    int x = 5, y = 3;
    int ab = 100;
    printf("CONCAT(a, b) = %d\n", CONCAT(a, b));
    printf("APPLY(SQUARE, 4) = %d\n", APPLY(SQUARE, 4));
    printf("MAX(x++, y++) = %d, x = %d, y = %d\n", MAX(x++, y++), x, y);
    print()
    return 0;
}
```
|出题人|鲁樊栋  |
|--|--|
| 知识点一 |宏的文本替换  |
|知识点二|自增运算符|

Q1.说出输出结果

Q2.分析x，y的自增过程

A1:
```c
CONCAT(a, b) = 100
APPLY(SQUARE, 4) = 16
MAX(x++, y++) = 6, x = 7, y = 4
SUM(10) = 55
```
A2:

求值过程：
比较：x++和y++，后置自增，所以比较时用原值，然后自增。

比较：5>3 -> true，然后x变为6，y变为4
因为true，所以执行x++，注意这个x++是三元运算符的返回值表达式，所以：
返回x的值（6），然后x再自增变为7。

x: 初始5 -> 比较后（第一次自增）6 -> 返回时（第二次自增）7

y: 初始3 -> 比较后（自增）4
所以，输出：
```c
MAX(x++, y++) = 6, x=7, y=4
```
|知识点一| 知识点二 |
|--|--|
| 宏的文本替换  | 自增运算符 |
