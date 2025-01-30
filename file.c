#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd_origen, fd_destino;
    char buf[1024];
    ssize_t bytes_leidos;

    fd_origen = open(argv[1], O_RDONLY);

    if (fd_origen == -1) {
        perror("Error al abrir el archivo origen");
        return 1; 
    }

    fd_destino = open(argv[2], O_WRONLY | O_CREAT, 0644);

    if (fd_destino == -1) {
        perror("Error al abrir el archivo destino");
        return 1; 
    }

    while ((bytes_leidos = read(fd_origen, buf, sizeof(buf))) > 0) {
        if (write(fd_destino, buf, bytes_leidos) == -1) {
            perror("Error al escribir en el archivo destino");
            close(fd_origen);
            close(fd_destino);
            return 1; 
        }
    }

    close(fd_origen);
    close(fd_destino);

    printf("Archivo copiado exitosamente.\n");

    return 0; 
}
