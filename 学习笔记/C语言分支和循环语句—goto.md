# C语言分支和循环语句—goto



---

> C语言中提供了可以随意滥用的 goto语句和标记跳转的标号。 从理论上 goto语句是没有必要的，实践中没有goto语句也可以很容易的写出代码。 但是某些场合下goto语句还是用得着的，最常见的用法就是终止程序在某些深度嵌套的结构的处理过程。



例如：一次跳出两层或多层循环。 多层循环这种情况使用break是达不到目的的。它只能从最内层循环退出到上一层的循环。 



**goto语言真正适合的场景如下：**

```c
for(...)
    for(...)
   {
        for(...)
       {
            if(disaster)
                goto error;
       }
   }
    …
error:
 if(disaster)
         // 处理错误情况
```



---

小例子

```c
#include <stdio.h>
int main()
{
    char input[10] = {0};
    system("shutdown -s -t 60");
again:
    printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
    scanf("%s", input);
    if(0 == strcmp(input, "我是猪"))
   {
        system("shutdown -a");
   }
    else
   {
        goto again;
   }
    return 0;
}
```

而如果不适用goto语句，则可以使用循环：

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char input[10] = {0};
    system("shutdown -s -t 60");
    while(1)
   {
        printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
        scanf("%s", input);
        if(0 == strcmp(input, "我是猪"))
       {
            system("shutdown -a");
            break;
       }
   }
    return 0;
}
```

