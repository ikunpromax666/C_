
//#include<stdio.h>打印字符串中字符的个数
//int mystrlen(const char* str ) {
//	int count = 0;
//	while (*str != '\0') {
//		count++;
//		str++;
//	}
//	return count;
//}
//int main() {
//	char arr[] = "hello bit";
//	int str = mystrlen(arr);
//	printf("%d",str);
//	return 0;
//}
//#include <stdio.h>利用地址打印数组
//printt(int *p, int sz) {
//	int i = 0;
//	for (i = 0; i < sz; i++) {
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	return 0;
//}
//int main() {
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = 0;
//	sz = sizeof(arr) / sizeof(arr[0]);
//	printt(arr,  sz);
//	return 0;
//}
//#include <stdio.h>逆序输出字符串
//int main() {
//	char arr[10001] = {0};
// scanf遇到空格时会结束读取
//	gets( arr);
//	int  left = 0;
//	int right = strlen(arr) - 1;
//	while (left < right) {
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s \n", arr);
//	return 0;
//}
//#include <stdio.h>打印2+22+222+2222.。。。。。
//int main() {
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a, &n);
//	int k = 0;
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		k = k * 10 + a;
//		sum += k;
//	}
//	printf("%d ", sum);
//	return 0;
//}
//#include <stdio.h>打印菱形
//int main() {
//	int line;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++) {
//		int j = 0;
//		int k = 0;
//		for (j = 0; j < line - i - 1; j++) {
//			printf(" ");
//		}
//		for (k = 0; k < 2 * (i + 1) - 1; k++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < line - 1; i++) {
//		int a = 0;
//		int b = 0;
//		for(a = 0; a <= i ; a++) {
//			printf(" ");
//		}
//		for (b = 0; b < 2 * (line - 1 - i) - 1; b++) {
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>自恋数
//#include<math.h>
//
//int numDigits(int n) {
//    int count = 0;
//    while (n != 0) {
//        n /= 10;
//        count++;
//    }
//    return count;
//}
//
//int main() {
//    for (int i = 1; i < 100000; i++) {
//        int sum = 0;
//        int temp = i;
//        int digits = numDigits(i);
//        while (temp != 0) {
//            int digit = temp % 10;
//            sum += pow(digit, digits);
//            temp /= 10;
//        }
//        if (sum == i) {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}
 /*#include<stdio.h>求两个数的最小公倍数
int main() {
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);
	int i = 1;
	while (x * i % y) {
		i++;
	}
	printf("%d", x * i);
	return 0;
}*/
//#include<stdio.h将该字符串中的每个单词进行反转，但保持单词之间的顺序不变。最后，输出处理后的字符串。
//#include<string.h>
//#include<assert.h>
//void reserve(char* left, char* right) {
//	assert(left);
//	assert(right);
//	while (left < right) {
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main() {
//	char arr[101] = { 0 };
//	gets(arr);
//	reserve(arr, arr + strlen(arr) - 1);
//	char* start = arr;
//	while (*start) {
//		char* end = start;
//		while (*end != ' ' && *end != '\0') {
//			end++;
//		}
//		reserve(start, end - 1);
//		if (*end != '\0')
//			end++;
//		start = end;
//	}
//
//	printf("%s\n", arr);
//	return 0;
//}
//#include <stdio.h>
//#define  f(x)  x*x
//void main()
//{
//	int  a = 6, b = 2, c;
//	c = f(a) / f(b);
//	printf("%d", c);
//	return 0;
//}
//#include<stdio.h>
//int test(const char* str) {
//	printf("test()");
//}
//int main() {
//	int (*sp)(const char*) = &test;
//	test("abc");
//	sp("abc");
//	(*sp)("abc");
//	return 0;
//}
//#include <stdio.h>
//int Add(int x, int y) {
//	return x + y;
//}
//void calc(int (*sp)(int, int)) {
//	int a = 3;
//	int b = 5;
//	int ret = sp(a, b);
//	printf("%d", ret);
//}
//int main() {
//	int a, b = 0;
//	calc(Add);
//	return 0;
//}
//#include<stdio.h>{
//int main() {
//	( *( void (*)()  )0)();
//	以上代码是一次函数调用，调用的是0作为地址处的参数。
//		1.把0强制类型转换为无参，返回类型是void的函数的地址
//		2.调用0地址处的这个函数
//	return 0;
//}
//}
//#利用函数指针封装函数
//#include<stdio.h>
//void menu() {
//	printf("*********************\n");
//	printf("*** 1.Add  2.Sub  ***\n");
//	printf("*** 3.Mul   4.Div ***\n");
//	printf("***** 0.exit ********\n");
//	printf("*********************\n");
//
//}
//void calc(int (*sp)(int, int)) {
//	int x = 0;
//	int y = 0;
//	printf("请输入两个数字\0");
//	scanf("%d %d", &x, &y);
//	int ret = sp(x, y);
//	printf("%d\n", ret);
//}
//int Add(int x, int y) {
//	return x + y;
//}
//
//int Sub(int x, int y) {
//	return x - y;
//}
//
//int Mul(int x, int y) {
//	return x * y;
//}
//int Div(int x, int y) {
//	return x / y;
//}
//
//int main() {
//	int input = 0;
//	do {
//		menu();
//		printf("请选择\0");
//		scanf("%d", &input);
//
//		switch (input) {
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出程序\0");
//			break;
//		default:
//			printf("输入错误\0");
//			break;
//		}
//	} while (input);
//	return 0;
//}