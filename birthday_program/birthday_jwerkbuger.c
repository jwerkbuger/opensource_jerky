#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // 임의 선정

// 정렬 함수 제작
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

    // 월
    if (personA->month != personB->month) {
        return personA->month - personB->month;
    }
    // 일
    return personA->day - personB->day;
}

// 기본 입력 제작
int main() {
    FILE* fp;
    fp = fopen("birthday_list.txt", "a+");
    if (fp == NULL) {
        perror("파일 열기 실패");
        exit(1);
    }

    struct person people[MAX];
    int cnt = 0;
    do {
        int choice = 0;

        printf("메뉴를 선택하세요.\n");
        printf("1) 생일 추가    2) 생일 조회    3) 수정    4) 종료: ");
        scanf("%d", &choice);
        getchar(); // 입력 버퍼 비우기
        if (choice == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        switch (choice) {
        case 1:
            if (cnt >= MAX) {
                printf("정원 초과 입니다.\n");
                break;
            }

            printf("양식에 맞춰 입력해주세요.\n");
            printf("날짜(00/00) : ");
            scanf("%d/%d", &people[cnt].month, &people[cnt].day);

            printf("이름 : ");
            scanf("%s", people[cnt].name);

            printf("기타(비고) : ");
            scanf("%s", people[cnt].etc);
            fprintf(fp, "%d/%d %s %s\n", people[cnt].month, people[cnt].day, people[cnt].name, people[cnt].etc);

            printf("저장이 완료되었습니다.\n");
            cnt++;
            break; 
        }
    } while (1);

    fclose(fp);
    return 0;
}
