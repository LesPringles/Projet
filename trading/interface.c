#include "interface.h"
#define UTF8(string) g_locale_to_utf8(string, -1, NULL, NULL, NULL)

gchar* utf8(char *police, char *color, char *size, char *string){
char tab[100] = "<span face=\"";
strcat(tab, police);
strcat(tab, "\" foreground=\"");
strcat(tab, color);
strcat(tab, "\" size=\"");
strcat(tab, size);
strcat(tab, "\">");
strcat(tab, string);
strcat(tab, "</span>\n");
return UTF8(tab);
}

gchar* mot(char *string[]){
char tab[100]="";
for(int i = 0; i < 12; i++)
{
strcat(tab, string[i]);
if(i % 2 == 0)
strcat(tab, " :  ");
else
strcat(tab, "     ");
if(i == 5 || i == 11 || i == 17)
strcat(tab, "\n\n");
}

return UTF8(tab);
}

/*void set_item_menu(GtkWidget* elem, char *string[]){
for(int i = 0; i < 15; i++)
{
menu_item_new(GTK_MENU(elem), string[i], G_CALLBACK(changename), user_data);
}

}*/

//void mafonction(GtkWidget* elem, gpointer data){}

void interface(int argc, char **argv)
{
	/* Variables */
  	GtkWidget* p_Windows = NULL;
	GtkWidget* Label = NULL;
	GtkWidget* pVbox1 = NULL;
	GtkWidget* pVbox2 = NULL;
	GtkWidget* pVboxd = NULL;
	GtkWidget* pHbox = NULL;
	GtkWidget* pElement[4];
	gchar* Texte = NULL;
	gchar* Valeurs = NULL;
	char Action[20] = "Nom l'Action";
	char *string[12]; 
	string[0]="mma150";
	string[1]="40";
	string[2]="mme";
	string[3]="30";
	string[4]="geo";
	string[5]="40.5";
	string[6]="tje";
	string[7]="97";
	string[8]="tjzeh";
	string[9]="85";
	string[10]="jpea";
	string[11]="85";
	/* Initialisation de GTK+ */
	gtk_init(&argc, &argv);
	
	/* Creation de la fenetre */
	p_Windows = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(p_Windows), "Interface Graphique");
	gtk_window_set_default_size(GTK_WINDOW(p_Windows), 500, 400);
	g_signal_connect(G_OBJECT(p_Windows), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	
	
	Texte = utf8("Verdana", "#000000", "xx-large", Action);
	//Texte = g_locale_to_utf8("YO", -1, NULL, NULL, NULL);
	//Label = gtk_label_new(Texte); 

	/*
	gtk_label_set_use_markup(GTK_LABEL(Label), TRUE);
	gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

	gtk_container_add(GTK_CONTAINER(p_Windows), Label);*/

	/* Création des GtkBox */
	pVbox1 = gtk_vbox_new(FALSE, 0);
	pVbox2 = gtk_vbox_new(FALSE, 0);
	pVboxd = gtk_vbox_new(FALSE, 0);
	pHbox = gtk_hbox_new(FALSE, 0);
	/* Ajout de la GtkVBox dans la window*/
	gtk_container_add(GTK_CONTAINER(p_Windows), pVbox1);
	gtk_box_pack_start(GTK_BOX(pVbox1), pHbox, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(pHbox), pVbox2, FALSE, FALSE, 0);	
	gtk_box_pack_start(GTK_BOX(pHbox), pVboxd, FALSE, FALSE, 0);


	/* Création des contents*/
	pElement[0] = gtk_label_new(Texte);
	pElement[1] = gtk_image_new_from_file("./resources/graphe.jpg");
//	g_signal_connect(G_OBJECT(pElement[3]), "clicked", G_CALLBACK(mafonction), pElement[0]);
	pElement[2] = gtk_button_new_with_label("menu déroulant");

	Valeurs = mot(string); 

//g_locale_to_utf8("YO<span face=\"Verdana\" foreground=\"#73b5ff\" size=\"xx-large\"><b>4</b></span>\n <span face=\"Verdana\" foreground=\"#39b500\" size=\"x-large\">Le tuto GTK</span>\n", -1, NULL, NULL, NULL);
	pElement[3] = gtk_label_new(Valeurs);

	gtk_label_set_use_markup(GTK_LABEL(pElement[0]), TRUE);
	//gtk_label_set_use_markup(GTK_LABEL(pElement[3]), TRUE);
	gtk_label_set_justify(GTK_LABEL(pElement[0]), GTK_JUSTIFY_LEFT);
	gtk_label_set_justify(GTK_LABEL(pElement[3]), GTK_JUSTIFY_FILL);

	g_free(Texte);
	g_free(Valeurs);
	/* Ajout des éléments */
	gtk_box_pack_start(GTK_BOX(pVbox2), pElement[0], FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(pVbox2), pElement[1], FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(pVboxd), pElement[2], FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(pVbox1), pElement[3], FALSE, FALSE, 0);

	/* Affichage de la boucle evenementielle*/
	gtk_widget_show_all(p_Windows);

	gtk_main();

}


