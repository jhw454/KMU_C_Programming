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
    Drink drink_list[] = { {"��ī�ݶ�", 1700, Sparkling, 0}, {"��������Ʈ", 1500, Sparkling, 0}, {"Ŀ��", 1500, Water, 4}, {"����", 800, Water, 2}, {"�ֽ�", 1700, Juice, 3}, {"Asahi Beer", 4500, Alcohol, 1} };
    char* type_list[] = { "Sparkling", "Alcohol", "Water", "Juice" };
    char* brand_list[] = { "CoCa", "Asahi", "Evian", "Capri", "Starbucks"};
    int choice = 0;
    int DRINK_COUNT = sizeof(drink_list) / sizeof(drink_list[0]);
    
    while (1)
    {
        system("cls");

        for (int i = 0; i < DRINK_COUNT; i++) {
            printf("%d. %s - %d��\n", i + 1, drink_list[i].name, drink_list[i].pirce);
        }

        printf("\n=== �� ���Ḧ ������ ���� ������ ���͵帳�ϴ� ===\n");
        printf("1. ���ݺ��� ���� ����\n");
        printf("2. �������� ���� ����\n");
        printf("3. �����纰�� ���� ����\n");
        printf("4. ����");

        printf("\n��ȣ�� �����ϼ���: ");
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
            printf("���α׷��� �����մϴ�.");
            break;
        }
        else 
        {
            printf("\n�߸��� ��ȣ�� �����ϼ̽��ϴ�.\n");
        }
    }


    return 0;
}

classifiy_for_price(Drink drink[], int size)
{
    printf("[���ݴ뺰 ���� �з�]\n");
    printf("�� 1000�� �̸�\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].pirce < 1000)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("\n�� 1000�� ~ 2500�� �̸�\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].pirce >= 1000 && drink[i].pirce < 2500)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("\n�� 2500�� �̻�\n");
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
    printf("[������ ���� �з�]\n");

    printf("�� Sparkling\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 0)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Alcohol\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 1)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Water\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].type == 2)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Juice\n");
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
    printf("[�귣�庰 ���� �з�]\n");
    printf("�� CoCa\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 0)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Ashahi\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 1)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Evian\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 2)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Capri\n");
    for (int i = 0; i < size; i++)
    {
        if (drink[i].brand == 3)
        {
            printf("%s\n", drink[i].name);
        }
    }

    printf("�� Starbucks\n");
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
    printf("��� �Ϸ��� �ƹ� Ű�� �Է��ϼ���...\n");
    _getch();
}