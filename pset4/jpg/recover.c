    /**
     * recover.c
     *
     * Computer Science 50
     * Problem Set 4
     *
     * Recovers JPEGs from a forensic image.
     */
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>

    #define infile "card.raw"

    int main(int argc, char* argv[])
    {
        
        uint8_t buffer[512];
        uint8_t startcheck1[4] = {0xff, 0xd8, 0xff, 0xe0}; 
        uint8_t startcheck2[4] = {0xff, 0xd8, 0xff, 0xe1}; 
        char outfile[8] = {0};
        int filecounter = 0;
        int fileopen = 0;
        FILE* outptr = NULL;
               
        // open input file 
        FILE* inptr = fopen(infile, "r");
        if (inptr == NULL)
        {
            printf("Could not open %s.\n", infile);
            return 2;
        }
        
        // reads until EOF
        while(fread(&buffer, sizeof(buffer), 1, inptr) == 1)
        {   
            int counter = 0;
            
            // compares the first 4 bytes
            for (int i = 0; i < 4; i++)
            {
                if (buffer[i] == startcheck1[i] || buffer[i] == startcheck2[i])
                {
                    counter += 1;   
                }
                else
                {
                    break;
                }
            }
            
            // if the 4 bytes are a jpg signatures, writes the file
            if (counter == 4)
            {
                // closes the file, if there was one open
                if (fileopen != 0)
                {
                    fclose(outptr);
                }
                
                sprintf(outfile, "%03d.jpg", filecounter);
                outptr = fopen(outfile, "w");
                if (outptr == NULL)
                {
                    fclose(inptr);
                    fprintf(stderr, "Could not create %s.\n", outfile);
                    return 3;
                } 
                fileopen = 1;
                filecounter +=1; 
            }
            
            if (fileopen == 1)
            {
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
        
        }
        
        fclose(outptr);
        fclose(inptr);   
    }
