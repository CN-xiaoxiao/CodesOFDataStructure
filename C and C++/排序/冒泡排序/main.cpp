#include <iostream>

/**
    ������ʵ��ð���������Ż���
*/
using namespace std;

/**
    �������ð������
*/
void bubbleSort1(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++) { /* n�����ݣ�ֻ�����n-1��*/
        for (j = 0; j < len - i -1; j++) {
            if (arr[j] > arr[j+1]) { /* ע�������� > �ţ������ >= ���ƻ�ð��������ȶ��ԣ���*/
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/**
    ����һ����־�����Ƿ����˽��������û�з������������������Ѿ����
*/
void bubbleSort2(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++) {
        int isChange = 1; // �Ƿ��������ı�־
        for (j = 0; j < len - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isChange = 0;
            }
        }
        if (isChange) break; // Ϊ1��ʾû�з���������˵���Ѿ��ź�����,���ʱ�����ֱ������ѭ��
    }
}

/**
    ��¼���һ�ν�����λ�ã���һ�α߽�������λ��
*/
void bubbleSort3(int arr[], int len)
{
    int i, j;
    int lastChangeIndex = 0;     // ���һ�η���������λ��
    int sortBorder = len - 1; // ��һ�α����ı߽�

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
