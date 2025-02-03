#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")
sources = Glob("src/*.cpp")

env.Append(CPPPATH=["src/"])

if env["platform"] == "macos":
    pass
elif env["platform"] == "windows":
    pass
elif env["platform"] == "ios":
    pass
else:
    env.Append(LIBS=["X11", "xcb", "xcb-xinput"])

    library = env.SharedLibrary(
        "test/bin/liboslistener{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
