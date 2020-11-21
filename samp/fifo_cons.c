/* Filename: fifoclient_twoway.c */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/fifo_twoway"
int main()
{
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[80];
   char end_str[5];
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
   fd = open(FIFO_FILE, O_CREAT | O_RDWR);
   strcpy(end_str, "end");

   while (1)
   {
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';
      end_process = strcmp(readbuf, end_str);

      //printf("end_process is %d\n", end_process);
      if (end_process != 0)
      {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         readbuf[read_bytes] = '\0';
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      }
      else
      {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);
         break;
      }
   }
   return 0;
}


//FIFO_CLIENT: Send messages, infinitely, to end enter "end"
//Enter string: LINUX IPCs
//FIFOCLIENT: Sent string: "LINUX IPCs" and string length is 10
//FIFOCLIENT: Received string: "sCPI XUNIL" and length is 10
//Enter string: Inter Process Communication
//FIFOCLIENT: Sent string: "Inter Process Communication" and string length is 27
//FIFOCLIENT: Received string: "noitacinummoC ssecorP retnI" and length is 27
//Enter string: end
//FIFOCLIENT: Sent string: "end" and string length is 3