/** https://www.joinc.co.kr/w/man/3/htons
 *  htonl : host byte order을 따르는 데이터를 network byte order로 변경한다.
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

/* ./server <server Port> */
#define MAX_MSG 30
int main(int argc, char *argv[])
{
  int serv_sock, clnt_sock = -1; // socket filedescriptor
  struct sockaddr_in serv_addr, clnt_addr;
  socklen_t clnt_addr_size;
  char msg[MAX_MSG];

  serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_IP); // PF_INET = IPv4, SOCK_STREAM = TCP
  printf("fd of socket : %d\n", serv_sock);

  uint32_t x = 0x01020304;
  printf("%08x\n", x);
  printf("%08x\n", htonl(x));
  printf("%04x\n", htons(x));
  printf("%08x\n", ntohl(x));
  printf("%04x\n\n", ntohs(x));

  char addr[30] = "192.168.0.1";
  struct in_addr trans_addr;
  trans_addr.s_addr = inet_addr(addr);
  unsigned long trans_addr01 = inet_addr(addr);
  printf("%08lx\n", trans_addr01);
  printf("%08x\n", trans_addr.s_addr); // 168 -16진수-> a8
  char *ptr = inet_ntoa(trans_addr);
  printf("%s\n", ptr);

  // if(serv_sock == -1) error_handling("socket() error");
  // memset(&serv_addr, 0 , sizeof(serv_addr));
  // serv_addr.sin_family = AF_INET;
  // serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  // serv_addr.sin_port = htons(atoi(argv[1]));

  // printf("02\n");

  // /* bind */
  // if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
  //   error_handling("bind() error");

  // printf("03\n");

  // if(listen(serv_sock,5) == -1) error_handling("listen() error");

  // printf("04\n");

  // if(clnt_sock<0){
  //   clnt_addr_size = sizeof(clnt_addr);
  //   clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
  //   if(clnt_sock == -1)
  //     error_handling("accept() error");
  // }

  // printf("05\n");

  // while(1){
  //   printf(">> ");
  //   fgets(msg, sizeof(msg), stdin);
  //   write(clnt_sock, msg, sizeof(msg));
  // }

  close(clnt_sock);
  close(serv_sock);

  return (0);
}