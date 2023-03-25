#include <iostream>
#include <string>
#include <regex>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int get_ttl(string ip_address) {

    // Creo el proceso y lo redirijo a la salida estándar
    string cmd = "/bin/ping -c 1 " + ip_address;
    FILE* pipe = popen(cmd.c_str(), "r");

    if (!pipe) {
        return -1;
    }

    // Leo la salida del comando ping
    string ping_output;
    char buffer[128];
    while (fgets(buffer, 128, pipe)) {
        ping_output += buffer;
    }

    // Cierro el proceso
    int status = pclose(pipe);
    if (status < 0) {
        return -1;
    }

    // Busco el TTL en la salida del comando ping
    regex re("ttl=(\\d+)");
    smatch match;
    if (regex_search(ping_output, match, re)) {
        return stoi(match[1]);
    } else {
        return -1;
    }
}

string get_os(int ttl) {
    if (ttl > 0 && ttl <= 64) {
        return "LINUX";
    } else if (ttl > 64 && ttl <= 128) {
        return "WINDOWS";
    } else {
        return "NOT FOUND";
    }
}

int main(int argc, char *argv[]) {

    // Verifico el número de argumentos
    if (argc != 2) {
        cerr << "[Uso] " << argv[0] << " <ip-address>" << endl;
        exit(1);
    }

    // Obtengo la dirección IP
    string ip_address = argv[1];

    // Obtengo el TTL
    int ttl = get_ttl(ip_address);
    if (ttl == -1) {
        cerr << "Error: no se pudo obtener el TTL" << endl;
        exit(1);
    }

    // Obtengo el sistema operativo
    string os = get_os(ttl);

    // Imprimo los resultados
    cout << "ip => " << ip_address << endl;
    cout << "ttl => " << ttl << endl;
    cout << "os => " << os << endl;

    return 0;
}
