#include"header.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int Decrypt(){
    Integer_Type Num;//It stores the first alternate number from code.txt the
    Integer_Type Code_Ch;//It stores the character ascii from fname file
    Integer_Type Flag_1 = 1;//A flag for the First while loop
    Integer_Type Flag_2 = 1;//A flag for the interior while loop
    Integer_Type Ch;//It gets the second alternate number from "code.txt"
    Character_Type fname[File_Size];//This variable is used to store the file name
    FILE *fpts, *fptt, *fptu;//File type pointers
    
   (void) printf("\n\n Decrypt a text file :\n");
    (void)printf("--------------------------\n");
    
    (void)printf(" Input the name of file to decrypt : ");
    (void)scanf("%20s",fname);//Inputing file name

    if((strstr(fname,"./")) != NULL)
    {
        printf("ERROR :- Illegally running a ./ file");
        exit(EXIT_FAILURE);
    }
    fptu = fopen("code.txt", "r");//Opening "code.txt" file
    while(Flag_1){
     
    fpts=fopen(fname, "r");
        Flag_2 = 1;//Setting this flag back to 1 so it goes and decrypts again till ' ' or EOF is detected
    if(fpts==NULL)
    {
        (void)printf(" File does not exists or error in opening..!!");
        exit(EXIT_FAILURE);
    }
    fptt=fopen("temp.txt", "w+");
    if(fptt==NULL)
    {
        (void)printf(" File does not exist or error in opening..!!");
        (void)fclose(fpts);
        exit(EXIT_FAILURE);
    }
    
    while(Flag_2)//This loop decrypts the contents of the fname file and stores it in the temporary file temp.txt
    {
        if ((Num = fgetc(fptu)) == EOF)
        {
            Flag_1 = 0;
            Flag_2 = 0;
            break;
        }
        else if(Num == (int)' ')
        {
            Flag_2 = 0;
            break;
            
        }
       
        Num = Num - 48;//Convert characters to ascii code and decrypt
        Num = Num*10;//Random numbers are generated in two digit numbers so i am joining two adjacent numbers to get the two digit number
        Ch = fgetc(fptu);
        Ch = Ch - 48;
        Ch = Ch + Num;
        Code_Ch=fgetc(fpts);
        Code_Ch = Code_Ch - Ch;
        (void)fputc(Code_Ch, fptt);
        //printf("Stuck in flag2");}}
    }
    
        (void)fclose(fpts);
        (void)fclose(fptt);
        
    fpts = fopen(fname, "w+");
    fptt = fopen("temp.txt", "r+");
    while((Ch = fgetc(fptt)) != EOF)//From "temp.txt" i am writing to file fname
    {
        (void)fputc(Ch,fpts);
    }
    
    
        
        (void)fclose(fpts);
        (void)fclose(fptt);
        (void)remove("temp.txt");
    
    }
    (void)printf("--------------------------\n");
    (void)printf("\nThe file %s decrypted successfully..!!\n\n",fname);
    (void)printf("--------------------------\n");
    return(EXIT_SUCCESS);

}

