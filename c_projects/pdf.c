#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <cs50.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;
#define list_size 2

bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;
    for (int i = 0; i < list_size; i++)
    {
        string phrase = get_string ("get the phrase: ");
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return 1;
        }
        n -> phrase = phrase;
        n -> next = NULL;
        n -> next = list;
        list = n;
        visualizer(list);
    }
    if(!unload(list))
    {
        printf("error");
        return 1;
    }
    printf("freed the list");
    return 0;

}

bool unload(node *list)
{
    node* ptr = list;
    while(ptr != NULL)
    {
        ptr = list-> next;
        free(list);
        list = ptr; 
    }
    return true;
}
void visualizer(node *list)
{

}
