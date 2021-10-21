//
//  main.cpp
//  expl5a
//
//  Created by Мишаня on 12.11.2020.
//  Copyright © 2020 m1xxos. All rights reserved.
//

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
char *some_memory = (char*)0;
printf("A read from null %sn", some_memory);
sprintf(some_memory, "A write to nulln");
exit(EXIT_SUCCESS);
}
