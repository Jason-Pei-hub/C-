# 初识C语言—结构体

---

> 生活中很多东西都是复杂对象
>
> 就比如一本书，有书名，作者，编号，价钱
>
> C语言中提供了结构体来让我们描述这种复杂结构

结构体可以让C语言创造新的类型出来

```c
//创建一个学生
struct Stu
{
    char name[20];
    int age;
    double score;
};

//创建一个书的类型
struct Book
{
    char name[20];
    float price;
    char id[30];
};

int main()
{
    struct Stu s = { "张三",20,85.5 };//结构体的创建和初始化
    printf("%s %d %lf\n", s.name,s.age,s.score);//结构体变量，成员变量
    
    return 0;
}
```

运行结果

```c
张三 20 85.500000
```

OK，让我们带上指针再试一次

```c
//创建一个学生
struct Stu
{
    char name[20];
    int age;
    double score;
};

//创建一个书的类型
struct Book
{
    char name[20];
    float price;
    char id[30];
};

int main()
{
    struct Stu s = { "张三",20,85.5 };//结构体的创建和初始化
    printf("1: %s %d %lf\n", s.name,s.age,s.score);//结构体变量，成员变量
    struct Stu* ps = &s;
    printf("2: %s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
    return 0;
}
```

运行结果

```c
1: 张三 20 85.500000
2: 张三 20 85.500000
```

**一模一样 **但是 **太麻烦**

**结构体指针->成员变量名**

```c
//创建一个学生
struct Stu
{
    char name[20];
    int age;
    double score;
};

//创建一个书的类型
struct Book
{
    char name[20];
    float price;
    char id[30];
};

int main()
{
    struct Stu s = { "张三",20,85.5 };//结构体的创建和初始化
    printf("1: %s %d %lf\n", s.name,s.age,s.score);//结构体变量，成员变量
    struct Stu* ps = &s;
    printf("2: %s %d %lf\n", (*ps).name, (*ps).age, (*ps).score);
    printf("3: %s %d %lf\n", ps->name, ps->age, ps->score);
    return 0;
}
```

运行结果

```c
1: 张三 20 85.500000
2: 张三 20 85.500000
3: 张三 20 85.500000
```

三种方法都可以实现找到成员变量

**今天还是点到为止，后面会写更加详细的笔记！！！**

---

到今天为止，初识C语言就结束了，接下来就是每一个部分更加细致的学习和记录！！！

#### 感谢您的观看！！！

