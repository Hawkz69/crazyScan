// created by Harrisson Biaggio

#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int my_socket;
    int conn;

    int port;
    int start = 0;
    int end = 65535;
    char *destiny;
    destiny = argv[1];

    if(argc < 2) {
        printf("|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--| \n");
        printf("|--|--|--|--|--|--|--|-- SCANO PORT v1 --|--|--|--|--|--|--|--| \n");
        printf("|--|--|--|--|--|--|-- Use: ./scanoport ip --|--|--|--|--|--|--| \n");
        printf("|--|--|--|--|--|-- dev by: Harrisson Biaggio --|--|--|--|--|--| \n");
        printf("|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--| \n");
        return 0;
    }
   
    struct sockaddr_in target;

    for (port = start; port < end; port++)
    {
       my_socket = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(destiny);

        conn = connect(my_socket, (struct sockaddr *)&target, sizeof target);

        if(conn == 0){
            printf("Port %d [OPEN] \n", port);
            close(my_socket);
            close(conn);
        } else {
            close(my_socket);
            close(conn);
        } 
    }
}