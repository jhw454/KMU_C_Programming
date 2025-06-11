#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum drink_type {
    Sparkling,
    Alcohol,
    Water,
    Juice
}Drink_type;

typedef enum drink_brand {
    CoCa,
    Asahi,
    Evian,
    Capri,
    Starbucks
}Drink_brand;

typedef struct drink
{
    char name[20];
    int pirce;
    Drink_type type;
    Drink_brand brand;
}Drink;


classifiy_for_price(Drink drink[], int size);
classifiy_for_type(Drink drink[], int size, char type_list);
classifiy_for_brand(Drink drink[], int size, char brand_list);
void hold_state();

int main() 
{
    Drink drink_list[] = { {"코카콜라", 1700, Sparkling, 0}, {"스프라이트", 1500, Sparkling, 0}, {"커피", 1500, Water, 4}, {"생수", 800, Water, 2}, {"주스", 1700, Juice, 3}, {"Asahi Beer", 4500, Alcohol, 1} };
    char* type_list[] = { "Sparkling", "Alcohol", "Water", "Juice" };
    char* brand_list[] = { "CoCa", "Asahi", "Evian", "Capri", "Starbucks"};
    int choice = 0;
    int DRINK_COUNT = sizeof(drink_list) / sizeof(drink_list[0]);
    
    while (1)
    {
        system("cls");

        for (int i = 0; i < DRINK_COUNT; i++) {
            printf("%d. %s - %d원\n", i + 1, drink_list[i].name, drink_list[i].pirce);
        }

        printf("\n=== 위 음료를 다음과 같이 정리를 도와드립니다 ===\n");
        printf("1. 가격별로 음료 정리\n");
        printf("2. 종류별로 음료 정리\n");
        printf("3. 제조사별로 음료 정리\n");
        printf("4. 종료");

        printf("\n번호를 선택하세요: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1) 
        {
            classifiy_for_price(drink_list, DRINK_COUNT);
        }
        else if (choice == 2)
        {
            classifiy_for_type(drink_list, DRINK_COUNT, type_list);
        }
        else if (choice == 3)
        {
            classifiy_for_brand(drink_list, DRINK_COUNT, type_list);
        }
        else if (choice == 4)
        {
            printf("프로그램을 종료합니다.");
            break;
        }
        else 
        {
            printf("\n잘못된 번호를 선택하셨습니다.\n");
        }
    }


    return 0;
}

classifiy_for_price(Drink drink[], int size)
{
    printf("[가격대별 음료 분류]\n");
    printf("▶ 1000원 미만\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].pirce < 1000)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("\n▶ 1000원 ~ 2500원 미만\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].pirce >= 1000 && drink[i].pirce < 2500)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("\n▶ 2500원 이상\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].pirce > 2500)
        {
            printf("%s\n", drink[i].name);
        }
    }

    hold_state();
}

classifiy_for_type(Drink drink[], int size, char type_list)
{
    printf("[종류별 음료 분류]\n");

    printf("▶ Sparkling\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 0)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Alcohol\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 1)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Water\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 2)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Juice\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 3)
        {
            printf("%s\n", drink[i].name);
        }
    }

    hold_state();
}

classifiy_for_brand(Drink drink[], int size, char brand_list)
{
    printf("[브랜드별 음료 분류]\n");
    printf("▶ CoCa\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 0)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Ashahi\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 1)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Evian\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 2)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Capri\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 3)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("▶ Starbucks\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 4)
        {
            printf("%s\n", drink[i].name);
        }
    }

    hold_state();
}

void hold_state() {
    printf("계속 하려면 아무 키나 입력하세요...\n");
    _getch();
}