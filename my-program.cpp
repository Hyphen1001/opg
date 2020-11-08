#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

char stack[5];
stringstream ss;
string str;
//优先算符矩阵
int cmp_matrix[6][6] = {
    1, -1, -1, -1, 1, 1,
    1, 1, -1, -1, 1, 1,
    1, 1, 2, 2, 1, 1,
    -1, -1, -1, -1, 0, 1,
    1, 1, 2, 2, 1, 1,
    -1, -1, -1, -1, -1, 0};

int to_index(char a)
{
    int ret=-1;
    switch (a)
    {
    case '+':
        ret = 0;
        break;
    case '*':
        ret = 1;
        break;
    case 'i':
        ret = 2;
        break;
    case '(':
        ret = 3;
        break;
    case ')':
        ret = 4;
        break;
    case '#':
        ret = 5;
        break;
    }
    return ret;
}
//-1小于，0等于，1大于，2非法
int cmp(char a, char b)
{
    return cmp_matrix[to_index(a)][to_index(b)];
}
int reduce(int top)
{
    int ret = -1;
    if (stack[top] == 'N')
    {
        if (stack[top - 1] == '+' && stack[top - 2] == 'N')
        {
            top -= 2;
            ret = top;
        }
        else if (stack[top - 1] == '*' && stack[top - 2] == 'N')
        {
            top -= 2;
            ret = top;
        }
    }
    else if (stack[top] == 'i')
    {
        stack[top] = 'N';
        ret = top;
    }
    else if (stack[top] == ')')
    {
        if (stack[top - 1] == 'N' && stack[top - 2] == '(')
        {
            stack[top - 2] = 'N';
            top -= 2;
            ret = top;
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    fstream fs(argv[1]);
    ss << fs.rdbuf();
    str = ss.str();
    int len = str.length();
    str[len - 2] = '#';
    int i = 0, top = 0;
    stack[top] = '#';
    while (1)
    {
        char top_tmp = stack[top];
        if (stack[top] == 'N')
        {
            top_tmp = stack[top - 1];
        }
        int cmp_ans = cmp(top_tmp, str[i]);
        if (cmp_ans == 2)
        {
            printf("E\n");
            break;
        }
        else if (cmp_ans == -1)
        {
            printf("I%c\n", str[i]);
            top++;
            stack[top] = str[i];
            i++;
        }
        else if (cmp_ans == 0)
        {
            if (str[i] == '#')
            {
                break;
            }
            else
            {
                printf("I%c\n", str[i]);
                top++;
                stack[top] = str[i];
                i++;
            }
        }
        else if (cmp_ans == 1)
        {
            top = reduce(top);
            if (top == -1)
            {
                printf("RE\n");
                break;
            }
            else
            {
                printf("R\n");
            }
        }
    }
    return 0;
}
