#!bin/bash    			#escribimos bin bash siempre al principio
clima=$(curl wttr.in)		#definimos la variable clima
echo "$clima" > text.txt	#le decimosa a la màquina que tome el archivo .txt y le haga echo
head -7 text.txt		#definimos con el comanto head cuantas lineas queremos mostrar
rm text.txt			#borramos el archivo .txt
