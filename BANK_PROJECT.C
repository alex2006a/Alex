#include <stdio.h>

int main() {
    char name[30], family[30];
    int pin, inputpin;
    int flag = 0;
    int try_count = 0;
    double mojoodi = 0;
    double tarikhche[10];
    int tarakonesh = 0;
    int choice;

    printf("be system bank seyed ali khosh amadid\n");

    do {
        printf("\nlotfan shomare amaliat ra vared konid:\n");
        printf("1) eftetah hesab\n");
        printf("2) variz\n");
        printf("3) bardasht\n");
        printf("4) moshahede mojoodi\n");
        printf("5) tarikhche tarakonesh ha\n");
        printf("6) hazf hesab\n");
        printf("7) taghir pin\n");
        printf("0) khorooj\n");

        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (flag == 0) {
                printf("enter name: ");
                scanf("%s", name);
                printf("enter family: ");
                scanf("%s", family);
                printf("enter pin: ");
                scanf("%d", &pin);
                flag = 1;
                try_count = 0;
            } else {
                printf("hesab ghablan ijad shode\n");
            }
            break;

        case 2:
            if (flag == 1) {
                printf("enter pin: ");
                scanf("%d", &inputpin);

                if (inputpin == pin) {
                    try_count = 0;

                    double mablagh;
                    printf("mablagh varizi: ");
                    scanf("%lf", &mablagh);
                    mojoodi += mablagh;

                    if (tarakonesh < 10)
                        tarikhche[tarakonesh++] = mablagh;

                    printf("variz anjam shod\n");
                } else {
                    try_count++;
                    printf("pin eshtebah (%d/3)\n", try_count);

                    if (try_count == 3) {
                        printf("3 bar ramz eshtebah! khorooj...\n");
                        return 0;
                    }
                }
            } else {
                printf("hesabi vojood nadarad\n");
            }
            break;

        case 3:
            if (flag == 1) {
                printf("enter pin: ");
                scanf("%d", &inputpin);

                if (inputpin == pin) {
                    try_count = 0;

                    double mablagh;
                    printf("mablagh bardasht: ");
                    scanf("%lf", &mablagh);

                    if (mablagh <= mojoodi) {
                        mojoodi -= mablagh;

                        if (tarakonesh < 10)
                            tarikhche[tarakonesh++] = -mablagh;

                        printf("bardasht anjam shod\n");
                    } else {
                        printf("mojoodi kafi nist\n");
                    }
                } else {
                    try_count++;
                    printf("pin eshtebah (%d/3)\n", try_count);

                    if (try_count == 3) {
                        printf("3 bar ramz eshtebah! khorooj...\n");
                        return 0;
                    }
                }
            } else {
                printf("hesabi vojood nadarad\n");
            }
            break;

        case 4:
            if (flag == 1) {
                printf("enter pin: ");
                scanf("%d", &inputpin);

                if (inputpin == pin) {
                    try_count = 0;
                    printf("mojoodi: %.2lf\n", mojoodi);
                } else {
                    try_count++;
                    printf("pin eshtebah (%d/3)\n", try_count);

                    if (try_count == 3) {
                        printf("3 bar ramz eshtebah! khorooj...\n");
                        return 0;
                    }
                }
            } else {
                printf("hesabi vojood nadarad\n");
            }
            break;

        case 5:
            if (flag == 1) {
                printf("enter pin: ");
                scanf("%d", &inputpin);

if (inputpin == pin) {
                    try_count = 0;
                    for (int i = 0; i < tarakonesh; i++)
                        printf("%.2lf\n", tarikhche[i]);
                } else {
                    try_count++;
                    printf("pin eshtebah (%d/3)\n", try_count);

                    if (try_count == 3) {
                        printf("3 bar ramz eshtebah! khorooj...\n");
                        return 0;
                    }
                }
            } else {
                printf("hesabi vojood nadarad\n");
            }
            break;

        case 6:
            if (flag == 1) {
                printf("enter pin: ");
                scanf("%d", &inputpin);

                if (inputpin == pin) {
                    try_count = 0;
                    flag = 0;
                    mojoodi = 0;
                    tarakonesh = 0;
                    printf("hesab hazf shod\n");
                } else {
                    try_count++;
                    printf("pin eshtebah (%d/3)\n", try_count);

                    if (try_count == 3) {
                        printf("3 bar ramz eshtebah! khorooj...\n");
                        return 0;
                    }
                }
            } else {
                printf("hesabi vojood nadarad\n");
            }
            break;

        case 7:
            if (flag == 1) {
                printf("enter pin: ");
                scanf("%d", &inputpin);

                if (inputpin == pin) {
                    try_count = 0;
                    printf("pin jadid: ");
                    scanf("%d", &pin);
                } else {
                    try_count++;
                    printf("pin eshtebah (%d/3)\n", try_count);

                    if (try_count == 3) {
                        printf("3 bar ramz eshtebah! khorooj...\n");
                        return 0;
                    }
                }
            }
            break;

        case 0:
            printf("khorooj az barname\n");
            break;

        default:
            printf("gozine na motabar\n");
        }

    } while (choice != 0);

    return 0;
}