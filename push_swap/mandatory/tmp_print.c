#include "../includes/push_swap.h"

void	tmp_print(t_info *i, char *command)
{
	t_stack *next;
	next = i->a_head;
	if (command)
		printf("%s\n", command);
	printf("a:");
	while (next)
	{
		printf("[%d]", next->cc);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = i->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->cc);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}

// void	tmp_print(t_info *i, char *command)
// {
// 	(void)i;
// 	(void)command;
// }

void	tmp_print_lis(t_info *i)
{
	t_stack *next;
	next = i->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->cycle);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = i->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->cycle);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}

void	tmp_print_booll(t_info *i)
{
	t_stack *next;
	next = i->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->part_of_lis != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = i->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->part_of_lis != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}


void	tmp_print_cycles(t_info *i)
{
	t_stack *next;
	next = i->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->no_lis_cc);
		next = next->next;
	}
	printf("\n");
	next = i->b_head;
	printf("cycle:%d\n", next->cycle);
	int first_cycle = next->cycle;
	printf("b:");
	while (next)
	{
		if (next->cycle < first_cycle)
		{
			first_cycle = next->cycle;
			printf(" | ");
		}
		printf("[%d]", next->no_lis_cc);
		next = next->next;
	}
	printf("\n------------------------------\n");
}
