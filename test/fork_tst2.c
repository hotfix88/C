/**
 * Author:      fyso@163.com   fengyangsgs@js.chinamobile.com
 * DateTime:    2017-09-15 10:36:31
 * Description: Description
 */


// 在window下没有一个函数可以实现UNIX下的fork()函数,其原因是历史造成的.对于UNIX来说它一出生就是多用户的系统,所以它的所有进程都共有一个最原始的父进程init.而windows生下来时是个单用户系统(DOS),不存在这样的概念.所以fork这个函数是UNIX下特有的.

// 如果硬要模似,CreateProcess()不如用CreateThread()更接近实际情况,把主thread中的所有公共变量都塞入一个结构/类的,带入新的thread中,这样可以大致完成"复制自身"的要求.

// 但由于是thread,所以主thread死后,子thread不能独立存在,而fork()出来的子进程可以脱离主进程独立存在,这一点在window下只有CreateProcess()才略有相似之处.

// 总之,实现类似fork()的功能在window下是复杂,必须个案处理,无法"一言以蔽之曰".

#include <unistd.h>  
#include <stdio.h>   
int main ()   
{   
    pid_t fpid; //fpid表示fork函数返回的值  
    int count=0;  
    fpid=fork();   
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) {  
        printf("i am the child process, my process id is %d/n",getpid());   
        printf("我是爹的儿子/n");//对某些人来说中文看着更直白。  
        count++;  
    }  
    else {  
        printf("i am the parent process, my process id is %d/n",getpid());   
        printf("我是孩子他爹/n");  
        count++;  
    }  
    printf("统计结果是: %d/n",count);  
    return 0;  
}  