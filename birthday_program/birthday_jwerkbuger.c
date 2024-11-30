#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // ���� ����

// ���� �Լ� ����
struct person {
    int month;
    int day;
    char name[20];
    char etc[100];
};
int compare_name(const void* a, const void* b) {
    struct person* personA = (struct person*)a;
    struct person* personB = (struct person*)b;
    return strcmp(personA->name, personB->name);
}
int compare_date(const void* a, const void* b) {
    struct person* personA = (struct person*)a;
    struct person* personB = (struct person*)b;

    // ��
    if (personA->month != personB->month) {
        return personA->month - personB->month;
    }
    // ��
    return personA->day - personB->day;
}

// �⺻ �Է� ����
int main() {
    FILE* fp;
    fp = fopen("birthday_list.txt", "a+");
    if (fp == NULL) {
        perror("���� ���� ����");
        exit(1);
    }

    struct person people[MAX];
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

        switch (choice) {
        case 1:
            if (cnt >= MAX) {
                printf("���� �ʰ� �Դϴ�.\n");
                break;
            }

            printf("��Ŀ� ���� �Է����ּ���.\n");
            printf("��¥(00/00) : ");
            scanf("%d/%d", &people[cnt].month, &people[cnt].day);

            printf("�̸� : ");
            scanf("%s", people[cnt].name);

            printf("��Ÿ(���) : ");
            scanf("%s", people[cnt].etc);
            fprintf(fp, "%d/%d %s %s\n", people[cnt].month, people[cnt].day, people[cnt].name, people[cnt].etc);

            printf("������ �Ϸ�Ǿ����ϴ�.\n");
            cnt++;
            break; 
        }
    } while (1);

    fclose(fp);
    return 0;
}
