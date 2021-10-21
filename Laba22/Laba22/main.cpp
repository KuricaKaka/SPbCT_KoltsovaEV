//
//  main.cpp
//  Laba22
//
//  Created by Мишаня on 29.10.2020.
//  Copyright © 2020 m1xxos. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int x, pid;
    FILE *f;
    f = fopen("/Users/macos/SPbCT_BulyninMA/Laba22/Laba22/bruh.txt", "w");
    x=5;
    fprintf(f, "Standart, x = %d\n",x);
    printf("Standart, x = %d\n",x);
    x++;
    fprintf(f, "after ++, x = %d\n",x);
    printf("after ++, x = %d\n",x);
    pid=fork();
    if (pid == 0){
        fprintf(f, "\nChild 1, x = %d\n",x);
        printf("\nChild 1, x = %d\n",x);
        x-=3;
        fprintf(f, "Child 2, x = %d\n",x); // Потомок
        printf("Child 2, x = %d\n",x);
    }
    else if(pid > 0){ // Родитель
        fprintf(f, "\nParent 1, x = %d, pid = %d\n",x,pid);
        printf("\nParent 1, x = %d, pid = %d\n",x,pid);
        x+=2;
        fprintf(f, "Parent 2, x = %d\n",x);
        printf("Parent 2, x = %d\n",x);
        sleep(5);
        waitpid(pid, NULL, NULL);
    }
    else {
        perror("Fork error ");
        return -1;
    }
    
return 0;
}
