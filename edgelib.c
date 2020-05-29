#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "edgelib.h"

void printList(edge* L) {
    if (L != NULL) {
        printf("%d costo:%d distanza:%d -> ", L->key, L->pesoEconomy, L->pesoDistanza);
        printList(L->next);
    }
}


edge* checkListRemoval(edge* L, int node_to_remove) {
    if (L != NULL) {
        L->next = checkListRemoval(L->next, node_to_remove);
        if (L->key == node_to_remove) {
            edge* tmp = L->next;
            free(L);
            return tmp;
        }
        else if (L->key > node_to_remove) {
            L->key -= 1;
        }
    }
    return L;
}

edge* initNodeList(int info, int eco, int dist) {
    edge* L = (edge*)malloc(sizeof(edge));
    L->key = info;
    L->pesoEconomy = eco;
    L->pesoDistanza = dist;
    L->next = NULL;
    return L;
}


edge* randomList(int index, int mod) {
    edge* L = NULL;
    int i = 0;
    for (i = 0; i < index; i++) {
        L = appendNodeList(L, rand() % mod, rand() % mod, rand() % mod);
    }
    return L;
}


edge* appendNodeList(edge* L, int target, int eco, int dist) {
    if (L != NULL) {
        if (L->key != target) {
            L->next = appendNodeList(L->next, target, eco, dist);
        }
    }
    else {
        L = initNodeList(target, eco, dist);
    }
    return L;
}


edge* addNodeHead(edge* L, int target, int eco, int dist) {
    if (L != NULL) {
        edge* G = (edge*)malloc(sizeof(edge));
        G->key = target;
        L->pesoEconomy = eco;
        L->pesoDistanza = dist;
        G->next = L;
        return G;
    }
    return initNodeList(target, eco, dist);
}


edge* removeNodeList(edge* L, int target) {
    if (L != NULL) {
        if (L->key == target) {
            edge* tmp = L->next;
            free(L);
            return tmp;
        }
        L->next = removeNodeList(L->next, target);
    }
    return L;
}


void freeList(edge* L) {
    if (L != NULL) {
        freeList(L->next);
        free(L);
    }
}


int DimLista(edge* L) {
    if (L == NULL)
        return 0;
    return 1 + DimLista(L->next);
}