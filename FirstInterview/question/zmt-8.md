#### 8.数组、指针、函数

阅读下面代码并回答问题。

```c
int square(int x) { return x * x; }
int cube(int x) { return x * x * x; }

int main() {
    int v[4] = {1, 2, 3, 4};
    int *p = v;
    int (*pa)[4] = &v;
    int *ap[2] = {v, v+2};
    int (*pf[2])(int) = {square, cube};
    return 0;
}
```
这些输出分别是什么？
```c
p[2] , *(p+3) , *(v+1) , *(pa[0]+2)
ap[0][1] , ap[1][-1]
sizeof(v) , sizeof(p) , sizeof(pa) , sizeof(ap)
(*pf[0])(3) , (*pf[1])(2)

```

------

| **出题人** | **张铭涛**   |
| ---------- | ------------ |
| 知识点1    | 数组指针与指针数组 |
| 知识点2    |   指针偏移与寻址 |
| 知识点3    |    sizeof 在数组和指针上的差别  |
| 知识点4    |   函数指针数组调用 |
------

Q1. p[2], *(p+3), *(v+1), *(pa[0]+2) 的值是多少？ 25%

Q2. ap[0][1] 和 ap[1][-1] 的值是多少？ 25%

Q3. sizeof(v), sizeof(p), sizeof(pa), sizeof(ap) 各是多少？ 25%

Q4. 调用 (*pf[0])(3) 和 (*pf[1])(2) 各输出多少？25%

```
A1：
p[2] = v[2] = 3
*(p+3) = v[3] = 4
*(v+1) = v[1] = 2
*(pa[0]+2) = *(*(pa)+2) = v[2] = 3
A2：
ap[0] = v，所以 ap[0][1] = *(v+1) = 2
ap[1] = v+2，所以 ap[1][-1] = *(v+2-1) = v[1] = 2
arr[i]本质是*(arr+i)，所以负下标合法，只要地址没越界。
A3：
int为4字节，指针为8字节
sizeof(v) = 4 * sizeof(int) = 16
sizeof(p) = sizeof(int*) = 8
sizeof(pa) = sizeof(int (*)[4]) = 8
sizeof(ap) = 2 * sizeof(int*) = 16
数组名在大多数表达式中 会退化为指针，但 sizeof 和 & 是例外。
A4：
(*pf[0])(3)，调用square(3)，输出 9
(*pf[1])(2)，调用cube(2)，输出 8
```