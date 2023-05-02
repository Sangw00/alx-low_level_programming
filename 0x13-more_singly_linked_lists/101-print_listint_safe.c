#include "lists.h"

/**
 * free_listp - function
 * @head: head of a list.
 *
 * Return: no return.
 * Description: frees a linked list
 */
void free_listp(listp_t **head)
{
listp_t *temp;
listp_t *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}

/**
 * print_listint_safe - function
 * @head: head of a list.
 *
 * Return: number of nodes in the list.
 * Description: prints a linked list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t nodes_ = 0;
listp_t *hptr, *new, *add;

hptr = NULL;
while (head != NULL)
{
new = malloc(sizeof(listp_t));

if (new == NULL)
exit(98);

new->p = (void *)head;
new->next = hptr;
hptr = new;

add = hptr;

while (add->next != NULL)
{
add = add->next;
if (head == add->p)
{
printf("-> [%p] %d\n", (void *)head, head->n);
free_listp(&hptr);
return (nodes_);
}
}

printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
nodes_++;
}

free_listp(&hptr);
return (nodes_);
}
