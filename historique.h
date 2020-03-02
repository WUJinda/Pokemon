#ifndef historique_h
#define historique_h


typedef struct Evolution{
	
	const char* from;
	const char* to; 
	Evolution* nextEvol;
} Evolution;


typedef struct {
	int nombre;
	Evolution* debut;
} Historique;



void insererTete(Historique* historique, const char* from,const char* to);
void afficherHistorique(Historique* historique);
#endif /* historique_h */ 

