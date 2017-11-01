/**
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER 512

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover forensicImage\n");
        return 1;
    }

    // remember forensicImage
    char *infile = argv[1];

    // open memory card file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    uint8_t buffer[BUFFER];

    FILE* outptr = NULL;
    int fileCounter = 0;

    // repeat until end of card
    while (fread(buffer, BUFFER, 1, inptr) == 1) // or while (!feof(file))
    {
        if (buffer[0] == 0xFF &&
            buffer[1] == 0xD8 &&
            buffer[2] == 0xFF &&
            (buffer[3] & 0xF0) == 0xE0)
        {
            // is there a file open already?
            if (fileCounter > 0)
            {
                fclose(outptr);
            }

            // build new file name
            char filename[8];
            sprintf(filename, "%03i.jpg", fileCounter);

            // open the output file to write in
            outptr = fopen(filename, "w");

            fileCounter ++;
        }

        if (fileCounter > 0)
        {
            // write to file, update outptr
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }
    }

    // close input file
    fclose(inptr);

    // close the file
    fclose(outptr);

    // successful
    return 0;
}