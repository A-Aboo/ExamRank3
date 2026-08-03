#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct s_city
{
	float x;
	float y;
}	t_city;

/*
** You must implement this function
** It should return the Euclidean distance between 2 cities
*/
float	distance(t_city a, t_city b){
	float dx , dy ;
	dx = b.x - a.x;
	dy = b.y - a.y;
	return sqrtf(dx *dx + dy *dy);
}

/*
** You must implement this function
** It should compute total distance of the path
** including the return to the starting city
*/
float	total_distance(t_city *cities, int *path, int n){
	float total = 0 ;
	int i = 0;
	while (i < n - 1){
		total += distance(cities[path[i]] , cities[path[i +1]]);
		i++;
	}
	total += distance(cities[path[n - 1]] , cities[path[0]]);
	return total;
}



void swap ( int *a , int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
** You must implement this function
** Use backtracking to try all permutations
*/
void	solve(t_city *cities, int *path, int n, int pos, float *min){
	float current;
	if (pos == n){
		current = total_distance(cities , path  , n);
		if (current < *min)
			*min =current;
		return;
	}
	int i =pos;
	while (i  <pos){
		swap(&path[pos] , &path[i]);
		solve ( cities , path , n , pos +1 , min);
		swap(&path[pos] , &path[i]);
		i++;
	}

}

int	main(void)
{
	t_city	cities[11];
	int		n = 0;

	// Read input from stdin
	while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;

	// If less than 2 cities → distance = 0
	if (n < 2)
	{
		printf("0.00\n");
		return (0);
	}

	// Initialize path: [0,1,2,...]
	int path[11];
	for (int i = 0; i < n; i++)
		path[i] = i;

	float min = FLT_MAX;

	/*
	** Optimization:
	** Fix first city → start from pos = 1
	*/
	solve(cities, path, n, 1, &min);

	printf("%.2f\n", min);
	return (0);
}