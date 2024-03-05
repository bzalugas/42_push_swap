/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_quicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:50:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/05 10:53:18 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void int_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	display_arr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

static int	partition(int *arr, int l, int r)
{
	int	p;
	int	i;
	int	j;

	/* printf("partition\n"); */
	p = r;
	i = l - 1;
	j = l;
	while (j < r)
	{
		if (arr[j] < arr[p])
		{
			i++;
			printf("swap\n");
			if (i != j)
				int_swap(&arr[i], &arr[j]);
		}

		j++;
	}
	i++;
	int_swap(&arr[i], &arr[r]);
	return (i);
}

void	quicksort(int *arr, int l, int r)
{
	int	p;

	/* printf("\033[31mquicksort\n\033[0m"); */
	if (l >= r || l < 0)
		return ;
	p = partition(arr, l, r);
	quicksort(arr, l, p - 1);
	quicksort(arr, p + 1, r);
}
#include <ctype.h>

int check(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char *av[])
{
	(void)ac;
	int i = 0;
	int j = 0;
	int arr[500];
	while (av[1][i] && j < 500)
	{
		arr[j] = atoi(&av[1][i]);
		while (av[1][i] && (isdigit(av[1][i]) || av[1][i] == '-'))
			i++;
		i++;
		j++;
	}
	/* int	arr[] = {5, -12, 8, 23, -58, 26, 2}; */
	int	len = sizeof(arr) / sizeof(int);
	/* printf("Before : "); */
	/* display_arr(arr, len); */
	quicksort(&arr[0], 0, len - 1);
	/* printf("After : "); */
	/* display_arr(arr, len); */
	/* if (check(arr, len)) */
	/* 	printf("\n\nOK\n"); */
	/* else */
	/* 	printf("\n\nKO\n"); */
	return (0);
}
