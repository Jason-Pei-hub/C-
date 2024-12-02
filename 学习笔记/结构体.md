# C语言结构体



---

```c
struct tag//结构体名称
{
 member-list;//成员变量
}variable-list;//变量名
```

##  结构体的声明

>  结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。



我们学习了好多变量类型

但是都是单一的类型

在生活中还会有更多的复杂对象

描述一个人需要

> 名字 + 电话 + 身高 + 性别



**对于复杂对象的描述，就需要用到结构体**

```c
struct peo//定义一个人的类型
{
 char name[20];
 char tele[12];
 char sex[5];
 int high;
}p1,p2;//P1和P2是两个全局的结构体变量
```

P1和P2是使用struct peo类型创建的两个变量

通常情况下还是使用这样写

```c
struct peo
{
 char name[20];
 char tele[12];
 char sex[5];
 int high;
};

int main()
{
    struct peo p1 = { 0 };//创建结构体变量
    
    return 0;
}
```

#### 请注意

```c
struct peo
{
 char name[20];
 char tele[12];
 char sex[5];
 int high;
};
```

此时只是类型，此时并没有分配内存空间，可以理解为只是画了图纸

直到这里

```c
int main()
{
    struct peo p1 = { 0 };//创建结构体变量
    return 0;
}
```

p1才变成了结构体变量，才分配空间，利用图纸改了房子

---

## 结构成员的类型

结构的成员可以是标量、数组、指针，甚至是其他结构体。

---

## 结构体变量的定义和初始化

有了结构体类型，那如何定义变量，其实很简单

```c
struct Point
{
	int x;
	int y;
}p1; //声明类型的同时定义变量p1
struct Point p2; //定义结构体变量p2
//初始化：定义变量的同时赋初值。
struct Point p3 = { x, y };
struct Stu        //类型声明
{
	char name[15];//名字
	int age;      //年龄
};
struct Stu s = { "zhangsan", 20 };//初始化
struct Node
{
	int data;
	struct Point p;
	struct Node* next;
}n1 = { 10, {4,5}, NULL }; //结构体嵌套初始化
struct Node n2 = { 20, {5, 6}, NULL };//结构体嵌套初始化
```

##  结构体成员的访问

结构体变量访问成员 结构变量的成员是通过点操作符（.）访问的。

点操作符接受两个操作数。 

例如：

```c
struct Stu
{
    char name[20];
    int age;
};

struct Stu s;
```

我们可以看到 s 有成员 name 和 age ；

 那我们如何访问s的成员？

```c
struct S s;
strcpy(s.name, "zhangsan");//使用.访问name成员
s.age = 20;//使用.访问age成员
```

结构体指针访问指向变量的成员

有时候我们得到的不是一个结构体变量

而是指向一个结构体的指针。 

那该如何访问成员。 如下：

```c
struct Stu
{
 char name[20];
 int age;
};
void print(struct Stu* ps)
{
 printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
    //使用结构体指针访问指向对象的成员
 printf("name = %s   age = %d\n", ps->name, ps->age);
}
int main()
{
    struct Stu s = {"zhangsan", 20};
    print(&s);//结构体地址传参
    return 0;
}
```

---

## 结构体传参

```c
struct S
{
	int data[1000];
	int num;
};
struct S s = { {1,2,3,4}, 1000 };
//结构体传参
void print1(struct S s)
{
	printf("%d\n", s.num);
}
//结构体地址传参
void print2(struct S* ps)
{
	printf("%d\n", ps->num);
}
int main()
{
	print1(s);  //传结构体
	print2(&s); //传地址
	return 0;
}
```

上面的 print1 和 print2 函数哪个好些？

**首选print2函数。**

原因：

> 函数传参的时候，参数是需要压栈的。 如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。



### 结论： 

结构体传参的时候，要传结构体的地址。