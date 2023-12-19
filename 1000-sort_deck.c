#include "deck.h"
#include <string.h>

/**
 * compare_cards - compare function using qsort algo
 * @a: pointer to the first card
 * @b: ointer to the second card
 *
 * Return: Integer less than, equal to, or greater than zero
 */
static int compare_cards(const void *a, const void *b);
static int compare_cards(const void *a, const void *b)
{
	char *card_values[] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	int card_num_value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13};
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	int value_a, value_b, i;


	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	for (i = 0; i < 13; i++)
	{
		if (strcmp(node_a->card->value, card_values[i]) == 0)
			value_a = card_num_value[i];
		if (strcmp(node_b->card->value, card_values[i]) == 0)
			value_b = card_num_value[i];
	}

	return (value_a - value_b);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t count = 0, i;
	deck_node_t *current = *deck;
	deck_node_t **array;

	while (current)
	{
		count++;
		current = current->next;
	}

	array = malloc(count * sizeof(deck_node_t *));
	if (!array)
		return;

	current = *deck;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}

	qsort(array, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count - 1; i++)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}
	array[0]->prev = NULL;
	array[count - 1]->next = NULL;

	*deck = array[0];

	free(array);
}

