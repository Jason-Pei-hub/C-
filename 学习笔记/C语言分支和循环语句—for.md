# C语言分支和循环语句—for



---

前情提要

我们重新来看这串代码

```c
#include <stdio.h>
int main()
{
 int i = 1;//初始化
 while(i<=10)//判断部分
 {
 printf("%d ", i);
 i = i+1;//调整部分
 }
 return 0;
}
```

上面三个部分任何一个部分发生变化就会影响程序的本身，那么，有没有一种简单的写法呢？

---

**我们已经知道了while循环，但是我们为什么还要一个for循环呢？ 首先来看看for循环的语法：**

```c
for(表达式1; 表达式2; 表达式3)
 循环语句;

```

**表达式1** 表达式1为**初始化部分**，用于初始化循环变量的。 

**表达式2** 表达式2为条件**判断部分**，用于判断循环时候终止。 

**表达式3** 表达式3为**调整部分**，用于循环条件的调整。

实际的问题： 

> 使用for循环 在屏幕上打印1-10的数字。

```c
#include <stdio.h>
int main()
{
 int i = 0;
 //for(i=1/*初始化*/; i<=10/*判断部分*/; i++/*调整部分*/)
 for(i=1; i<=10; i++)
 {
 printf("%d ", i);
 }
 return 0;
}
```

---

现在我们对比一下for循环和while循环。

```c
int i = 0;
//实现相同的功能，使用while
i=1;//初始化部分
while(i<=10)//判断部分
{
 printf("hehe\n");
 i = i+1;//调整部分
}
//实现相同的功能，使用while
for(i=1; i<=10; i++)
{
 printf("hehe\n");
}
```

可以发现在while循环中依然存在循环的三个必须条件，但是由于风格的问题使得三个部分很可能偏离较 远，这样 查找修改就不够集中和方便。

所以，for循环的风格更胜一筹；for循环使用的频率也最高。



## break和continue

我们发现在for循环中也可以出现break和continue，他们的意义和在while循环中是一样的。 但是还是有些差异：

```c
//代码1
#include <stdio.h>
int main()
{
 	int i = 0;
 	for(i=1; i<=10; i++)
 	{
 		if(i == 5)
 		break;
 		printf("%d ",i);
 	}
 return 0;
}

//这里还是直接跳出循环

//代码2
#include <stdio.h>
int main()
{
 	int i = 0;
 	for(i=1; i<=10; i++)
 	{
 		if(i == 5)
 		continue;
 		printf("%d ",i);
 	}
 	return 0;
}

//这里是跳过本次循环，但是i还是能够继续往上加，并不是一到5就终止了，这一点和while不一样
```

## for语句的循环控制变量

**建议：**

> 1. 不可在for 循环体内修改循环变量，防止 for 循环失去控制。 
> 2. 2. 建议for语句的循环控制变量的取值采用“前闭后开区间”写法。

```c
int i = 0;
//前闭后开的写法
for(i=0; i<10; i++)
{}

//两边都是闭区间
for(i=0; i<=9; i++)
{}
```



## 一些for循环的变种

```c
#include <stdio.h>
int main()
{
 //代码1
 for(;;)
 {
 printf("hehe\n");
 }
    //for循环中的初始化部分，判断部分，调整部分是可以省略的，但是不建议初学时省略，容易导致问
题。
    
    //代码2
    int i = 0;
    int j = 0;
    //这里打印多少个hehe?
    for(i=0; i<10; i++)
   {
        for(j=0; j<10; j++)
       {
 printf("hehe\n");
       }
   }
    
    //代码3
    int i = 0;
    int j = 0;
    //如果省略掉初始化部分，这里打印多少个hehe?
    for(; i<10; i++)
   {
        for(; j<10; j++)
       {
 printf("hehe\n");
       }
   }
    
 //代码4-使用多余一个变量控制循环
 int x, y;
    for (x = 0, y = 0; x<2 && y<5; ++x, y++)
   {
        printf("hehe\n");
   }
 return 0;
}
```



## 那接下来一起看一道笔试题

```c
//请问循环要循环多少次？
#include <stdio.h>
int main()
{
 int i = 0;
 int k = 0;
 for(i =0,k=0; k=0; i++,k++)
        k++;
 return 0;
}

```

很简单，在判断部分的代码为k = 0，所以for循环对于判断的内容永远会认为是假的（0），所以这个循环会一直执行下去



---

### 感谢您的观看！
