#include <stdio.h>
#include <string.h>

#define maxSubscribers 1

struct abonent
{
    char name[32];
    char second_name[32];
    char tel[11];
};

struct abonent subscribers[maxSubscribers];

int findEmptyIndex()
{
    for (int i = 0; i < maxSubscribers; i++)
    {
        if (strlen(subscribers[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void addSubscriber()
{
    int index = findEmptyIndex();
    if (index != -1)
    {
        printf("\nenter name, last name and phone number separated by a SPACE:\n");
        scanf("%s", subscribers[index].name);
        scanf("%s", subscribers[index].second_name);
        scanf("%s", subscribers[index].tel);
    }
    else
    {
        printf("Directory is full. Cannot add more subscribers.\n");
    }
}

void deleteSubscriber()
{
    char nameToDelete[32];

    printf("Enter the name of the subscriber to delete: ");
    scanf("%s", nameToDelete);

    for (int i = 0; i < maxSubscribers; i++)
    {
        if (strcmp(subscribers[i].name, nameToDelete) == 0)
        {
            memset(&subscribers[i], 0, sizeof(struct abonent));
        }
    }
}

void searchSubscriber()
{
    char nameToSearch[32];

    printf("Enter the name of the subscriber to search: ");
    scanf("%s", nameToSearch);

    for (int i = 0; i < maxSubscribers; i++)
    {
        if (strcmp(subscribers[i].name, nameToSearch) == 0)
        {
            printf("\n%s %s %s\n", subscribers[i].name, subscribers[i].second_name, subscribers[i].tel);
        }
    }
}

void printAllSubscribers()
{
    for (int i = 0; i < maxSubscribers; i++)
    {
        if (strlen(subscribers[i].name) != 0)
        {
            printf("\t%s\t%s\t%s\t%s\t%s\t%s", "name", "last name", "telephone\n", subscribers[i].name, subscribers[i].second_name, subscribers[i].tel);
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu:\n1) Add a subscriber\n2) Delete a subscriber\n3) Search for subscribers by name\n4) Output all records\n5) Exit\n\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSubscriber();
            break;

        case 2:
            deleteSubscriber();
            break;

        case 3:
            searchSubscriber();
            break;

        case 4:
            printAllSubscribers();
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
