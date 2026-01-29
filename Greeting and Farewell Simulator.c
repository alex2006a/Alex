#include <stdio.h>

int main() {
    int Y;
    scanf("%d", &Y);

    char names[50][11];
    for (int i = 0; i < Y; i++) {
        scanf("%s", names[i]);
    }

    // helos
    for (int i = 0; i < Y; i++) {
        for (int j = i - 1; j >= 0; j--) {
            printf("%s: salam %s!\n", names[i], names[j]);
        }
    }

    // byes
    for (int i = 0; i < Y; i++) {
        printf("%s: khodafez bacheha!\n", names[i]);
        for (int j = i + 1; j < Y; j++) {
            printf("%s: khodafez %s!\n", names[j], names[i]);
        }
    }

    return 0;
}
