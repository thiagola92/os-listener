/*
    Adaptation from Godot:
    https://github.com/godotengine/godot/blob/master/platform/windows/key_mapping_windows.h
    https://github.com/godotengine/godot/blob/master/platform/windows/key_mapping_windows.cpp
*/

#ifndef KEY_MAPPING_WIN32_H
#define KEY_MAPPING_WIN32_H

#include "godot_cpp/godot.hpp"
#include "keyboard.h"

#include <unordered_map>
#include <winuser.h>

static std::unordered_map<uint32_t, Keyboard> vk_map = {
    // VK_LBUTTON (0x01)
    // VK_RBUTTON (0x02)
    // VK_CANCEL (0x03)
    // VK_MBUTTON (0x04)
    // VK_XBUTTON1 (0x05)
    // VK_XBUTTON2 (0x06), We have no mappings for the above;as we only map
    // keyboard buttons here.
    // 0x07 is undefined.
    {VK_BACK, Keyboard::BACKSPACE}, // (0x08)
    {VK_TAB, Keyboard::TAB},        // (0x09)
    // 0x0A-0B are reserved.
    {VK_CLEAR, Keyboard::CLEAR},  // (0x0C)
    {VK_RETURN, Keyboard::ENTER}, // (0x0D)
    // 0x0E-0F are undefined.
    {VK_SHIFT, Keyboard::SHIFT},      // (0x10)
    {VK_CONTROL, Keyboard::CTRL},     // (0x11)
    {VK_MENU, Keyboard::ALT},         // (0x12)
    {VK_PAUSE, Keyboard::PAUSE},      // (0x13)
    {VK_CAPITAL, Keyboard::CAPSLOCK}, // (0x14)
    // 0x15-1A are IME keys.
    {VK_ESCAPE, Keyboard::ESCAPE}, // (0x1B)
    // 0x1C-1F are IME keys.
    {VK_SPACE, Keyboard::SPACE},   // (0x20)
    {VK_PRIOR, Keyboard::PAGEUP},  // (0x21)
    {VK_NEXT, Keyboard::PAGEDOWN}, // (0x22)
    {VK_END, Keyboard::END},       // (0x23)
    {VK_HOME, Keyboard::HOME},     // (0x24)
    {VK_LEFT, Keyboard::LEFT},     // (0x25)
    {VK_UP, Keyboard::UP},         // (0x26)
    {VK_RIGHT, Keyboard::RIGHT},   // (0x27)
    {VK_DOWN, Keyboard::DOWN},     // (0x28)
    // VK_SELECT (0x29), Old select key},e.g. on Digital Equipment Corporation
    // keyboards.
    {VK_PRINT,
     Keyboard::PRINT}, // (0x2A), Old IBM key},modern keyboards use VK_SNAPSHOT.
    // VK_EXECUTE (0x2B), Old and uncommon.
    {VK_SNAPSHOT, Keyboard::PRINT},    // (0x2C)
    {VK_INSERT, Keyboard::INSERT},     // (0x2D)
    {VK_DELETE, Keyboard::KEY_DELETE}, // (0x2E)
    {VK_HELP, Keyboard::HELP},         // (0x2F)
    {0x30, Keyboard::KEY_0},           // 0 key.
    {0x31, Keyboard::KEY_1},           // 1 key.
    {0x32, Keyboard::KEY_2},           // 2 key.
    {0x33, Keyboard::KEY_3},           // 3 key.
    {0x34, Keyboard::KEY_4},           // 4 key.
    {0x35, Keyboard::KEY_5},           // 5 key.
    {0x36, Keyboard::KEY_6},           // 6 key.
    {0x37, Keyboard::KEY_7},           // 7 key.
    {0x38, Keyboard::KEY_8},           // 8 key.
    {0x39, Keyboard::KEY_9},           // 9 key.
    // 0x3A-40 are undefined.
    {0x41, Keyboard::A},            // A key.
    {0x42, Keyboard::B},            // B key.
    {0x43, Keyboard::C},            // C key.
    {0x44, Keyboard::D},            // D key.
    {0x45, Keyboard::E},            // E key.
    {0x46, Keyboard::F},            // F key.
    {0x47, Keyboard::G},            // G key.
    {0x48, Keyboard::H},            // H key.
    {0x49, Keyboard::I},            // I key
    {0x4A, Keyboard::J},            // J key.
    {0x4B, Keyboard::K},            // K key.
    {0x4C, Keyboard::L},            // L key.
    {0x4D, Keyboard::M},            // M key.
    {0x4E, Keyboard::N},            // N key.
    {0x4F, Keyboard::O},            // O key.
    {0x50, Keyboard::P},            // P key.
    {0x51, Keyboard::Q},            // Q key.
    {0x52, Keyboard::R},            // R key.
    {0x53, Keyboard::S},            // S key.
    {0x54, Keyboard::T},            // T key.
    {0x55, Keyboard::U},            // U key.
    {0x56, Keyboard::V},            // V key.
    {0x57, Keyboard::W},            // W key.
    {0x58, Keyboard::X},            // X key.
    {0x59, Keyboard::Y},            // Y key.
    {0x5A, Keyboard::Z},            // Z key.
    {VK_LWIN, Keyboard::META}, // (0x5B)
    {VK_RWIN, Keyboard::META}, // (0x5C)
    {VK_APPS, Keyboard::MENU},      // (0x5D)
    // 0x5E is reserved.
    {VK_SLEEP, Keyboard::STANDBY},        // (0x5F)
    {VK_NUMPAD0, Keyboard::KP_0},         // (0x60)
    {VK_NUMPAD1, Keyboard::KP_1},         // (0x61)
    {VK_NUMPAD2, Keyboard::KP_2},         // (0x62)
    {VK_NUMPAD3, Keyboard::KP_3},         // (0x63)
    {VK_NUMPAD4, Keyboard::KP_4},         // (0x64)
    {VK_NUMPAD5, Keyboard::KP_5},         // (0x65)
    {VK_NUMPAD6, Keyboard::KP_6},         // (0x66)
    {VK_NUMPAD7, Keyboard::KP_7},         // (0x67)
    {VK_NUMPAD8, Keyboard::KP_8},         // (0x68)
    {VK_NUMPAD9, Keyboard::KP_9},         // (0x69)
    {VK_MULTIPLY, Keyboard::KP_MULTIPLY}, // (0x6A)
    {VK_ADD, Keyboard::KP_ADD},           // (0x6B)
    {VK_SEPARATOR, Keyboard::KP_PERIOD},  // (0x6C)
    {VK_SUBTRACT, Keyboard::KP_SUBTRACT}, // (0x6D)
    {VK_DECIMAL, Keyboard::KP_PERIOD},    // (0x6E)
    {VK_DIVIDE, Keyboard::KP_DIVIDE},     // (0x6F)
    {VK_F1, Keyboard::F1},                // (0x70)
    {VK_F2, Keyboard::F2},                // (0x71)
    {VK_F3, Keyboard::F3},                // (0x72)
    {VK_F4, Keyboard::F4},                // (0x73)
    {VK_F5, Keyboard::F5},                // (0x74)
    {VK_F6, Keyboard::F6},                // (0x75)
    {VK_F7, Keyboard::F7},                // (0x76)
    {VK_F8, Keyboard::F8},                // (0x77)
    {VK_F9, Keyboard::F9},                // (0x78)
    {VK_F10, Keyboard::F10},              // (0x79)
    {VK_F11, Keyboard::F11},              // (0x7A)
    {VK_F12, Keyboard::F12},              // (0x7B)
    {VK_F13, Keyboard::F13},              // (0x7C)
    {VK_F14, Keyboard::F14},              // (0x7D)
    {VK_F15, Keyboard::F15},              // (0x7E)
    {VK_F16, Keyboard::F16},              // (0x7F)
    {VK_F17, Keyboard::F17},              // (0x80)
    {VK_F18, Keyboard::F18},              // (0x81)
    {VK_F19, Keyboard::F19},              // (0x82)
    {VK_F20, Keyboard::F20},              // (0x83)
    {VK_F21, Keyboard::F21},              // (0x84)
    {VK_F22, Keyboard::F22},              // (0x85)
    {VK_F23, Keyboard::F23},              // (0x86)
    {VK_F24, Keyboard::F24},              // (0x87)
    // 0x88-8F are reserved for UI navigation.
    {VK_NUMLOCK, Keyboard::NUMLOCK},   // (0x90)
    {VK_SCROLL, Keyboard::SCROLLLOCK}, // (0x91)
    {VK_OEM_NEC_EQUAL,
     Keyboard::EQUAL}, // (0x92), OEM NEC PC-9800 numpad '=' key.
    // 0x93-96 are OEM specific (e.g. used by Fujitsu/OASYS);
    // 0x97-9F are unassigned.
    {VK_LSHIFT, Keyboard::SHIFT},                   // (0xA0)
    {VK_RSHIFT, Keyboard::SHIFT},                   // (0xA1)
    {VK_LCONTROL, Keyboard::CTRL},                  // (0xA2)
    {VK_RCONTROL, Keyboard::CTRL},                  // (0xA3)
    {VK_LMENU, Keyboard::MENU},                     // (0xA4)
    {VK_RMENU, Keyboard::MENU},                     // (0xA5)
    {VK_BROWSER_BACK, Keyboard::BACK},              // (0xA6)
    {VK_BROWSER_FORWARD, Keyboard::FORWARD},        // (0xA7)
    {VK_BROWSER_REFRESH, Keyboard::REFRESH},        // (0xA8)
    {VK_BROWSER_STOP, Keyboard::STOP},              // (0xA9)
    {VK_BROWSER_SEARCH, Keyboard::SEARCH},          // (0xAA)
    {VK_BROWSER_FAVORITES, Keyboard::FAVORITES},    // (0xAB)
    {VK_BROWSER_HOME, Keyboard::HOMEPAGE},          // (0xAC)
    {VK_VOLUME_MUTE, Keyboard::VOLUMEMUTE},         // (0xAD)
    {VK_VOLUME_DOWN, Keyboard::VOLUMEDOWN},         // (0xAE)
    {VK_VOLUME_UP, Keyboard::VOLUMEUP},             // (0xAF)
    {VK_MEDIA_NEXT_TRACK, Keyboard::MEDIANEXT},     // (0xB0)
    {VK_MEDIA_PREV_TRACK, Keyboard::MEDIAPREVIOUS}, // (0xB1)
    {VK_MEDIA_STOP, Keyboard::MEDIASTOP},           // (0xB2)
    {VK_MEDIA_PLAY_PAUSE,
     Keyboard::MEDIAPLAY}, // (0xB3), Media button play/pause toggle.
    {VK_LAUNCH_MAIL, Keyboard::LAUNCHMAIL},          // (0xB4)
    {VK_LAUNCH_MEDIA_SELECT, Keyboard::LAUNCHMEDIA}, // (0xB5)
    {VK_LAUNCH_APP1, Keyboard::LAUNCH0},             // (0xB6)
    {VK_LAUNCH_APP2, Keyboard::LAUNCH1},             // (0xB7)
    // 0xB8-B9 are reserved.
    {VK_OEM_1, Keyboard::SEMICOLON}, // (0xBA), Misc. character;can vary by
                                     // keyboard/region.
                                     // For US standard keyboards;the ';:' key.
    {VK_OEM_PLUS, Keyboard::EQUAL},  // (0xBB)
    {VK_OEM_COMMA, Keyboard::COMMA}, // (0xBC)
    {VK_OEM_MINUS, Keyboard::MINUS}, // (0xBD)
    {VK_OEM_PERIOD, Keyboard::PERIOD}, // (0xBE)
    {VK_OEM_2,
     Keyboard::SLASH}, // (0xBF), For US standard keyboards;the '/?' key.
    {VK_OEM_3,
     Keyboard::QUOTELEFT}, // (0xC0), For US standard keyboards;the '`~' key.
    // 0xC1-D7 are reserved. 0xD8-DA are unassigned.
    // 0xC3-DA may be used for old gamepads? Maybe we want to support this? See
    // WinUser.h.
    {VK_OEM_4,
     Keyboard::BRACKETLEFT}, // (0xDB),  For US standard keyboards;the '[{' key.
    {VK_OEM_5,
     Keyboard::BACKSLASH}, // (0xDC), For US standard keyboards;the '\|' key.
    {VK_OEM_6,
     Keyboard::BRACKETRIGHT}, // (0xDD), For US standard keyboards;the ']}' key.
    {VK_OEM_7, Keyboard::APOSTROPHE}, // (0xDE), For US standard
                                      // keyboards;single quote/double quote.
    // VK_OEM_8 (0xDF)
    // 0xE0 is reserved. 0xE1 is OEM specific.
    {VK_OEM_102, Keyboard::BAR},   // (0xE2), Either angle bracket or backslash
                                   // key on the RT 102-key keyboard.
    {VK_ICO_HELP, Keyboard::HELP}, // (0xE3)
    // 0xE4 is OEM (e.g. ICO) specific.
    // VK_PROCESSKEY (0xE5), For IME.
    {VK_ICO_CLEAR, Keyboard::CLEAR}, // (0xE6)
    // VK_PACKET (0xE7), Used to pass Unicode characters as if they were
    // keystrokes.
    // 0xE8 is unassigned.
    // 0xE9-F5 are OEM (Nokia/Ericsson) specific.
    {VK_ATTN, Keyboard::ESCAPE}, // (0xF6), Old IBM 'ATTN' key used on
                                 // midrange computers ;e.g. AS/400.
    {VK_CRSEL, Keyboard::TAB},   // (0xF7), Old IBM 3270 'CrSel' (cursor
                                 // select) key},used to select data fields.
    // VK_EXSEL (0xF7), Old IBM 3270 extended selection key.
    // VK_EREOF (0xF8), Old IBM 3270 erase to end of field key.
    {VK_PLAY, Keyboard::MEDIAPLAY}, // (0xFA), Old IBM 3270 'Play' key.
    // VK_ZOOM (0xFB), Old IBM 3290 'Zoom' key.
    // VK_NONAME (0xFC), Reserved.
    // VK_PA1 (0xFD), Old IBM 3270 PA1 key.
    {VK_OEM_CLEAR, Keyboard::CLEAR}, // (0xFE), OEM specific clear key. Unclear
                                     // how it differs from normal clear.
};

#endif