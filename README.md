# os-listener
Listen for keyboard events from OS (Operating System).  

- Linux
    - ✔️ X11
    - ❌ Wayland
- Windows
    - ❌ When window is focus
    - ✔️ When window isn't focus
- ❌ MacOS

Why only keyboard events? No reason, I could add others.  

# development
```bash
git clone --filter=blob:none --recurse-submodules https://github.com/thiagola92/os-shortcut.git
```

## linux (debian)
```bash
sudo apt install libx11-dev libxcb-xinput-dev

cd godot-cpp
godot --dump-extension-api
scons platform=linux custom_api_file=extension_api.json
cd ..

scons platform=linux                            # Debug
scons platform=linux target=template_release    # Release
```

## windows
```bash
cd godot-cpp
godot --dump-extension-api
python -m SCons platform=windows custom_api_file=extension_api.json
cd ..

python -m SCons platform=windows                            # Debug
python -m SCons platform=windows target=template_release    # Release
```