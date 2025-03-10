/*
    Adaptation from Godot:
    https://github.com/godotengine/godot/blob/master/platform/linuxbsd/x11/key_mapping_x11.h
    https://github.com/godotengine/godot/blob/master/platform/linuxbsd/x11/key_mapping_x11.cpp
*/

#ifndef KEY_MAPPING_X11_H
#define KEY_MAPPING_X11_H

// To use XK_* defines from <X11/keysymdef.h>
#define XK_MISCELLANY
#define XK_LATIN1
#define XK_XKB_KEYS

#include <X11/XF86keysym.h>
#include <X11/keysymdef.h>
#include <godot_cpp/godot.hpp>
#include <unordered_map>

static std::unordered_map<uint32_t, Key> xkeysym_map = {
    {XK_Escape, Key::KEY_ESCAPE},
    {XK_Tab, Key::KEY_TAB},
    {XK_ISO_Left_Tab, Key::KEY_BACKTAB},
    {XK_BackSpace, Key::KEY_BACKSPACE},
    {XK_Return, Key::KEY_ENTER},
    {XK_Insert, Key::KEY_INSERT},
    {XK_Delete, Key::KEY_DELETE},
    {XK_Clear, Key::KEY_DELETE},
    {XK_Pause, Key::KEY_PAUSE},
    {XK_Print, Key::KEY_PRINT},
    {XK_Home, Key::KEY_HOME},
    {XK_End, Key::KEY_END},
    {XK_Left, Key::KEY_LEFT},
    {XK_Up, Key::KEY_UP},
    {XK_Right, Key::KEY_RIGHT},
    {XK_Down, Key::KEY_DOWN},
    {XK_Prior, Key::KEY_PAGEUP},
    {XK_Next, Key::KEY_PAGEDOWN},
    {XK_Shift_L, Key::KEY_SHIFT},
    {XK_Shift_R, Key::KEY_SHIFT},
    {XK_Shift_Lock, Key::KEY_SHIFT},
    {XK_Control_L, Key::KEY_CTRL},
    {XK_Control_R, Key::KEY_CTRL},
    {XK_Meta_L, Key::KEY_META},
    {XK_Meta_R, Key::KEY_META},
    {XK_Alt_L, Key::KEY_ALT},
    {XK_Alt_R, Key::KEY_ALT},
    {XK_Caps_Lock, Key::KEY_CAPSLOCK},
    {XK_Num_Lock, Key::KEY_NUMLOCK},
    {XK_Scroll_Lock, Key::KEY_SCROLLLOCK},
    {XK_less, Key::KEY_QUOTELEFT},
    {XK_grave, Key::KEY_SECTION},
    {XK_Super_L, Key::KEY_META},
    {XK_Super_R, Key::KEY_META},
    {XK_Menu, Key::KEY_MENU},
    {XK_Hyper_L, Key::KEY_HYPER},
    {XK_Hyper_R, Key::KEY_HYPER},
    {XK_Help, Key::KEY_HELP},
    {XK_KP_Space, Key::KEY_SPACE},
    {XK_KP_Tab, Key::KEY_TAB},
    {XK_KP_Enter, Key::KEY_KP_ENTER},
    {XK_Home, Key::KEY_HOME},
    {XK_Left, Key::KEY_LEFT},
    {XK_Up, Key::KEY_UP},
    {XK_Right, Key::KEY_RIGHT},
    {XK_Down, Key::KEY_DOWN},
    {XK_Prior, Key::KEY_PAGEUP},
    {XK_Next, Key::KEY_PAGEDOWN},
    {XK_End, Key::KEY_END},
    {XK_Begin, Key::KEY_CLEAR},
    {XK_Insert, Key::KEY_INSERT},
    {XK_Delete, Key::KEY_DELETE},
    {XK_KP_Equal, Key::KEY_EQUAL},
    {XK_KP_Separator, Key::KEY_COMMA},
    {XK_KP_Decimal, Key::KEY_KP_PERIOD},
    {XK_KP_Multiply, Key::KEY_KP_MULTIPLY},
    {XK_KP_Divide, Key::KEY_KP_DIVIDE},
    {XK_KP_Subtract, Key::KEY_KP_SUBTRACT},
    {XK_KP_Add, Key::KEY_KP_ADD},
    {XK_KP_0, Key::KEY_KP_0},
    {XK_KP_1, Key::KEY_KP_1},
    {XK_KP_2, Key::KEY_KP_2},
    {XK_KP_3, Key::KEY_KP_3},
    {XK_KP_4, Key::KEY_KP_4},
    {XK_KP_5, Key::KEY_KP_5},
    {XK_KP_6, Key::KEY_KP_6},
    {XK_KP_7, Key::KEY_KP_7},
    {XK_KP_8, Key::KEY_KP_8},
    {XK_KP_9, Key::KEY_KP_9},

    // Same keys but with numlock off.
    {XK_KP_Insert, Key::KEY_INSERT},
    {XK_KP_Delete, Key::KEY_DELETE},
    {XK_KP_End, Key::KEY_END},
    {XK_KP_Down, Key::KEY_DOWN},
    {XK_KP_Page_Down, Key::KEY_PAGEDOWN},
    {XK_KP_Left, Key::KEY_LEFT},

    // X11 documents this (numpad 5) as "begin of line" but no toolkit seems to
    // interpret it this way. On Windows this is emitting Key::KEY_Clear so for
    // consistency it will be mapped to Key::KEY_Clear
    {XK_KP_Begin, Key::KEY_CLEAR},
    {XK_KP_Right, Key::KEY_RIGHT},
    {XK_KP_Home, Key::KEY_HOME},
    {XK_KP_Up, Key::KEY_UP},
    {XK_KP_Page_Up, Key::KEY_PAGEUP},
    {XK_F1, Key::KEY_F1},
    {XK_F2, Key::KEY_F2},
    {XK_F3, Key::KEY_F3},
    {XK_F4, Key::KEY_F4},
    {XK_F5, Key::KEY_F5},
    {XK_F6, Key::KEY_F6},
    {XK_F7, Key::KEY_F7},
    {XK_F8, Key::KEY_F8},
    {XK_F9, Key::KEY_F9},
    {XK_F10, Key::KEY_F10},
    {XK_F11, Key::KEY_F11},
    {XK_F12, Key::KEY_F12},
    {XK_F13, Key::KEY_F13},
    {XK_F14, Key::KEY_F14},
    {XK_F15, Key::KEY_F15},
    {XK_F16, Key::KEY_F16},
    {XK_F17, Key::KEY_F17},
    {XK_F18, Key::KEY_F18},
    {XK_F19, Key::KEY_F19},
    {XK_F20, Key::KEY_F20},
    {XK_F21, Key::KEY_F21},
    {XK_F22, Key::KEY_F22},
    {XK_F23, Key::KEY_F23},
    {XK_F24, Key::KEY_F24},
    {XK_F25, Key::KEY_F25},
    {XK_F26, Key::KEY_F26},
    {XK_F27, Key::KEY_F27},
    {XK_F28, Key::KEY_F28},
    {XK_F29, Key::KEY_F29},
    {XK_F30, Key::KEY_F30},
    {XK_F31, Key::KEY_F31},
    {XK_F32, Key::KEY_F32},
    {XK_F33, Key::KEY_F33},
    {XK_F34, Key::KEY_F34},
    {XK_F35, Key::KEY_F35},
    {XK_yen, Key::KEY_YEN},
    {XK_section, Key::KEY_SECTION},

    // Media keys.
    {XF86XK_Back, Key::KEY_BACK},
    {XF86XK_Forward, Key::KEY_FORWARD},
    {XF86XK_Stop, Key::KEY_STOP},
    {XF86XK_Refresh, Key::KEY_REFRESH},
    {XF86XK_Favorites, Key::KEY_FAVORITES},
    {XF86XK_OpenURL, Key::KEY_OPENURL},
    {XF86XK_HomePage, Key::KEY_HOMEPAGE},
    {XF86XK_Search, Key::KEY_SEARCH},
    {XF86XK_AudioLowerVolume, Key::KEY_VOLUMEDOWN},
    {XF86XK_AudioMute, Key::KEY_VOLUMEMUTE},
    {XF86XK_AudioRaiseVolume, Key::KEY_VOLUMEUP},
    {XF86XK_AudioPlay, Key::KEY_MEDIAPLAY},
    {XF86XK_AudioStop, Key::KEY_MEDIASTOP},
    {XF86XK_AudioPrev, Key::KEY_MEDIAPREVIOUS},
    {XF86XK_AudioNext, Key::KEY_MEDIANEXT},
    {XF86XK_AudioRecord, Key::KEY_MEDIARECORD},
    {XF86XK_Standby, Key::KEY_STANDBY},

    // Launch keys.
    {XF86XK_Mail, Key::KEY_LAUNCHMAIL},
    {XF86XK_AudioMedia, Key::KEY_LAUNCHMEDIA},
    {XF86XK_MyComputer, Key::KEY_LAUNCH0},
    {XF86XK_Calculator, Key::KEY_LAUNCH1},
    {XF86XK_Launch0, Key::KEY_LAUNCH2},
    {XF86XK_Launch1, Key::KEY_LAUNCH3},
    {XF86XK_Launch2, Key::KEY_LAUNCH4},
    {XF86XK_Launch3, Key::KEY_LAUNCH5},
    {XF86XK_Launch4, Key::KEY_LAUNCH6},
    {XF86XK_Launch5, Key::KEY_LAUNCH7},
    {XF86XK_Launch6, Key::KEY_LAUNCH8},
    {XF86XK_Launch7, Key::KEY_LAUNCH9},
    {XF86XK_Launch8, Key::KEY_LAUNCHA},
    {XF86XK_Launch9, Key::KEY_LAUNCHB},
    {XF86XK_LaunchA, Key::KEY_LAUNCHC},
    {XF86XK_LaunchB, Key::KEY_LAUNCHD},
    {XF86XK_LaunchC, Key::KEY_LAUNCHE},
    {XF86XK_LaunchD, Key::KEY_LAUNCHF},
};

#endif