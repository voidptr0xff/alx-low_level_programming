#include "lists.h"

/**
  * print_list - prints nodes of a linked list.
  *
  *@h: a pointer to a linked list to be printed.
  *
  *Return: Returns number of nodes.
  */
size_t print_list(const list_t *h)
{
	size_t len = 0;

	len = 0;
	while (h != NULL)
	{
		if (h->str != NULL)
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}
		h = h->next;
		len++;
	}
	return (len);
}
