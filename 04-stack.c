#include <stdio.h>

void foo(int z) {
    int a = 2;
    z = 5;
    printf("a : %d, z : %d\n", a, z);

}

int main() {
    int a = 0;
    foo(a);
    printf("a: %d\n", a);
}
