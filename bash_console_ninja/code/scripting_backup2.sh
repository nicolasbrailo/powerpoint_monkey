#!/bin/bash

ARCHIVO=laodisea
SERVIDOR_REMOTO=grecia
USUARIO=homero

echo "Copiando $ARCHIVO a $SERVIDOR_REMOTO..."
scp $ARCHIVO $USUARIO @ $SERVIDOR_REMOTO:~
echo "Fin!"

