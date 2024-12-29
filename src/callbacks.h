#ifndef CALLBACKS_H_INCLUDED
#define CALLBACKS_H_INCLUDED

#include <gtk/gtk.h>

void
on_RHbuttonG__rerCompteCitoyen_clicked (GtkButton *button,
                                        gpointer   user_data);

void
on_RHbuttonG__rerReservationCitoyen_clicked
                                        (GtkButton *button,
                                         gpointer   user_data);

void
on_RHbuttonAvis_ReclamationCitoyen_clicked
                                        (GtkButton *button,
                                         gpointer   user_data);

void
on_RHbuttonEnregistrerAjouterReclamation_clicked
                                        (GtkWidget *button,
                                         gpointer   user_data);


void
on_RHbuttonSupprimerReclamation_clicked
                                        (GtkButton *button,
                                         gpointer   user_data);

void
on_RHradiobuttonBasseUrgenceAjouterReclamation_toggled
                                        (GtkToggleButton *togglebutton,
                                         gpointer         user_data);

void
on_RHradiobuttonMoyenneUrgenceAjouterReclamation_toggled
                                        (GtkToggleButton *togglebutton,
                                         gpointer         user_data);

void
on_RHradiobuttonHauteUrgenceAjouterReclamation_toggled
                                        (GtkToggleButton *togglebutton,
                                         gpointer         user_data);




void
on_RHcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHcheckbutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHcheckbutton3_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHcheckbutton4_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHcheckbutton5_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHbuttonEnregistrementAvis_clicked  (GtkButton       *button,
                                        gpointer         user_data);



void
on_RHbuttonEnregistrementAvis_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_RHbuttonAfficherReclamation_clicked (GtkButton       *button,
                                        gpointer         user_data);


#endif

void
on_RHtreeviewAfficherReclamation_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_RHbuttonChercherIdAfficherReclamation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RHbuttonChercherReclamationSuprrimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RHcheckbuttonReclamationSupprimer_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHbuttonChercherIdModifierReclamation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RHradiobuttonBasseModifierReclamation_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHradiobuttonMoyenneModifierReclamation_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RHbuttonEnregistrerModifierReclamation_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_RHradiobuttonHauteModifierReclamation_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
