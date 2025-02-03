# os-listener

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