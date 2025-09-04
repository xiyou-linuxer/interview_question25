#### 9.令人头痛的宏

仔细想一下结果，并尝试解释一下原理。

```c  
#define JUDGE(a) a % 3 ? true : false
#define ADD(x) x + x
#define STR(str) #str  
#define PRINT(str , b) printf("%s %d\n" , STR(str) , b);

int main(){
    int num = 3;
    if ((JUDGE(num))){
        PRINT(answer is , num)
    }else {
        PRINT(answer is , ADD(num) * ADD(num))
    }
    return 0;    
}
```

------

| **出题人** | **王家懿**   |
| ---------- | ------------ |
| 知识点1    | 宏的替换       |
| 知识点2    | 字符串化运算符  |
| 知识点3    | 布尔类型       |

------

Q1.程序能编译通过吗，为什么 20%  

Q2.程序是如何运行的，输出是什么 60%

Q3.说明一下什么是宏 20%  


```
A1：
能，#是c语言中的一个字符串化运算符，直接将数据格式化为const char *类型，不需要输入双引号
  
A2：
将宏展开后程序为  
if ((num % 3 ? true : false)) {
    printf("%s %d\n" , "answer is" , num);
} else {
    printf("%s %d\n" , "answer is" , num + num * num + num);
}
进入else语句，进行计算得出结果 answer is 15

A3：
宏是 C 语言预处理器提供的一种机制，在编译前对源代码进行文本替换，简单粗暴的由一段文本替换成另外一段文本，而不考虑其中任何的语义内容
```
