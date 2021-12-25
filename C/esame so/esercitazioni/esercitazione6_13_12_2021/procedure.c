#include "header.h"



void inizializza(struct monitor* m)
{
	m->molo = 0;
	m->id_nave = 0;
    
    m->nscritt = 0;
    m->nlett = 0;
    m->nwaitscritt = 0;
    m->nwaitlett = 0;

    /* TODO: Inizializzare le variabili dell'algoritmo, il mutex, e le variabili condition */
    pthread_mutex_init(&m->mutex, NULL);
    pthread_cond_init(&m->cvlett, NULL);
    pthread_cond_init(&m->cvscritt, NULL);
}

void rimuovi (struct monitor* m)
{
    /* TODO: Disattivare mutex e variabili condition */
    pthread_mutex_destroy(&m->mutex);
    pthread_cond_destroy(&m->cvlett);
    pthread_cond_destroy(&m->cvscritt);
}


void inizio_scrittura(struct monitor* m)
{
    pthread_mutex_lock(&m->mutex);

    while(m->nlett > 0 || m->nscritt > 0){
        //printf("[DEBUG]: Lettura o scrittura in corso, scrittore in attesa\n");
        m->nwaitscritt++;
        pthread_cond_wait(&m->cvscritt, &m->mutex);
        //printf("[DEBUG]: Riattivazione scrittura\n");
        m->nwaitscritt--;
    }

    m->nscritt++;
    //printf("[DEBUG]: Scrittore aggiunto: %d\n", m->nscritt);

    pthread_mutex_unlock(&m->mutex);
}

void fine_scrittura(struct monitor* m)
{
    pthread_mutex_lock(&m->mutex);

    m->nscritt--;
    //printf("[DEBUG]: Scrittora rimosso: %d\n", m->nscritt);

    if(m->nwaitscritt > 0){ // se ci sono scrittori in attesa, segnalali
        //printf("[DEBUG]: Segnalazione scrittori in attesa");
        pthread_cond_signal(&m->cvscritt);
    }
    else{
        /* non vi sono rimasti scrittori, allora segnala i lettori.
        /* Essendo pthread intrinsecamente basato su monitor signal and continue, 
        /* allora segnala tutti i lettori in broadcast (sgnal all)
        */
        //printf("[DEBUG]: ")
        pthread_cond_broadcast(&m->cvlett);
    }

    pthread_mutex_unlock(&m->mutex);
}

//SCRITTURA. AGGIORNAMENTO DELLA POSIZIONE DEL TRENO
void scrivi_molo(struct monitor* m, int molo)
{
    inizio_scrittura(m);

    //SCRITTURA
    //sleep(1) // simulare operazione lenta
    m->molo = molo;
    printf("[SCRITTORE]: valore scritto: %d\n", m->molo);

    fine_scrittura(m);
}

void inizio_lettura(struct monitor* m)
{
    pthread_mutex_lock(&m->mutex);

    while(m->nscritt > 0){
        //p("[DEBUG]: Scrittura in corso, lettore in attesa\n");
        m->nwaitlett++;
        pthread_cond_wait(&m->cvlett, &m->mutex);
        //printf("[DEBUG]: Riattivazione lettura\n");
        m->nwaitlett--;
    }

    m->nlett++;
    printf("[DEBUG]: Lettore aggiunto: %d\n", m->nlett);

    pthread_mutex_unlock(&m->mutex);
}

void fine_lettura(struct monitor* m)
{
    pthread_mutex_lock(&m->mutex);

    m->nlett--;
    printf("[DEBUG]: Lettore rimosso: %d\n", m->nlett);

    if(m->nlett == 0){
        //printf("[DEBUG]: signal su scrittori");
        pthread_cond_signal(&m->cvscritt);
    }

    pthread_mutex_unlock(&m->mutex);
}

//LETTURA. RESTITUISCE LA POSIZIONE DEL TRENO
int leggi_molo(struct monitor* m)
{
    int molo;

    inizio_lettura(m);

    //LETTURA
    //sleep(2); //simulare operazione lenta
    molo = m->molo;
    printf("[LETTORE]: valore letto: %d\n", molo);

    fine_lettura(m);

    return molo;
}

