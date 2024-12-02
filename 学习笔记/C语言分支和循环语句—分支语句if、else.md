# C语言分支和循环语句—分支语句if、else



> 到今天为止，我们已经在前面了解了C语言的大部分内容
>
> 对C语言有一个全面的了解是学好一门语言的开始
>
> 那么从今天开始，我们将会认真详细的去学习C语言各部分内容
>
> 无限进步吧！

---

C语言是结构化的程序设计语言

生活中所有结构都可以抽象成以下三种结果

* **顺序结构**

  按照顺序一直往下走

* **选择结构**

  对于事情有选择，不同的选择导致不同的结果

  我现在不选择敲代码可能就导致我以后卖红薯

* **循环结构**

  生活是一个圈

****

**那接下来就来讲解：**

> 分支语句

* if
* switch

> 循环语句

* while
* for
* do while

> goto语句

---

正文开始！

## 什么是语句？

**C语言中由一个分号隔开的语句就是一条语句**

```c
int main()
{
    printf("hehe\n");//语句
    ;//空语句
    return 0；//语句
}
```

---

## 分支语句（选择结构）

如果你好好学习，校招拿一个好offer，走上人生巅峰。

如果你不学习，卖红薯。

这就是选择



当然也可以回家继承88套房子



> C语言如何表示真假呢
>
> 非0就是真 -1也是真
>
> 0 就是假

## if语句

if的语法结构是怎么样的呢？

```c
if(表达式)//表达式为真，语句执行，表达式为假，语句不执行
    语句；
    
if(表达式)//表达式为真时，语句1执行
    语句1;
else//其他情况（表达式为假）语句2执行
    语句2;

//多分枝
if(表达式1)//表达式1为真时，语句1执行
    语句1;
else if(表达式2)//表达式2为真时，语句2执行
    语句2;
else//其他情况语句3执行
    语句3;
```

简单的小例子，很好理解

```c
int main()
{
	int age = 10;
	if (age >= 18)
		printf("成年\n");
	else
		printf("未成年\n");
	return 0;
}
```

**当然if语句也可以执行多条语句**

if只能管下面的第一句代码，如果不止一句需要加大括号

```c
int main()
{
	int age = 10;
	if (age >= 18)
		printf("成年\n");
	else
    {
        printf("未成年\n");
        printf("不能谈恋爱\n");
    }
	return 0;
}
```

多分支举个例子

```c
	else if(18 <= age < 26)这种写法是错误的
```

没有语法错误但是有逻辑错误

我们可以看到当我们**age为80**时

18<=age 为真 记为1

1<=26 又为真，所以执行if下的语句

应该写为

```c
int main()
{
	int age = 50;
	if (age < 18)
		printf("少年\n");
	else if (age >= 18 &&  age < 26)
		printf("青年\n");
	else if (age >= 26 && age <= 40)
		printf("中年\n");
	else if (age >= 40 && age <= 60)
		printf("壮年\n");
	else if (age >= 60 && age <= 100)
		printf("老年\n");
	else
		printf("神仙\n");
	return 0;
}
```

输出结果

```c
壮年
```

> 上面的多分支代码，并且（&&）前面的条件实际上不写也是可以的，因为else本身就去掉了前面if的条件，但是写上可读性会更好，更让人一目了然

## 悬空else

```c
int main()
{
	int a = 0;
    int b = 2;
    if (a == 1)
        if(b == 2)
            printf("hehe\n");
    else
		printf("haha\n");
	return 0;
}
```

思考一下这串代码的结果是什么?

|

|

|

|

揭晓答案

```c
```

是的没有显示错误，正确的答案就是不打印

朋友这不是python，if else并不是对齐就是配对的

**下面的else匹配的是最近的if**

而不是和哪个对齐就和谁匹配

所以一定要养成良好的代码风格

```c
int main()
{
	int a = 0;
    int b = 2;
    if (a == 1)
    {
        if(b == 2)
        {
            printf("hehe\n");
        }         
        else
        {
            printf("haha\n");
        }	    
    }     
	return 0;
}
```

这样是不是就是很清晰了

> 好的，那么提到了代码风格
>
> 不得不提到这本书
>
> 《高质量C-C++编程》
>
> 我不是打广告哈，看个前面两章二十多页就差不多了，一定会很有帮助的
>
> 一定要有自己的代码风格
>
> 想要电子书可以来找我



## if书写形式的对比

```c
//代码1
if (condition) {
	return x;
}
return y;

//代码2
if (condition)
{
	return x;
}
else
{
	return y;
}
```



**代码1和代码2一样吗？**

哈哈，其实是一样的，太有误导性了，我本来也以为是不一样的

但是我们仔细看

```c
//代码1
if (condition) {
	return x;//如果条件满足返回了x,代码是不会继续往下执行的
}
return y;//如果条件不满足，返回y的值
```

不太直观，举个小例子

```c
int test()
{
	if (1)//if内永远执行
		return 0;//返回 0
	printf("hehe\n");//那么这一句还会执行吗？让我们看看结果
	return 1;
}

int main()
{
	test();
	return 0;
}
```

运行结果

```c
```

好的是个空值

**那么代码2的形式是不是更加清晰一点呢？**

```c
//代码3
int num = 1;
if (num == 5)
{
	printf("hehe\n");
}

//代码4
int num = 1;
if (5 == num)
{
	printf("hehe\n");
}
```

我们注意一下代码3

```c
//代码3
int num = 1;
if (num = 5)//如果我写成这样运行时会有什么结果呢，if内永真，而且不报错，那有什么办法可以解决我们一不小心手误的错误呢
{
	printf("hehe\n");
}
```

我们只需要这样

```c
//代码4
int num = 1;
if (5 == num)//这种写法是没有任何问题的，而且当你少写一个等号，编译器是会报错的
{
	printf("hehe\n");
}
```

如果你找工作的时候把常量写在左边

面试官：这小子，代码老司机呀



---

## switch语句



**switch语句也是一种分支语句。**

 **常常用于多分支的情况。**



**比如：** 

>  输入1，输出星期一 
>
> 输入3，输出星期三 
>
> 输入4，输出星期四 
>
> 输入5，输出星期五 
>
> 输入6，输出星期六 
>
> 输入7，输出星期日



```c
switch (整型表达式)
{
	语句项;
}
```

上例子

```c
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("星期1\n");
	case 2:
		printf("星期2\n");
	case 3:
		printf("星期3\n");
	case 4:
		printf("星期4\n");
	case 5:
		printf("星期5\n");
	case 6:
		printf("星期6\n");
	case 7:
		printf("星期7\n");
	}
}
```

输出结果

```c
1
星期1
星期2
星期3
星期4
星期5
星期6
星期7
```

**为什么呢？**

switch语句的工作原理是，case语句和上面的switch语句共同决定了程序的入口，上面的代码中，我们从1进去，并没有设置出口，所以后面的语句都会执行

那么该怎么改呢

```c
int main()
{
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("星期1\n");
		break;
	case 2:
		printf("星期2\n");
		break;
	case 3:
		printf("星期3\n");
		break;
	case 4:
		printf("星期4\n");
		break;
	case 5:
		printf("星期5\n");
		break;
	case 6:
		printf("星期6\n");
		break;
	case 7:
		printf("星期7\n");
		break;
	}
}
```

所以case决定入口，break决定出口



还有一点需要注意

```c
switch(整型表达式)
{
    语句项；
}
```

```c
case 整形常量表达式:
    语句;
```

都需要是整型表达式，case需要是整型常量

#### break

> reak一定要加吗？

如果我们的需求变了，现在的要求是

> 1. 输入1-5，输出的是“weekday”; 
> 2. 输入6-7，输出“weekend

我们的代码就应该这样实现

```c
#include <stdio.h>
//switch代码演示
int main()
{
    int day = 0;
    switch(day)
   {
        case 1：
        case 2:
        case 3:
        case 4:
        case 5:
            printf("weekday\n");
            break;
        case 6:
        case 7:
            printf("weekend\n");
            break;
   }
    return 0;
}

```

所以break不是必须加的，具体实现还是要看我们的需求



**break语句** 的实际效果是把语句列表划分为不同的分支部分。





**编程好习惯** 

>  在最后一个 case 语句的后面加上一条 break语句。 
>
> 因为在代码中，实际上最后一个break加不加是没有区别的，但是如果有一天，别人在你的代码下再加一个case，这个时候你没有break，那是不是后两个case就会连续执行，和我们的需求不一样了



#### default

如果表达的值与所有的case标签的值都不匹配怎么办？ 

其实也没什么，结构就是所有的语句都被跳过而已。 程序并不会终止，也不会报错，因为这种情况在C中并不认为是个错误。 

但是，如果你并不想忽略不匹配所有标签的表达式的值时该怎么办呢？ 

你可以在语句列表中增加一条default子句，把下面的标签 

```c
default： 
```

写在任何一个 case 标签可以出现的位置。 

当 switch 表达式的值并不匹配所有 case 标签的值时，这个 default 子句后面的语句就会执行。 

所以，每个switch语句中只能出现一条default子句。 

但是它可以出现在语句列表的任何位置，而且语句流会像执行一个case标签一样执行default子句。



上例子

```c
#include <stdio.h>

int main()
{
    int day = 9;
    switch(day)
   {
        case 1：
        case 2:
        case 3:
        case 4:
        case 5:
            printf("weekday\n");
            break;
        case 6:
        case 7:
            printf("weekend\n");
            break;
        default:
            printf("输入错误\n");
            break;
   }
    return 0;
}
```

day为9时，输出

```c
输入错误
```



---

小练习

```c
#include <stdio.h>
int main()
{
    int n = 1;
    int m = 2;
    switch (n)
   {
    case 1:
            m++;
    case 2:
            n++;
    case 3:
            switch (n)
           {//switch允许嵌套使用
             case 1:
                    n++;
             case 2:
                    m++;
                    n++;
                    break;
           }
    case 4:
            m++;
            break;
    default:
            break;
   }
    printf("m = %d, n = %d\n", m, n);
    return 0;
}

```

输出结果是多少？

```c
m = 5,n = 3
```

不是很难



---



感谢大家的阅读！！！

