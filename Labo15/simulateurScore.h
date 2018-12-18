// Laboratoires d'Analyse Programmation 1 
// Simulation de registres de micro controleur par accès à une mémoire partagée
// Fichier à inclure dans le programme
// 

#include <stdlib.h>


#ifndef PAGE_READWRITE
#define PAGE_READWRITE 0x04
#endif

#ifndef FILE_MAP_ALL_ACCESS 
#define FILE_MAP_ALL_ACCESS 0xF001F
#endif

#ifdef  __cplusplus
extern "C"
{
#endif

#ifndef CreateFileMappingA
void * _stdcall CreateFileMappingA(void *, long, long, long, long, const char *);
#endif

#ifndef MapViewOfFile
void * _stdcall MapViewOfFile(void *, long, long, long, long);
#endif

//#ifndef Sleep  // old solution
//void _stdcall Sleep(long);
//#endif

#ifdef  __cplusplus
}
#endif

//#ifndef sleep // old solution
//#define sleep Sleep
//#endif

static volatile char * _memoryAddress = NULL;
static void * _fileMappingHandle;

void open_shared_memory()
{

   if (_memoryAddress == NULL)
    {
        const char * memoryBlockName = "HEIGVD.INFO1.Labos.MemoirePartagee";
        const long MemorySize = 65536;
        _fileMappingHandle = CreateFileMappingA((void *)-1, 0, PAGE_READWRITE, 0,
            MemorySize, memoryBlockName);
        // minimalist error management
        if (_fileMappingHandle == NULL)
        {
            printf("Could not create shared memory %s\n", memoryBlockName);
            system("pause");
            exit(0);
        }
        _memoryAddress = (volatile char *)MapViewOfFile(_fileMappingHandle, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (_memoryAddress == NULL)
        {
            printf("Could not map shared memory %s", memoryBlockName);
            system("pause");
            exit(0);
        }
    }
}

unsigned char read_register(unsigned short address)
{
    open_shared_memory();
    return *(_memoryAddress + address);
        
}

void write_register(unsigned short address, unsigned char value)
{
    open_shared_memory();
    *(_memoryAddress + address) = value;    
}

