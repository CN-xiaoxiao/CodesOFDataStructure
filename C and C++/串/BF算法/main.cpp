#include <iostream>
#include <string.h>

using namespace std;

/**
    @param pos 从pos位置后开始匹配
    @param str1 主串
    @param str2 模式串
    @return 匹配成功就返回，模式串str2第一次出现在主串str1的位置否则返回-1
*/
int BF(char str1[], char str2[], int pos)
{
    int i = pos;
    int j = 0;
    int len1 = strlen(str1); // 获取字符串的长度
    int len2 = strlen(str2);

    while(i < len1 && j < len2) {
        if (str1[i] == str2[j]) { /* 如果当前模式串与主串的字符相同就往后移，再一次进行比较*/
            i++;
            j++;
        }
        else {
            i = i - j + 1; // i - j 回到最开始i的位置， +1后，来到下一个字符
            j = 0;  // b把 j 置为0， 因为要重新遍历模式串
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
