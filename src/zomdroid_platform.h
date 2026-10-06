#include <android/native_window.h>

#define GLFW_ZOMDROID_WINDOW_STATE          _GLFWwindowZomdroid zomdroid;
#define GLFW_ZOMDROID_LIBRARY_WINDOW_STATE  _GLFWlibraryZomdroid zomdroid;
#define GLFW_ZOMDROID_MONITOR_STATE         _GLFWmonitorZomdroid zomdroid;

typedef struct _GLFWwindowZomdroid
{
    int             width;
    int             height;
} _GLFWwindowZomdroid;

typedef struct _GLFWmonitorZomdroid
{
} _GLFWmonitorZomdroid;

typedef struct _GLFWlibraryZomdroid
{
    ANativeWindow* aNativeWindow;
    int aNativeWindowWidth;
    int aNativeWindowHeight;
    ANativeWindow_Buffer* aNativeWindowBuffer;
    double          cursorX;
    double          cursorY;
    char*           clipboardString;
    _GLFWwindow*    window;
} _GLFWlibraryZomdroid;

void _glfwPollMonitorsZomdroid(void);

GLFWbool _glfwConnectZomdroid(int platformID, _GLFWplatform* platform);
int _glfwInitZomdroid(void);
void _glfwTerminateZomdroid(void);

void _glfwFreeMonitorZomdroid(_GLFWmonitor* monitor);
void _glfwGetMonitorPosZomdroid(_GLFWmonitor* monitor, int* xpos, int* ypos);
void _glfwGetMonitorContentScaleZomdroid(_GLFWmonitor* monitor, float* xscale, float* yscale);
void _glfwGetMonitorWorkareaZomdroid(_GLFWmonitor* monitor, int* xpos, int* ypos, int* width, int* height);
GLFWvidmode* _glfwGetVideoModesZomdroid(_GLFWmonitor* monitor, int* found);
GLFWbool _glfwGetVideoModeZomdroid(_GLFWmonitor* monitor, GLFWvidmode* mode);
GLFWbool _glfwGetGammaRampZomdroid(_GLFWmonitor* monitor, GLFWgammaramp* ramp);
void _glfwSetGammaRampZomdroid(_GLFWmonitor* monitor, const GLFWgammaramp* ramp);

GLFWbool _glfwCreateWindowZomdroid(_GLFWwindow* window, const _GLFWwndconfig* wndconfig, const _GLFWctxconfig* ctxconfig, const _GLFWfbconfig* fbconfig);
void _glfwDestroyWindowZomdroid(_GLFWwindow* window);
void _glfwSetWindowTitleZomdroid(_GLFWwindow* window, const char* title);
void _glfwSetWindowIconZomdroid(_GLFWwindow* window, int count, const GLFWimage* images);
void _glfwSetWindowMonitorZomdroid(_GLFWwindow* window, _GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate);
void _glfwGetWindowPosZomdroid(_GLFWwindow* window, int* xpos, int* ypos);
void _glfwSetWindowPosZomdroid(_GLFWwindow* window, int xpos, int ypos);
void _glfwGetWindowSizeZomdroid(_GLFWwindow* window, int* width, int* height);
void _glfwSetWindowSizeZomdroid(_GLFWwindow* window, int width, int height);
void _glfwSetWindowSizeLimitsZomdroid(_GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight);
void _glfwSetWindowAspectRatioZomdroid(_GLFWwindow* window, int n, int d);
void _glfwGetFramebufferSizeZomdroid(_GLFWwindow* window, int* width, int* height);
void _glfwGetWindowFrameSizeZomdroid(_GLFWwindow* window, int* left, int* top, int* right, int* bottom);
void _glfwGetWindowContentScaleZomdroid(_GLFWwindow* window, float* xscale, float* yscale);
void _glfwIconifyWindowZomdroid(_GLFWwindow* window);
void _glfwRestoreWindowZomdroid(_GLFWwindow* window);
void _glfwMaximizeWindowZomdroid(_GLFWwindow* window);
GLFWbool _glfwWindowMaximizedZomdroid(_GLFWwindow* window);
GLFWbool _glfwWindowHoveredZomdroid(_GLFWwindow* window);
GLFWbool _glfwFramebufferTransparentZomdroid(_GLFWwindow* window);
void _glfwSetWindowResizableZomdroid(_GLFWwindow* window, GLFWbool enabled);
void _glfwSetWindowDecoratedZomdroid(_GLFWwindow* window, GLFWbool enabled);
void _glfwSetWindowFloatingZomdroid(_GLFWwindow* window, GLFWbool enabled);
void _glfwSetWindowMousePassthroughZomdroid(_GLFWwindow* window, GLFWbool enabled);
float _glfwGetWindowOpacityZomdroid(_GLFWwindow* window);
void _glfwSetWindowOpacityZomdroid(_GLFWwindow* window, float opacity);
void _glfwSetRawMouseMotionZomdroid(_GLFWwindow *window, GLFWbool enabled);
GLFWbool _glfwRawMouseMotionSupportedZomdroid(void);
void _glfwShowWindowZomdroid(_GLFWwindow* window);
void _glfwRequestWindowAttentionZomdroid(_GLFWwindow* window);
void _glfwHideWindowZomdroid(_GLFWwindow* window);
void _glfwFocusWindowZomdroid(_GLFWwindow* window);
GLFWbool _glfwWindowFocusedZomdroid(_GLFWwindow* window);
GLFWbool _glfwWindowIconifiedZomdroid(_GLFWwindow* window);
GLFWbool _glfwWindowVisibleZomdroid(_GLFWwindow* window);
void _glfwPollEventsZomdroid(void);
void _glfwWaitEventsZomdroid(void);
void _glfwWaitEventsTimeoutZomdroid(double timeout);
void _glfwPostEmptyEventZomdroid(void);
void _glfwGetCursorPosZomdroid(_GLFWwindow* window, double* xpos, double* ypos);
void _glfwSetCursorPosZomdroid(_GLFWwindow* window, double x, double y);
void _glfwSetCursorModeZomdroid(_GLFWwindow* window, int mode);
GLFWbool _glfwCreateCursorZomdroid(_GLFWcursor* cursor, const GLFWimage* image, int xhot, int yhot);
GLFWbool _glfwCreateStandardCursorZomdroid(_GLFWcursor* cursor, int shape);
void _glfwDestroyCursorZomdroid(_GLFWcursor* cursor);
void _glfwSetCursorZomdroid(_GLFWwindow* window, _GLFWcursor* cursor);
void _glfwSetClipboardStringZomdroid(const char* string);
const char* _glfwGetClipboardStringZomdroid(void);
const char* _glfwGetScancodeNameZomdroid(int scancode);
int _glfwGetKeyScancodeZomdroid(int key);

EGLenum _glfwGetEGLPlatformZomdroid(EGLint** attribs);
EGLNativeDisplayType _glfwGetEGLNativeDisplayZomdroid(void);
EGLNativeWindowType _glfwGetEGLNativeWindowZomdroid(_GLFWwindow* window);