#! /bin/python3.9


#importo las librerias necesarias

#para usar expreciones regulares y buscar el ttl
import re

#para obtener la ip que ingrese el usuario por la consola o interprete
import sys

#para ejecutar procesos desde python . 
import subprocess

#en caso del que el tamaño sea superior oinferior a dos
#es porque puso menos argumentos o demaciados
if len(sys.argv) != 2:

    print("[Uso] python3 {} <ip-address>".format(sys.argv[0]))

#Entra al if porque uso mal la erramienta y con sys.exit(1)
#corto la ejecucion.
    sys.exit(1)

def get_ttl(ip):

    #creo el proceso
    ping = subprocess.Popen(["/usr/bin/ping -c 1 {}".format(ip),""], \
            stdout = subprocess.PIPE, shell = True )

    #ejecutor el proceso llamado ping y lo almaceno en una tupla dentro de ttl
    ttl = ping.communicate()

    #busco dentro de la tupla el ttl y lo returno en formato entero
    ttl = int(re.findall(r'\d{1,3}',re.findall(r'ttl=\d{1,3}',\
            ttl[0].decode('utf-8'))[0])[0]) 

    return ttl 

def get_os(ttl):
    
#dependiendo del numero de ttl informara si es una maquina Windows o Linux
    if ttl > 0 and ttl <= 64:

        return "LINUX"

    elif ttl > 64 and ttl <= 128:
        return "WINDOWS"
    
    else:
        return "NOT FOUND"

if __name__ == '__main__':

    #la primera posicion es el nombre de la herramienta el segundo es la ip
    #tomo la ip y la almaceno en una variable
    ip = sys.argv[1]

    ttl = get_ttl(ip)

    os = get_os(ttl)

    print("ip => {}\nttl => {}\nos => {}".format(ip,ttl,os))

