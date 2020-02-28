#!/bash/bim
echo "Agregar nombre del archivo"			#nombre que llevarà  el archivo
read y							#comando que leerà lo que se escriba

if [ "$y" == "" ];					#si el archivo està vacìo, pedir escribir algo
then
echo "No es aceptable un archivo vacìo, agregar nombre para continuar"
else

if [ "${y:(-2)}" == ".c" ]; 				#Si se le agrega el .c pedir que sea quitado.
then
echo "No se debe agregar .c al final, quitarlo para continuar."

else
touch $y.c						#Creaciòn del archivo .c

y=$(hostname)						#Variables que guardaràn informacion a utilizar.
version=$(gcc --version)
fecha=$(date)


echo Resumen:						#Vamos a preguntarle al usuario què quiere agregar en su  
read Resumen						#archivo .c

echo Entrada:
read Entrada

echo Salida:
read Salida

touch versiongcc.txt					#creamos un archivo .txt el cual almacenarà los datos de la versiòn de gcc.
echo "$version" > versiongcc.txt


							#Hacemos echo a lo que se nos pide.
echo " 
/* Autor: $x
Compilador: $(head -1 versiongcc.txt)
Fecha: $fecha
Resumen $Resumen
Entrada:$Entrada
Salida: $Salida
*/

//librearias
#include <stdio.h>
//numerar los pasos del pseudocodigo
	" > $y.c					#Que lo anterior estè en nuestro archivo .c
	rm versiongcc.txt				#Que se borre el .txt de version
	vim $y.c					#Que sea abierto automàticamente en vim
	fi
fi

