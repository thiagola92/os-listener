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
        "test/bin/liboslistener{}{}".format(
            env["suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )
elif env["platform"] == "linux":
    env.Append(
        CPPPATH=["src/linux/"],
        CPPDEFINES=["OS_LINUX"],
        LIBPATH=["lib"],
        LINKFLAGS=["-l:libX11.a", "-l:libxcb.a", "-l:libxcb-xinput.a", "-l:libxcb-keysyms.a", "-l:libwayland-client.a"]
    )

    sources += Glob("src/linux/*.cpp")

    library = env.SharedLibrary(
        "test/bin/linux/liboslistener{}{}".format(
            env["suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )
else:
    # Creates library but the library doesn't do nothing.
    library = env.SharedLibrary(
        "test/bin/{}/liboslistener{}{}".format(
            env["platform"],
            env["suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )

Default(library)
