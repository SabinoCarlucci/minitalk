script funzionano scriverndo ./nomedelloscript <pid> -m

cose da fare:

1) come faccio a verificare che il pid usato nel client e' corretto?
	mando un segnale dal client al server, e se la funzione restituisce numero positivo, allora il pid e' corretto.
	vedi "man 3 kill"
	problema: devo usare per forza uno dei due segnali ammessi, e quindi devo fare in modo che il server ignori il primo segnale che riceve ad ogni messaggio.
	so avendo difficolta' a farlo funzionare
	forse dovrei usare un'altra funzione che intercetta il segnale e, se la variabbile globale e' a 0, la setta a uno e basta.
	se invece la vairiabile globale e' a uno, allora chiama l'altra funzione che decodifica i segnali.

2) aggiustare la funzione che manda i messaggi di errore nel client

3) caricare tutto su github
