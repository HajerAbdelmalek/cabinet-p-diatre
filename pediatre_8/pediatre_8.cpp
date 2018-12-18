#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "mes_fonctions.h"

void main()
{
	int n,c,ind_patient,sup,k,mod,l,modc,x;
	int code_sup,code_modf,code_ajout,j,num,tache;
	PATIENT *tab;
	printf("saisir le nombre de patients  ");
	n=saisir();
	allouer_patient(&tab,n);
	remplir_tab_patient(tab,n);
	printf("\n---------------------------------------------\n");
	afficher_tab_patient(tab,n);
	 tri_insertion(tab,n);
	 printf("-----------patient apres le trie-----------------------\n");
	afficher_tab_patient(tab,n);
	printf(" saisir la tache a faire \n 1)          *****       consulter un patient         *****"
									"\n 2)          *****  modifier le contenu des patients  ***** "
									"\n 3)          *****       supprimer d'un dossier       ***** "
									"\n 4)          *****  ajouter un ou plusieurs patients  *****\n");
	tache=saisir();
	 if (tache==1)
	{
	printf("\n saisir le numero du dossier a consulter  ");
		c=saisir();
	ind_patient=rechercher_ind_patient(tab,n,c);
	if(ind_patient==-1)
		printf("le patient n existe pas");
	else
		afficher_patient(tab[ind_patient]);}

	 else if (tache==2)
		{ printf("\n si vous voulez modifier un patient d une facon complete tapez sur 1 \n si vous allez  modifier un seul champ tapez sur 0 \n sinon tapez sur une autre valeur ");


	code_modf=saisir();
	if (code_modf==1)
	{printf("\n saisir le numero du dossier a modifier");
	mod=saisir();
	printf("\n Attention vous allez changer le dossier numero: %d d'une facon complete! \n",mod);

	l=rechercher_ind_patient(tab,n,mod);
	modification(tab,n,l);
	printf("\n ~~~~~~~~~~~~ patient apres modification ~~~~~~~~~~~\n ");
	afficher_tab_patient(tab,n);}
	else if (code_modf==0)
		{
			printf("saisir le dossier  qui vous allez modifier quelques champs ");
	num=saisir();
	j=rechercher_ind_patient(tab,n,num);
	modifier_patient(tab,n,j);
	printf("\n ~~~~~~~~~~~~ patient apres modification ~~~~~~~~~~~ \n ");

	afficher_tab_patient(tab,n);}
	 }
	 else if (tache==3)
	 {printf("si vous voulez supprimer un patient tapez 1 sinon tapez sur une autre valeur");
	code_sup=saisir();
	if (code_sup==1)
	{printf("\n Saisir le numero de dossier a supprimer ");
	sup=saisir();
	k=rechercher_ind_patient(tab,n,sup);
	if (k==-1) printf("\n Le patient a supprimer  n existe pas ");}
	else
		{supprimer_patient(tab,&n,k);
	printf("\n ~~~~~~~~~~~~ patient apres suppression ~~~~~~~~~~~ \n ");

	afficher_tab_patient(tab,n);}}
	 else if (tache==4)
	 {printf("\n si vous voulez ajouter un patient tapez 1 sinon tapez 0: ");
		code_ajout=saisir();
	if (code_ajout==1)
	{
		printf("\n saisir le nombre des patients a ajouter ");
		x=saisir();
		tab = (PATIENT*) realloc (tab,sizeof(PATIENT)*(n+x));
			if(!tab) exit(-5) ;
	ajout_patient (tab,n, x);
	n+=x;
	printf("\n ~~~~~~~~~~~~ patient apres l'ajout ~~~~~~~~~~~ \n ");
	afficher_tab_patient(tab,n);
	tri_insertion(tab,n);}
	printf("\n Affichage des patients triees apres l'ajout  \n");
	afficher_tab_patient(tab,n);}
	getch();
}