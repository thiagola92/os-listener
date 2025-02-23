/*
    Adaptation from Godot:
    https://github.com/godotengine/godot/blob/master/platform/windows/key_mapping_windows.h
    https://github.com/godotengine/godot/blob/master/platform/windows/key_mapping_windows.cpp
*/

#ifndef KEY_MAPPING_WIN32_H
#define KEY_MAPPING_WIN32_H

#include <godot_cpp/godot.hpp>
#include <unordered_map>
#include <winuser.h>

static std::unordered_map<uint32_t, Key> vk_map = {
    // VK_LBUTTON (0x01)
    // VK_RBUTTON (0x02)
    // VK_CANCEL (0x03)
    // VK_MBUTTON (0x04)
    // VK_XBUTTON1 (0x05)
    // VK_XBUTTON2 (0x06), We have no mappings for the above;as we only map
    // keyboard buttons here.
    // 0x07 is undefined.
    {VK_BACK, Key::KEY_BACKSPACE}, // (0x08)
    {VK_TAB, Key::KEY_TAB},        // (0x09)
    // 0x0A-0B are reserved.
    {VK_CLEAR, Key::KEY_CLEAR},  // (0x0C)
    {VK_RETURN, Key::KEY_ENTER}, // (0x0D)
    // 0x0E-0F are undefined.
    {VK_SHIFT, Key::KEY_SHIFT},      // (0x10)
    {VK_CONTROL, Key::KEY_CTRL},     // (0x11)
    {VK_MENU, Key::KEY_ALT},         // (0x12)
    {VK_PAUSE, Key::KEY_PAUSE},      // (0x13)
    {VK_CAPITAL, Key::KEY_CAPSLOCK}, // (0x14)
    // 0x15-1A are IME keys.
    {VK_ESCAPE, Key::KEY_ESCAPE}, // (0x1B)
    // 0x1C-1F are IME keys.
    {VK_SPACE, Key::KEY_SPACE},   // (0x20)
    {VK_PRIOR, Key::KEY_PAGEUP},  // (0x21)
    {VK_NEXT, Key::KEY_PAGEDOWN}, // (0x22)
    {VK_END, Key::KEY_END},       // (0x23)
    {VK_HOME, Key::KEY_HOME},     // (0x24)
    {VK_LEFT, Key::KEY_LEFT},     // (0x25)
    {VK_UP, Key::KEY_UP},         // (0x26)
    {VK_RIGHT, Key::KEY_RIGHT},   // (0x27)
    {VK_DOWN, Key::KEY_DOWN},     // (0x28)
    // VK_SELECT (0x29), Old select key},e.g. on Digital Equipment Corporation
    // keyboards.
    {VK_PRINT,
     Key::KEY_PRINT}, // (0x2A), Old IBM key},modern keyboards use VK_SNAPSHOT.
    // VK_EXECUTE (0x2B), Old and uncommon.
    {VK_SNAPSHOT, Key::KEY_PRINT},    // (0x2C)
    {VK_INSERT, Key::KEY_INSERT},     // (0x2D)
    {VK_DELETE, Key::KEY_DELETE}, // (0x2E)
    {VK_HELP, Key::KEY_HELP},         // (0x2F)
    {0x30, Key::KEY_0},           // 0 key.
    {0x31, Key::KEY_1},           // 1 key.
    {0x32, Key::KEY_2},           // 2 key.
    {0x33, Key::KEY_3},           // 3 key.
    {0x34, Key::KEY_4},           // 4 key.
    {0x35, Key::KEY_5},           // 5 key.
    {0x36, Key::KEY_6},           // 6 key.
    {0x37, Key::KEY_7},           // 7 key.
    {0x38, Key::KEY_8},           // 8 key.
    {0x39, Key::KEY_9},           // 9 key.
    // 0x3A-40 are undefined.
    {0x41, Key::KEY_A},       // A key.
    {0x42, Key::KEY_B},       // B key.
    {0x43, Key::KEY_C},       // C key.
    {0x44, Key::KEY_D},       // D key.
    {0x45, Key::KEY_E},       // E key.
    {0x46, Key::KEY_F},       // F key.
    {0x47, Key::KEY_G},       // G key.
    {0x48, Key::KEY_H},       // H key.
    {0x49, Key::KEY_I},       // I key
    {0x4A, Key::KEY_J},       // J key.
    {0x4B, Key::KEY_K},       // K key.
    {0x4C, Key::KEY_L},       // L key.
    {0x4D, Key::KEY_M},       // M key.
    {0x4E, Key::KEY_N},       // N key.
    {0x4F, Key::KEY_O},       // O key.
    {0x50, Key::KEY_P},       // P key.
    {0x51, Key::KEY_Q},       // Q key.
    {0x52, Key::KEY_R},       // R key.
    {0x53, Key::KEY_S},       // S key.
    {0x54, Key::KEY_T},       // T key.
    {0x55, Key::KEY_U},       // U key.
    {0x56, Key::KEY_V},       // V key.
    {0x57, Key::KEY_W},       // W key.
    {0x58, Key::KEY_X},       // X key.
    {0x59, Key::KEY_Y},       // Y key.
    {0x5A, Key::KEY_Z},       // Z key.
    {VK_LWIN, Key::KEY_META}, // (0x5B)
    {VK_RWIN, Key::KEY_META}, // (0x5C)
    {VK_APPS, Key::KEY_MENU}, // (0x5D)
    // 0x5E is reserved.
    {VK_SLEEP, Key::KEY_STANDBY},        // (0x5F)
    {VK_NUMPAD0, Key::KEY_KP_0},         // (0x60)
    {VK_NUMPAD1, Key::KEY_KP_1},         // (0x61)
    {VK_NUMPAD2, Key::KEY_KP_2},         // (0x62)
    {VK_NUMPAD3, Key::KEY_KP_3},         // (0x63)
    {VK_NUMPAD4, Key::KEY_KP_4},         // (0x64)
    {VK_NUMPAD5, Key::KEY_KP_5},         // (0x65)
    {VK_NUMPAD6, Key::KEY_KP_6},         // (0x66)
    {VK_NUMPAD7, Key::KEY_KP_7},         // (0x67)
    {VK_NUMPAD8, Key::KEY_KP_8},         // (0x68)
    {VK_NUMPAD9, Key::KEY_KP_9},         // (0x69)
    {VK_MULTIPLY, Key::KEY_KP_MULTIPLY}, // (0x6A)
    {VK_ADD, Key::KEY_KP_ADD},           // (0x6B)
    {VK_SEPARATOR, Key::KEY_KP_PERIOD},  // (0x6C)
    {VK_SUBTRACT, Key::KEY_KP_SUBTRACT}, // (0x6D)
    {VK_DECIMAL, Key::KEY_KP_PERIOD},    // (0x6E)
    {VK_DIVIDE, Key::KEY_KP_DIVIDE},     // (0x6F)
    {VK_F1, Key::KEY_F1},                // (0x70)
    {VK_F2, Key::KEY_F2},                // (0x71)
    {VK_F3, Key::KEY_F3},                // (0x72)
    {VK_F4, Key::KEY_F4},                // (0x73)
    {VK_F5, Key::KEY_F5},                // (0x74)
    {VK_F6, Key::KEY_F6},                // (0x75)
    {VK_F7, Key::KEY_F7},                // (0x76)
    {VK_F8, Key::KEY_F8},                // (0x77)
    {VK_F9, Key::KEY_F9},                // (0x78)
    {VK_F10, Key::KEY_F10},              // (0x79)
    {VK_F11, Key::KEY_F11},              // (0x7A)
    {VK_F12, Key::KEY_F12},              // (0x7B)
    {VK_F13, Key::KEY_F13},              // (0x7C)
    {VK_F14, Key::KEY_F14},              // (0x7D)
    {VK_F15, Key::KEY_F15},              // (0x7E)
    {VK_F16, Key::KEY_F16},              // (0x7F)
    {VK_F17, Key::KEY_F17},              // (0x80)
    {VK_F18, Key::KEY_F18},              // (0x81)
    {VK_F19, Key::KEY_F19},              // (0x82)
    {VK_F20, Key::KEY_F20},              // (0x83)
    {VK_F21, Key::KEY_F21},              // (0x84)
    {VK_F22, Key::KEY_F22},              // (0x85)
    {VK_F23, Key::KEY_F23},              // (0x86)
    {VK_F24, Key::KEY_F24},              // (0x87)
    // 0x88-8F are reserved for UI navigation.
    {VK_NUMLOCK, Key::KEY_NUMLOCK},   // (0x90)
    {VK_SCROLL, Key::KEY_SCROLLLOCK}, // (0x91)
    {VK_OEM_NEC_EQUAL,
     Key::KEY_EQUAL}, // (0x92), OEM NEC PC-9800 numpad '=' key.
    // 0x93-96 are OEM specific (e.g. used by Fujitsu/OASYS);
    // 0x97-9F are unassigned.
    {VK_LSHIFT, Key::KEY_SHIFT},                   // (0xA0)
    {VK_RSHIFT, Key::KEY_SHIFT},                   // (0xA1)
    {VK_LCONTROL, Key::KEY_CTRL},                  // (0xA2)
    {VK_RCONTROL, Key::KEY_CTRL},                  // (0xA3)
    {VK_LMENU, Key::KEY_MENU},                     // (0xA4)
    {VK_RMENU, Key::KEY_MENU},                     // (0xA5)
    {VK_BROWSER_BACK, Key::KEY_BACK},              // (0xA6)
    {VK_BROWSER_FORWARD, Key::KEY_FORWARD},        // (0xA7)
    {VK_BROWSER_REFRESH, Key::KEY_REFRESH},        // (0xA8)
    {VK_BROWSER_STOP, Key::KEY_STOP},              // (0xA9)
    {VK_BROWSER_SEARCH, Key::KEY_SEARCH},          // (0xAA)
    {VK_BROWSER_FAVORITES, Key::KEY_FAVORITES},    // (0xAB)
    {VK_BROWSER_HOME, Key::KEY_HOMEPAGE},          // (0xAC)
    {VK_VOLUME_MUTE, Key::KEY_VOLUMEMUTE},         // (0xAD)
    {VK_VOLUME_DOWN, Key::KEY_VOLUMEDOWN},         // (0xAE)
    {VK_VOLUME_UP, Key::KEY_VOLUMEUP},             // (0xAF)
    {VK_MEDIA_NEXT_TRACK, Key::KEY_MEDIANEXT},     // (0xB0)
    {VK_MEDIA_PREV_TRACK, Key::KEY_MEDIAPREVIOUS}, // (0xB1)
    {VK_MEDIA_STOP, Key::KEY_MEDIASTOP},           // (0xB2)
    {VK_MEDIA_PLAY_PAUSE,
     Key::KEY_MEDIAPLAY}, // (0xB3), Media button play/pause toggle.
    {VK_LAUNCH_MAIL, Key::KEY_LAUNCHMAIL},          // (0xB4)
    {VK_LAUNCH_MEDIA_SELECT, Key::KEY_LAUNCHMEDIA}, // (0xB5)
    {VK_LAUNCH_APP1, Key::KEY_LAUNCH0},             // (0xB6)
    {VK_LAUNCH_APP2, Key::KEY_LAUNCH1},             // (0xB7)
    // 0xB8-B9 are reserved.
    {VK_OEM_1, Key::KEY_SEMICOLON},   // (0xBA), Misc. character;can vary by
                                      // keyboard/region.
                                      // For US standard keyboards;the ';:' key.
    {VK_OEM_PLUS, Key::KEY_EQUAL},    // (0xBB)
    {VK_OEM_COMMA, Key::KEY_COMMA},   // (0xBC)
    {VK_OEM_MINUS, Key::KEY_MINUS},   // (0xBD)
    {VK_OEM_PERIOD, Key::KEY_PERIOD}, // (0xBE)
    {VK_OEM_2,
     Key::KEY_SLASH}, // (0xBF), For US standard keyboards;the '/?' key.
    {VK_OEM_3,
     Key::KEY_QUOTELEFT}, // (0xC0), For US standard keyboards;the '`~' key.
    // 0xC1-D7 are reserved. 0xD8-DA are unassigned.
    // 0xC3-DA may be used for old gamepads? Maybe we want to support this? See
    // WinUser.h.
    {VK_OEM_4,
     Key::KEY_BRACKETLEFT}, // (0xDB),  For US standard keyboards;the '[{' key.
    {VK_OEM_5,
     Key::KEY_BACKSLASH}, // (0xDC), For US standard keyboards;the '\|' key.
    {VK_OEM_6,
     Key::KEY_BRACKETRIGHT}, // (0xDD), For US standard keyboards;the ']}' key.
    {VK_OEM_7, Key::KEY_APOSTROPHE}, // (0xDE), For US standard
                                     // keyboards;single quote/double quote.
    // VK_OEM_8 (0xDF)
    // 0xE0 is reserved. 0xE1 is OEM specific.
    {VK_OEM_102, Key::KEY_BAR},   // (0xE2), Either angle bracket or backslash
                                  // key on the RT 102-key keyboard.
    {VK_ICO_HELP, Key::KEY_HELP}, // (0xE3)
    // 0xE4 is OEM (e.g. ICO) specific.
    // VK_PROCESSKEY (0xE5), For IME.
    {VK_ICO_CLEAR, Key::KEY_CLEAR}, // (0xE6)
    // VK_PACKET (0xE7), Used to pass Unicode characters as if they were
    // keystrokes.
    // 0xE8 is unassigned.
    // 0xE9-F5 are OEM (Nokia/Ericsson) specific.
    {VK_ATTN, Key::KEY_ESCAPE}, // (0xF6), Old IBM 'ATTN' key used on
                                // midrange computers ;e.g. AS/400.
    {VK_CRSEL, Key::KEY_TAB},   // (0xF7), Old IBM 3270 'CrSel' (cursor
                                // select) key},used to select data fields.
    // VK_EXSEL (0xF7), Old IBM 3270 extended selection key.
    // VK_EREOF (0xF8), Old IBM 3270 erase to end of field key.
    {VK_PLAY, Key::KEY_MEDIAPLAY}, // (0xFA), Old IBM 3270 'Play' key.
    // VK_ZOOM (0xFB), Old IBM 3290 'Zoom' key.
    // VK_NONAME (0xFC), Reserved.
    // VK_PA1 (0xFD), Old IBM 3270 PA1 key.
    {VK_OEM_CLEAR, Key::KEY_CLEAR}, // (0xFE), OEM specific clear key. Unclear
                                    // how it differs from normal clear.
};

#endif