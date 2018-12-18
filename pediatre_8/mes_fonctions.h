struct date 
{int jour ;
int mois ; 
int annee;
};
typedef struct date DATE ;
struct horaire 
{int heure;
int minute;
};
typedef struct horaire HORAIRE;
struct information
{int poids ;
float taille;
};
typedef struct information INFO ;

struct rendez_vous
{ DATE date_rendez_vous;
HORAIRE horaire_rendez_vous;
};
typedef struct rendez_vous RDV;
struct patient 
{ int numero_dossier ;
char nom [50];
char prenom [50];
DATE date_naissance;
char adresse [50];
int nb_mesures;
float* mesures;
RDV rdv;
INFO info;
};
typedef patient PATIENT ;
int saisir();
void allouer (float** ,int );
void remplir_tab(float*, int);

void afficher_tab(float*,int);
PATIENT remplir_patient();
void afficher_patient(PATIENT);
void allouer_patient (PATIENT **,int);
void remplir_tab_patient(PATIENT *, int );
void afficher_tab_patient(PATIENT *, int);
int rechercher_ind_patient (PATIENT*,int , int);
int saisir_bool();
void supprimer_patient(PATIENT *,int*,int);
 void modification (PATIENT*,int,int);
void tri_insertion(PATIENT *,int);
void ajout_patient (PATIENT*,int,int);
void modifier_patient(PATIENT *,int,int);