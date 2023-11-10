#include <stdio.h>
#define INT_SIZE sizeof(int) * 8 /* Размер в битах */

int num, index, i;
int bin[INT_SIZE];

int convert_binary()
{
    printf("\nEnter any number: ");
    scanf("%d", &num);

    index = INT_SIZE - 1;

    while (index >= 0)
    {
        bin[index] = num & 1;
        index--;
        num >>= 1;
    }

    printf("\nConverted binary: ");
    for (i = 0; i < INT_SIZE; i++)
    {
        printf("%d", bin[i]);
    }

    return 0;
};

int binary_count_ones()
{
    int count_one = 0;
    convert_binary();

    for (i = 0; i < INT_SIZE; i++)
    {
        if (bin[i])
        {
            count_one++;
        }
    };
    printf("\n\nCount of number: ");
    printf("%d", count_one);
    return 0;
};

int binary_third_bit()
{
    int third_bit;

    convert_binary();

    printf("\n\nEnter 1 or 0 value: ");
    scanf("%i", &third_bit);

    if (third_bit != 1 & third_bit != 0)
    {
        printf("bit value 1 or 0, goodbye\n");
        return 0;
    }

    printf("\nThird bit of binary: ");

    for (i = 0; i < INT_SIZE; i++)
    {
        // 29 бит, т.к. у меня отсчет идет с левой стороны
        bin[29] = third_bit;
        printf("%i", bin[i]);
    }

    return 0;
};

int main()
{

    // 1. Вывести двоичное представление целого положительного числа,
    // используя битовые операции (число вводится с клавиатуры).

    // 2. Вывести двоичное представление целого отрицательного числа,
    // используя битовые операции (число вводится с клавиатуры).

    // 3. Найти количество единиц в двоичном представлении целого
    // положительного числа (число вводится с клавиатуры).

    // 4. Поменять в целом положительном числе (типа int) значение третьего
    // бита на введенное пользователем число (изначальное число также
    // вводится с клавиатуры).

    int task_num;

    printf("Select task from 1-3: ");
    scanf("%d", &task_num);

    switch (task_num)
    {
    case 1:
        // Объеденены 1 и 2 задание
        convert_binary();
        break;

    case 2:
        binary_count_ones();
        break;

    case 3:
        binary_third_bit();
        break;

    default:
        printf("Task number %u not found\n", task_num);
    }
    return 0;
}