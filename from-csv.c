#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Smith-Waterman.h"

int main(int argc, char **argv)
{
    // first command line argument (stored in argv[1]) is the csv filename
    // open the csv file a
    FILE* file = fopen(argv[1],"r");
    char buffer[256];
    char *line;    

    char* a = malloc(128);
    char* b = malloc(128);

    int i;
    //Assign a boolean value to keep track of when the comma has been passed
    int bool = 0;
    //Repeat for each line in the file
    while(fgets(buffer, sizeof(&buffer), file)){

        //If the line begins with a # then move to the next line
        line = strdup(buffer);
        if(line[0] == '#'){
            continue;
        }
        //Iterate through each character
        for(i=0; i<strlen(line); i++){
            //Change rhe boolean value if true
            //Skip over spaces
            //If the comma has not yet been reached add the letter to a
            //else add to b
            if (line[i] == ','){
                bool = 1;
            } else if(line[i] == ' '){
                continue;
            } else if (bool == 0) {
                a[strlen(a)] = line[i];
            } else{
                b[strlen(b)] = line[i];
            }

        }
    }
    //Call the algorithm and free the memory data
    print_smith_waterman(a,b);
    free(a);
    free(b);
    free(line);

    return EXIT_SUCCESS;
}