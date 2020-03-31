#!/bin/bash

: '
Autor:		Maynor Ballina
Tipo:		Script de bash
run with:	bash fileGen.sh
fecha:		jue feb 13 13:00:01 CST 2020
Resumen:	Crea un archivo con extencion .c ingresando un header personalizado
'
#bienvenida
echo "*** Este generador de archivos automaticamente ingresa la ***"
echo "*** fecha en la que fue creado, al escribir el nombre del ***"
echo "*** del archivo, este no debe contener la extension '.c'  ***"
echo "*************************************************************"
read -p "Nombre del archivo: " name
fname=$name".c"
if [ -z $name ]; then
	echo El archivo debe de tener un nombre
	exit 2
fi
if [[ "$name" == *".c"* ]] 
then
	name="${name%.*}"
	echo escribiste .c, no importa continuemos.
fi
fname=$name".c"
if [[ -e $fname ]];
then
	echo El archivo $fname ya existe
	exit 2
fi
autor=$(whoami)
fecha=$(date)
compilador=$(gcc --version > nousar && head -n 1 nousar && rm nousar)
echo "/*" > $fname
echo Autor:			$autor >> $fname
echo Compilador:	$compilador >> $fname
echo Compilado:		gcc $fname -o $name >> $fname
echo Fecha:			$fecha >> $fname
echo Librerias:		stdio, otras librerias >> $fname
read -p "Resumen: " resumen
echo Resumen:		$resumen  >> $fname
read -p "Entrada: " entrada
echo "Entrada: " 	$entrada >> $fname
read -p "Salida: " salida
echo "Salida: " 	$salida >> $fname
echo "*/" >> $fname
echo "" >> $fname
echo "//Incluir librerias" >> $fname
echo "#include <stdio.h>" >> $fname
echo "//Declarar variables globales" >> $fname
echo "" >> $fname
echo "//numerar los pasos del pseudocodigo" >> $fname
echo $name >> .gitignore
vim $fname
