#!/bin/bash

#à noter que "Linux" seul est pour la distribution Linux Mint

var=`cat /etc/issue | cut -f1 -d ' '` # Recupere le premier du nom de la distribution

if [ $var = "Debian" ] || [ $var = "Ubuntu" ] || [ $var = "Linux" ] 
then
	sudo apt-get install -y libsdl*
elif [ $var = "Fedora" ] || [ $var = "openSUSE" ] || [ $var = "CentOS" ]
then
	sudo yum -y install SDL*
fi

make
