#include <gtk/gtk.h>

// Signal handler for the "clicked" signal of the start button.
void on_start(GtkButton *button, gpointer user_data)
{
    g_print("on_start()\n");
}

gboolean on_configure(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    GdkRectangle *r = user_data;
    gint width = gtk_widget_get_allocated_width(widget);
    gint height = gtk_widget_get_allocated_height(widget);
    r->x = width/2;
    r->y = height/2;

    return FALSE;
}

// Signal handler for the "draw" signal of the drawing area.
gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
    // Gets the rectangle.
    GdkRectangle *r = user_data;

    // Sets the background to white.
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    // Draws the rectangle in red.
    cairo_set_source_rgb(cr, 1, 0, 0);
    cairo_rectangle(cr, r->x, r->y, r->width, r->height);
    cairo_fill(cr);

    // Propagates the signal.
    return FALSE;
}


// Main function.
int main (int argc, char *argv[])
{
    // Initializes GTK.
    gtk_init(NULL, NULL);

    // Creates a rectangle.
    GdkRectangle rect = { 100, 100, 10, 10 };

    // Loads the UI description and builds the UI.
    // (Exits if an error occurs.)
    GtkBuilder* builder = gtk_builder_new();
    GError* error = NULL;
    if (gtk_builder_add_from_file(builder, "plain.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return 1;
    }

    // Gets the widgets.
    GtkDrawingArea* area = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "area"));
    GtkWindow* window = GTK_WINDOW(gtk_builder_get_object(builder, "org.gtk.duel"));
    GtkButton* start_button = GTK_BUTTON(gtk_builder_get_object(builder, "start_button"));

    // Connects signal handlers.
    g_signal_connect(area, "configure-event", G_CALLBACK(on_configure), &rect);
    g_signal_connect(area, "draw", G_CALLBACK(on_draw), &rect);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(start_button, "clicked", G_CALLBACK(on_start), NULL);

    // Runs the main loop.
    gtk_main();

    // Exits.
    return 0;
}