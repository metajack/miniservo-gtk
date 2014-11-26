#ifndef __MINISERVO_APP_H
#define __MINISERVO_APP_H


#include <gtk/gtk.h>


#define MINISERVO_APP_TYPE (miniservo_app_get_type ())
#define MINISERVO_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MINISERVO_APP_TYPE, MiniServoApp))


typedef struct _MiniServoApp MiniServoApp;
typedef struct _MiniServoAppClass MiniServoAppClass;


GType miniservo_app_get_type();
MiniServoApp *miniservo_app_new();


#endif /* __MINISERVO_APP_H */
