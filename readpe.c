#include <stdio.h>
#include <stdlib.h>
#include "lib/petest.h"

void fatal(char msg[]){

  fprintf(stderr,"Error: %s\n", msg);
  exit(EXIT_FAILURE);

}

void usage(){

  printf("usage:\treadpe <file.exe>\n");
  exit(EXIT_FAILURE);

}

int main(int argc, char *argv[]){

  if(argc!=2)
    usage();
  
  PEFILE pe;
  pe.filepath = argv[1];

  petest_init(&pe);
  
  if(petest_ispe(&pe))
      printf("Eh um PE, continuando...\n");
  else
      fatal("nao eh um PE. Saindo...");

  printf("File:\t%s\n",pe.filepath);
  printf("%x\n", pe.hdr_dos->e_magic);
  printf("COFF header offset: %x\n", pe.hdr_dos->e_lfanew);

  petest_deinit(&pe);  

  /*
typedef struct {
  char *filepath;
  IMAGE_DOS_HEADER *hdr_dos;
} PEFILE;
*/

//  if(!petest_ispe(buffer))
  //  fatal("File not PE executable.");

  

  return 0;
}
