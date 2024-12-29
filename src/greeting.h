#ifndef GREETING_H_INCLUDED
#define GREETING_H_INCLUDED

#include <stdio.h>
#include <gtk/gtk.h>

/*typedef struct {
    int Basse;   
    int Moyenne; 
    int Haute;   
} Urgence;*/


typedef struct {
    char ID[15];                       
    char Nom_du_parking[20];           
    char Sujet[30];                   // Sujet de la réclamation
    char Description_du_probleme[100]; // Description du problème
    int CIN;                           // Carte d'identité nationale du client
    char Urgence[10];                       // Niveau d'urgence (1 = Basse, 2 = Moyenne, 3 = Haute)
    char Avis[30];
    char date[30];
    int Choix;	
    int Jour,Mois,Annee; 
	char ID_Unique[25];
 //  Date dt_res;
} Reclamation;

void show_id_dialog(GtkWidget *parent);
char *generate_unique_id();
int avis_rec(const char *fich, Reclamation a);
int Ajouter(const char *fichier, Reclamation r, GtkWidget *parent);
int supprimer_reclamation(const char *fichier, const char *id_unique, const char *date);
gchar *rechercher_reclamation(const gchar *id, int jour, int mois, int annee);

void populate_treeview1(GtkTreeView *treeview, const char *filename);
void setup_treeview_columns1(GtkTreeView *treeview);

int Modifier(char *fic, char *ID, Reclamation nouvrec);


//void setup_treeview_columns(GtkTreeView *treeview);
//void populate_treeview(GtkTreeView *treeview, char *fichier);



#endif // GREETING_H_INCLUDED


