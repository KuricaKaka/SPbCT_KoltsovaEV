//
//  main.cpp
//  expl5b
//
//  Created by Мишаня on 12.11.2020.
//  Copyright © 2020 m1xxos. All rights reserved.
//

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
char z = *(const char *)0;
printf("I read from location zeron");
exit(EXIT_SUCCESS);
}
