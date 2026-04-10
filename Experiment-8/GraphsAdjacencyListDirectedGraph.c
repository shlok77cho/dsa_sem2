#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int vertex;
    struct node* next;
};

typedef struct node* GNODE;

GNODE graph[MAX] = {NULL};

void print(int *N) {
    for (int i = 1; i <= *N; i++) {
        if (graph[i] != NULL) {
            printf("%d=>", i);

            GNODE p = graph[i];
            while (p != NULL) {
                printf("%d\t", p->vertex);
                p = p->next;
            }
            printf("\n");
        }
    }
}

void insertVertex(int *N) {
    int inEdges, outEdges, s, d;

    (*N)++;
    int newV = *N;

    scanf("%d", &inEdges);
    for (int i = 0; i < inEdges; i++) {
        scanf("%d", &s);
        if (s <= 0 || s >= newV) {
            printf("Invalid vertex.\n");
            continue;
        }

        GNODE q = (GNODE)malloc(sizeof(struct node));
        q->vertex = newV;
        q->next = NULL;

        if (graph[s] == NULL)
            graph[s] = q;
        else {
            GNODE p = graph[s];
            while (p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    scanf("%d", &outEdges);
    for (int i = 0; i < outEdges; i++) {
        scanf("%d", &d);
        if (d <= 0 || d >= newV) {
            printf("Invalid vertex.\n");
            continue;
        }

        GNODE q = (GNODE)malloc(sizeof(struct node));
        q->vertex = d;
        q->next = NULL;

        if (graph[newV] == NULL)
            graph[newV] = q;
        else {
            GNODE p = graph[newV];
            while (p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}

void insertEdge(int *N) {
    int s, d;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &s);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &d);

    if (s <= 0 || d <= 0 || s > *N || d > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE q = (GNODE)malloc(sizeof(struct node));
    q->vertex = d;
    q->next = NULL;

    if (graph[s] == NULL)
        graph[s] = q;
    else {
        GNODE p = graph[s];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}

void deleteEdge(int *N) {
    int s, d;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &s);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &d);

    if (s <= 0 || s > *N) return;

    GNODE p = graph[s], prev = NULL;

    while (p != NULL) {
        if (p->vertex == d) {
            if (prev == NULL)
                graph[s] = p->next;
            else
                prev->next = p->next;

            free(p);
            break;
        }
        prev = p;
        p = p->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}

void deleteVertex(int *N) {
    int v;

    if (*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (v <= 0 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE p = graph[v];
    while (p != NULL) {
        GNODE temp = p;
        p = p->next;
        free(temp);
    }
    graph[v] = NULL;

    for (int i = 1; i <= *N; i++) {
        GNODE curr = graph[i], prev = NULL;

        while (curr != NULL) {
            if (curr->vertex == v) {
                if (prev == NULL)
                    graph[i] = curr->next;
                else
                    prev->next = curr->next;

                free(curr);

                if (prev == NULL)
                    curr = graph[i];
                else
                    curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}
