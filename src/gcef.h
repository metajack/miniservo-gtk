#ifndef __MINISERVO_CEF_OBJECTS_H
#define __MINISERVO_CEF_OBJECTS_H


#include <glib-object.h>
#include <include/capi/cef_app_capi.h>
#include <include/capi/cef_client_capi.h>


typedef struct {
  GObject parent;
  cef_app_t app;
} GCefApp;

typedef struct {
  GObjectClass parent_class;
} GCefAppClass;

#define GCEF_TYPE_APP (gcef_app_get_type())
#define GCEF_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GCEF_TYPE_APP, GCefApp))
#define GCEF_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GCEF_TYPE_APP, GCefAppClass))
#define GCEF_IS_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), GCEF_TYPE_APP))
#define GCEF_IS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GCEF_TYPE_APP))
#define GCEF_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GCEF_TYPE_APP, GCefAppClass))

GCefApp *gcef_app_new();


typedef struct {
  GObject parent;
  cef_client_t client;
} GCefClient;

typedef struct {
  GObjectClass parent_class;
} GCefClientClass;

#define GCEF_TYPE_CLIENT (gcef_client_get_type())
#define GCEF_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GCEF_TYPE_CLIENT, GCefClient))
#define GCEF_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GCEF_TYPE_CLIENT, GCefClientClass))
#define GCEF_IS_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), GCEF_TYPE_CLIENT))
#define GCEF_IS_CLIENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GCEF_TYPE_CLIENT))
#define GCEF_CLIENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GCEF_TYPE_CLIENT, GCefClientClass))

GCefClient *gcef_client_new();


#endif /* __MINISERVO_CEF_OBJECTS_H */
