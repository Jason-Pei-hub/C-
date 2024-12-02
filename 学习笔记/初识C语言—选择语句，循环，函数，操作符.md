# 初识C语言—选择语句，循环，函数，操作符



---

## 选择语句

好好学习拿好offer，不好好学习卖红薯

```c
int main()
{
    int input = 0;
    printf("好好学习");
    printf("那要好好写代码吗？");
    scanf("%d",&input);
    if(input == 1)
        printf("好offer\n");
    else
        printf("卖红薯\n")
}
```



---

## 循环语句

有一些事情必须一直做，比如学习学习，跑步跑步

所以重复发生的事情需要引入循环

```c
#include<stdio.h>
int main()
{
    int line = 0;
    //循环
    while (line < 30000)
    {
        printf("写代码:%d\n", line);
        line++;
    }
    if (line == 30000)
    {
        printf("好offer");
    }
    return 0;
}
```

**好好写代码吧！！！**

---

## 函数：

数学中见过函数

C语言中的函数也是一样的

可以通过函数实现特定的功能

```c
#include<stdio.h>
int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2;
    printf("%d\n", sum);
    return 0;
} 
```

简单的加法，那么用函数怎么实现呢

```c
#include<stdio.h>

Add(int x,int y)
{
    int z = 0;
    z = x + y;
    return z;

}

int main()
{
    int num1 = 0;
    int num2 = 0;
    scanf("%d %d", &num1, &num2);
    int sum = Add(num1,num2);
    printf("%d\n", sum);
    return 0;
} 
```

**很简单，通过例子就可以看出函数的作用**

```c
张三（蛋炒饭，20）
    return 蛋炒饭；
    
我：张三 带饭 
    张三（蛋炒饭，20）
```

---

## 数组

存1-10怎么存呢

```c
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    ......
    //太麻烦了
    return 0;
} 
```

```c
//一组相同类型的元素的集合
//10个整形1-10存起来
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    //这里也演示一下存字符串
    char ch[5] = {'a','b','c'};//不完全初始化，剩余默认为零
    return 0;
} 
```

数组是用下标来访问，下标是从零开始

```c
arr[0]//即为第一个元素
```

打印全部元素

```c
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    while(i < 10)
    {
        printf("%d",arr[i]);
        i++;
    }
    return 0;
} 
```

运行结果

```c
12345678910
```

---

## 操作符

#### 算数操作符

````c
+ - * / %
````

注意这里有**魔鬼细节**

```c
int a = 9 / 2;
//那么a是多少
//很简单，整型变量没有小数，所以结果是
//4
```

那么问题来了

```c
float a = 9 / 2;
//a是多少
//答案是4.000000
//是因为除号两端都是整数，执行的是整数除法
```

```c
float a = 9 / 2.0;
//此时答案为4.5
```

取模即为求余，这里不在演示，符号为%

#### 移位操作

```c
<<  >> 
```

```c
int main()
{
    int a = 2;
    int b = a << 1;
    printf("%d",b);
    return 0;
} 
```

左移操作符，向左移动两位

a是2

二进制为                             	  00000000000000000000000000000010

向左移动1位结果为             	00000000000000000000000000000100

所以结果为

```c
4
```

#### **位操作符**

| &    | 按位与   |
| ---- | -------- |
| \|   | 按位或   |
| ^    | 按位异或 |

#### 赋值操作符

```c
=  +=  -+  *=  &=  ^=  |=  <<=  >>=
```

```c
a = a + 3;
a += 3;
//结果一样
```

#### 单目操作符

| ！       | 逻辑反操作                     |
| -------- | ------------------------------ |
| -        | 负值                           |
| +        | 正值                           |
| &        | 取地址                         |
| sizeof   | 操作数的类型长度（字节）       |
| ~        | 对前一个数二进制取反           |
| --       | 前置，后置--                   |
| ++       | 前置，后置++                   |
| *        | 间接访问操作符（解引用操作符） |
| （类型） | 强制类型转换                   |

单目操作符：只有一个操作数

```c
#include<stdio.h>

int main()
{
    //0表示假，非0即为真
    int a = 0;
    printf("%d",!a);//1
    return 0;
}
```

结果为

```c
1
```

**如何使用呢？**

```c
#include<stdio.h>

int main()
{
    //0表示假，非0即为真
    int a = 0;
    printf("%d",!a);//1
    
    if(a)
    {
        //如果a为真，做事
    }
    
    if(!a)
    {
        //如果a为假，做事
    }
    
     return 0;
}
```

```c
#include<stdio.h>

int main()
{
    //sizeof是一个操作符
    //计算类型或者变量大小
    //不是函数
    int a = 10;
    printf("%d",sizeof(int));
    printf("%d",sizeof(a));
 
     return 0;
}
```

结果为

```c
4
4
```

**也可以计算数组大小**

```c
#include<stdio.h>

int main()
{
    int arr[10] = { 0 };
    printf("%d",sizeof(arr));
 
    return 0;
}
```

结果为

```c
40
```

计算的是数组总大小，单位为字节

```c
#include<stdio.h>

int main()
{
    int arr[10] = { 0 };
    printf("%d",sizeof(arr));
    printf("%d",sizeof(arr[0]));
    int sz = size(arr) / sizeof(arr[0]);
    printf("%d",sz);
 
    return 0;
}
```

输出结果为

```c
40
4
10//即为数组个数
```

