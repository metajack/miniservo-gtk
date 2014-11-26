#include "servo_client.h"
#include <include/cef_client.h>

/* virtual override */ CefRefPtr<CefRenderHandler> ServoClient::GetRenderHandler() {
  return this;
}

/* virtual override */ CefRefPtr<CefLoadHandler> ServoClient::GetLoadHandler() {
  return this;
}

/* virtual override */ bool ServoClient::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) {
  rect.x = rect.y = 0;
  rect.width = 0;
  rect.height = 0;
  return true;
}

/* virtual override */ bool ServoClient::GetBackingRect(CefRefPtr<CefBrowser> browser, CefRect& rect) {
    rect.x = rect.y = 0;
    rect.width = 0;
    rect.height = 0;
    return true;
}

/* virtual override */ void ServoClient::OnPaint(CefRefPtr<CefBrowser> browser,
                                                 CefRenderHandler::PaintElementType type,
                                                 const CefRenderHandler::RectList& dirtyRects,
                                                 const void* buffer,
                                                 int width,
                                                 int height) {
}

/* virtual override */ void ServoClient::OnPresent(CefRefPtr<CefBrowser> browser) {
}

/* virtual override */ void ServoClient::OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
                                                              bool isLoading,
                                                              bool canGoBack,
                                                              bool canGoForward) {
}
