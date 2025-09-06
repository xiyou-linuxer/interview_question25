#### 6.const与指针：谁能动，谁不能动？

怎么编译无法通过呢，尝试解释原因并修改。

```c
struct P {
    int x;
    const int y;
};

int main() {
    struct P p1 = {10, 20};
    struct P p2 = {30, 40};
    const struct P p3 = {50, 60};

    struct P *const ptr1 = &p1;
    const struct P *ptr2 = &p2;
    const struct P *const ptr3 = &p3;

    ptr1->x = 100;
    ptr1->y = 200;
    ptr1 = &p2;

    ptr2->x = 300;
    ptr2->y = 400;
    ptr2 = &p1;

    ptr3->x = 500;
    ptr3->y = 600;
    ptr3 = &p1;

    return 0;
}

```

------

| **出题人** | **张铭涛**   |
| ---------- | ------------ |
| 知识点1    |  常量指针|
| 知识点2    |  指向常量的指针  |
| 知识点3    |    指向常量的常量指针  |


------

Q1. 为什么p1.y不能被修改，而p1.x却能？请解释结构体成员const的作用。 30%

Q2. 在ptr1、ptr2、ptr3里，指出指针本身和指针指向的内容哪些可以修改，哪些不能修改。 40%

Q3. 为什么const struct P p3里的x和y都不能通过ptr3修改？请解释整体对象const与成员const的区别。 30%

```
A1：
p1.y是const int成员，在结构体初始化后不可修改；
p1.x是普通成员，可以修改。
A2：
struct P *const ptr1：指针本身不可改，指向的内容可改。
const struct P *ptr2：指针本身可改，指向的内容不可改。
const struct P *const ptr3：指针本身不可改，指向的内容也不可改。
A3：
const struct P p3表示整个结构体对象是常量，任何成员都不可修改。
const int y 表示结构体的某个成员是常量，只针对y。
```