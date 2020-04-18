
#include <stdio.h>
#include <stdarg.h>

#include <iostream>
#include <string>
using namespace std;

int my_snprintf(char *s, int size, const char *fmt, ...) //该自定义函数，与系统提供的snprintf()函数相同。
{
    va_list ap;
    int n=0;
    va_start(ap, fmt); //获得可变参数列表
    n=vsnprintf (s, size, fmt, ap); //写入字符串s
    va_end(ap); //释放资源
    return n; //返回写入的字符个数
}

int demo1() {
    char str[10];
    int n = my_snprintf( str, sizeof(str), "%d,%d,%d,%d",5,6,7,8);
    printf("%d\n",n); // 7
    printf("%s\n",str); // 5,6,7,8
    return 0;
}

void SnprintfDemo()
{
    char fmt[1024];
    int len = snprintf(fmt, sizeof(fmt), "[%s-%s]:%s-%d", "PushDDemo", "we4f2w4e", "0A15116A00002A9F000013872A0725B8", 453434321);
    string a(fmt, len);
    cout << a << endl;

    string b(fmt);
    cout << b << endl;
    cout << string(fmt) << endl;

}


int main()
{
    SnprintfDemo();
}

