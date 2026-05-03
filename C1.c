#include <stdio.h>
#include <ctype.h> // character predicates

int getIntHelper(int acc) {
    int c = getchar();
    return (isdigit(c)) ? getIntHelper(10 * acc + c - '0') : (ungetc(c, stdin), acc);
}

int skipws() {
    int c = getchar();
    if (c == EOF) return EOF;
    else if (isspace(c)) {
        return skipws();
    } else return (ungetc(c, stdin), 0);
}
int getInt() {
    int c = getchar();
    if (c == EOF) return -1;
    ungetc(c, stdin);
    skipws();
    return getIntHelper(0);
}

int func() {
    int ans = getInt();
    if (ans == -1) return 0;
    else return ans + func();
}

int main() {
    printf("%d\n", func());
    return 0;
}