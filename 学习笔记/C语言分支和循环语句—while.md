# C语言分支和循环语句—while



> 空杯心态，把自己当成什么都不会的状态来学习，一定能收获的更多
>
> 我也会抱着这样一个心态来认真的重新学习一遍C语言

---

**我们已经掌握了，if语句：**

```c
if(条件)
     语句;
```

我们看下面这个例子

```c
int main()
{
	if (1)
		printf("hehe\n");
	return 0;
}
```

运行结果是

```c
hehe
```

当我们把if换成while再来运行

```c
int main()
{
	while (1)
		printf("hehe\n");
	return 0;
}
```

运行结果是无限的循环

```c
hehe
hehe
hehe
...
hehe
```

当条件满足的情况下，if语句后的语句执行，否则不执行。

 但是这个语句只会执行一次。

 由于我们发现生活中很多的实际的例子是：

同一件事情我们需要完成很多次。 

那我们怎么做呢？ 

C语言中给我们引入了： while 语句，可以实现循环。

```c
//while 语法结构
while(表达式)
 循环语句;
```

比如

> 在屏幕上打印1-10的数字。

```c
#include <stdio.h>
int main()
{
 int i = 1;
 while(i<=10)
 {
 printf("%d ", i);
 i = i+1;
 }
 return 0;
}
```

运行结果

```c
1 2 3 4 5 6 7 8 9 10
```



上面的代码已经帮我了解了 while 语句的基本语法，那我们再了解一下：

### break和continue

直接上例子

```c
#include <stdio.h>
int main()
{
 int i = 1;
 while(i<=10)
 {
     if (i == 5)
         break;
 	printf("%d ", i);
 	i = i+1;
 }
 return 0;
}
```

运行结果

```c
1 2 3 4 
```

在while循环中只要遇到break，就停止后期的所有的循环，直接终止循环。

那如果是continue呢

```c
#include <stdio.h>
int main()
{
 int i = 1;
 while(i<=10)
 {
     if (i == 5)
         continue;
 	printf("%d ", i);
 	i = i+1;
 }
 return 0;
}
```

运行结果

```c
1 2 3 4 //后面是死循环，一直在循环
```

为什么呢，因为continue跳过了本次循环后面的代码，直接跳过了i++，所以i一直是5，就一直在循环

**continue**是用于终止本次循环的，也就是本次循环中continue后边的代码不会再执行， 而是直接跳转到while语句的判断部分。进行下一次循环的入口判断。

---

接下来分析几个代码

```c
//代码什么意思？
#include <stdio.h>
int main()
{
 int ch = 0;
 while ((ch = getchar()) != EOF)//getchar()是用来从键盘获取一个字符
       putchar(ch);//
    return 0;
}
```

这里说一下EOF

```c
EOF - end of file - 文件的结束标志 - -1
```

所以上面的代码也就很简单了

就是你输入什么字符，屏幕上就打印什么字符，一直循环

那么该怎么结束呢

很简单，当你输入ctrl + z时

就会自动结束

---

**回车算字符吗**

其实在getchar和键盘之间有一个缓冲区

输入字符时，当你输入a和回车

实际上缓冲区就放入  a\n

当getchar读到a时打印在屏幕上，当读取到\n时就会换行，所以实际上回车也是被读取了

---

**代码2**

```c
//代码2
#include <stdio.h>
int main()
{
    char ch = '\0';
 while ((ch = getchar()) != EOF)
 {
     if (ch < ‘0’ || ch > ‘9’)
        continue;
     putchar(ch);
 }
 return 0;
}
//这个代码的作用是：只打印数字字符，跳过其他字符的、
```

---

**实际使用场景**

```c
int main()
{
    char password[20] = { 0 };
    printf("请输入密码：>");
    scanf("%s",password);
    printf("请确认密码(Y/N)")；
    int ch = getchar();
    if(ch == 'Y')
        printf("确认成功\n");
    else
    {
        printf("确认失败\n");
    }
    return 0;
}
```

运行时发现

我在没有输入的情况下会直接打印确认失败

```c
请输入密码：>123
请确认密码(Y/N)确认失败
```

**为什么呢**

是因为我们之前提到的

getchar在缓冲区读取了我们上一个scanf中输入的回车

也就是\n，所以直接判断确认失败

所以我们需要在getchar之前清理缓冲区

```c
int main()
{
    char password[20] = { 0 };
    printf("请输入密码：>");
    scanf("%s",password);
    printf("请确认密码(Y/N)")；
    //清理缓冲区
    getchar();//处理缓冲区的\n
    int ch = getchar();
    if(ch == 'Y')
        printf("确认成功\n");
    else
    {
        printf("确认失败\n");
    }
    return 0;
}
```

运行结果

```c
请输入密码：>123
请确认密码(Y/N)Y
确认成功
```

但是如果我们这样输入呢

```c
请输入密码：>123 asc
请确认密码(Y/N)确认失败
```

又失败了，为什么呢

是因为中间缓冲区中放的是

> 123 asc\n

当scanf第一次拿取的时候，拿的是123（空格之前）

> asc\n

接下来getchar取走一个字符，缓冲区还剩

> sc\n

所以才会出现这种问题

我们在解决问题时，应该循环取走字符，如果不是\n，就一直取走

```c
int main()
{
    char password[20] = { 0 };
    printf("请输入密码：>");
    scanf("%s",password);
    printf("请确认密码(Y/N)")；
    //清理缓冲区
    //getchar();//处理缓冲区的\n
    //清理缓冲区多个字符
    int tmp = 0;
    while ((tmp = getchar()) != '\n')
    {
        ;
    }
    int ch = getchar();
    if(ch == 'Y')
        printf("确认成功\n");
    else
    {
        printf("确认失败\n");
    }
    return 0;
}
```

运行结果

```c
请输入密码：>123456 asdfghjk
请确认密码(Y/N)Y
确认成功
```

**成功啦！**

---

> getchar的返回值是int，所以才用int进行存储



---

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



**感谢您的阅读！**