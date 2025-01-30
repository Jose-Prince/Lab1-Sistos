#include <stdio.h>
#include <unistd.h>

int main() {
    int f = fork(); // Crea un nuevo proceso

    if (f == 0) {
        // Proceso hijo
        execl("./helloworld", "hello", (char*)NULL); // Ejecuta el programa helloworld
    } else {
        // Proceso padre
        printf("%d\n", (int)getpid()); // Imprime el PID del proceso padre
    }

    return 0;
}
