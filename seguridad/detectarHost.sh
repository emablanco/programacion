#! /bin/bash


#creo un bucle que va del 1 al 254
for i in $(seq 1 254);do
   
    #ejecuto el comando y la salida en caso de erro la redirijo a null
    #en caso de que no produsca erro mando la salida a null
    timeout 1 ping -c 1 192.168.1.$i 2>/dev/null 1>/dev/null

    if [ $? -eq 0 ];then
       echo -e "\nHOST [*]" 
        python3 wichOS.py 192.168.1.$i
    fi
done

