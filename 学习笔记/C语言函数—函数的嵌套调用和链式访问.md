# C语言函数—函数的嵌套调用、链式访问、声明和定义

---

首先声明，函数绝对不能被嵌套定义

```c
int test1
{
    int test2()
    {
        
    } 
    
}

int main
{
    return 0;
}
//错误！！！！
```

**但是函数可以嵌套调用**

```c
void test3()
{
	printf("hehe\n");
}

int test2()
{
	test3();
	return 0;
}

int main()
{
	test2();
	return 0;
}
```

## 链式访问

> 把一个函数的返回值作为另外一个函数的参数。

```c
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[20] = "hello";
 int ret = strlen(strcat(arr,"bit"));//这里介绍一下strlen函数
 printf("%d\n", ret);
 return 0;
}

#include <stdio.h>
int main()
{
    printf("%d", printf("%d", printf("%d", 43)));
    //结果是啥？
    //注：printf函数的返回值是打印在屏幕上字符的个数
    return 0;
}
```



## 函数的声明和定义

### 函数声明

> 1. 告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。但是具体是不是存在，函数 声明决定不了。
> 2. 函数的声明一般出现在函数的使用之前。要满足**先声明后使用**。
> 3.  函数的声明一般要放在头文件中的。

```c
int main()
{
	int a = 10;
	int b = 20;

	//函数声明一下 - 告知
	int Add(int x, int y);

	int c = Add(a, b);

	printf("%d\n", c);
	return 0;
}

//函数的定义
int Add(int x, int y)
{
	return x + y;
}
```



> 因为代码是从上往下运行的，所以把函数放在主函数的前面就不用声明了
>
> 定义是一种更强有力的声明



### 函数的声明一般要放在头文件中的。

什么意思呢

我们以后写程序一般都是分模块写的，各司其职

我现在是A程序员，写我这一部分代码，我会写两个文件

```c
project.c
//在这个文件中写我们的函数主体
project.h
//在这个函数中写我们的函数声明

这样子在别人引用我们的头文件时可以直接调用我们的函数
```



###  函数定义

> 函数的定义是指函数的具体实现，交待函数的功能实现。

**project.h的内容**

放置函数的声明

```c
#ifndef __PROJECT_H__
#define __PROJECT_H__
//函数的声明
int Add(int x, int y);
#endif //__PROJECTT_H__
```

project.c的内容

```c
#include "project.h"
//函数Add的实现
int Add(int x, int y)
{
 return x+y;
}

```



具体的使用，在后面出实战笔记的时候会详细来写