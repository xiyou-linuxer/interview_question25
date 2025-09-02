#### 9.三选一，你选谁?
​​回调函数​​是一种强大而灵活的编程思想和技术。观察并试试设计一个 `register_handler` 函数，可以动态往 `handlers` 里注册不同的回调函数。

```c
typedef void (*Callback)(int);
void onSuccess(int data) { printf(" [成功啦!] 结果是 %d\n", data); }
void onError(int code)   { printf(" [哎呀!] 错误代码 %d\n", code); }
void onWarning(int w)    { printf(" [注意!] 警告值 %d\n", w); }

void process(int value, Callback callbacks[3]) {
    if(value < 0)               callbacks[1](-value);
    else if(value > 100)        callbacks[2](value);
    else                        callbacks[0](value * 2);
}
int main() {
    Callback handlers[3] = {on_success, on_error, on_warning};
    int test[] = {50, -10, 150, 0};
    for(int i = 0; i < 4; i++) {
        printf("\n=== 处理数据ing %d ===\n", test[i]);
        process(test[i], handlers);
    }
}
```

------
| **出题人** | **朱斌**   |
| ------- | -------- |
| 知识点1    | 函数指针     |
| 知识点2    | 回调函数     |
| 知识点3    | 动态注册处理函数 |

------


Q1. 程序输出是什么？40%

Q2. 如何增加一个新的回调 onInfo 并处理条件 value == 0？25%

Q3. 设计一个 register_handler 函数，可以动态注册不同回调函数，如何实现？25%

Q4. 理解函数回调的思想是什么了吗，是什么呢? 10%

------

A1：
处理50 → [成功啦!] 结果是 100  
处理-10 → [哎呀!] 错误代码 10  
处理150 → [注意!] 警告值 150  
处理0 → [成功啦!] 结果是 0  

A2：
新增函数：
```c
void onInfo(int val) { printf(" [信息] 值是 %d\n", val); }
```
在 process 中增加判断：
```c
else if(value == 0) callbacks[3](value);
```

A3：
设计 register_handler：
```c
Callback handlers[4]; // 扩大数组
void register_handler(int idx, Callback cb) { handlers[idx] = cb; }
```

使用方式：
register_handler(0, onSuccess);
register_handler(1, onError);
register_handler(2, onWarning);
register_handler(3, onInfo);
然后 process 内通过 handlersidx调用。

A4：
函数回调的核心思想是“把函数作为参数传入另一个函数，让它在特定条件下被调用”。  
它实现了 控制反转：调用方不需要知道具体逻辑，只需提供回调函数，由被调用方在合适的时机触发，从而实现灵活、可扩展的处理机制。
