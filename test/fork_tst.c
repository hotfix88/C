/**
 * Author:      fyso@163.com   fengyangsgs@js.chinamobile.com
 * DateTime:    2017-09-15 10:34:49
 * Description: fork
 */

#include <stdio.h>  
#include <unistd.h>  
  
int main()  
{  
    printf("a");  
    pid_t fpid = fork();  
  
    return 0;  
}  

// 上面程序的结果是多少呢？ 没接触过unix/linux编程的Windows程序猿肯定会说输出a啊， 
// 其实， 这也真难为你了。 有一点unix/linux基础的程序猿很容易知道， 上面程序的结果为aa. 
//       那一年， 某公司校园招聘的笔试题目中， 就考了fork， 还考了两个题目， 两个题目还很类似， 
//       弄晕了不少经常在Windows下写程序但较少接触unix/linux的程序猿。 
//       在下一篇博文中， 我们将一起学习这两个题目。 期待的心情， 总是那么迫切。