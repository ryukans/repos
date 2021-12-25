#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "auth.h"

void Server(int id_coda_elab_req, int id_coda_elab_resp, int id_coda_auth_req, int id_coda_auth_resp) {

    RichiestaAuth msg_auth_req;
    RispostaAuth msg_auth_resp;
    RichiestaElab msg_elab_req;
    RispostaElab msg_elab_resp;

    int ret;

    int risorsa = 0;


    for(int i = 0; i < 10; i++){
 
       printf("Server: in attesa di richieste\n");

        /* TBD: Ricezione messaggi di richiesta elaborazione */
        ret = msgrcv(id_coda_elab_req, (void*)&msg_elab_req, MSGSZ(RichiestaElab), ELAB_REQ_TYPE, 0);

        int valore = msg_elab_req.valore;
        int PIDclient = msg_elab_req.PID;
        int token = msg_elab_req.token;

        printf("Server: ricevuta richiesta %d da %d (token=%d)\n", valore, PIDclient, token);


        printf("Server: invio conferma autenticazione\n");

        /* TBD: Invio messaggio di richiesta conferma autenticazione */
        msg_auth_req.type = CONFERMA_AUTH_REQ_TYPE;
        msg_auth_req.PIDclient = PIDclient;
        msg_auth_req.PIDserver = getpid();
        msg_auth_req.token = token;
        ret = msgsnd(id_coda_auth_req, (void*)&msg_auth_req, MSGSZ(RichiestaAuth), 0);

        printf("Server: in attesa di conferma\n");

        /* TBD: Ricezione messaggio di risposta conferma autenticazione */ 
		ret = msgrcv(id_coda_auth_resp, (void*)&msg_auth_resp, MSGSZ(RispostaAuth), getpid(), 0);
	
        int esito;

        if(msg_auth_resp.esito == 1) {

            printf("Server: autenticazione del client %d riuscita\n", PIDclient);

            risorsa = valore;

            printf("Server: nuovo valore risorsa = %d\n", risorsa);

            esito = 1;
        }
        else {

            printf("Server: autenticazione del client %d fallita\n", PIDclient);
 
            esito = 0;
        }

        printf("Server: invio risposta al client\n");

        /* TBD: Invio messaggio di risposta elaborazione, con esito positivo o negativo */
        msg_elab_resp.type = PIDclient;
        msg_elab_resp.esito = esito;
        ret = msgsnd(id_coda_elab_resp, (void*)&msg_elab_resp, MSGSZ(RispostaElab), 0);


    }

}
