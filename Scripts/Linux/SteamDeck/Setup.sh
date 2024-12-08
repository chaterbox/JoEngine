#!/bin/sh
echo -e "\e[1;96mset steamos readonly to false\e[0m"
echo -e "\e[1;33mAdmin Privages Required\e[0m"
sudo btrfs property set -ts / ro false
echo -e "\e[1;96mInit keyring\e[0m"
sudo pacman-key --init
echo -e "\e[1;96mPopulate keyring\e[0m"
sudo pacman-key --populate archlinux
sudo pacman-key --populate holo
echo -e "\e[1;96mInstall necessary packages\e[0m"
sudo pacman -S glibc linux-api-headers make clang bear
echo -e "\e[1;32mScript done\e[0m"