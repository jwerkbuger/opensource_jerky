#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        char search[10];

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
        case 2:
            printf("�����Ͻ� ���(�߰�/�̸�/��¥) Ȥ�� �̸��� �Է����ּ���.\n");
            scanf("%s", search);
            if (search == "�߰�") {
                printf("���� ����� �߰������� ����մϴ�.\n");
                for (int i = 0; i < cnt; i++) {
                    printf("%02d/%02d %s %s\n", people[cnt].month, people[cnt].day, people[cnt].name, people[cnt].etc);
                }
            }
            else if (search == "�̸�") {
                printf("���� ����� �̸������� ����մϴ�.\n");
                qsort(people, cnt, sizeof(struct person), compare_name);
                for (int i = 0; i < cnt; i++) {
                    printf("%02d/%02d %s %s\n", people[cnt].month, people[cnt].day, people[cnt].name, people[cnt].etc);
                }
            }
            else if (search == "��¥") {
                printf("���� ����� ��¥������ ����մϴ�.\n");
                qsort(people, cnt, sizeof(struct person), compare_date);
                for (int i = 0; i < cnt; i++) {
                    printf("%02d/%02d %s %s\n", people[cnt].month, people[cnt].day, people[cnt].name, people[cnt].etc);
                }
            }

            break;
        case 3:
            printf("���� ����� ���� �������� �ʽ��ϴ�.\n");
            break;
        }
    } while (1);

    fclose(fp);
    return 0;
}
