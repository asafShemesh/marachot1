#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include <string.h>
#include <ctype.h>

int V;
int C;

int main()
{
    printf("Enter the number of Rows: ");
    scanf("%d", &V);
    printf("Enter the number of Columns: ");
    scanf("%d", &C);

    if (V != C)
    {
        printf("INVALID rows and col, they must be equal \n");
        exit(EXIT_FAILURE);
    }

    while (getchar() != '\n');

    int(*graph)[V] = malloc(V * sizeof(*graph));
    if (!graph)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the adjacency matrix for the graph:\n");
    char input[1024];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (token == NULL || isspace((unsigned char)*token))
            {
                printf("Not enough numbers provided in the input.\n");
                free(graph);
                exit(EXIT_FAILURE);
            }
            int value = atoi(token);
            if (value < 0)
            {
                printf("Invalid input or negative weights.\n");
                free(graph);
                exit(EXIT_FAILURE);
            }
            graph[i][j] = value;
            token = strtok(NULL, " ");
        }
    }

    if (token != NULL && !isspace((unsigned char)*token))
    {
        printf("Too many numbers provided in the input.\n");
        free(graph);
        exit(EXIT_FAILURE);
    }

    int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    if (scanf("%d", &source) != 1 || source < 0 || source >= V)
    {
        fprintf(stderr, "Invalid source vertex.\n");
        free(graph);
        exit(EXIT_FAILURE);
    }

    dijkstra(graph, source);

    free(graph);

    return 0;
}