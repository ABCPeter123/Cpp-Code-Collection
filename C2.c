#include <stdio.h>
#include <ctype.h> // character predicates

int getIntHelper(int acc) {
    int c = getchar();
    if (isdigit(c)) {
        return getIntHelper(16 * acc + c - '0');
    } else if (65 <= c && c <= 70) {
        return getIntHelper(16 * acc + 10 + c - 'A');
    } else if (97 <= c && c <= 102) {
        return getIntHelper(16 * acc + 10 + c - 'a');
    } else return (ungetc(c, stdin), acc);
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

void convert(int n) {
    if (n == 0) return;
    int c = n % 16;
    convert((n - c) / 16);
    printf("%x", c);
}

int main() {
    int c = func();
    if (c == 0) printf("0\n");
    else {
        convert(c);
        printf("\n");
    }
    return 0;
}