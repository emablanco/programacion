Generar un binario que tome el uid del usuario que lo llama.. y que escriba en alguna parte del / el uid
para que luego lo tome systemd
# Espera 30 segundos (ajusta este valor según tus necesidades)
sleep 30

# Lee el UID desde el archivo temporal
USER_UID=$(cat /tmp/uid_temp.txt)

# Realiza la configuración que depende del UID
# ... tu código de configuración aquí ...
------------------------------------------------------------------------------------------------
Dentro de bash_profile

aqui ejecutar el binario
# Obtén el UID del usuario actual
USER_UID=$(id -u)

# Escribe el UID en el archivo /tmp/limit.txt
echo "$USER_UID" > /tmp/limit.txt

-----------------------------------------------------------------------------------------------


Este script lo ejecuta defaul.conf

#!/bin/bash

# Ruta al archivo que contiene el UID del usuario
UID_FILE="/tmp/limit.tex"

# Verifica si el archivo existe y si se puede leer
if [ -r "$UID_FILE" ]; then
  # Lee el UID del archivo
  USER_UID=$(cat "$UID_FILE")

  # Límite de CPU en milisegundos (50.000 milisegundos = 50 segundos)
  CPU_LIMIT=50000

  # Ruta al archivo de configuración del cgroup
  CGROUP_FILE="/sys/fs/cgroup/user.slice/user-$USER_UID.slice/cpu.max"

  # Verifica si el directorio cgroup existe
  if [ -d "$(dirname $CGROUP_FILE)" ]; then
    # Configura el límite de CPU
    echo "$CPU_LIMIT" > "$CGROUP_FILE"
    echo "Límite de CPU configurado correctamente para el usuario con UID $USER_UID."
  else
    echo "El directorio cgroup no existe. Asegúrate de que el usuario haya iniciado sesión y que el directorio cgroup esté disponible."
  fi
else
  echo "No se puede leer el archivo de UID en $UID_FILE. Asegúrate de que el archivo exista y tenga permisos de lectura."
fi


