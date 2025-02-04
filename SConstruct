#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")
sources = Glob("src/*.cpp")

env.Append(CPPPATH=["src/"])

if env["platform"] == "macos":
    env.Append(CPPDEFINES=["OS_MACOS"])
elif env["platform"] == "windows":
    env.Append(CPPDEFINES=["OS_WINDOWS"])
elif env["platform"] == "linux":
    env.Append(LIBS=["X11", "xcb", "xcb-xinput"], CPPDEFINES=["OS_LINUX"])

    library = env.SharedLibrary(
        "test/bin/liboslistener{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )
else:
    print("OSListener doesn't support this operating system")
    exit(1)

Default(library)
