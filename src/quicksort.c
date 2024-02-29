/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:24:20 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/29 16:12:25 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static void swap(int *i, int *j)
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
		if (arr[j] < arr[p] && ++i != j)//don't increment everytime!!!
		{
			printf("swap\n");
			swap(&arr[i], &arr[j]);
		}

		j++;
	}
	i++;
	swap(&arr[i], &arr[r]);
	return (i);
}

void	quicksort(int *arr, int l, int r)
{
	int	p;

	/* printf("\033[31mquicksort\n\033[0m"); */
	if (l >= r)
		return ;
	p = partition(arr, l, r);
	quicksort(arr, l, p - 1);
	quicksort(arr, p, r);
}
#include <ctype.h>
int main(int ac, char *av[])
{
	(void)ac;
	int i = 0;
	int j = 0;
	int arr[500];
	while (av[1][i])
	{
		arr[j] = atoi(&av[1][i]);
		while (av[1][i] && isdigit(av[1][i]))
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
	return (0);
}
