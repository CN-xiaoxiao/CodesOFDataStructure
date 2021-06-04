#include <iostream>
#include <string.h>

using namespace std;
/**
    �ַ���ƥ�������ʵ�֣��ֳƱ�������
*/

/**
    @param pos ��posλ�ú�ʼƥ��
    @param str1 ����
    @param str2 ģʽ��
    @return ƥ��ɹ��ͷ��أ�ģʽ��str2��һ�γ���������str1��λ�÷��򷵻�-1
*/
int BF(char str1[], char str2[], int pos)
{
    int i = pos;
    int j = 0;
    int len1 = strlen(str1); // ��ȡ�ַ����ĳ���
    int len2 = strlen(str2);

    while(i < len1 && j < len2) {
        if (str1[i] == str2[j]) { /* �����ǰģʽ�����������ַ���ͬ�������ƣ���һ�ν��бȽ�*/
            i++;
            j++;
        }
        else {
            i = i - j + 1; // i - j �ص��ʼi��λ�ã� +1��������һ���ַ�
            j = 0;  // b�� j ��Ϊ0�� ��ΪҪ���±���ģʽ��
        }
    }

    return (j >= len2) ? i - j : -1;
}

int main()
{
    char str1[] = "ABCDABD";
    char str2[] = "ABD";

    cout << BF(str1, str2, 0);
    return 0;
}
