#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "greeting.h"
#include <time.h>
#include <gtk/gtk.h>

#define MAX_LINE 256 

//int urgenceLevel;
//Reclamation r;

/*enum
{	ID,
	NOM_PARKING,
	SUJET,
	DESCRIPTION_PROBLEME,
	CIN,
	URGENCE,
	DATE,
	ID_UNIQUE
};*/

int avis_rec(const char *fich, Reclamation a) { 
	fich="avis.txt";
	FILE *f=fopen(fich,"a");
	if (!f) {
		printf("Erreur d'ouverture du fichier.\n");
	return 0; 
		}
	   // Obtenir la date et l'heure actuelles
    time_t now = time(NULL);
    struct tm *temps = localtime(&now);
    if (temps == NULL) {
        perror("Erreur lors de l'obtention de l'heure");
       // fclose(file);
        return 0;
    }

    // Formater la date et l'heure (par exemple : "2024-12-13 14:35:00")
    char date_heure[20];
    strftime(date_heure, sizeof(date_heure), "%Y-%m-%d %H:%M:%S", temps);
    strcpy(a.date,date_heure);

        fprintf(f,"%s ; %s ; %s ; sous la date : %s\n",a.ID, a.Nom_du_parking, a.Avis, a.date);
	fclose(f);
	return 1;

} 

// Fonction pour générer un ID unique
char *generate_unique_id() {
Reclamation r;
    time_t t = time(NULL);                // Récupérer le temps actuel
    struct tm tm = *localtime(&t);       // Découper le temps en parties lisibles

    // Générer un ID basé sur l'année, le mois, le jour, l'heure, les minutes et les secondes
    char *id = malloc(20); // Allouer de la mémoire pour l'ID
    snprintf(id, 20, "%04d%02d%02d%02d%02d%02d",
             tm.tm_year + 1900,   // Année
             tm.tm_mon + 1,       // Mois
             tm.tm_mday,          // Jour
             tm.tm_hour,          // Heure
             tm.tm_min,           // Minutes
             tm.tm_sec);          // Secondes
    strcpy(r.ID_Unique, id);
    return id; // Retourner l'ID généré
}

//Fonction pour Ajouter une Reclamation

int Ajouter(const char *fichier, Reclamation r, GtkWidget *parent) {
    // Fichier cible
    fichier = "reclamation.txt";

    // Ouvrir le fichier en mode ajout
    FILE *file = fopen(fichier, "a");
    if (!file) {
        printf("Erreur d'ouverture du fichier.\n");
        return 0;
    }

    // Générer un ID unique
    char *id = generate_unique_id();
    if (id == NULL) {
        printf("Erreur lors de la génération de l'ID unique.\n");
        fclose(file);
        return 0;
    }
    strcpy(r.ID_Unique, id); // Stocker l'ID dans la structure Reclamation

    // Afficher l'ID unique dans une boîte de dialogue
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_CLOSE,
                                               "L'ID de la réclamation est : %s", id);
    gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog),
                                             "Vous pouvez copier cet ID : %s", id);
    gtk_dialog_run(GTK_DIALOG(dialog)); // Afficher la boîte de dialogue
    gtk_widget_destroy(dialog);         // Détruire la boîte de dialogue après fermeture

    // Obtenir la date et l'heure actuelles
    time_t now = time(NULL);
    struct tm *temps = localtime(&now);
    if (temps == NULL) {
        perror("Erreur lors de l'obtention de l'heure");
        fclose(file);
        free(id);
        return 0;
    }

    // Formater la date (par exemple : "2024-12-13")
    char date_heure[30];
    strftime(date_heure, sizeof(date_heure), "%d-%m-%Y", temps);
    strcpy(r.date, date_heure); // Stocker la date dans la structure Reclamation

    // Ajouter les détails de la réclamation au fichier
    fprintf(file, "%s;%s;%s;%s;%d;%s;%s;%s\n",
            r.ID,                // ID réclamation
            r.Nom_du_parking,    // Nom du parking
            r.Sujet,             // Sujet de la réclamation
            r.Description_du_probleme, // Description du problème
            r.CIN,               // CIN
            r.Urgence,           // Niveau d'urgence
            r.date,              // Date de la réclamation
            r.ID_Unique);        // ID unique de la réclamation

    fclose(file);  // Fermer le fichier
    free(id);      // Libérer la mémoire allouée pour l'ID unique

    return 1;
}



// setup la treeview

void setup_treeview_columns1(GtkTreeView *treeview) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;



    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("ID Parking", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 15);
    gtk_tree_view_column_set_resizable(column, TRUE);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("NOM Parking", renderer, "text", 1, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 30);
    gtk_tree_view_column_set_resizable(column, TRUE);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("SUJET", renderer, "text", 2, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 15);
    gtk_tree_view_column_set_resizable(column, TRUE);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("DESCRIPTION", renderer, "text", 3, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 100);
    gtk_tree_view_column_set_resizable(column, TRUE);
 
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text", 4, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 8);
    gtk_tree_view_column_set_resizable(column, TRUE);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("URGENCE", renderer, "text", 5, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 10);
    gtk_tree_view_column_set_resizable(column, TRUE);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("DATE", renderer, "text", 6, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 15);
    gtk_tree_view_column_set_resizable(column, TRUE);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("ID_UNIQUE", renderer, "text", 7, NULL);
    gtk_tree_view_append_column(treeview, column);
    gtk_tree_view_column_set_fixed_width(column, 20);
    gtk_tree_view_column_set_resizable(column, TRUE);
}

  // Fonction pour remplir la treeview

void populate_treeview1(GtkTreeView *treeview, const char *filename) {
    GtkListStore *store;
    GtkTreeIter iter;
    FILE *file = fopen(filename, "r");
//filename="reclamation.txt";
    char line[256];

    // Create a GtkListStore with 8 columns (8 fields + 1 for agent ID)
    store = gtk_list_store_new(8, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, 
                               G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    gtk_tree_view_set_model(treeview, GTK_TREE_MODEL(store));

    while (fgets(line, sizeof(line), file)) {
        Reclamation r;
        
        // Parse the line to fill the parking structure, including the agent ID
        sscanf(line, "%99[^;];%99[^;];%99[^;];%99[^;];%d;%99[^;];%99[^;];%99[^\n]",
               r.ID, r.Nom_du_parking, r.Sujet, r.Description_du_probleme, 
               &r.CIN, r.Urgence, r.date, r.ID_Unique);

        // Add data to the GtkListStore (including agent ID)
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, r.ID, 1, r.Nom_du_parking, 2, r.Sujet, 
                           3, r.Description_du_probleme, 4, r.CIN, 5, r.Urgence, 
                           6, r.date, 7, r.ID_Unique, -1);
    }

    fclose(file);
}


/*
// Fonction pour afficher l'ID dans une boîte de dialogue
void show_id_dialog(GtkWidget *parent) {
    char *id = generate_unique_id(); // Générer l'ID unique

    // Créer une boîte de dialogue
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(parent),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_CLOSE,
                                               "L'ID de la reclamation est : %s", id);

    // Ajouter une instruction pour copier l'ID
    gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog),
                                             "Vous pouvez copier cet ID : %s", id);

    gtk_dialog_run(GTK_DIALOG(dialog)); // Afficher la boîte de dialogue
    gtk_widget_destroy(dialog);         // Détruire la boîte de dialogue après fermeture

    free(id); // Libérer la mémoire de l'ID
}*/




/* int Modifier(char *fic, char *ID, Reclamation nouvrec) {
    Reclamation r;
    Reclamation temp;
    const char fic[]="relamation.txt";
    FILE *file = fopen(fic, "r");
    if (!file) {
        printf("Erreur d'ouverture du fichier.\n");
        return 0;
    }
    
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        fclose(file);
        printf("Erreur de création du fichier temporaire.\n");
        return 0;
    }


    int found = 0;
   
    while (fscanf(file, "%s;%s;%s;%s;%d;%s:%s\n", 
                   r.ID, r.Nom_du_parking, r.Sujet, 
                   r.Description_du_probleme, &r.CIN,r.Urgence, r.date) == 7) {

        if ((strcmp(r.ID, ID) == 0) && (strcmp(r.date,date)) {
            // Mettre à jour les champs de la réclamation avec les nouvelles informations
            strcpy(r.Nom_du_parking, nouvrec.Nom_du_parking);
            strcpy(r.Sujet, nouvrec.Sujet);
            strcpy(r.Description_du_probleme, nouvrec.Description_du_probleme);
            r.CIN = nouvrec.CIN;
	    strcpy(r.Urgence, nouvrec.Urgence);
	    strcpy(r.date, nouvrec.date);
            found = 1;
        }

        // Écrire la réclamation (modifiée ou non) dans le fichier temporaire
        fprintf(tempFile, "%s;%s;%s;%s;%d;%s;%s\n", 
                r.ID, r.Nom_du_parking, r.Sujet, 
                r.Description_du_probleme, r.CIN, r.Urgence, r.date);
    }

    fclose(file);
    fclose(tempFile);

    if (remove(reclamation) != 0) {
        perror("Erreur lors de la suppression du fichier original");
        return -3;
    }

    if (rename("temp.txt", reclamation) != 0) {
        perror("Erreur lors du renommage du fichier temporaire");
        return -4;
    }

    if (!found) {
        printf("Reclamation avec l'ID %s non trouvée.\n", ID);
    }

    return found;
}*/
