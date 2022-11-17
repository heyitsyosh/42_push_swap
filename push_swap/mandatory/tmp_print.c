#include "../includes/push_swap.h"

void	tmp_print(t_save *s, char *command)
{
	t_stack *next;
	next = s->a_head;
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
	next = s->b_head;
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

// void	tmp_print(t_save *s, char *command)
// {
// 	(void)s;
// 	(void)command;
// }

void	tmp_print_lis(t_save *s)
{
	t_stack *next;
	next = s->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->i_s_len);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = s->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->i_s_len);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}

void	tmp_print_booll(t_save *s)
{
	t_stack *next;
	next = s->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->part_of_lis != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = s->b_head;
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


void	tmp_print_bool(t_save *s)
{
	t_stack *next;
	next = s->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->to_push != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = s->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->to_push != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}
