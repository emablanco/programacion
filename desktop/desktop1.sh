
#! /bin/bash

sudo apt install -y build-essential xorg xterm git kitty vim xcb libxcb-util0-dev libxcb-ewmh-dev libxcb-randr0-dev libxcb-icccm4-dev libxcb-keysyms1-dev libxcb-xinerama0-dev libasound2-dev libxcb-xtest0-dev libxcb-shape0-dev
sudo apt install --no-install-recommends xserver-xorg-core
sudo apt install --no-install-recommends xterm
sudo apt install --no-install-recommends xserver-xorg-video-amdgpu # Si tu tarjeta gráfica es intel, cambiamos amdgpu por intel
sudo apt install --no-install-recommends xserver-xorg-input-libinput
sudo apt install --no-install-recommends sxhkd bspwm

mkdir -p ~/Descargas

cd ~/Descargas

git clone https://github.com/baskerville/bspwm.git
git clone https://github.com/baskerville/sxhkd.git

cd bspwm/

make

sudo make install

cd ../sxhkd/

make

sudo make install

sudo apt install bspwm

mkdir -p ~/.config/bspwm

mkdir -p ~/.config/sxhkd

cd ~/Descargas/bspwm/

cp examples/bspwmrc ~/.config/bspwm/

chmod +x ~/.config/bspwm/bspwmrc

cat > ~/.config/sxhkd/sxhkdrc<<EOF

# wm independent hotkeys

#screenshot
ctrl + shift + s
 gnome-screenshot

# terminal emulator

super + Return
 /usr/bin/kitty

# program launcher

super + d
 rofi -show run

#caja laucher

ctrl + shift + n
 nautilus

# make sxhkd reload its configuration files:

super + Escape
 pkill -USR1 -x sxhkd

# bspwm hotkeys

#firefox

ctrl + shift + b
 firejail /opt/brave.com/brave/brave-browser

# quit/restart bspwm

super + alt + {q,r}
 bspc {quit,wm -r}

# close and kill

super + {_,shift + }w
 bspc node -{c,k}

# alternate between the tiled and monocle layout

super + m
 bspc desktop -l next

# send the newest marked node to the newest preselected node

super + y
 bspc node newest.marked.local -n newest.!automatic.local

# swap the current node and the biggest node

super + g
 bspc node -s biggest

# state/flags

# set the window state

super + {t,shift + t,s,f}
 bspc node -t {tiled,pseudo_tiled,floating,fullscreen}

# set the node flags

super + ctrl + {m,x,y,z}
 bspc node -g {marked,locked,sticky,private}

# focus/swap

super + {_,shift + }{Left,Down,Up,Right}
 bspc node -{f,s} {west,south,north,east}

# focus the node for the given path jump

super + {p,b,comma,period}
 bspc node -f @{parent,brother,first,second}

# focus the next/previous node in the current desktop

super + {_,shift + }c
 bspc node -f {next,prev}.local

# focus the next/previous desktop in the current monitor

super + bracket{left,right}
 bspc desktop -f {prev,next}.local

# focus the last node/desktop

super + {grave,Tab}
 bspc {node,desktop} -f last

# focus the older or newer node in the focus history

super + {o,i}
 bspc wm -h off; \
 bspc node {older,newer} -f; \
 bspc wm -h on

# focus or send to the given desktop

super + {_,shift + }{1-9,0}
 bspc {desktop -f,node -d} '^{1-9,10}'

# preselect

# preselect the direction

super + ctrl + alt + {Left,Down,Up,Right}
 bspc node -p {west,south,north,east}

# preselect the ratio

super + ctrl + {1-9}
 bspc node -o 0.{1-9}

# cancel the preselection for the focused node

super + ctrl + space
 bspc node -p cancel

# cancel the preselection for the focused desktop

super + ctrl + alt + space
 bspc query -N -d | xargs -I id -n 1 bspc node id -p cancel

# move/resize

# expand a window by moving one of its side outward

#super + alt + {h,j,k,l}

# bspc node -z {left -20 0,bottom 0 20,top 0 -20,right 20 0}

# contract a window by moving one of its side inward

#super + alt + shift + {h,j,k,l}

# bspc node -z {right -20 0,top 0 20,bottom 0 -20,left 20 0}

# move a floating window

super + ctrl + {Left,Down,Up,Right}
 bspc node -v {-20 0,0 20,0 -20,20 0}

# Custom move/resize

alt + super + {Left,Down,Up,Right}
 /home/natsu/.config/bspwm/scripts/bspwm_resize {west,south,north,east}
EOF

mkdir -p ~/.config/bspwm/scripts/

cat >~/.config/bspwm/scripts/bspwm_resize<<EOF

#!/usr/bin/env dash

if bspc query -N -n focused.floating > /dev/null; then
step=20
else
 step=100
fi

case "$1" in
 west) dir=right; falldir=left; x="-$step"; y=0;;
 east) dir=right; falldir=left; x="$step"; y=0;;
 north) dir=top; falldir=bottom; x=0; y="-$step";;
 south) dir=top; falldir=bottom; x=0; y="$step";;
esac

bspc node -z "$dir" "$x" "$y" || bspc node -z "$falldir" "$x" "$y"
EOF

chmod +x ~/.config/bspwm/scripts/bspwm_resize

sudo apt install -y cmake cmake-data pkg-config python3-sphinx libcairo2-dev libxcb1-dev libxcb-util0-dev libxcb-randr0-dev libxcb-composite0-dev python3-xcbgen xcb-proto libxcb-image0-dev libxcb-ewmh-dev libxcb-icccm4-dev libxcb-xkb-dev libxcb-xrm-dev libxcb-cursor-dev libasound2-dev libpulse-dev libjsoncpp-dev libmpdclient-dev libcurl4-openssl-dev libnl-genl-3-dev

cd ~/Descargas

sudo apt install libuv1-dev

git clone --recursive https://github.com/polybar/polybar

cd polybar/

mkdir -p build

cd build/

cmake ..

make -j$(nproc)

sudo make install

sudo apt update
sudo apt install -y meson libxext-dev libxcb1-dev libxcb-damage0-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-render-util0-dev libxcb-render0-dev libxcb-randr0-dev libxcb-composite0-dev libxcb-image0-dev libxcb-present-dev libxcb-xinerama0-dev libpixman-1-dev libdbus-1-dev libconfig-dev libgl1-mesa-dev libpcre2-dev libevdev-dev uthash-dev libev-dev libx11-xcb-dev libxcb-glx0-dev

cd ~/Descargas

git clone https://github.com/ibhagwan/picom.git

cd picom/

git submodule update --init --recursive

sudo apt install libpcre3-dev -y

meson --buildtype=release . build

ninja -C build

sudo ninja -C build install

sudo apt install rofi -y

sudo reboot
