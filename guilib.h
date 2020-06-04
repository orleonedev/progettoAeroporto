#ifndef gui
#define gui
#include "definers.h"
#include "utentilib.h"
#include "graphlib.h"
#include "Dijkstra.h"

//Pulisce l'output
void clrscr();

//funzione per ottenere le richieste di un singolo carattere in input
char catchRequest();

//funzione per ottenere le stringhe in input
char* getString();

//men� dell'admin
void menuAdmin(Utente* radUtente, Graph G, list** destinazioni);

//men� dell'utente
void menuUtente(Utente* User, Graph G, list* destinazioni);

//restituisce il nodo con distanza minore
int metaEconomica(int d[], int dim, int source);

//funzione per la creazione di una prenotazione
void catchPrenotazione(Utente* User, Graph G, list* destinazioni);

#endif

