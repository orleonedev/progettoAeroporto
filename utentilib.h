#ifndef utentilib
#define utentilib
#include "prenotazionilib.h"    //libreria delle prenotazioni
#include "definers.h"           //libreria delle costanti definite

//definizione struttura ABR Utenti
typedef struct nodo_utente {
    char nomeUtente[maxstring];         //chiave stringa del nodo utente
    int pswd;            //password dell'utente
    prenotazione* prenotazioniUtente;   //puntatore alla lista prenotazioni 

    //puntatori ai sottoalberi destro e sinistro
    struct nodo_utente* sx;
    struct nodo_utente* dx;
} Utente;

//funzione aggiunta nodo utente nell'ABR utenti
void addNodoUtente(Utente** radUtente, char* nome, int password);

//funzione di rimozione nodo utente nell'ABR utenti
void eliminaNodoUtente(Utente** radUtente, char* nome);

//funzione di ricerca del minimo nodo dell'ABR utenti (ordinamento alfanumerico ASCII)
char* ricercaMinUtente(Utente* radUtente);

//funzione di ricerca utente, restituzione booleano
int ricercaUtente(Utente* radUtente, char* nome);

//funzione di ricerca utente, con riferimento all'utente
Utente* referenceUtente(Utente* radUtente, char* nome);

//funzione visita in Preordine ABR utenti
void visitaInPreOrdineUtenti(Utente* radUtente);


#endif