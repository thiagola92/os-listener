# OSListener
Listen for keyboard events from OS (Operating System).  

- Linux
    - ✔️ X11
    - ❌ Wayland
- ✔️ Windows
- ❌ MacOS

Why only keyboard events? No reason, I could add others.  

# Development
```bash
git clone --filter=blob:none --recurse-submodules https://github.com/thiagola92/os-listener.git
```

## Linux (debian)
```bash
sudo apt install libx11-dev libxcb-xinput-dev libxcb-keysyms1-dev

# Wayland static library was compile from official repository.
git clone https://gitlab.freedesktop.org/wayland/wayland
cd wayland
meson build -Ddocumentation=false -Dtests=false -Ddefault_library=static
ninja -C build/ install
cp build/src/libwayland-client.a ../lib
cd ..
rm -rf wayland

cd godot-cpp
godot --dump-extension-api
scons platform=linux custom_api_file=extension_api.json
cd ..

scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
```

Binaries will be located at `test/bin`.  

## Windows
```bash
cd godot-cpp
./godot --dump-extension-api
python -m SCons platform=windows custom_api_file=extension_api.json
cd ..

python -m SCons platform=windows                            # Debug
python -m SCons platform=windows target=template_release    # Release
```

Binaries will be located at `test/bin`.  

## Web
**WARNING**: Needs [Emscripten](https://emscripten.org/) installed and in your PATH (check by writing `emcc` in the terminal).  

```bash
scons platform=web threads=no                            # Debug
scons platform=web threads=no target=template_release    # Release
```

**NOTE**: Not about GDExtension for web but it can help: https://docs.godotengine.org/en/stable/contributing/development/compiling/compiling_for_web.html#doc-compiling-for-web  