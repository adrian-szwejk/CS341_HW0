#include <stdio.h>

void write_triangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    write_triangle(5);
}