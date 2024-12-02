# 初识C语言—数据类型 20240303



---

### 数据类型

```c
char		//字符数据类型
short		//短整型
int         //整形
long        //长整形
long long   //更长的整形
float       //单精度浮点数
double      //双精度浮点数

```

计算机语言 -写程序-解决生活中的问题

有能力来描述生活中的问题

购物商城 - 价格 - 13.4元 - 小数

C语言  浮点数，所以我们需要不同的数据类型来存储我们的数据

```c
int main() 
{
    //字符类型
	char ch = 'a';
    //整形
    int age = 20；
    //long
    //long long
    //单精度浮点型
    float  weight = 13.4;
	return 0;
}
```

---

### 每种类型的大小

```c
int main() 
{
    //sizeof - 关键字 - 操作符 - 计算类型或者变量所占空间大小
	printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(short));
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(long));
    printf("%d\n",sizeof(long long));
    printf("%d\n",sizeof(double));
    printf("%d\n",sizeof(float));
	return 0;
}
```

运行结果

```c
1
2
4
4		//为什么长整型没有整型长呢，C语言标准中 sizeof(long)>=sizeof(int),这里是等于的情况
8
8
4
```

单位是字节 byte

> 计算机中的单位
>
> bit - 比特位 - 一个1或者0，存放单个计算机二进制位，计算机最小单位
>
> byte - 字节 = 8bit
>
> kb - 1024byte
>
> mb - 1024kb
>
> gb - 1024mb
>
> tb - 1024gb
>
> pb - 1024tb

这样子可以避免空间浪费，按需分配，空间利用率更高



---

### 变量和常量



生活中的数据：

有些数据不能变：性别、血型、圆周率

有些数据一定可变：年龄、工资、体重



***C语言如何描述***

定义变量的方法

```c
//创建变量
//类型 变量名字 = 0 （初始化）
//类型 变量名字 （不推荐）
int age = 20;
double weight = 75.5;
age = age + 1;
weight = weight - 10;
printf("%d\n",age);
printf("%lf\n",weight);

%d 整型
%f float
%lf double
```

##### 变量的分类

局部变量 - 大括号内部定义的变量

```c
int main()
{
    int a = 10;
    return 0;
}
```

全局变量 - 大括号外部定义的变量

```c
int a = 10;
int main()
{
    return 0;
}
```



这个程序打印的是多少?

```c
int a = 100;
int main()
{
    int a = 10;
    return 0;
}
```

##### 当局部变量和全局变量冲突时，局部变量优先

打印结果

```c
10
```

不建议把全局变量和局部变量名字写成一样的

---

### 求两个数的和

```c
int main()
{
    int a = 0;
    int b = 0;
    int sun = 0;
    scanf("%d %d",&a,&b);
    sum = a + b;
    printf("%d\n",sum);
}
```

简单的例子，也可以说明问题

### **作用域和生命周期**

**局部变量的作用域在变量所在的范围（大括号内）**

**全局变量作用域为全局**

在同一工程里不同文件之间使用全局变量需要提前声明

```c
int g_val = 2024;
```

其他工程的文件需要使用时需要声明

```c
extern int g_val

int main()
{
    printf("%d\n",g_val);
    return 0;
}
```

运行结果

```c
2024
```



#### 生命周期

从创建到销毁，之间的时间段

局部变量的生命周期：进入局部范围，生命开始，出局部范围，生命结束

全局变量的生命周期：程序的生命周期

```c
int b = 100;

int main()
{
    {
        int a = 10;
        printf("%d",a);
    }
    
    return 0;
}
```

---

### 常量

* 字面常量

  ```c
  3.14;
  10;
  'a';
  "asdhjkasd"
  ```

* const修饰的常变量

  ```c
  const int num = 10;//num为常变量，常属性即为不能改变的属性
  
  const int n = 10;
  int arr2[n] = {0};//这里还是不能这么写，这里数组需要常量，常变量也会报错
  ```

* #define定义的标识符常量

  ```c
  #define MAX 10000
  
  int n = MAX;
  printf("%d",n);
  
  //运行结果为10000
  ```

  

* 枚举常量

  ```c
  enum Sex
  {
      //枚举变量未来的可能取值
      MALE,
      FEMALE,
      SECRET
  }
  
  int mian()
  {
      enum Sex s = MALE;
      printf("%d\n",MALE);
      printf("%d\n",FEMALE);
      printf("%d\n",SECRET);
      return 0;
  }
  ```

  ```c
  //运行结果
  0
  1
  2
      
  ```

  枚举常量是常量，可以赋初值，但是下面不能修改

  ```c
  enum Sex
  {
      //枚举变量未来的可能取值
      MALE = 3,//赋初值
      FEMALE,
      SECRET
  }
  ```

  