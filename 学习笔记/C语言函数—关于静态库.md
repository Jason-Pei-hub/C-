# C语言函数—关于静态库



> 具体的函数声明和定义请参考上一篇文章

**如果我们成为了库的开发者，要卖给别人C语言库，该怎么办呢？**



**A不会写减法，想找你买一个函数**

**但是，他给的太少了，你不想把源码卖给他**

**那怎么办呢？**



**首先，肯定不能卖.c文件和.h文件呀**

## 我们先新建一个工程

![image-20240313180714214](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131807367.png)

这里用VS2022演示

![image-20240313180849726](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131808759.png)

**首先肯定得创建一个头文件和源文件**

然后简单写一下我们最贵的客户要求的实现代码以及头文件（声明函数）

![image-20240313181435390](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131814422.png)

```c
//test.c
#define _CRT_SECURE_NO_WARNINGS 1

int Sub(int x, int y)
{
	return x - y;
}
```

```c
#pragma once
int Sub(int x, int y);
```

## 那我们接下来该怎么做呢？

我们需要修改属性中的配置类型

![image-20240313181634707](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131816733.png)

![image-20240313182051976](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131820008.png)



选择**静态库**点击**应用**，点击**确定**

**点击重新生成解决方案**

![image-20240313182527535](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131825564.png)

可以看到已经生成了lib文件

![image-20240313182548027](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131825052.png)

这个文件就是vs把.c文件和.h文件编译产生的一个静态库

我们打开看一下能不能看懂

![image-20240313183120788](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131831813.png)

全是乱码

### 我们现在把这个project1.lib卖给刚刚的A程序员，他看不懂，怎么办

很简单，我们把.h文件一起卖，我们只要注释的详细一点，A就能看懂

![image-20240313183844162](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131838187.png)

## 现在我是A程序员

首先把文件粘贴到项目里(最下面两个文件)

![image-20240313221243666](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403132212700.png)

先把头文件导入（选择.h）文件即可

![image-20240313221410938](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403132214977.png)



```c
#include"test.h"
int main()
{
	int a = 10;
	int b = 20;

	int c = Sub(a, b);
	printf("%d\n", c);
	return 0;
}
```

还是会报错

![image-20240313184257241](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403131842268.png)

解决办法很简单，我们只需要导入刚刚买来的静态库就行

```c
#pragma comment(lib,"Project1.lib")
```

![image-20240313222448649](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403132224677.png)

可以成功运行

---

但是过程之中还是遇到一些小插曲

在函数编译的过程中，main函数出现重定义，解决方法就是防止源文件中出现多个主程序，这在C语言和C++中都是不可取的