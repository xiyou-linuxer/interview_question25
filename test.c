#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

#include <stdio.h>


#include <stdio.h>

int g ;

int func() {
    static int j = 98;
    j += g;
    return j;
}

int main() {
    g += 3;
    char arr[5];
    arr[1] = func();
    arr[0] = func();
    arr[2] = arr[3] = func() + 1;
    arr[4] = func() + 1;
    printf("%s linux\n", arr);
}