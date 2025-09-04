
#### 4. 来抓卧底吧！

>在一场游戏中，房间里有一组玩家，每个玩家都有一个整数 ID;  
>所有玩家 ID 中，只有 两个玩家的 ID 出现了奇数次，其他 ID 都出现偶数次;  
>我们是怎么抓到这两个卧底的呢？

```c
#include <stdio.h>

void findUndercoverIDs(int players[], int n, int *a, int *b) {
    int xorAll = 0;
    // n 是数组大小
    for (int i = 0; i < n; i++) {
        xorAll ^= players[i];
    }

    int diffBit = xorAll & -xorAll;

    // a, b 是卧底ID
    *a = 0;
    *b = 0;
    for (int i = 0; i < n; i++) {
        if (players[i] & diffBit)
            *a ^= players[i];
        else
            *b ^= players[i];
    }
}
``` 
------

| **出题人** | **林芯宇**   |
| ---------- | ------------ |
| 知识点1    | 位运算 |
| 知识点2    | 分组异或   |
| 知识点3    | 时间与空间复杂度分析     |
| 知识点4    | 补码与位掩码   |

------

#### 问题
Q1. 简述函数 findUndercoverIDs 的功能，输入输出是什么？	10%   
Q2.	解释为什么 xorAll ^= players[i] 可以抵消偶数次出现的元素，保留奇数次元素	30%  
Q3.	解释 diffBit = xorAll & -xorAll 的作用，以及为什么可以提取最低不同位 20%  
Q4.	说明为什么根据 diffBit 将数组分成两组，再分别异或可以得到两个奇数次元素	30%  
Q5.	分析函数的时间复杂度和空间复杂度  10%

------

#### 答案
```
A1. 在数组中找出两个出现奇数次的 ID  
A2. x ^ x = 0，x ^ 0 = x, 遍历数组并异或，偶数次出现的 ID 会被抵消为 0，剩下的就是奇数次的元素  
A3. diffBit = xorAll & -xorAll 提取 最低位的 1，保证 x 和 y 在这一位不同, 利用补码性质：-n = ~n + 1 获取  
A4. 根据 diffBit 将数组分成两组：该位为 1 的一组, 该位为 0 的另一组, 每组再异或，偶数次元素抵消，剩下的就是每组的奇数次元素  
A5. 时间复杂度：O(n)，数组遍历两次; 空间复杂度：O(1)，只用常数个整型变量
```