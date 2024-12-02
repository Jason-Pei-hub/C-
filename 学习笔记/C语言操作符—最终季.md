# C语言操作符—最终章



## 算术转换

如果某个操作符的各个操作数属于不同的类型，那么除非其中一个操作数的转换为另一个操作数的类 型，否则操作就无法进行。

下面的层次体系称为**寻常算术转换**。

```c
long double
double
float
unsigned long int
long int
unsigned int
int
```

如果某个操作数的类型在上面这个列表中排名较低，那么首先要转换为另外一个操作数的类型后执行运算。 

**警告**： 但是算术转换要合理，要不然会有一些潜在的问题。

```c
float f = 3.14;
int num = f;//隐式转换，会有精度丢失
```



###  操作符的属性

复杂表达式的求值有三个影响的因素。

1. 操作符的优先级 
2.  操作符的结合性 
3.  是否控制求值顺序。

**两个相邻的操作符先执行哪个？**

取决于他们的优先级。如果两者的优先级相同，取决于他们的结合性。 操作符优先级

| 操作符 | 描述 | 用法示例 | 结果类型 | 结合性 | 是否控制求值 |
| --- | --- | --- | --- | --- | --- |
| `()` | 聚组 | `(表达式)` | 与表达式同 | N/A | 否 |
| `()` | 函数调用 | `rexp(rexp, ..., rexp)` | rexp | L-R | 否 |
| `[]` | 下标引用 | `rexp[rexp]` | lexp | L-R | 否 |
| `.` | 访问结构成员 | `lexp.member_name` | lexp | L-R | 否 |
| `->` | 访问结构指针成员 | `rexp->member_name` | lexp | L-R | 否 |
| `++` | 后缀自增 | `lexp++` | rexp | L-R | 否 |
| `--` | 后缀自减 | `lexp--` | rexp | L-R | 否 |
| `!` | 逻辑反 | `!rexp` | rexp | R-L | 否 |
| `~` | 按位取反 | `~rexp` | rexp | R-L | 否 |
| `+` | 单目，表示正值 | `+rexp` | rexp | R-L | 否 |
| `-` | 单目，表示负值 | `-rexp` | rexp | R-L | 否 |
| `++` | 前缀自增 | `++lexp` | rexp | R-L | 否 |
| `--` | 前缀自减 | `--lexp` | rexp | R-L | 否 |
| `*` | 间接访问 | `*rexp` | lexp | R-L | 否 |
| `&` | 取地址 | `&lexp` | rexp | R-L | 否 |
| `sizeof` | 取其长度，以字节表示 | `sizeof rexp` `sizeof(类型)` | rexp | R-L | 否 |
| `(类型)` | 类型转换 | `(类型) rexp` | rexp | R-L | 否 |
| `*` | 乘法 | `rexp * rexp` | rexp | L-R | 否 |
| `/` | 除法 | `rexp / rexp` | rexp | L-R | 否 |
| `%` | 整数取余 | `rexp % rexp` | rexp | L-R | 否 |
| `+` | 加法 | `rexp + rexp` | rexp | L-R | 否 |
| `-` | 减法 | `rexp - rexp` | rexp | L-R | 否 |
| `<<` | 左移位 | `rexp << rexp` | rexp | L-R | 否 |
| `>>` | 右移位 | `rexp >> rexp` | rexp | L-R | 否 |
| `>` | 大于 | `rexp > rexp` | rexp | L-R | 否 |
| `>=` | 大于等于 | `rexp >= rexp` | rexp | L-R | 否 |
| `<` | 小于 | `rexp < rexp` | rexp | L-R | 否 |
| `<=` | 小于等于 | `rexp <= rexp` | rexp | L-R | 否 |
| `==` | 等于 | `rexp == rexp` | rexp | L-R | 否 |
| `!=` | 不等于 | `rexp != rexp` | rexp | L-R | 否 |
| `&` | 位与 | `rexp & rexp` | rexp | L-R | 否 |
| `^` | 位异或 | `rexp ^ rexp` | rexp | L-R | 否 |
| `|` | 位或 | `rexp | rexp` | rexp | L-R | 否 |
| `&&` | 逻辑与 | `rexp && rexp` | rexp | L-R | 是 |
| `||` | 逻辑或 | `rexp || rexp` | rexp | L-R | 是 |
| `? :` | 条件操作符 | `rexp ? rexp : rexp` | rexp | N/A | 是 |
| `=` | 赋值 | `lexp = rexp` | rexp | R-L | 否 |
| `+=` | 以...加 | `lexp += rexp` | rexp | R-L | 否 |
| `-=` | 以...减 | `lexp -= rexp` | rexp | R-L | 否 |
| `*=` | 以...乘 | `lexp *= rexp` | rexp | R-L | 否 |
| `/=` | 以...除 | `lexp /= rexp` | rexp | R-L | 否 |
| `%=` | 以...取模 | `lexp %= rexp` | rexp | R-L | 否 |
| `<<=` | 以...左移 | `lexp <<= rexp` | rexp | R-L | 否 |
| `>>=` | 以...右移 | `lexp >>= rexp` | rexp | R-L | 否 |
| `&=` | 以...与 | `lexp &= rexp` | rexp | R-L | 否 |
| `^=` | 以...异或 | `lexp ^= rexp` | rexp | R-L | 否 |
| `|=` | 以...或 | `lexp |= rexp` | rexp | R-L | 否 |
| `,` | 逗号 | `rexp, rexp` | rexp | L-R | 是 |



一些**问题表达式**

```c
//表达式的求值部分由操作符的优先级决定。
//表达式1
a*b + c*d + e*f
```

> 注释：代码1在计算的时候，由于*比+的优先级高，只能保证，*的计算是比+早，但是优先级并不 能决定第三个*比第一个+早执行。

所以表达式的计算机顺序就可能是：

```c
a*b
c*d
a*b + c*d
e*f
a*b + c*d + e*f
    
或者：
    
a*b
c*d
e*f
a*b + c*d
a*b + c*d + e*f
```

```c
//表达式2
c + --c;
```

> 注释：同上，操作符的优先级只能决定自减--的运算在+的运算的前面，但是我们并没有办法得 知，+操作符的左操作数的获取在右操作数之前还是之后求值，所以结果是不可预测的，是有歧义 的。

```c
//代码3-非法表达式
int main()
{
 int i = 10;
 i = i-- - --i * ( i = -3 ) * i++ + ++i;
 printf("i = %d\n", i);
 return 0;
}
```

表达式3在不同编译器中测试结果是不同的



```c
//代码4
int fun()
{
     static int count = 1;
     return ++count;
}
int main()
{
     int answer;
     answer = fun() - fun() * fun();
     printf( "%d\n", answer);//输出多少？
     return 0;
}
```

这个代码有没有实际的问题？ 

**有问题！** 

虽然在大多数的编译器上求得结果都是相同的。 但是上述代码 answer = fun() - fun() * fun(); 中我们只能通过操作符的优先级得知：先算乘法， 再算减法。

 函数的调用先后顺序无法通过操作符的优先级确定。



---

**总结：我们写出的表达式如果不能通过操作符的属性确定唯一的计算路径，那这个表达式就是存在问题 的。**
