#### 10.排序！

请你使用两种方法对这个数组进行升序排序来补全这个函数

```c

    void your_sort(int* arr,int len);

    int main() {
        int arr[] = {3,0,4,5,1,2,6,9,8,7};
        int len = sizeof(arr) / sizeof(arr[0]);

        your_sort(arr,len);
        for(int i = 0;i < len; i++) {
            printf("%d ",arr[i]);
        }

        return 0;
    }

```

------


| **出题人** | **孟昶羽**   |
| ---------- | ------------ |
| 知识点1    | 排序算法 |



------


Q1. 请你说说使用的排序算法和思路并说出它们的时间复杂度 80%

Q2. 你还了解其他的排序算法吗，详细说一说 20%


------


A1：
冒泡排序：
时间复杂度：O(n^2)
```c
    void your_sort(int* arr,int len) {
        for(int i = 0; i < len - 1; i++) {
            for(int j = 0; j < len - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }
    }
```

选择排序：
时间复杂度：O(n^2)
```c
    void your_sort(int* arr,int len) {
        for(int i = 0; i < len - 1; i++) {
            int min_idx = i;
            for(int j = i + 1; j < len; j++) {
                if(arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(arr[i], arr[min_idx]);
        }
    }
```

快速排序：
时间复杂度：O(nlog n)
```c
    void quick_sort(int* arr, int left, int right) {
        if(left >= right) return;
        int i = left, j = right;
        int pivot = arr[left];
        while(i < j) {
            while(i < j && arr[j] >= pivot) j--;
            arr[i] = arr[j];
            while(i < j && arr[i] <= pivot) i++;
            arr[j] = arr[i];
        }
        arr[i] = pivot;
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }

    void your_sort(int* arr,int len) {
        quick_sort(arr, 0, len - 1);
    }
```

A2：
1. 选择排序（Selection Sort）：每次从未排序部分选择最小元素放到前面，时间复杂度 O(n²)，不稳定。
2. 插入排序（Insertion Sort）：把元素插入到已排序部分的合适位置，稳定排序，适合小规模数组。
3. 归并排序（Merge Sort）：分治法，将数组分成两部分分别排序，再合并，时间复杂度 O(n log n)，稳定排序。
4. 堆排序（Heap Sort）：利用堆结构，每次取最大（或最小）元素放到末尾，时间复杂度 O(n log n)，不稳定。
5. 桶排序、计数排序、基数排序等：适合特定类型的数据，部分排序可以达到线性时间复杂度 O(n)。