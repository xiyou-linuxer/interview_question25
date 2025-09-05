#### 2.字符串与指针
​为什么同样的 "HiLinux"，在不同声明方式下会有不同结果？观察输出，理解 C 语言中指针与数组的微妙差异

```c
int main(void) {
    char *ptr0 = "HiLinux\0"; 
    char ptr1[] = "HiLinux"; 
    char ptr2[] = "HiLinux\0Group"; 
    if (strlen(ptr0) == strlen(ptr2)) { 
        printf("%dyears, wow!\nAnd just getting started!\n", printf("2") - 1); 
    } 
    if (sizeof(ptr0) == sizeof(ptr2)) { 
        printf("%dyears, wow!\nAnd just getting started!\n", printf("2") - 1); 
    } 
    else { 
        printf("----------------------------------------------\n"); 
    } 
    if (sizeof(ptr0) == sizeof(ptr1)) { 
        printf("%dyears behind us.\nA brighter journey ahead.\n", printf("2") - 1); 
    } 
}
```

------
| **出题人** | **郑成龙**   |
| ------- | -------- |
| 知识点1    | strlen和sizeof     |
| 知识点2    | printf的返回值     |
| 知识点3    | 字符串指针和字符数组 |

------


Q1. 你知道程序的输出吗，解释为什么？30%

Q2. 你知道sizeof和strlen的区别吗？35%

Q3. 你知道这两种表示字符串的方法是什么吗，有什么区别？35%


------

A1：
程序输出
```
2years, wow!
And just getting started!
----------------------------------------------
2years behind us.
A brighter journey ahead.
```
条件一：strlen遇到\0停止，条件成立，打印语句
条件二：sizeof ptr0 和 ptr2 一个是指针大小，一个是数组大小，条件不成立，打印横线
条件三：同条件二一样，但在这里不论是指针还是数组，都固定为8，条件成立，打印语句

A2：
strlen：程序运行时的函数，计算字符串有效长度，直到遇到 \0。不包含 \0 本身
sizeof：编译时运行的运算符，得到类型所占字节数，对指针是固定大小，对数组是整体大小

A3：
char *ptr0 = "HiLinux\0";
指针指向常量区字符串字面量，内容不可修改
char ptr1[] = "HiLinux";
在栈上分配数组，拷贝字符串副本，内容可修改

