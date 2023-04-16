#! /bin/bash


sudo apt install kdeconnect blender thunderbird gufw clangd firejail htop inkscape handbrake evince vlc meshlab libreoffice gimp qbittorrent terminator vim -y

cd /opt/

wget https://downloads.arduino.cc/arduino-ide/arduino-ide_2.0.4_Linux_64bit.zip

unzip arduino-ide_2.0.4_Linux_64bit.zip

wget https://downloads.arduino.cc/arduino-1.8.19-linux64.tar.xz

tar xvf arduino-1.8.19-linux64.tar.xz


echo "INSTALAR EFM-LANGSERVER NVIM deb http://ftp.de.debian.org/debian bookworm main"

cat > /etc/apt/source.list<<EOF
#deb http://security.debian.org/debian-security bullseye-security main contrib
#deb-src http://security.debian.org/debian-security bullseye-security main contrib

# bullseye-updates, to get updates before a point release is made;
# see https://www.debian.org/doc/manuals/debian-reference/ch02.en.html#_updates_and_backports
# A network mirror was not selected during install.  The following entries
# are provided as examples, but you should amend them as appropriate
# for your mirror of choice.
#
#deb http://deb.debian.org/debian/ bullseye main contrib
#deb-src http://deb.debian.org/debian/ bullseye main contrib
#deb http://ftp.de.debian.org/debian bullseye main non-free

##efm-server instalar 
deb http://ftp.de.debian.org/debian bookworm main 

EOF
sudo apt update
sudo apt install efm-server -y

cat > /etc/apt/source.list<<EOF
deb http://security.debian.org/debian-security bullseye-security main contrib
deb-src http://security.debian.org/debian-security bullseye-security main contrib

# bullseye-updates, to get updates before a point release is made;
# see https://www.debian.org/doc/manuals/debian-reference/ch02.en.html#_updates_and_backports
# A network mirror was not selected during install.  The following entries
# are provided as examples, but you should amend them as appropriate
# for your mirror of choice.
#
deb http://deb.debian.org/debian/ bullseye main contrib
deb-src http://deb.debian.org/debian/ bullseye main contrib
deb http://ftp.de.debian.org/debian bullseye main non-free

##efm-server instalar 
#deb http://ftp.de.debian.org/debian bookworm main 

EOF
cd ~

sudo curl -fsSL https://deb.nodesource.com/setup_19.x | bash - &&\
sudo apt-get install -y nodejs

sudo npm install -g bash-language-server pyright vscode-langservers-extracted typescript typescript-language-server

echo "Descargar haroopad http://pad.haroopress.com/user.html"
wget https://bitbucket.org/rhiokim/haroopad-download/downloads/haroopad-v0.13.1-x64.deb
