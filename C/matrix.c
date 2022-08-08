#include <stdio.h>
#include <windows.h>
#include <string.h>

int main(int argc, char **argv)
{


  int arg_index;  //index of command line argument
  int length;     //length of current arg
  int count;      //index of current letter in arg
  int ch;         //ascii index of current letter
  int letter;

  if (argc < 2) {
    printf("nUsage: PROG stringn");
    return 0;
  }

  for(arg_index = 1; arg_index < argc; arg_index++){

      length = strlen(argv[arg_index]);

      for(count = 0; count <= length; count++){

          ch = argv[arg_index][count];

          for(letter = 65; letter < ch; letter++){

               printf("%c", letter);
               Sleep(10);
               printf("b");

           }
          printf("%c", ch);
      }
  }

 return 0;
}
