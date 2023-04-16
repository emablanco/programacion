#!/bin/bash


#TOKEN
TOKEN='5608271045:AAHJOM8H7R5c9MVQsjNq-IhDdefEYWKXkVI'

# ID DEL CHAT O GRUPO
ID='-1001531220301'

function enviarMensajeAlBot() {
	
	#$0 -> REPRESENTA EL NOMBRE DEL ARCHIVO
	#$1 -> REPRESENTA EL PRIMER ARGUMENTO QUE SE PASA
	#$2 -> REPRESENTA EL SEGUNDO ARGUMENTO QUE SE PASA
	#${3,4,5,6,7,8,9} -> REPRESENTA ARGUMENTOS

	message=$1
	
	#ENVIA UN MENSAJE 
	curl -s -X POST https://api.telegram.org/bot${TOKEN}/sendMessage -d text="${message}" -d chat_id=${ID} > /dev/null 2>&1
}

#COMPARA LA CANDITDAD DE ARGUMENTOS PASADOS AL SCRIPT
# 0 -> no se paso ningun argumento
#imprime en pantalla los parametros que se deben pasar

if [ $# -eq 0 ]; then

	#-a -> start o stop
	#-b -> IP baneada
	#-u -> IP desbaneada
	#
	echo "Usage $0 -a ( start || stop ) || -b \$IP || -u \$IP"
	
	#FINALIZA EL SCRIPT
	exit 1;
fi


#PARAMETROS ACEPTADOS
#-a, -n , -b , -u

while getopts "a:n:b:u:" opcion; do

	case "$opcion" in
		a)
			accion=$OPTARG
		;;
		n)
			nombre_jaula=$OPTARG
		;;
		b)
			ban=y #se crea una variable con el caracter "y"
			ip_add_ban=$OPTARG #se guarda la IP dentro de esta variable
		;;
		u)
			unban=y # se crea una variable con el caracter "y"
			ip_add_unban=$OPTARG # la IP se guarda dentro de esta variable
		;;
		\?)  #cualquier otro parametro es invalido y termina el script
			echo "OPCION INVALIDA. -$OPTARG" 
			exit 1
		;;
	esac
done

# -z -> Verdadero si la longitud de la cadena es cero.
#si la variable string no esta vacia devuelve false y ! la niega y cambia a true.

if [[ ! -z ${accion} ]]; then

	case "${accion}" in

		start) #si la variable "accion" contine la cadena "start"

			enviarMensajeAlBot "FAIL2BAN START"
		;;
		
		stop) # si la variable "accion" contiene la cadena "stop"
		
			enviarMensajeAlBot "FAIL2BAN STOP"
		;;
		
		*) # si la variable "accion" contiene cualquier otra cadena
			
			echo "OPCION INCORRECTA"
			
			exit 1; #termina el script
		;;

	esac

elif [[ ${ban} == "y" ]]; then

	#se llama a la funcion con un solo argumento
	#[nobre de la jaula] IP y el mensaje
	enviarMensajeAlBot "[${nombre_jaula}] LA IP: ${ip_add_ban} FUE BANEADA"
	
	exit 0;

elif [[ ${unban} == "y" ]]; then

	#se llama a la funcion con un solo argumento que es nombre de la jaula, ip y mensaje
	enviarMensajeAlBot "[${nombre_jaula}] LA IP: ${ip_add_unban} FUE DESBANEADA"
	
	#finaliza el script correctamente
	exit 0;
else

	info
fi
