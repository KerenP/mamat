#include <stdio.h>

int main() {
    char buf;
    while (scanf("%c",&buf) >= 0) {
        printf("%c",buf);
    }
    return 0;
}
