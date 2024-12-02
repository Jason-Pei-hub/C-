# 二级指针和指针数组

## 二级指针

---

指针变量也是变量，是变量就有地址，那指针变量的地址存放在哪里？

 **这就是二级指针 。**

```c
int main()
{
    int a = 10;
    int* pa = &a;//pa是一个指针变量，同时也是一个一级指针变量
    *pa = 20;//此时解引用pa就是a
    return 0；
}
```

那么指针变量也是变量，那么pa在内存空间中应该也有地址

```c
int main()
{
    int a = 10;
    int* pa = &a;
    int** ppa = &pa//此时ppa就是一个二级指针变量
    return 0；
}
```

pa的地址中存放了a的地址

ppa中存放的是pa的地址

那么我们该如何解引用呢

```c
int main()
{
    int a = 10;
    int* pa = &a;
    int** ppa = &pa//此时ppa就是一个二级指针变量
    **ppa = 20;//第一次解引用解的pa中存放的a的地址，第二次解引用解出a
    return 0；
}
```

那么我们再来详细解释一下

```c
int* pa
    
int说明变量是整型变量 
*说明变量是指针
    
int** ppa
第二颗星说明ppa是指针
int和*合起来说明ppa指向的对象是int*类型
```



**二级指针变量是用来存放一级指针变量的地址**

>  注意不能理解为存放地址的地址



## 指针数组

>  存放指针的数组就是指针数组

```v
int arr1[5];
char arr2[6];
```

那么我们存放指针变量的数组

是不是应该这么声明

```c
int a;
int b;
int c;

char* parr[3] = {&a,&b,&c};
```

当然我们也是可以打印出来的

```c
for(i = 0; i < 3 ;i++)
{
    printf("%d",*(parr[i]));
}
```



### 指针数组模拟二维数组

我们先写一个简单的二维数组

```c
int main()
{
    int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };

    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

![image-20240410180226368](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404101802425.png)

有什么方法可以模拟二维数组呢

```c
int arr1[4] = {1,2,3,4};
int arr2[4] = {2,3,4,5};
int arr3[4] = {3,4,5,6};
```

**该怎么把这三个数组关联起来呢？**

```c
int* parr[3] = {arr1,arr2,arr3};
```

所存的是三个数组的首元素地址

我们打印出来看看

```c
for (i = 0; i < 3; i++)
{
    for (j = 0; j < 4; j++)
    {
        printf("%d ", parr[i][j]);
    }
    printf("\n");
}
```

![image-20240410180857519](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404101808568.png)

实际上和二维数组一样了

指针数组存放的是每一个数组首元素的地址，每一个数组之后又是有地址

我们可以这么理解

```c
parr[0]就等价于arr1的首元素地址
所以parr[0][0]就等价于arr[0]
parr[1]就等价于arr2的首元素地址
所以parr[1][2]就等价于arr2[2]   
```

这么看是不是更明白了





---

到目前为止初阶指针就结束了，在后面的部分也会继续更新进阶指针部分