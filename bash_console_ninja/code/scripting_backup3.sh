#!/bin/bash

ARCHIVO=laodisea
SERVIDOR_REMOTO=grecia
USUARIO=homero

echo "Copiando $ARCHIVO a $SERVIDOR_REMOTO..."
# Comprimir el archivo antes de enviarlo
tar -xvzf $ARCHIVO.tar.gz $ARCHIVO
scp $ARCHIVO.tar.gz $USUARIO @ $SERVIDOR_REMOTO:~
rm $ARCHIVO.tar.gz
echo "Fin!"


