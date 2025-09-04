
#### 7. 玩玩 argc 和 argv！

>运行一下以下程序，记得输入参数哦～  
>然后看看这个程序是如何运作的吧！

```c
#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("请至少输入一个整数！\n");
        return 0;
    }

    int sum = 0;
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]); 
    }

    printf("输入的参数个数: %d\n", argc - 1);
    printf("所有参数的和: %d\n", sum);

    return 0;
}

``` 
------

| **出题人** | **林芯宇**   |
| ---------- | ------------ |
| 知识点1    | 全局变量与局部变量 |
| 知识点2    | 数组操作   |
| 知识点3    | 时间复杂度     |

------

#### 问题
Q1. 请解释 argc 和 argv 的含义及区别	20%  
Q2.	如果输入命令 ./程序名 5 6 7，argc 的值是多少？argv[0] 和 argv[1] 分别是什么？	30%  
Q3.	程序如何将 argv[i]（字符串）转换为整数？请讲出具体函数	20%   
Q4.	程序在没有输入参数时应该输出什么？请说明实现思路	20%  
Q5.	分析该程序的时间复杂度和空间复杂度	10%  
Q6.	扩展题：如果我希望程序还输出输入的最大整数，该怎么实现？   无分，扩展题

------

#### 答案
```
A1. argc：命令行参数的数量，包括程序名本身，argv：字符串数组，存储命令行参数，其中：
argv[0] = 程序名
argv[1] ... argv[argc-1] = 用户输入的参数字符串  
A2. argc = 4（程序名 + 3 个参数），argv[0] = "./程序名"，argv[1] = "5"  
A3. 使用函数 atoi(argv[i])，可以把字符串转换为 int  
A4. 当 argc == 1 时（只包含程序名），输出提示："请至少输入一个整数！" 
A5. 时间复杂度：O(n)，其中 n = argc - 1（循环次数），空间复杂度：O(1)，只用常数额外空间   
A6. 在循环中添加：
```

```c
int maxVal = atoi(argv[1]); // 初始化最大值
for (int i = 1; i < argc; i++) {
    int val = atoi(argv[i]);
    sum += val;
    if (val > maxVal) maxVal = val;
}
printf("最大整数是: %d\n", maxVal);
```