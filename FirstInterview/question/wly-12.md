## 神奇的魔法阵

1. 请分析程序输出，并解释原因。
2. 魔法阵需要升级（减小内存），你有什么办法吗？

```c
// 魔法符文（联合体）
typedef union MagicalRune
{
    short manaCost;        // 魔力消耗
    int spellDuration;     // 法术持续时间
    long long enchantment; // 附魔强度
    char incantation[21];  // 咒语文字
} MagicalRune;

// 魔法阵结构
struct MagicCircle
{
    char circleType;          // 魔法阵类型
    unsigned long protection; // 防护力量
    char elementalAffinity;   // 元素亲和力
    int magicLevel;           // 魔法等级
    MagicalRune rune;         // 魔法符文
} Circle;

void printWelcome(int num)
{
    int welcome[] = {87, 101, 108, 99, 111, 109, 101, 32, 116, 111, 32, 88, 85, 80, 84, 32, 76, 105, 110, 117, 120};
    int size = sizeof(welcome) / sizeof(welcome[0]);
    for (int i = 0; i < size; i++)
        printf("%c", welcome[i]);
    printf(" %d\n", num);
    return;
}

int main()
{
    int size = sizeof(Circle);
    printf("结构体大小: %d\n", size);
    printWelcome((size - 3) * (size - 3));
    return 0;
}

```

---

| **出题人** | **王力扬**                            |
| ---------- | ------------------------------------- |
| 知识点 1   | ASCII 码表的转换                      |
| 知识点 2   | 结构体和联合体的内存对齐 及其**优化** |

---

Q1.结构体和联合体的大小是多少？为什么？

Q2.为什么输出结果是 Welcome to XUPT Linux 2025？

Q3.如何减小结构体的大小？

---

A1：

-   联合体的大小取决于其最大成员的大小。`MagicalRune` 的成员中：
    -   `short manaCost` 占 2 字节。
    -   `int spellDuration` 占 4 字节。
    -   `long long enchantment` 占 8 字节。
    -   `char incantation[21]` 占 21 字节。
-   最大成员是 `char incantation[21]`（21 字节），但由于联合体需要满足对齐要求（特别是 `long long` 类型通常需要 8 字节对齐），编译器会将联合体的大小填充到 8 的倍数。因此，21 字节被填充到 24 字节。
    **结构体 `MagicCircle` 的大小是 48 字节**。原因如下：

-   结构体成员依次为：
    -   `char circleType` 占 1 字节。
    -   `unsigned long protection` 占 8 字节（在 64 位系统上）。
    -   `char elementalAffinity` 占 1 字节。
    -   `int magicLevel` 占 4 字节。
    -   `MagicalRune rune` 占 24 字节（如上所述）。
-   由于对齐要求：
    -   `circleType` 后需要 7 字节填充，使 `protection` 在 8 字节对齐的地址。
    -   `protection` 后是 `elementalAffinity`，占 1 字节。
    -   `elementalAffinity` 后需要 3 字节填充，使 `magicLevel` 在 4 字节对齐的地址。
    -   `magicLevel` 后是 `rune`，其对齐要求为 8 字节。此时偏移地址为 24（0-based），已是 8 的倍数，因此无需填充。
-   总计算：1（circleType） + 7（填充） + 8（protection） + 1（elementalAffinity） + 3（填充） + 4（magicLevel） + 24（rune） = 48 字节。
-   结构体整体也需要对齐（最大对齐要求为 8 字节），48 是 8 的倍数，因此大小是 48 字节。

A2：

-   在 `main` 函数中，首先计算结构体 `Circle` 的大小（`sizeof(Circle)`），结果为 48 字节。
    然后调用 `printWelcome` 函数，参数为 `(size - 3) * (size - 3)`，即 `(48 - 3) * (48 - 3) = 45 * 45 = 2025`。
    `printWelcome` 函数内部有一个整数数组 `welcome`，其元素是 ASCII 码值，对应字符：

-   `87` -> 'W', `101` -> 'e', `108` -> 'l', `99` -> 'c', `111` -> 'o', `109` -> 'm', `101` -> 'e', `32` -> ' ', `116` -> 't', `111` -> 'o', `32` -> ' ', `88` -> 'X', `85` -> 'U', `80` -> 'P', `84` -> 'T', `32` -> ' ', `76` -> 'L', `105` -> 'i', `110` -> 'n', `117` -> 'u', `120` -> 'x'。
-   因此，循环打印这些字符后形成字符串 "Welcome to XUPT Linux"。
-   最后，函数打印参数值 `2025`，所以整体输出为 "Welcome to XUPT Linux 2025"。

A3:
当前结构体大小是 48 字节，通过调整结构体元素位置，可优化到 40 字节

```c
// 魔法阵结构
struct MagicCircle
{
    char circleType;          // 魔法阵类型
    char elementalAffinity;   // 元素亲和力
    int magicLevel;           // 魔法等级
    unsigned long protection; // 防护力量
    MagicalRune rune;         // 魔法符文
} Circle;
```
