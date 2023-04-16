#! /bin/bash

sudo apt install apt-transport-https curl -y

cd ~/Descargas

wget https://github.com/ryanoasis/nerd-fonts/releases/download/v2.2.2/Hack.zip

unzip Hack.zip

sudo mv *.ttf /usr/share/fonts

#fondo de Pantalla

sudo apt install feh -y

mkdir -p ~/.fondo

echo "feh --bg-fill ~/.fondo/fondo.jpg" >> ~/.config/bspwm/bspwmrc

cd ~/Descargas

git clone https://github.com/VaughnValle/blue-sky.git

mkdir -p ~/.config/polybar

cd ~/Descargas/blue-sky/polybar/

cp * -r ~/.config/polybar

echo '~/.config/polybar/./launch.sh' >> ~/.config/bspwm/bspwmrc

cd fonts

sudo cp * /usr/share/fonts/truetype/

fc-cache -v

mkdir -p ~/.config/picom

cd ~/.config/picom

cp ~/Descargas/blue-sky/picom.conf .

echo 'picom --experimental-backends &' >> ~/.config/bspwm/bspwmrc

echo 'bspc config border_width 0' >> ~/.config/bspwm/bspwmrc

echo "bspc config focus_follows_pointer true" >> ~/.config/bspwm/bspwmrc

mkdir -p ~/.config/bin

mkdir -p ~/.config/rofi/themes

cp ~/Descargas/blue-sky/nord.rasi ~/.config/rofi/themes

xsetroot -cursor_name left_ptr &

wget https://github.com/sharkdp/bat/releases/download/v0.22.1/bat-musl_0.22.1_amd64.deb

sudo dpkg -i bat-musl_0.22.1_amd64.deb

wget https://github.com/Peltoche/lsd/releases/download/0.23.1/lsd-musl_0.23.1_amd64.deb

sudo dpkg -i lsd-musl_0.23.1_amd64.deb

git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
~/.fzf/install

sudo apt install ranger zsh

sudo apt install fzf gnome-session gnome-shell gnome-backgrounds gnome-applets gnome-control-center mutter gjs gnome-terminal

