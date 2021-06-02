#include <iostream>

/**
    本程序将实现冒泡排序及其优化。
*/
using namespace std;

/**
    最基础的冒泡排序
*/
void bubbleSort1(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++) { /* n个数据，只需遍历n-1次*/
        for (j = 0; j < len - i -1; j++) {
            if (arr[j] > arr[j+1]) { /* 注意这里是 > 号，如果是 >= 将破坏冒泡排序的稳定性！！*/
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/**
    设置一个标志，看是否发生了交换，如果没有发生交换，声明排序已经完成
*/
void bubbleSort2(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++) {
        int isChange = 1; // 是否发生交换的标志
        for (j = 0; j < len - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isChange = 0;
            }
        }
        if (isChange) break; // 为1表示没有发生交换，说明已经排好序了,这个时候可以直接跳出循环
    }
}

/**
    记录最后一次交换的位置，下一次边界就是这个位置
*/
void bubbleSort3(int arr[], int len)
{
    int i, j;
    int lastChangeIndex = 0;     // 最后一次发生交换的位置
    int sortBorder = len - 1; // 下一次遍历的边界

    for (i = 0; i < len - 1; i++) {
        int isChange = 1;
        for (j = 0; j < sortBorder; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isChange = 0;
                lastChangeIndex = j;
            }
        }
        sortBorder = lastChangeIndex;
        if (isChange) break;
    }
}

int main()
{
    int arr[] = {9,5,6,2,4,5,1};
    bubbleSort3(arr, 7);
    for (int i = 0; i < 7; i++) {
        cout<<arr[i]<<' ';
    }
    return 0;
}
