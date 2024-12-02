# 野指针、指针运算、指针与数组

---

# 野指针

### 指针未初始化

```c
int main()

{
    int *p;
    //没有初始化，就意味着没有明确的方向
    //一个局部变量不初始化，放的是随机值:0xCCCCCCCC
    //请注意，这个地址并不是我们定义的，是一个非法的地址
    
    *p = 10;//非法访问内存了，这里的p就是野指针
    
    return 0;
}
```

---

### 指针越界访问

```c
int main()
{
    int arr[10] = { 0 };
    int* p = arr;//arr[0]首元素地址，p指向数组第一个元素
    int i = 0;
    for (i = 0; i <= 11; i++)
    {
        //当指针指向的范围超出数组arr的范围时，p就是野指针
        *(p++) = i;
    }
    return 0;
}
```

### 指针指向的空间释放

```c
int* test()
{
    int a = 10;
    return &a;//出函数时a被销毁
}


int main()
{
    int* p = test();//传回了a的地址，但是a已经被销毁了，这个地址谁也不知道还有什么
    return 0;
}
```

---

## 如何避免野指针的出现

* #### 指针初始化

```c
int* p = NULL;//空指针
//如果被空指针被解引用赋值会发生异常
```

**那么当我们以后去使用指针时，应该先去询问**

```c
if(p != NULL)
{
    *p = 1;
}
```

* #### 小心指针越界

* #### 指针指向空间释放及时置NULL

* #### 避免返回局部变量的地址

* #### 指针使用之前检查有效性

```c
int main()
{
    int* p = NULL;
    //....
    int a = 10;
    p = &a;
    if (p != NULL)
    {
        *p = 20;
    }
    return 0;
}
```

---

# 指针运算

## 指针+-整数

```c
#define N_VALUES 5//宏定义常量
float values[N_VALUES];//定义浮点型数组
float *vp;//注意了，这里虽然是野指针但是我们并未使用它
//指针+-整数；指针的关系运算
for (vp = &values[0]; vp < &values[N_VALUES];)//初始化指针了
    //在这里遍历数组地址
{
     *vp++ = 0;//后置++,先使用后++，先解引用，再++，所以一次可以移动一个元素
}
```

```1c
int main()
{
    int arr[10] = {0};
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    //数组下标写法
    //for (i = 0; i < sz; i++)
    //{
    //    arr[1] = 1;
    //}
    //写法1
    //int* p = arr;
    //for (i = 0; i < sz; i++)
    //{
    //    *p = 1;
    //    p++;
    //}
    int* p = arr;
    for (i = 0; i < sz; i++)
    {
        *(p + i) = 1;
    }
    return 0;
}
```

---

## 指针相减

我们来看下面的式子的运算结果

```c
int main()
{
    int arr[10] = { 0 };
    printf("%d", &arr[9] - &arr[0]);
    return 0;
}
```

我们直接来看结果

![image-20240409204404398](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404092044431.png)

```c
int main()
{
    int arr[10] = { 0 };
    printf("%d", &arr[0] - &arr[9]);
    return 0;
}
```

![image-20240409204343247](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404092043278.png)

**指针减去指针的绝对值得到的是指针和指针之间的元素个数**

**注意：**不是所有的指针都能相减

>  指向同一块空间的指针相减才会有意义

### 计算字符串长度

```c
int my_strlen(char *s)
{
       char *p = s;
       while(*p != '\0' )
              p++;
       return p-s;
}
```

那这样我们就可以很简单的计算出字符串长度

## 指针的关系运算

 ```c
 for(vp = &values[N_VALUES]; vp > &values[0];)
 {
     *--vp = 0;
 }
 ```

这个代码之前写过，但是是不是还能简化一下

```c
for(vp = &values[N_VALUES-1]; vp >= &values[0];vp--)
{
    *vp = 0;
}
```

#### 但是：

**实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写，因为标准并不保证它可行。**

**标准规定：**

> 允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与 指向第一个元素之前的那个内存位置的指针进行比较。

---

# 数组和指针

```c
#include <stdio.h>
int main()
{
 int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    return 0;
}
```

![image-20240409204307130](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404092043166.png)

**数组**：一组相同类型的元素集合

**指针变量**：是一个变量，存放的是数组

```c
int main()
{
    int arr[10] = { 0 };
    //arr是首元素的地址
    //&arr[0]
    int* p = arr;
    //通过指针来访问数组
    
    return 0;
}
```

但是，数组就是数组，指针就是指针，二者不能混为一谈

既然可以把数组名当成地址存放到一个指针中，我们使用指针来访问一个就成为可能。

```c
#include <stdio.h>
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int *p = arr; //指针存放数组首元素的地址
    int i = 0;
    int sz = sizeof(arr)/sizeof(arr[0]);
    for(i=0; i<sz; i++)
   {
        printf("&arr[%d] = %p   <====> p+%d = %p\n", i, &arr[i], i, p+i);
   }
    return 0;
}
```

![image-20240409204608438](https://gitee.com/jason_pei/typora-bed/raw/master/image/202404092046484.png)
