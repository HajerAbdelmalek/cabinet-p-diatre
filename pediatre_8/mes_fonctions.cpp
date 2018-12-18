#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"

// saisir d'un entier
int saisir()
{ 
	int n;
	scanf("%d",&n);
	return(n);
}
void allouer (float **t,int n)
{
	 *t=(float*)malloc(n*sizeof (float ));
	if(!t) exit(-1);
}
void remplir_tab(float*t, int *n)
{
	int i;
	for(i=0;i<*n;i++)
		scanf("%f",(t+i));
}
void afficher_tab(float*t,int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%.2f \t ",*(t+i));
}
// remplissage de dossier de patient
PATIENT remplir_patient()
{
	PATIENT pat;
		printf("\n Saisir le numero du dossier ");
		scanf("%d",&pat.numero_dossier);
		printf("\n saisir le nom  ");
		scanf("%s",&pat.nom);

		printf("\n saisir le prenom  ");
		scanf("%s",&pat.prenom);
		printf("\n saisir date de naissance  ");
		scanf("%d%d%d",&pat.date_naissance.jour,&pat.date_naissance.mois,&pat.date_naissance.annee);

		printf("\n saisir l'adresse ");
		scanf("%s",&pat.adresse);

		printf("\n saisir le nombre de fois de mesure de vision  ");
		scanf("%d",&pat.nb_mesures);
		allouer(&pat.mesures,pat.nb_mesures);
		printf("\n saisir les mesures ");
		remplir_tab(pat.mesures,&pat.nb_mesures);
		printf("\n saisir la date de rendez_vous prochain ");
		scanf("%d%d%d",&pat.rdv.date_rendez_vous.jour,&pat.rdv.date_rendez_vous.mois,&pat.rdv.date_rendez_vous.annee);
		printf ("\n saisir l horaire ");
		scanf("%d%d",&pat.rdv.horaire_rendez_vous.heure,&pat.rdv.horaire_rendez_vous.minute);
		printf("\n saisir le poids  ");
		scanf("%d",&pat.info.poids);
		printf("\n saisir la taille  ");
		scanf("%f",&pat.info.taille);

		return pat;
		}
		// affichage du dossier du patient
		void afficher_patient (PATIENT pat)
		{printf("\n**********************************************\n");
		printf ("\n Le numero de dossier est %d",pat.numero_dossier);
		printf("\n Nom %s    ",pat.nom);
		printf(" prenom: %s",pat.prenom);
		printf("\n Date de naissance : %d/%d/%d ",pat.date_naissance.jour,pat.date_naissance.mois,pat.date_naissance.annee);
		printf("\n Adresse : %s",pat.adresse);
		printf("\n les mesures sont: ");
		afficher_tab(pat.mesures,pat.nb_mesures);
		printf("\n poids:%d",pat.info.poids);
		printf("\n Taille: %.2f",pat.info.taille);
		printf("\n Date de rendez-vous : %d/%d/%d",pat.rdv.date_rendez_vous.jour,pat.rdv.date_rendez_vous.mois,pat.rdv.date_rendez_vous.annee);
		printf(" \n Horaire rendez-vous:  %d:%d",pat.rdv.horaire_rendez_vous.heure,pat.rdv.horaire_rendez_vous.minute);
		printf("\n**********************************************\n");

}
void allouer_patient (PATIENT **t,int n)
{
	*t=(PATIENT*)malloc(n*sizeof (PATIENT ));
	if(!t) exit(-2);
}
// remplissage d'un ensemble des patients dans un tableau
void remplir_tab_patient(PATIENT *t , int n )
{
	int i;
	printf("\n ");
	for(i=0;i<n;i++)
	{printf ("\n Remplissage des patient n  :%d  ",i+1);
	*(t+i)=remplir_patient();}
}
// affichage des patients
void afficher_tab_patient(PATIENT *t, int n)
{
	int i;
	for(i=0;i<n;i++)
	{printf(" affichage de patient n : %d",i+1);
	afficher_patient(*(t+i));
	}
}
// recherche d'un patient
int rechercher_ind_patient (PATIENT *t,int n, int c)
{
	int ind_pat=-1,trouve=0,i;
do 
{
	for(i=0;i<n;i++)
	{
		if (t[i].numero_dossier==c)
		{
			ind_pat=i;
trouve=1;
		}
	}
} 
	while( (trouve==0) && (i<n));
		return(ind_pat);
}
	int saisir_bool()
{
	int n;
	do
{
	scanf("%d",&n);
}
	while( n!=0||n!=1);
		return(n);
}
// suppression d'un patient

 void supprimer_patient(PATIENT *tab,int *n,int k)
{
	int i;

	for(i=k;i<*n;i++)
	tab[i]=tab[i+1];
	*n=*n-1;
}
 // modification total d'un patient
void modification (PATIENT *tab,int n,int l)
{
	if (l==-1) printf("\n Le patient n existe pas ");
	else
	tab[l]=remplir_patient();
}
// tri des dossiers
void tri_insertion(PATIENT *t,int n)
{
	int i,p,j;
	PATIENT x;
	for(i=1;i<n;i++)
	{x=t[i];
	p=i-1;
	while (t[p].numero_dossier>x.numero_dossier && p-->0){}
	p++;
	for(j=i-1;j>=p;j--)
		t[j+1]=t[j];
	t[p]=x;
	}
}
// l'ajout des patients
void ajout_patient (PATIENT* t,int n,int x) 
{		
			for (int i=n;i<x+n;i++)
				*(t+i)=remplir_patient() ;
			

}
//modification partielle d'un patient
void modifier_patient(PATIENT *tab,int n ,int l)
{
	int code_modification;

	printf("\n Donner le champ a modifier");
printf("\n les numeros des champs    \n 1)     *****         Prenom      *****"
	                                "\n 2)     *****           Nom       *****"
									"\n 3)     *****  Date de naissance  *****"
									"\n 4)     *****        Adresse      *****"
									"\n 5)     *****        Poids        *****"
									"\n 6)     *****        Taille       *****"
									"\n 7)     ***** Date de rendevou    *****"
									"\n 8)     ***** Horaire de rendevou *****\n");
code_modification=saisir();
	if (code_modification==1)
		{printf("Attention! la modification sera faites sur le nom \n saisir le nouvau  nom ");
	scanf("%s",&tab[l].nom);}
	else if (code_modification==2)
	{printf("Attention! la modification sera faites sur le prenom \n saisir le nouvaux prenom ");
	scanf("%s",&tab[l].prenom);}
	else if (code_modification==3)
	{printf("Attention! la modification sera faites sur la date de naissance \n saisir la nouvelle date de naissance ");
	scanf("%d%d%d",&tab[l].date_naissance.jour,&tab[l].date_naissance.mois,&tab[l].date_naissance.annee);}
	else if(code_modification==4)
	{printf("Attention! la modification sera faites sur l adresse \n saisir la nouvelle adresse ");
	scanf("%s",&tab[l].adresse);}
	else if (code_modification==5)
	{printf("Attention! la modification sera faites sur le poids \n saisir le nouvau poids ");
	scanf("%d",&tab[l].info.poids);}
	else if (code_modification==6)
	{printf("Attention! la modification sera faites sur la taille  \n saisir le nouvau  taille ");
	scanf("%.2f",&tab[l].info.taille);}
	else if (code_modification==7) 
	{printf("Attention! la modification sera faites sur le date de rendez-vous \n saisir la nouvelle date de rendez-vous ");
	scanf("%d%d%d",&tab[l].rdv.date_rendez_vous.jour,&tab[l].rdv.date_rendez_vous.mois,&tab[l].rdv.date_rendez_vous.annee);}
	else if (code_modification==8)
	{printf("Attention! la modification sera faites sur l horaire \n saisir le nouveau horaire  ");
	scanf("%d%d",&tab[l].rdv.horaire_rendez_vous.heure,&tab[l].rdv.horaire_rendez_vous.minute);
	}
	else printf("\n le champ n existe pas");
}
