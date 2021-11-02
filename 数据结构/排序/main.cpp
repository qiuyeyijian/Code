#include <stdlib.h>

#include <algorithm>
#include <iostream>

using namespace std;

void show(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 冒泡排序
void bubbleSort(int* arr, int len) {
  // 从后向前冒泡，从小到大排序
  for (int i = 0; i < len; ++i) {
    for (int j = len - 1; j > i; --j) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
      }
    }
  }

  // 从前向后冒泡，从小到大排序
  /* for (int i = len - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j + 1] < arr[j]) {
        swap(arr[j + 1], arr[j]);
      }
    }
  } */
}

// 冒泡排序优化
void bubbleSortPro(int* arr, int len) {
  // 从后向前冒泡
  for (int i = 0; i < len - 1; ++i) {
    bool flag = 0;
    for (int j = len - 1; j > i; j--) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        flag = true;
      }
    }

    if (!flag) {  // 如果本趟没有发生交换说明线性表有序
      break;
    }
  }
}

// 选择排序
void selectSort(int arr[], int len) {
  // for (int i = 0; i < len - 1; ++i) {
  //   for (int j = i + 1; j < len; ++j) {
  //     if (arr[i] > arr[j]) {
  //       int temp = arr[j];
  //       arr[j] = arr[i];
  //       arr[i] = temp;
  //     }
  //   }
  // }

  // 下面的实现可以比上面减少交换次数
  int min;
  for (int i = 0; i < len - 1; ++i) {
    min = i;  // 默认当前元素为最小
    for (int j = i + 1; j < len - 1; ++j) {
      // 只要遇到比arr[min]小的元素，就更新min的值
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    // 如果min值发生和改变，就交换两元素的值
    // 这个思想在堆排序也有应用
    if (min != i) {
      swap(arr[i], arr[min]);
    }
  }
}

// 插入排序
void insertSort(int* arr, int len) {
  int temp, j;
  for (int i = 1; i < len; ++i) {
    temp = arr[i];
    // 每次判断j前面的一个元素arr[j-1]是否大于temp
    // 如果大于，就将arr[j-1]向后移动，更新j的位置
    // 如果不大于，则按照递增排序，说明j就是要插入的位置
    for (j = i; j > 0 && arr[j - 1] > temp; --j) {
      arr[j] = arr[j - 1];
    }

    // 插入数据
    arr[j] = temp;
  }
}

// 折半插入排序
// 数组前面的有序部分进行二分（折半）查找定位，减少比较次数
void binaryInsertSort(int* arr, int len) {
  int i, j, left, right, mid, temp;
  for (int i = 1; i < len; ++i) {
    temp = arr[i];
    left = 0;
    right = i - 1;

    // arr[i]之前的有序序列进行二分查找定位
    // 最后left指向待插入位置
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid] > temp) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    // 将arr[left...i-1]元素统一向后移动
    for (int j = i; j > left; --j) {
      arr[j] = arr[j - 1];
    }

    // 插入元素
    arr[left] = temp;
  }
}

// 希尔排序
void shellSort(int* arr, int len) {
  int temp, j;
  // 第一次间隔为长度的一半，以后每次减半，最后一次为1
  for (int gap = len / 2; gap > 0; gap /= 2) {
    // 为了减少代码复杂度，不是每次处理一组，而是多组交替处理
    for (int i = gap; i < len; i++) {
      temp = arr[i];
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

// 将[left, right]按照arr[left]分成两部分
// 左边都比arr[left]小，右边都比arr[left]大
// 返回中心下标
int partition(int arr[], int left, int right) {
  int pivot = arr[left];  // 将arr[left] 作为主元
  while (left < right) {  // 只要left和right不相遇
    // 反复左移right直到找到一个元素比pivot小
    while (left < right && arr[right] >= pivot) right--;
    // 将找到的元素移到左边
    arr[left] = arr[right];
    // 再反复右移left直到找到一个元素比pivot大
    while (left < right && arr[left] <= pivot) left++;
    // 将该元素移动到右边
    arr[right] = arr[left];
  }

  // left 和 right相遇，则将pivot元素放到该位置下，一轮快排结束
  arr[left] = pivot;
  return left;  // left和right相遇的地方就是中心下标
}

// 快读排序， left和right初始值为序列的首尾下标
void quickSort(int arr[], int left, int right) {
  // 递归边界，left>=right说明此时区间不能再分了
  if (left >= right) {
    return;
  }

  // 将[left, right]按照arr[left]分成两部分
  // 左边都比arr[left]小，右边都比arr[left]大
  // 然后对这两部分递归再次划分，每划分一次都能确定一个元素的最终位置
  int pos = partition(arr, left, right);
  // 对左边区间进行递归快速排序
  quickSort(arr, left, pos - 1);
  // 对右边区间进行递归快速排序
  quickSort(arr, pos + 1, right);
}

// 归并排序，需要使用辅助数组
const int maxn = 100;

// 将数组arr的[l1, r1]与[l2, r2]相邻的两个有序区间合并为一个有序区间（此处l2,
// 即为 r1 + 1） 利用双指针法将两个区间合并， 注意while的边界
void merge(int* arr, int l1, int r1, int l2, int r2) {
  int i = l1, j = l2;  // i 指向arr[l1], j指向ar[l2]

  // 定义一个辅助数组
  int temp[maxn], index = 0;
  while (i <= r1 && j <= r2) {
    if (arr[i] <= arr[j]) {
      temp[index++] = arr[i++];
    } else {
      temp[index++] = arr[j++];
    }
  }

  // 如果两个数组如果有剩余元素，直接复制到temp数组后面
  // 两个while只可能会执行一个
  while (i <= r1) temp[index++] = arr[i++];
  while (j <= r2) temp[index++] = arr[j++];

  // 将合并后的序列赋值回数组arr
  for (int i = 0; i < index; i++) {
    arr[l1 + i] = temp[i];
  }
}

// 将arr数组当前区间[left, right]进行归并排序
void mergeSort(int arr[], int left, int right) {
  // 递归边界，left>=right说明此时区间不能再分了
  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2;  // 取[left, right]的中点
  // 递归划分左半区
  mergeSort(arr, left, mid);
  // 递归划分右半区
  mergeSort(arr, mid + 1, right);
  // 合并已经有序的两个区间
  merge(arr, left, mid, mid + 1, right);
}

// 维护堆
/**
 * @param arr 存储堆的数组
 * @param len 数组长度
 * @param pos 待维护结点位置下标
 * swap()是c++的iostream头文件里的函数
 */
void heapify(int* arr, int len, int pos) {
  int largest = pos;
  int lson = pos * 2 + 1;
  int rson = pos * 2 + 2;

  // 找到左右孩子中比父结点大的结点下标，并存储在largest中
  if (lson < len && arr[largest] < arr[lson]) {
    largest = lson;
  }
  if (rson < len && arr[largest] < arr[rson]) {
    largest = rson;
  }

  // 如果largest的值没有发生了变化，说明不需要维护堆
  // 否则交换父结点与arr[largest]的值，并递归继续维护堆
  if (largest != pos) {
    // 交换两个元素
    swap(arr[largest], arr[pos]);
    // 继续向下维护堆
    heapify(arr, len, largest);
  }
}

// 堆排序
void heapSort(int* arr, int len) {
  int i;
  // 建堆，时间复杂度O(n)
  // 找到堆最后一个元素的父结点，向前逐个调整堆
  // len/2-1 是由最后一个元素父结点公式 ((len-1)-1)/2 得到的
  for (i = len / 2 - 1; i >= 0; --i) {
    heapify(arr, len, i);
  }

  // 排序
  // 每一趟均会确定一个元素的最终位置，堆的大小减1
  for (i = len - 1; i > 0; --i) {
    // 将根结点和堆最后一个元素交换位置
    swap(arr[i], arr[0]);
    // 维护根结点，注意此时数组长度为i
    // 也就是每确定一个元素最终位置，数组长度减1
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {5, 9, 9, 1, 3, 4, 8, 2};
  int len = sizeof(arr) / sizeof(arr[0]);

  // bubbleSort(arr, len);
  bubbleSortPro(arr, len);
  // selectSort(arr, len);
  // binaryInsertSort(arr, len);
  // shellSort(arr, len);
  // insertSort(arr, len);
  // quickSort(arr, 0, len - 1);
  // mergeSort(arr, 0, len - 1);
  // heapSort(arr, len);
  show(arr, len);

  return 0;
}