#include <gtk/gtk.h>
#include <GL/gl.h>
#include <math.h>
#include <string.h>

#include "app.h"
#include "win.h"
#include "tegtkgl.h"

struct _MiniServoAppWindow {
  GtkApplicationWindow parent;
};

struct _MiniServoAppWindowClass {
  GtkApplicationWindowClass parent_class;
};

G_DEFINE_TYPE(MiniServoAppWindow, miniservo_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void miniservo_app_window_init(MiniServoAppWindow *win) {
}

static void miniservo_app_window_class_init(MiniServoAppWindowClass *klass) {
}

/* static gboolean draw_the_gl(gpointer data) { */
/*   static float s = 0.f; */
/*   GtkWidget *gl = data; */

/*   // this is very important, as OpenGL has a somewhat global state. */
/*   // this will set the OpenGL state to this very widget. */
/*   te_gtkgl_make_current(TE_GTKGL(gl)); */

/*   // some triangle rotation stuff */
/*   s += 0.03f; */

/*   // more bureaucracy */
/*   glDisable(GL_TEXTURE_2D); */
/*   glDisable(GL_DEPTH_TEST); */
/*   glDisable(GL_BLEND); */
/*   glViewport(0, 0, 200, 200); */
/*   glMatrixMode(GL_PROJECTION); */
/*   glLoadIdentity(); */
/*   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); */
/*   glMatrixMode(GL_MODELVIEW); */
/*   glLoadIdentity(); */
/*   glClearColor(0, 0, 1.0, 1.0); */
/*   glClear(GL_COLOR_BUFFER_BIT); */
/*   glRotatef(cos(s)*360.f-180.f, 0.f, 0.f, 1.0); */
/*   glColor4ub(0xed, 0xb9, 0x1e, 0xff); */
/*   glBegin(GL_TRIANGLES); */
/*   glVertex2f(-0.7f, -0.5f); */
/*   glVertex2f(0.4f, -0.5f); */
/*   glVertex2f(0.f, 0.8f); */
/*   glEnd(); */

/*   // this is also very important */
/*   te_gtkgl_swap(TE_GTKGL(gl)); */
/*   return TRUE; */
/* } */

MiniServoAppWindow *miniservo_app_window_new(MiniServoApp *app) {
  MiniServoAppWindow *win = g_object_new(MINISERVO_APP_WINDOW_TYPE, "application", app, NULL);

  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *back_button;
  GtkWidget *fwd_button;
  GtkWidget *entry;
  GtkWidget *gl;

  gtk_window_set_default_size(GTK_WINDOW(win), 1280, 1024);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(win), vbox);

  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

  back_button = gtk_button_new_with_label("\u25c0");
  gtk_box_pack_start(GTK_BOX(hbox), back_button, FALSE, FALSE, 0);

  fwd_button = gtk_button_new_with_label("\u25b6");
  gtk_box_pack_start(GTK_BOX(hbox), fwd_button, FALSE, FALSE, 0);
  
  entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 0);
    
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

  gl = te_gtkgl_new();
  gtk_box_pack_start(GTK_BOX(vbox), gl, TRUE, TRUE, 0);

  gtk_widget_show_all(GTK_WIDGET(win));

  /* ServoClient *client = new ServoClient(); */
  /* CefWindowInfo windowInfo; */
  /* windowInfo.SetAsWindowless(0, false); */
  /* CefBrowserSettings browserSettings; */
  /* CefRefPtr<CefBrowser> browser = CefBrowserHost::CreateBrowserSync( */
  /*   windowInfo, client, "http://asdf.com/", browserSettings, nullptr); */
  
  /* g_timeout_add_full(1000, 10, draw_the_gl, gl, 0); */

  return win;
}

