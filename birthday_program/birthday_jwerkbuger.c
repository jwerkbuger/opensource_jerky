#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        int month = 0, day = 0;
        char name[20];
        char etc[100];

        switch (choice) {
        case 1:
            cnt++;

            printf("양식에 맞춰 입력해주세요.\n");
            printf("날짜(00/00) : ");
            scanf("%d/%d", &month, &day);
            fprintf(fp, "%d/%d ", month, day);

            printf("이름 : ");
            scanf("%s", name);
            fprintf(fp, "%s ", name);

            printf("기타(비고) : ");
            scanf("%s", etc);
            fprintf(fp, "%s\n", etc);

            printf("저장이 완료되었습니다.\n");
            break; 
        }
    } while (1);

    fclose(fp);
    return 0;
}
