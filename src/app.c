#include <gtk/gtk.h>

#include "app.h"
#include "win.h"

struct _MiniServoApp {
  GtkApplication parent;
};

struct _MiniServoAppClass {
  GtkApplicationClass parent_class;
};

G_DEFINE_TYPE(MiniServoApp, miniservo_app, GTK_TYPE_APPLICATION)

static void miniservo_app_init(MiniServoApp *app) {
}

static void miniservo_app_activate(GApplication *app) {
  MiniServoAppWindow *win;
  win = miniservo_app_window_new(MINISERVO_APP(app));
  gtk_window_present(GTK_WINDOW(win));
}

static void miniservo_app_class_init(MiniServoAppClass *klass) {
  G_APPLICATION_CLASS(klass)->activate = miniservo_app_activate;
}

MiniServoApp *miniservo_app_new() {
  return g_object_new(MINISERVO_APP_TYPE,
                      "application-id", "org.servo.miniservo",
                      "flags", G_APPLICATION_FLAGS_NONE,
                      NULL);
}
