**7.会一直循环吗？**

程序的输出是什么？argc和argv分别是什么意思？程序会一直循环吗？

```
int main(int argc, char *argv[])
{
    printf("argc = %d\n",argc);
    while(argc++)
    {
       if(argc < 0)
       {
         printf("argv[0] %s\n",argv[0]);
         break;
       }
    }
    printf("argc = %d\n",argc);
    return 0;
}
```

| 出题人  | 刘雨熙     |
| ------- | ---------- |
| 知识点1 | argc和argv |
| 知识点2 | 算术溢出   |

Q1：解释程序输出的argc和argv70%

Q2：解释程序为什么不会一直循环30%

```
A1:
argc作用为读入当前程序变量参数个数，当前程序运行时只有一个参数，所以argc打印1。argv为一个NULL结尾的字符串指针数组，数组首元素为程序名称，argv[1] ~ argv[argc-1] 为命令行参数，argv[argc]为结束标志NULL
A2:
argc初始值为1,当argc为正值时，while循环一直进行，直到argc增大到int类型最大值后溢出，此时argc小于0,打印argv[0]，跳出循环。
```

