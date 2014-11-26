#ifndef __MiniServo__ServoClient__
#define __MiniServo__ServoClient__

#include <include/cef_client.h>

class ServoClient : public CefClient,
  public CefLoadHandler,
  public CefRenderHandler {
public:
  explicit ServoClient() {}

  // CefClient implementation
  virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override;
  virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override;
  // CefLoadHandler implementation
  virtual void OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
                                    bool isLoading,
                                    bool canGoBack,
                                    bool canGoForward);
  // CefRenderHandler implementation
  virtual bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
  virtual bool GetBackingRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
  virtual void OnPaint(CefRefPtr<CefBrowser> browser,
                       CefRenderHandler::PaintElementType type,
                       const CefRenderHandler::RectList& dirtyRects,
                       const void* buffer,
                       int width,
                       int height) override;
  virtual void OnPresent(CefRefPtr<CefBrowser> browser) override;
private:
  IMPLEMENT_REFCOUNTING(ServoClient);
  DISALLOW_COPY_AND_ASSIGN(ServoClient);
};
#endif /* __MiniServo__ServoClient__ */
