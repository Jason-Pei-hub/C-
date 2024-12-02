# C语言—调试

## 什么是bug？

第一次被发现的导致计算机错误的飞蛾，也是第一个计算机程序错误

![image-20240412234614121](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404122346343.png)

## 调试是什么？有多重要？ 

> 所有发生的事情都一定有迹可循，如果问心无愧，就不需要掩盖也就没有迹象了，如果问心有愧， 就必然需要掩盖，那就一定会有迹象，迹象越多就越容易顺藤而上，这就是推理的途径。 

> 顺着这条途径顺流而下就是犯罪，逆流而上，就是真相。 

**一名优秀的程序员是一名出色的侦探。** 

> 每一次调试都是尝试破案的过程。



### 我们是如何写代码的？

![image-20240412234725944](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404122347018.png)

### 又是如何排查出现的问题的呢？

拒绝-迷信式调试！！！！

## 调试是什么？ 

调试（英语：Debugging / Debug），又称除错，是发现和减少计算机程序或电子仪器设备中程序 错误的一个过程。 

### 调试的基本步骤 

* 发现程序错误的存在 
* 以隔离、消除等方式对错误进行定位 
* 确定错误产生的原因 
* 提出纠正错误的解决办法
*  对程序错误予以改正，重新测试

## Debug和Release的介绍。

> **Debug 通常称为调试版本**，它包含调试信息，并且不作任何优化，便于程序员调试程序。
>
>  **Release 称为发布版本**，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用。

##  Windows环境调试介绍

#### 调试环境的准备

![image-20240413123355635](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131233673.png)

在环境中选择 debug 选项，才能使代码正常调试。

#### 学会快捷键

- **F5**：

  启动调试，用于直接跳到下一个断点处。

- **F9**：

  创建断点和取消断点。断点的设置可以让程序在想要的位置停止执行，方便逐步调试。

  ![image-20240413125120919](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131251958.png)

  表达式为真时启用断点

- **F10**：

  逐过程，用于处理一个过程，可以是一次函数调用或一条语句。

- **F11**：

  逐语句，每次执行一条语句，可进入**函数内部**进行逐步调试。(最经常使用的)

- **Ctrl + F5**：

  开始执行不调试，直接运行程序而不进入调试模式。



更多快捷键：[VS中常用的快捷键_vs快捷键-CSDN博客](https://blog.csdn.net/mrlisky/article/details/72622009)

## 调试的时候查看程序当前信息

#### 查看临时变量的值

在调试开始之后，用于观察变量的值。

![image-20240413125709886](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131257932.png)

![image-20240413125849772](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131258827.png)

监视窗口是最常用的

![image-20240413130335343](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131303391.png)

这样的方式即可监视多个值

#### 查看内存信息

在调试开始之后，用于观察内存信息。

![image-20240413130749653](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131307688.png)

####  查看调用堆栈

通过调用堆栈，可以清晰的反应函数的调用关系以及当前调用所处的位置。

![image-20240413131101884](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131311915.png)

右键可以观察更多信息

![image-20240413131238322](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131312371.png)

很好的反映了代码调用关系

####  查看汇编信息

![image-20240413131355818](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131313868.png)

![image-20240413131418361](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131314410.png)

#### 查看寄存器信息

可以查看当前运行环境的寄存器的使用信息。

![image-20240413131652733](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404131316772.png)

## 多多动手，尝试调试，才能有进步。

一定要熟练掌握调试技巧。 

初学者可能80%的时间在写代码，20%的时间在调试。但是一个程序员可能20%的时间在写 程序，但是80%的时间在调试。 

我们所讲的都是一些简单的调试。

 以后可能会出现很复杂调试场景：多线程程序的调试等。

 多多使用快捷键，提升效率。



##  一些调试的实例

```c
#include <stdio.h>
int main()
{
    int i = 0;
    int arr[10] = { 0 };
    for (i = 0; i <= 12; i++)
    {
        arr[i] = 0;
        printf("hehe\n");
    }
    return 0;
}
```



## 如何写出好（易于调试）的代码

> 1. 代码运行正常
> 2.  bug很少 
> 3.  效率高 
> 4.  可读性高
> 5.  可维护性高
> 6.  注释清晰 
> 7.  文档齐全

常见的coding技巧：

> 1. 使用assert 
> 2. 尽量使用const 
> 3. 养成良好的编码风格
> 4. 添加必要的注释
> 5. 避免编码的陷阱。



##  示范

```c
#include <stdio.h>
#include <assert.h>
//void mystrcpy(char* p1, char* p2)
//{
//    while (*p2 != '\0')
//    {
//        *p1 = *p2;
//        p1++;
//        p2++;
//    }
//    *p1 = '\0';
//}
//void mystrcpy(char* p1,const char* p2)
//{
//    //断言
//    assert(p1 != NULL);
//    assert(p2 != NULL);
//
//    while (*p1++ = *p2++)
//    {
//        ;
//    }
//}
//为什么返回char*
//是为了实现链式访问
//返回目标空间的起始地址
char* mystrcpy(char* p1, const char* p2)
{
    char* ret = p1;
    //断言
    assert(p1 != NULL);
    assert(p2 != NULL);

    while (*p1++ = *p2++)
    {
        ;
    }
    return ret;
}

int main()
{
    char arr1[20] = { 0 };
    char arr2[] = "hello world";
    mystrcpy(arr1, arr2);
    return 0;
}
```

```c
//求字符串长度
int my_strlen( const char* str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char arr[] = "hello world!";
	int len = my_strlen(arr);
	printf("%d\n", len);

	return 0;
}
```

## 编程常见的错误

#### 编译型错误

> 直接看错误提示信息（双击），解决问题。或者凭借经验就可以搞定。相对来说简单。

#### 链接型错误

> 看错误提示信息，主要在代码中找到错误信息中的标识符，然后定位问题所在。一般是**标识符名不存在**或者**拼写错误**。

#### 运行时错误

> 借助调试，逐步定位问题。最难搞。

需要依靠调试来解决