#ifndef __MINISERVO_APP_WIN_H
#define __MINISERVO_APP_WIN_H


#include <gtk/gtk.h>
#include "app.h"


#define MINISERVO_APP_WINDOW_TYPE (miniservo_app_window_get_type())
#define MINISERVO_APP_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MINISERVO_APP_WINDOW_TYPE, MiniServoAppWindow))


typedef struct _MiniServoAppWindow MiniServoAppWindow;
typedef struct _MiniServoAppWindowClass MiniServoAppWindowClass;


GType miniservo_app_window_get_type();
MiniServoAppWindow *miniservo_app_window_new(MiniServoApp *app);


#endif /* __MINISERVO_APP_WIN_H */

