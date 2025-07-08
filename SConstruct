#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

sources = Glob("src/*.cpp")
env.Append(CPPPATH=["src/"])

if env["platform"] == "macos":
    env.Append(CPPDEFINES=["OS_MACOS"])
elif env["platform"] == "windows":
    env.Append(
        LIBS=["User32.lib"],
        CPPPATH=["src/windows/"],
        CPPDEFINES=["OS_WINDOWS"],
    )

    sources += Glob("src/windows/*.cpp")

    library = env.SharedLibrary(
        "demo/bin/windows/liboslistener{}{}".format(
            env["suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )
elif env["platform"] == "linux":
    env.Append(
        LIBPATH=["libs"],
        CPPPATH=["src/linux/"],
        CPPDEFINES=["OS_LINUX"],
        CCFLAGS=["-fPIC"],
    )

    sources += Glob("src/linux/*.cpp")

    library = env.SharedLibrary(
        "demo/bin/linux/liboslistener{}{}".format(
            env["suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
        LINKFLAGS=[
            # Force error.
            "-Wl,--no-undefined",
            # Order matters, dependencies must be linked first. For example:
            # libX11 uses libX11-xcb,               so libX11-xcb first
            # libxcb uses libxcb-xinput,            so libxcb-xinput first
            # libxcb uses libxcb-randr,             so libxcb-randr first
            # libwayland-client uses libffi,        so libffi first...
            "-Wl,--whole-archive",
            "libs/libffi.a",
            "libs/libwayland-client.a",
            "libs/libX11-xcb.a",
            "libs/libX11.a",
            "libs/libXau.a",
            "libs/libXdmcp.a",
            "libs/libxcb-keysyms.a",
            "libs/libxcb-randr.a",
            "libs/libxcb-xinput.a",
            "libs/libxcb.a",
            "-Wl,--no-whole-archive",
        ],
    )
else:
    # Creates library but the library doesn't do nothing.
    library = env.SharedLibrary(
        "demo/bin/{}/liboslistener{}{}".format(
            env["platform"],
            env["suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )

Default(library)
