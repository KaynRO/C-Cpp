#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdint.h>
#define MAX 1000

using namespace std ;
uint32_t dimensiune, nrblocuri,blocuri[MAX] = {-1}  ;
char *arena;
char *ocupat;

void functie_DUMP ()
{
uint32_t i,numar, line_cnt, data_cnt = 0;
uint32_t adresa = 0;
	numar = dimensiune / 16 + ((dimensiune%16 != 0) ? 1 : 0);
uint32_t last_line_size = dimensiune % 16;
uint32_t curr_line_size = 16;
	for(line_cnt = 0; line_cnt < numar; line_cnt++)
	{
		printf("%08X\t", adresa);

		if (line_cnt == numar-1 && last_line_size != 0) {
 			curr_line_size = last_line_size;
		}

		for (data_cnt = 0; data_cnt < curr_line_size; data_cnt++) {
			printf("%02X ", arena[line_cnt*16 + data_cnt]);
			if (data_cnt == 7) printf(" ");
		}
		printf("\n");

		adresa+=16;
	}
}
void functie_INITIALIZE (uint32_t size)
{

	dimensiune = size;
	arena = calloc( dimensiune,sizeof(char));
	ocupat = calloc(dimensiune,sizeof(char));
}
uint32_t cauta_spatiu (uint32_t size)
{
	uint32_t i,j, ok = 1;

	for(i = 0; i < dimensiune - 12 - size - 1; i++)
	{	ok = 1;
		for(j = i; j < i + 12 + size -1; j++)
			if( ocupat[j] != 0 )
			ok = 0;
		if(ok == 1)
		return i;

	}
	return -1;

}
uint32_t indice_bloc_inainte ( uint32_t indice)
{
	uint32_t max1 = -1, i, ok = 0;
	printf("%d " , indice ) ;
	printf("%d " , blocuri[nrblocuri] ) ;

	for(i = 1; i <= nrblocuri; i++)
	{
		printf("%d" , max1) ;
		if(blocuri[i] < indice && blocuri[i] > max1)
		{
			max1 = blocuri[i];
			ok = 1 ;
		}
	}
	if( ok == 0)
		return -1;
	return max1;

}
uint32_t indice_bloc_dupa ( uint32_t indice)
{
	uint32_t min1 = 99999, i, ok = 0;

	for(i = 1; i <= nrblocuri; i++)
		if(blocuri[i] > indice && blocuri[i] < min1)
		{
			min1 = blocuri[i];
			ok = 1 ;
		}
	if( ok == 0)
		return -1;
	return min1;

}
void functie_ALLOC ( uint32_t size)
{
	uint32_t i, indice = cauta_spatiu(size);
	uint32_t inainte, dupa;

	if(indice == -1)
		printf("0\n");
	else
	{
		printf("%d\n",indice + 12);
		for(i = indice; i < indice + 12 + size; i++)
			ocupat[i] = 1;
		arena[indice + 8] = size;
		inainte = indice_bloc_inainte(indice);
		dupa = indice_bloc_dupa(indice);
		printf("%d %d %d\n", inainte, dupa, nrblocuri);
		nrblocuri++;

		printf("%d\n", blocuri[1]	);
		if(inainte != -1)
		{
			arena[indice] = inainte;
			arena[inainte + 4] = indice;
		}
		if(dupa != -1)
		{
			arena[indice + 4] = dupa;
			arena[dupa] = indice;
		}
	}
	for(i = 0; i < dimensiune; i ++)
		printf("%d ", arena[i]);
	printf("\n");
}
void parse_command(char* cmd)
{
    const char* delims = " \n";

    char* cmd_name = strtok(cmd, delims);
    if (!cmd_name) {
        goto invalid_command;
    }

    if (strcmp(cmd_name, "INITIALIZE") == 0) {
        char* size_str = strtok(NULL, delims);
        if (!size_str) {
            goto invalid_command;
        }
        uint32_t size = atoi(size_str);
        // TODO - INITIALIZE
	functie_INITIALIZE(size);



    } else if (strcmp(cmd_name, "FINALIZE") == 0) {
        // TODO - FINALIZE
	free(arena);


    } else if (strcmp(cmd_name, "DUMP") == 0) {
        // TODO - DUMP
	functie_DUMP();



    } else if (strcmp(cmd_name, "ALLOC") == 0) {
        char* size_str = strtok(NULL, delims);
        if (!size_str) {
            goto invalid_command;
        }
        uint32_t size = atoi(size_str);
        // TODO - ALLOC
	functie_ALLOC(size);

    } else if (strcmp(cmd_name, "FREE") == 0) {
        char* index_str = strtok(NULL, delims);
        if (!index_str) {
            goto invalid_command;
        }
        uint32_t index = atoi(index_str);
        // TODO - FREE

    } else if (strcmp(cmd_name, "FILL") == 0) {
        char* index_str = strtok(NULL, delims);
        if (!index_str) {
            goto invalid_command;
        }
        uint32_t index = atoi(index_str);
        char* size_str = strtok(NULL, delims);
        if (!size_str) {
            goto invalid_command;
        }
        uint32_t size = atoi(size_str);
        char* value_str = strtok(NULL, delims);
        if (!value_str) {
            goto invalid_command;
        }
        uint32_t value = atoi(value_str);
        // TODO - FILL

    } else if (strcmp(cmd_name, "ALLOCALIGNED") == 0) {
        char* size_str = strtok(NULL, delims);
        if (!size_str) {
            goto invalid_command;
        }
        uint32_t size = atoi(size_str);
        char* align_str = strtok(NULL, delims);
        if (!align_str) {
            goto invalid_command;
        }
        uint32_t align = atoi(align_str);
        // TODO - ALLOCALIGNED

    } else if (strcmp(cmd_name, "REALLOC") == 0) {
        printf("Found cmd REALLOC\n");
        char* index_str = strtok(NULL, delims);
        if (!index_str) {
            goto invalid_command;
        }
        uint32_t index = atoi(index_str);
        char* size_str = strtok(NULL, delims);
        if (!size_str) {
            goto invalid_command;
        }
        uint32_t size = atoi(size_str);
        // TODO - REALLOC

    } else {
        goto invalid_command;
    }

    return;

invalid_command:
    printf("Invalid command: %s\n", cmd);
    exit(1);
}

int main(void)
{
    ssize_t read;
    char* line = NULL;
    size_t len;

    /* parse input line by line */
    while ((read = getline(&line, &len, stdin)) != -1) {
        /* print every command to stdout */
        //printf("%s", line);

        parse_command(line);
    }

    free(line);

    return 0;
}
