#include <stdio.h>
#include <glib-object.h>

#include "gcef.h"

G_DEFINE_TYPE(GCefApp, gcef_app, G_TYPE_OBJECT);

static void gcef_add_ref(cef_base_t *self) {
  GObject *obj = (gpointer)(self - sizeof(guint) - sizeof(GTypeInstance));
  g_object_ref(obj);
}

static int gcef_release(cef_base_t *self) {
  GObject *obj = (gpointer)(self - sizeof(guint) - sizeof(GTypeInstance));
  gint cnt = g_atomic_int_get(&obj->ref_count);
  g_object_unref(obj);
  return cnt == 1;
}

static int gcef_has_one_ref(cef_base_t *self) {
  GObject *obj = (gpointer)(self - sizeof(guint) - sizeof(GTypeInstance));
  gint cnt = g_atomic_int_get(&obj->ref_count);
  return cnt == 1;
}

static void gcef_app_init(GCefApp *self) {
  printf("gcef_app_init\n");
  self->app.base.size = sizeof(cef_app_t);
  self->app.base.add_ref = gcef_add_ref;
  self->app.base.release = gcef_release;
  self->app.base.has_one_ref = gcef_has_one_ref;
}

static void gcef_app_class_init(GCefAppClass *klass) {
}

GCefApp *gcef_app_new() {
  return g_object_new(GCEF_TYPE_APP, NULL);
}
