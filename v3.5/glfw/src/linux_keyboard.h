//========================================================================
// GLFW 3.5 Linux - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2014 Jonas Ådahl <jadahl@gmail.com>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include <linux/input.h>
#include <linux/limits.h>
#include <regex.h>

#define GLFW_LINUX_KEYBOARD_STATE         _GLFWkeyboardLinux linjs;
#define GLFW_LINUX_LIBRARY_KEYBOARD_STATE _GLFWlibraryKeyboardLinux  linjs;

// Linux-specific keyboard data
//
typedef struct _GLFWkeyboardLinux {
    int                     fd;
    char                    path[PATH_MAX];
    int                     keyMap[KEY_CNT - BTN_MISC];
    int                     absMap[ABS_CNT];
    struct input_absinfo    absInfo[ABS_CNT];
    int                     hats[4][2];
} _GLFWkeyboardLinux;

// Linux-specific keyboard API data
//
typedef struct _GLFWlibraryKeyboardLinux {
    int                     inotify;
    int                     watch;
    regex_t                 regex;
    GLFWbool                regexCompiled;
    GLFWbool                dropped;
} _GLFWlibraryKeyboardLinux;

void _glfwDetectKeyboardConnectionLinux(void);

GLFWbool _glfwInitKeyboardsLinux(void);
void _glfwTerminateKeyboardsLinux(void);
GLFWbool _glfwPollKeyboardLinux();

