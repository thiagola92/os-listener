# Compiling static libraries

```bash
# libX11
sudo apt build-dep libx11-dev

git clone --filter=blob:none --recurse-submodules https://gitlab.freedesktop.org/xorg/lib/libx11.git
cd libx11

./autogen.sh
./configure --enable-static --disable-shared CFLAGS="-fPIC"
make

cd ..
cp libx11/src/.libs/libX11.a libs
cp libx11/src/.libs/libX11-xcb.a libs
rm -rf libx11

# libxcb
sudo apt build-dep libx11-dev

git clone --filter=blob:none --recurse-submodules https://gitlab.freedesktop.org/xorg/lib/libxcb.git
cd libxcb

./autogen.sh
./configure --enable-static --disable-shared CFLAGS="-fPIC"
make

cd ..
cp libxcb/src/.libs/libxcb.a libs
cp libxcb/src/.libs/libxcb-xinput.a libs
cp libxcb/src/.libs/libxcb-randr.a libs
rm -rf libxcb

# libxcb-keysyms
sudo apt build-dep libxcb-keysyms1-dev

git clone --filter=blob:none --recurse-submodules https://gitlab.freedesktop.org/xorg/lib/libxcb-keysyms.git
cd libxcb-keysyms

./autogen.sh
./configure --enable-static --disable-shared CFLAGS="-fPIC"
make

cd ..
cp libxcb-keysyms/keysyms/.libs/libxcb-keysyms.a libs
rm -rf libxcb-keysyms

# libXau
sudo apt build-dep libxau-dev

git clone --filter=blob:none --recurse-submodules https://gitlab.freedesktop.org/xorg/lib/libxau.git
cd libxau

./autogen.sh
./configure --enable-static --disable-shared CFLAGS="-fPIC"
make

cd ..
cp libxau/.libs/libXau.a libs
rm -rf libxau

# libXdmcp
sudo apt build-dep libxdmcp-dev

git clone --filter=blob:none --recurse-submodules https://gitlab.freedesktop.org/xorg/lib/libxdmcp.git
cd libxdmcp

./autogen.sh
./configure --enable-static --disable-shared CFLAGS="-fPIC"
make

cd ..
cp libxdmcp/.libs/libXdmcp.a libs
rm -rf libxdmcp

# libffi
sudo apt build-dep libffi-dev

git clone --filter=blob:none --recurse-submodules https://github.com/libffi/libffi.git
cd libffi

./autogen.sh
./configure --disable-shared --enable-static CFLAGS="-fPIC"
make

cd ..
cp libffi/x86_64-pc-linux-gnu/.libs/libffi.a libs
cp libffi/x86_64-pc-linux-gnu/.libs/libffi_convenience.a libs
rm -rf libffi

# wayland-client
sudo apt build-dep libwayland-client0

git clone --filter=blob:none --recurse-submodules https://gitlab.freedesktop.org/wayland/wayland
cd wayland

meson build -Ddocumentation=false -Dtests=false -Ddefault_library=static -Dc_args=-fPIC -Dcpp_args=-fPIC
ninja -C build/ install

cd ..
cp wayland/build/src/libwayland-client.a libs
rm -rf wayland
```