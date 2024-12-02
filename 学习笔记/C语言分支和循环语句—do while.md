# C语言分支和循环语句—do while



---

## do语句的语法：

> do 循环语句; 
>
> while(表达式);

这个和while语句的区别就是，do while语句先执行，后判断，而while语句是先判断后执行



## do语句的特点

循环至少执行一次，使用的场景有限，所以不是经常使用。

```c
#include <stdio.h>
int main()
{
 int i = 10;
 do
 {
 printf("%d\n", i);
 }while(i<10);
 return 0;
}
```



## do while循环中的break和continue

```c
#include <stdio.h>
int main()
{
 int i = 10;
    
 do
 {
        if(5 == i)
            break;
 printf("%d\n", i);
 }while(i<10);
    
 return 0;
}
#include <stdio.h>
int main()
{
 int i = 10;
    
 do
 {
        if(5 == i)
            continue;
 printf("%d\n", i);
 }while(i<10);
    
 return 0;
}
```



和前面的逻辑其实差不多，这里就不过多讲述了

接下来会写一些实例的讲解



### 感谢您的观看