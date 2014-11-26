#include <string.h>

#include <gtk/gtk.h>

#include <include/capi/cef_app_capi.h>

#include "app.h"
#include "gcef.h"

int main(int argc, char **argv) {
  cef_main_args_t main_args = {};
  main_args.argc = argc;
  main_args.argv = argv;

  cef_settings_t settings = {};
  settings.size = sizeof(cef_settings_t);
  settings.single_process = TRUE;

  GCefApp *app = gcef_app_new();

  cef_initialize(&main_args, &settings, &app->app, NULL);
  
  int ret = g_application_run(G_APPLICATION(miniservo_app_new()), argc, argv);

  cef_shutdown();

  return ret;
}
