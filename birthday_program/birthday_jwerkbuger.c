#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �⺻ �Է� ����
int main() {
    FILE* fp;
    fp = fopen("birthday_list.txt", "a+");
    if (fp == NULL) {
        perror("���� ���� ����");
        exit(1);
    }

    int cnt = 0;
    do {
        int choice = 0;

        printf("�޴��� �����ϼ���.\n");
        printf("1) ���� �߰�    2) ���� ��ȸ    3) ����    4) ����: ");
        scanf("%d", &choice);
        getchar(); // �Է� ���� ����
        if (choice == 4) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        int month = 0, day = 0;
        char name[20];
        char etc[100];

        switch (choice) {
        case 1:
            cnt++;

            printf("��Ŀ� ���� �Է����ּ���.\n");
            printf("��¥(00/00) : ");
            scanf("%d/%d", &month, &day);
            fprintf(fp, "%d/%d ", month, day);

            printf("�̸� : ");
            scanf("%s", name);
            fprintf(fp, "%s ", name);

            printf("��Ÿ(���) : ");
            scanf("%s", etc);
            fprintf(fp, "%s\n", etc);

            printf("������ �Ϸ�Ǿ����ϴ�.\n");
            break; 
        }
    } while (1);

    fclose(fp);
    return 0;
}