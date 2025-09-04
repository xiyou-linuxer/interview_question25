#### 12. 别急，有反转

程序会输出什么？逐步分析一下。

~~~c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct item {
    long long a;
    union data {
        int *a[251];
        long double y;
        char z;
    } b;
    void (*func)(struct item *i);
    char c;
    char slogan[0];
} Item;

void rev(Item *i) {
    char* p = i->slogan;
    if (!i->c) {
        int len = strlen(p);
        for (int i = 0; i < len / 2; ++i) {
            char tmp = p[i];
            p[i] = p[len-1-i];
            p[len-1-i] = tmp;
        }
    } else {
        for (; *p; p++) {
            if (isupper(*p)) *p = tolower(*p);
            else if (islower(*p)) *p = toupper(*p);
        }
    }
}

int main() {
    const char* str = "Free, Open, Share";
    Item *it1 = (Item*)malloc(sizeof(Item) + strlen(str) + 1);
    it1->c = sizeof(Item) - 2025;
    it1->func = rev;
    Item *it2 = (Item*)malloc(sizeof(Item) + strlen(str) + 1);
    it2->c = !it1->c;
    it2->func = rev;
    strcpy(it1->slogan, str);
    strcpy(it2->slogan, str);
    it1->func(it2);
    it2->func(it1);
    printf("%s\n", it1->slogan);
    printf("%s\n", it2->slogan);
    return 0;
}
~~~



------

| 出题人  | 张若水                    |
| ------- | -------------------------- |
| 知识点1 | 联合体的大小               |
| 知识点2 | 结构体的大小和内存对齐规则 |
| 知识点3 | 简单数据类型的占用内存大小 |
| 知识点4 | 零长数组的使用技巧         |



------
Q1. 指出程序中出现的所有内置类型的占用内存大小。

Q2. 为什么要写成`malloc(sizeof(Item) + strlen(str) + 1)`而不是`malloc(sizeof(Item))`？`char slogan[0]`的作用是什么？

Q3. `struct Item`内部如何进行对齐？`sizeof(Item)`和`sizeof(it1)`分别是多少？

Q4. 程序的输出是什么？

~~~
A1:
在64位系统下，char->1,int->4,long long->8,
int*->8,void*->8,long double->16（单位：字节）。

A2:
slogan[0]作为最后一个成员，在结构体中不占用空间。
使用时，根据需求动态分配空间。这里strlen是字符串长度，
+1是为了存储'\0'。

A3:
内存对齐向最大的看齐。这里long double占用16字节，单个元素占用内存最大，
所以struct Item整体按照16字节进行对齐。
long long a: 0-7字节(8)
int *a[251]: 8-2015字节(2008)
（联合体内按照最大的变量计算占用内存）
void (*func): 2016-2023字节(8)
char c: 2024位置字节(1)
slogan[0]不占用空间
目前有8+2008+8+1=2025字节。
向上对齐至最近的16的倍数，即sizeof(Item)=2048字节。
sizeof(it1)=2048+18=2066字节

A4:
sizeof(it1)==2048（不是2025，易错），it1->c > 0,
it2->c = 0;
于是it1中翻转大小写（else分支）
it2中反转字符串(if分支)
输出：
fREE, oPEN, sHARE
erahS ,nepO ,eerF
~~~
