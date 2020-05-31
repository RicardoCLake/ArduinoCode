#! /bin/bash

arquivos=`ls -1 -b *.ino`
proximo=${arquivos%%.ino*}

echo $proximo

mkdir $proximo

mv $proximo".ino" ./$proximo

echo "DEU CERTO!"