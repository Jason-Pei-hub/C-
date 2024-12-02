# C语言函数—库函数



## 函数是什么？

数学中我们常见到函数的概念。但是你了解C语言中的函数吗？ 

维基百科中对函数的定义：子程序

> 在计算机科学中，子程序（英语：Subroutine, procedure, function, routine, method,  subprogram, callable unit），**是一个大型程序中的某部分代码， 由一个或多个语句块组成**。它负责完成某项特定任务，而且相较于其他代 码，**具备相对的独立性**。 
>
> **一般会有输入参数并有返回值**，提供对过程的封装和细节的隐藏。这些代码通常被集成为软件库。

**在数学中**

f(x) = 2 * x + 1;这就是一个函数



![image-20240312124951395](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403121249458.png)

这就是C语言中的函数，a,b为输入，c 为输出



### C语言中函数的分类： 

1.  库函数
2.  自定义函数

#### 库函数：

#####  为什么会有库函数？ 

1. 我们知道在我们学习C语言编程的时候，总是在一个代码编写完成之后迫不及待的想知道结果，想 把这个结果打印到我们的屏幕上看看。这个时候我们会频繁的使用一个功能：将信息按照一定的格 式打印到屏幕上（printf）。 
2. 2. 在编程的过程中我们会频繁的做一些字符串的拷贝工作（strcpy）。 
   3. 3. 在编程是我们也计算，总是会计算n的k次方这样的运算（pow）。 像上面我们描述的基础功能，它们不是业务性的代码。我们在开发的过程中每个程序员都可能用的到， 为了支持可移植性和提高程序的效率，所以C语言的基础库中提供了一系列类似的库函数，方便程序员 进行软件开发。 那怎么学习库函数呢？ 这里我们简单的看看：www.cplusplus.com

![image-20240312125320370](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403121253437.png)

![image-20240312125342451](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403121253497.png)

看看我们最熟悉的stdio头文件所定义的函数，每一个函数都解释的很详细



![image-20240312125539030](https://gitee.com/jason_pei/typora-bed/raw/master/image/202403121255073.png)

简单的总结，C语言常用的库函数都有： 

* IO函数 

  printf scanf putchar getchar

* 字符串操作函数 

  strcmp strlen

* 字符操作函数 

  toupper小写转大写

* 内存操作函数 

  memcpy memcmp memset

* 时间/日期函数 

  time

* 数学函数 

* 其他库函数

##### 如何学会使用库函数？

需要全部记住吗？**No** 

需要学会查询工具的使用： 

MSDN(Microsoft Developer Network) 

www.cplusplus.com http://en.cppreference.com（英文版）

 http://zh.cppreference.com（中文版）

 英文很重要。最起码得看懂文献。

