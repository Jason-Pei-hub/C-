

# 初识C语言—操作符，常见关键字，#define 定义常量和宏



---

> 前情提要，我们学到了操作符

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

**按位取反** ~

```c
int main()
{
    int a = 0;
    printf("%d", ~a);
    return 0;
}
```

输出结果

```c
-1
```

**按位取反，把所有二进制位中的数字取反（不考虑符号位）**

0变成1，1变成0



0的二进制 00000000000000000000000000000000（32个比特位）

~a结果为   11111111111111111111111111111111

> 整数的二进制表示有三种
>
> 原码、反码、补码（针对负数），正整数：原码反码补码相同
>
> -1：
>
> 10000000000000000000000000000001（最高位为符号位，）（-1的原码）
>
> 11111111111111111111111111111110（符号位不变，其他位取反）（-1的反码）
>
> 11111111111111111111111111111111（反码+1）（-1的补码）**（内存中储存的是补码）**

所以取反后我们得到的是数字的补码，并不是原码

---

```c
int main()
{
    int a = 10;
    int b = ++a;//前置++
    printf("%d\n", b);
    printf("%d\n", a);
    return 0;
}
```

前置++，先++后使用

所以输出结果为

```c
11
11
```

后置++

```c
int main()
{
    int a = 10;
    int b = a++;//后置++
    printf("%d\n", b);
    printf("%d\n", a);
    return 0;
}
```

结果为

```c
10
11
```

先使用，再++

---

#### 强制类型转换

```c
int main()
{
    int a = 3.14;
    printf("%d\n", a);
    return 0;
}
```



编译代码时出现警告，丢失精度，如何避免

```c
int main()
{
    int a = (int)3.14;//强制类型转换
    printf("%d\n", a);
    return 0;
}
```

**不推荐使用**

---

## 关系操作符

```c
>  >=  <  <=  !=  ==
```

很简单

---

## 逻辑操作符

```c
&&  逻辑与  
||  逻辑或
```

```c
int main()
{
    int a = 3;
    int b = 5;
    int c = a && b;
    //if(a && b)
    printf("%d\n", c);
    return 0;
}
```

输出结果为1

很简单的数学逻辑，不展开讲了，0为假，其他都为真

---

## 条件操作符

**三木操作符**

```c
exp1?exp2 : exp3
```

exp1如果成立，exp2计算，整个表达式结果为exp2的结果

exp1如果不成立，exp3计算，整个表达式结果为exp3的结果

```c
int main()
{
    int a = 0;
    int b = 3;
    int max = 0;
    max = a > b ? a : b;
    printf("%d\n", max);
    return 0;
}
```

输出结果为

```c
3
```

**逗号表达式**

逗号隔开的一串表达式

```c
int main()
{
    int a = 0;
    int b = 3;
    int c = 5;
    int d = (a = b + 2, c = a - 4, b = c + 2);
    printf("%d\n", d);
    return 0;
}
```

逗号表达式从左向右依次计算

真个表达式的结果是最后一个表达式的结果

输出结果

```c
3
```



下标引用操作符、函数调用操作符，结构成员

```c
[]   ()   .   ->
```

```c
int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    printf("%d\n", arr[5]);//下标引用操作符
    return 0;
}
```



函数调用操作符

```c
int main()
{
    printf("hehe\n");//调用函数的时候，函数名后面的圆括号
    return 0;
}
```

---

## 常见关键字

* C语言提供
* 不能自己创建
* 关键字不能做变量名

```c
auto  break  case  char const  continue default do double else enum 
extern float for goto if int long register return short signed sizeof
static struct switch typedef union unsigned void volatile while
```

### **auto** 

自动的 - 每个局部变量都是auto修饰的

```c
int main()
{
    {
        auto int a = 10;//自动创建 自动销毁 自动变量 一般省略auto
        //新的C语言语法中有其他用法，暂时不考虑
    }
    return 0;
}
```

### **extern**

是用来声明外部符号

### **register**

寄存器关键词

```c
int main()
{
    register int num = 100;//建议num的值存放在寄存器中
    return 0;
}
```

仅仅是建议，具体放在那里还要看编译器

### 计算机中数据可以存放在哪里呢？

* 寄存器  更小
* 高速缓存  几十MB
* 内存  8-16G
* 硬盘  500G
* 网盘  2T

越往上，造价越高，速度越快，空间越小

> **CPU 中央处理器** —— 内存中读取
>
> 随着发展，CPU速度越来越快，内存速度可能跟不上，所以这个时候再快也变得没意义
>
> 我们在内存之上提供高速缓存和寄存器
>
> CPU从寄存器拿，寄存器去高速缓存拿

**所以**大量频繁被使用的数据想着放进寄存器中

### **signed**

 有符号的 正数和负数

### **unsigned** 

无符号的

### **static**  

静态的

### **union** 

联合体

### **volatile**  

C语言暂时不讲



#### 注意

```c
define
include
都不是关键字，是预处理指令
```

### typedef

类型重命名

```c
typedef unsigned int u_int;

int main()
{
    unsigned int num = 100;
    u_int num2 = 100;
    return 0;
}
```

以上num和num2是一模一样的

 **张三** — **小三**

一样的朋友

### static

静态的

* static修饰局部变量

* static修饰全局变量

* static修饰函数

  

```c
void test()
{
    int a = 1;
    a++;
    printf("%d", a);
}
int main()
{
    int i = 0;
    while (i < 10)
    {
        test();
        i++;
    }
    return 0;
}
```

输出结果为

```c
2222222222
```

---

那我们用static修饰一下

```c
void test()
{
    static int a = 1;
    a++;
    printf("%d", a);
}
int main()
{
    int i = 0;
    while (i < 10)
    {
        test();
        i++;
    }
    return 0;
}
```

输出结果为

```c
234567891011
```

**出函数时a没有被销毁，生命周期变长了**

static可以改变局部变量的声明周期，本质上是改变了变量的存储类型



#### 内存分为

* **栈区**

  存局部变量 函数参数 临时的内存

* **堆区**

  动态内存分配！！

* **静态区**

  全局变量

  static修饰的静态变量

a由栈区变为静态区，所以生命周期延长



#### 全局变量在整个工程都可用

文件1

```c
#define _CRT_SECURE_NO_WARNINGS 1
int g_val = 2024;
//全局变量
```

文件2

```c
//声明
extern int g_val;

int main()
{
    printf("%d", g_val);
    return 0;
}
```

文件2运行结果

```c
2024
```

**但是**

当我们使用static修饰后

```c
#define _CRT_SECURE_NO_WARNINGS 1
static int g_val = 2024;
//全局变量
```

上面的文件2会报错

```c
无法解析的外部符号
```

static修饰全局变量使得全局变量只能在自己的源文件(,c)内部可以使用，其他源文件不可用！！！

**全局变量**

全局变量可以在其他源文件内部可以被使用，是因为源文件具有外部链接属性，但是被static修饰之后就变成了内部链接属性，其他源文件就不能链接到这个静态的全局变量了



#### 修饰函数

文件1

```c
int Add(int x, int y)
{
	return x + y;
}
```

文件2

```c
//声明函数
extern int Add(int, int);

int main()
{
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("sun = %d\n",sum);
    return 0;
}
```

文件2运行结果

```c
sum = 30
```

但是如果我们用static修饰一下函数

文件1

```c
static int Add(int x, int y)
{
	return x + y;
}
```

文件2运行就会报错

错误信息

```c
无法解析的外部符号
```

**所以static修饰使得函数只能在自己所在的源文件内部使用，不能在其他源文件内使用**

**本质上，static是将函数的外部链接属性变为内部链接属性（和static修饰全局变量一样！！！）**



## #define 定义常量和宏

define**是一个预处理指令**

* define定义符号

  ```c
  define MAX = 1000;
  ```

  

* difine定义宏

  ```c
  #define ADD(X,Y) X+Y
  
  int main
  {
      printf("%d",4*ADD(2,3));
      return 0;
  }
  ```

  结果为11

  **为什么呢**

  define定义宏是替换

  4*ADD(2,3)会被换成4X2+3，而不是4X（2+3）

  正确写法应该是这样的

  ```c
  #define ADD(X,Y) ((X)+(Y))
  
  int main
  {
      printf("%d",4*ADD(2,3));
      return 0;
  }
  ```

  运行结果为

  ```c
  20
  ```

  后面会详细讲一下这个！！！