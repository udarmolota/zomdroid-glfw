#include "internal.h"
#include <stdlib.h>
#include <string.h>
#include "zomdroid.h"
#include "zomdroid_globals.h"

#define NOOP
#define UNIMPLEMENTED_API _glfwInputError(GLFW_FEATURE_UNIMPLEMENTED, "Zomdroid: %s not implemented", __func__);


static void fitToSurface(_GLFWwindow* window)
{
    GLFWvidmode mode;
    _glfwGetVideoModeZomdroid(window->monitor, &mode);
    window->zomdroid.width = mode.width;
    window->zomdroid.height = mode.height;
}



//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

GLFWbool _glfwCreateWindowZomdroid(_GLFWwindow* window,
                               const _GLFWwndconfig* wndconfig,
                               const _GLFWctxconfig* ctxconfig,
                               const _GLFWfbconfig* fbconfig)
{
    static bool calledOnce = false;
    if (calledOnce) {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Window is supposed to be created only once");
        return GLFW_FALSE;
    }
    calledOnce = true;

    fitToSurface(window);
    _glfw.zomdroid.window = window;

    if ((g_zomdroid_renderer == GL4ES) || (g_zomdroid_renderer == NG_GL4ES)) {

        if (!_glfwInitEGL())
            return GLFW_FALSE;

        _GLFWctxconfig* _ctxconfig = ctxconfig;
        _ctxconfig->client = GLFW_OPENGL_ES_API;
        _ctxconfig->major = atoi(getenv("ZOMDROID_GLES_MAJOR"));
        _ctxconfig->minor = atoi(getenv("ZOMDROID_GLES_MINOR"));
        if (!_glfwCreateContextEGL(window, _ctxconfig, fbconfig))
            return GLFW_FALSE;

    } else if (g_zomdroid_renderer == ZINK_OSMESA) {

        if (!_glfwInitOSMesa())
            return GLFW_FALSE;
        if (!_glfwCreateContextOSMesa(window, ctxconfig, fbconfig))
            return GLFW_FALSE;

    } else if (g_zomdroid_renderer == ZINK_ZFA) {
        if (!_glfwInitZfa())
            return GLFW_FALSE;
        if (!_glfwCreateContextZfa(window, ctxconfig, fbconfig))
            return GLFW_FALSE;
    }

    if (!_glfwRefreshContextAttribs(window, ctxconfig))
        return GLFW_FALSE;

    return GLFW_TRUE;
}

void _glfwDestroyWindowZomdroid(_GLFWwindow* window)
{
    NOOP
}

void _glfwSetWindowTitleZomdroid(_GLFWwindow* window, const char* title)
{
    NOOP
}

void _glfwSetWindowIconZomdroid(_GLFWwindow* window, int count, const GLFWimage* images)
{
    NOOP
}

void _glfwSetWindowMonitorZomdroid(_GLFWwindow* window,
                               _GLFWmonitor* monitor,
                               int xpos, int ypos,
                               int width, int height,
                               int refreshRate)
{
    if (window->monitor && window->monitor->window == window) {
        _glfwInputMonitorWindow(window->monitor, NULL);
    }
    _glfwInputWindowMonitor(window, monitor);
}

void _glfwGetWindowPosZomdroid(_GLFWwindow* window, int* xpos, int* ypos)
{
    if (xpos)
        *xpos = 0;
    if (ypos)
        *ypos = 0;
}

void _glfwSetWindowPosZomdroid(_GLFWwindow* window, int xpos, int ypos)
{
    NOOP
}

void _glfwGetWindowSizeZomdroid(_GLFWwindow* window, int* width, int* height)
{
    if (width)
        *width = window->zomdroid.width;
    if (height)
        *height = window->zomdroid.height;
}

void _glfwSetWindowSizeZomdroid(_GLFWwindow* window, int width, int height)
{
    NOOP
}

void _glfwSetWindowSizeLimitsZomdroid(_GLFWwindow* window,
                                  int minwidth, int minheight,
                                  int maxwidth, int maxheight)
{
    NOOP
}

void _glfwSetWindowAspectRatioZomdroid(_GLFWwindow* window, int n, int d)
{
    NOOP
}

void _glfwGetFramebufferSizeZomdroid(_GLFWwindow* window, int* width, int* height)
{
    if (width)
        *width = window->zomdroid.width;
    if (height)
        *height = window->zomdroid.height;
}

void _glfwGetWindowFrameSizeZomdroid(_GLFWwindow* window,
                                 int* left, int* top,
                                 int* right, int* bottom)
{
    if (left)
        *left = 0;
    if (top)
        *top = 0;
    if (right)
        *right = 0;
    if (bottom)
        *bottom = 0;
}

void _glfwGetWindowContentScaleZomdroid(_GLFWwindow* window, float* xscale, float* yscale)
{
    if (xscale)
        *xscale = 1.f;
    if (yscale)
        *yscale = 1.f;
}

void _glfwIconifyWindowZomdroid(_GLFWwindow* window)
{
    NOOP
}

void _glfwRestoreWindowZomdroid(_GLFWwindow* window)
{
    NOOP
}

void _glfwMaximizeWindowZomdroid(_GLFWwindow* window)
{
    NOOP
}

GLFWbool _glfwWindowMaximizedZomdroid(_GLFWwindow* window)
{
    return GLFW_TRUE;
}

GLFWbool _glfwWindowHoveredZomdroid(_GLFWwindow* window)
{
    return GLFW_TRUE;
}

GLFWbool _glfwFramebufferTransparentZomdroid(_GLFWwindow* window)
{
    return GLFW_FALSE;
}

void _glfwSetWindowResizableZomdroid(_GLFWwindow* window, GLFWbool enabled)
{
    UNIMPLEMENTED_API
}

void _glfwSetWindowDecoratedZomdroid(_GLFWwindow* window, GLFWbool enabled)
{
    UNIMPLEMENTED_API
}

void _glfwSetWindowFloatingZomdroid(_GLFWwindow* window, GLFWbool enabled)
{
    UNIMPLEMENTED_API
}

void _glfwSetWindowMousePassthroughZomdroid(_GLFWwindow* window, GLFWbool enabled)
{
    UNIMPLEMENTED_API
}

float _glfwGetWindowOpacityZomdroid(_GLFWwindow* window)
{
    return 1.f;
}

void _glfwSetWindowOpacityZomdroid(_GLFWwindow* window, float opacity)
{
    UNIMPLEMENTED_API
}

void _glfwSetRawMouseMotionZomdroid(_GLFWwindow *window, GLFWbool enabled)
{
    UNIMPLEMENTED_API
}

GLFWbool _glfwRawMouseMotionSupportedZomdroid(void)
{
    UNIMPLEMENTED_API
    return GLFW_FALSE;
}

void _glfwShowWindowZomdroid(_GLFWwindow* window)
{
    //NOOP
}

void _glfwRequestWindowAttentionZomdroid(_GLFWwindow* window)
{
    //UNIMPLEMENTED_API
}

void _glfwHideWindowZomdroid(_GLFWwindow* window)
{
    UNIMPLEMENTED_API
}

void _glfwFocusWindowZomdroid(_GLFWwindow* window)
{
    //UNIMPLEMENTED_API
}

GLFWbool _glfwWindowFocusedZomdroid(_GLFWwindow* window)
{
    UNIMPLEMENTED_API
    return GLFW_TRUE;
}

GLFWbool _glfwWindowIconifiedZomdroid(_GLFWwindow* window)
{
    return GLFW_FALSE;
}

GLFWbool _glfwWindowVisibleZomdroid(_GLFWwindow* window)
{
    return GLFW_TRUE;
}

static void processZomdroidEvent(ZomdroidEvent* event) {
    switch (event->type) {
        case KEYBOARD: {
            KeyboardEvent* e = &event->keyboard;
            _glfwInputKey(_glfw.zomdroid.window, e->key, 0, e->is_pressed ? GLFW_PRESS : GLFW_RELEASE, 0);
            break;
        }
        case CURSOR_POS: {
            CursorPosEvent* e = &event->cursorPos;
            _glfwInputCursorPos(_glfw.zomdroid.window, e->x, e->y);
            break;
        }
        case MOUSE_BUTTON: {
            MouseButtonEvent* e = &event->mouseButton;
            _glfwInputMouseClick(_glfw.zomdroid.window, e->button, e->is_pressed ? GLFW_PRESS : GLFW_RELEASE, 0);
            break;
        }
        case JOYSTICK_CONNECTED: {
            JoystickConnectedEvent* e = &event->joystickConnected;
            _GLFWjoystick* js = _glfwAllocJoystick(e->joystick_name, e->joystick_guid, e->axis_count,
                                         e->button_count, e->hat_count);
            int jid = (int)(js - _glfw.joysticks);
            if (jid != GLFW_JOYSTICK_1) {
                // zomdroid only supports a single joystick
                _glfwInputError(GLFW_PLATFORM_ERROR, "Failed to process event: joystick already connected");
                _glfwFreeJoystick(js);
                return;
            }
            _glfwInputJoystick(js, GLFW_CONNECTED);
            break;
        }
        case JOYSTICK_DISCONNECTED: {
            JoystickDisconnectedEvent* e = &event->joystickDisconnected;
            _GLFWjoystick* js = &_glfw.joysticks[GLFW_JOYSTICK_1];
            _glfwInputJoystick(js, GLFW_DISCONNECTED);
            _glfwFreeJoystick(js);
            break;
        }
        case JOYSTICK_AXIS: {
            JoystickAxisEvent* e = &event->joystickAxis;
            _GLFWjoystick* js = &_glfw.joysticks[GLFW_JOYSTICK_1];
            _glfwInputJoystickAxis(js, e->axis, e->state);
            break;
        }
        case JOYSTICK_DPAD: {
            JoystickDpadEvent* e = &event->joystickDpad;
            _GLFWjoystick* js = &_glfw.joysticks[GLFW_JOYSTICK_1];
            _glfwInputJoystickHat(js, e->dpad, e->state);
            break;
        }
        case JOYSTICK_BUTTON: {
            JoystickButtonEvent* e = &event->joystickButton;
            _GLFWjoystick* js = &_glfw.joysticks[GLFW_JOYSTICK_1];
            _glfwInputJoystickButton(js, e->button, e->is_pressed ? GLFW_PRESS : GLFW_RELEASE);
            break;
        }
    }
}

void _glfwPollEventsZomdroid(void)
{
    int head = atomic_load_explicit(&g_zomdroid_event_queue.head, memory_order_acquire);
    int tail = atomic_load_explicit(&g_zomdroid_event_queue.tail, memory_order_relaxed);

    int size = (head - tail) & EVENT_QUEUE_MAX;

    for (int i = 0; i < size; i++) {
        int next = (tail + i + 1) & EVENT_QUEUE_MAX;
        ZomdroidEvent* e = &g_zomdroid_event_queue.buffer[next];
        processZomdroidEvent(e);
    }

    atomic_store_explicit(&g_zomdroid_event_queue.tail, head, memory_order_release);
}

void _glfwWaitEventsZomdroid(void)
{
    UNIMPLEMENTED_API
}

void _glfwWaitEventsTimeoutZomdroid(double timeout)
{
    UNIMPLEMENTED_API
}

void _glfwPostEmptyEventZomdroid(void)
{
    UNIMPLEMENTED_API
}

void _glfwGetCursorPosZomdroid(_GLFWwindow* window, double* xpos, double* ypos)
{
    if (xpos)
        *xpos = _glfw.zomdroid.cursorX;
    if (ypos)
        *ypos = _glfw.zomdroid.cursorY;
}

void _glfwSetCursorPosZomdroid(_GLFWwindow* window, double x, double y)
{
    _glfw.zomdroid.cursorX = (int) x;
    _glfw.zomdroid.cursorY = (int) y;
}

void _glfwSetCursorModeZomdroid(_GLFWwindow* window, int mode)
{
    NOOP
}

GLFWbool _glfwCreateCursorZomdroid(_GLFWcursor* cursor,
                               const GLFWimage* image,
                               int xhot, int yhot)
{
    return GLFW_FALSE;
}

GLFWbool _glfwCreateStandardCursorZomdroid(_GLFWcursor* cursor, int shape)
{
    return GLFW_FALSE;
}

void _glfwDestroyCursorZomdroid(_GLFWcursor* cursor)
{
    NOOP
}

void _glfwSetCursorZomdroid(_GLFWwindow* window, _GLFWcursor* cursor)
{
    NOOP
}

void _glfwSetClipboardStringZomdroid(const char* string)
{
    UNIMPLEMENTED_API
}

const char* _glfwGetClipboardStringZomdroid(void)
{
    UNIMPLEMENTED_API
    return _glfw.zomdroid.clipboardString;
}

EGLenum _glfwGetEGLPlatformZomdroid(EGLint** attribs)
{
    return 0;
}

EGLNativeDisplayType _glfwGetEGLNativeDisplayZomdroid(void)
{
    return EGL_DEFAULT_DISPLAY;
}

EGLNativeWindowType _glfwGetEGLNativeWindowZomdroid(_GLFWwindow* window)
{
    return _glfw.zomdroid.aNativeWindow;
}

const char* _glfwGetScancodeNameZomdroid(int scancode)
{
    return NULL;
}

int _glfwGetKeyScancodeZomdroid(int key)
{
    return -1;
}

