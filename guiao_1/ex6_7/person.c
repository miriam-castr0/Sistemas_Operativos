/* Write and read a binary file using system calls
   (open, write, read e close) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* For system calls write, read e close */

#include <sys/types.h> /* For system call open */
#include <sys/stat.h>  /* For system call open */
#include <fcntl.h>     /* For system call open */



typedef struct person
{
  char name[100];
  unsigned int age;

} person_t;

int main(int argc, const char *argv[])
{
  int fd; 
  person_t people;
  int i;
  int age;
 
  if (argc != 4)
  {
    printf("not enough arguments");
    _exit(1);
  }

  sscanf(argv[3], "%d", &age);

  // --------------------- Write the struct -------------
  if (strcmp(argv[1], "-i") == 0)
  {

    strcpy(people.name, argv[2]);
    people.age = age;

    fd = open("out.bin", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd == -1)
    { /* In the case of error, open returns -1 ! */
      perror("Fail to open: ");
      _exit(1);
    }

    write(fd, &people, sizeof(person_t));

    int n = lseek(fd, 0, SEEK_CUR);
    printf("registo %ld\n", n / sizeof(person_t));

    close(fd);
  }

  //------------------- Change age-------------------
  if (strcmp(argv[1], "-u") == 0)
  {

    fd = open("out.bin", O_RDWR, 0666);
    if (fd == -1)
    { /* In the case of error, open returns -1 ! */
      perror("Fail to open: ");
      _exit(1);
    }
    int i = 0;
    int n = 0;

    while ((i = read(fd, &people, sizeof(person_t)) > 0))
    {

      if (strcmp(people.name, argv[2]) == 0)
      {
        people.age = age;

        lseek(fd, -sizeof(person_t), SEEK_CUR);
        write(fd, &people, sizeof(person_t));
        break;
      }
    }
    close(fd);
  }

  //------------- Change Age by Regist-----------------
  if (strcmp(argv[1], "-U") == 0)
  {

    fd = open("out.bin", O_RDWR, 0666);
    if (fd == -1)
    { /* In the case of error, open returns -1 ! */
      perror("Fail to open: ");
      _exit(1);
    }
    int regist = 0;
    int i = 0;
    int n = 0;

    sscanf(argv[2], "%d", &regist);
    regist -= 1; //o registo é o 5, por exemplo, mas é o final do registo, o apontador tem de estar
                 //no inicio do registo, logo como se fosse no anterior

    lseek(fd, regist * sizeof(person_t), SEEK_SET);
    read(fd, &people, sizeof(person_t));    //ao fazer read o apontador fica com mais 104 bytes
    lseek(fd, -sizeof(person_t), SEEK_CUR); //aqui volto ao valor de onde quero alterar

    people.age = age;
    write(fd, &people, sizeof(person_t));

    close(fd);
  }

  //---------------- Read file---------------
  fd = open("out.bin", O_RDONLY);
  if (fd == -1)
  {
    perror("Fail to open: ");
    _exit(1);
  }
  i = 0;
  while ((i = read(fd, &people, sizeof(person_t)) > 0))
  {
    printf("%s %d\n", people.name, people.age);
  }

  close(fd);

  return 0;
}
