#include "postfix.h"

int main(int argc, char *argv[])
{
     	gtk_init(&argc, &argv);
	GtkWidget *window;		
	GtkWidget *button;	
	GtkWidget *entry; 	
	GtkWidget *vbox;
	GtkWidget *hbox1;

	/*initialise main window*/
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window, "delete-event", 
			 G_CALLBACK(delete_event), NULL);
	g_signal_connect(window, "destroy", 
			 G_CALLBACK(destroy), NULL);
    	gtk_window_set_title (GTK_WINDOW (window), "Postfix Calculator");
	gtk_container_set_border_width(GTK_CONTAINER(window), 15);

	/*initialise layout*/
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	gtk_widget_show(vbox);
	
	hbox1 = gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox), hbox1);

	/*initialise text field*/
	entry = gtk_entry_new();
	g_signal_connect(entry, "activate",
			 G_CALLBACK(button_callback), entry);           //signal for enter action
	gtk_entry_set_text (GTK_ENTRY (entry), "Enter Expression:");
	gtk_editable_set_editable(GTK_EDITABLE(entry), TRUE);
	gtk_box_pack_start(GTK_BOX(hbox1), entry, TRUE, TRUE, 0);
	gtk_widget_show(entry);

	/*initialise calculate button*/
	button = gtk_button_new_with_label("=");
	g_signal_connect(button, "clicked", 
			G_CALLBACK(button_callback), entry);	       
	gtk_box_pack_start(GTK_BOX(hbox1), button, TRUE, TRUE, 0);
	gtk_widget_show(button);
	gtk_widget_show(hbox1);
	gtk_widget_show(vbox);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}

/*GTK SHIT*/

/*delete event is called by window manager
 *returning true means you don't want window destroyed*/

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	g_print("delete event occured\n");
	return FALSE;
}

/*destory callback*/

static void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

static void button_callback(GtkWidget *widget, GtkWidget *entry)
{
	const gchar *entry_text;
        char str[30];
        int result;
	entry_text = gtk_entry_get_text (GTK_ENTRY (entry));
	printf("called by button - entry contents: %s\n", entry_text);
	result = evaluatePostfixExpression(entry_text);
        sprintf(str, "%d", result);
        gtk_entry_set_text(GTK_ENTRY(entry), str);
        gtk_widget_grab_focus(entry);
}

