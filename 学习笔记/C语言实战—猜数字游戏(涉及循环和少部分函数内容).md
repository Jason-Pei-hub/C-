# C语言实战—猜数字游戏(涉及循环和少部分函数内容)

> 对于前面一些内容的总结
>
> 不妨跟着一起试试吧

##  

## 折半查找算法（二分查找）



比如我买了一双鞋，你好奇问我多少钱，我说不超过300元。你还是好奇，你想知道到底多少，我就让 你猜，你会怎么猜？ 

答案：你每次猜中间数。 代码实现：

```c
实现在主函数内：
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 7;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			break;
	}
	if (left <= right)
		printf("找到了,下标是%d\n", mid);
	else
		printf("找不到\n");
}

如果实现一个二分查找函数：
int bin_search(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			return mid;//找到了，返回下标
	}
    return -1;//找不到
}
```



## 猜数字游戏

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	void menu()
	{
		printf("**********************************\n");
		printf("*********** 1.play     **********\n");
		printf("*********** 0.exit     **********\n");
		printf("**********************************\n");
	}
	//RAND_MAX--rand函数能返回随机数的最大值。
	void game()
	{
		int random_num = rand() % 100 + 1;
		int input = 0;
		while (1)
		{
			printf("请输入猜的数字>:");
			scanf("%d", &input);
			if (input > random_num)
			{
				printf("猜大了\n");
			}
			else if (input < random_num)
			{
				printf("猜小了\n");
			}
			else
			{
				printf("恭喜你，猜对了\n");
				break;
			}
		}
	}
	int main()
	{
		int input = 0;
		srand((unsigned)time(NULL));
		do
		{
			menu();
			printf("请选择>:");
			scanf("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("选择错误,请重新输入!\n");
				break;
			}
		} while (input);
		return 0;
	}
```

