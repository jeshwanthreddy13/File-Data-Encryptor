#include<stdio.h>
#include<stdlib.h>
#include<time.h>//For the time() function
#include"header.h"


void cleanup(void) {
  /* Do cleanup */
 

  if (fflush(stdout) == EOF) {
      exit(EXIT_FAILURE);
  }
    printf("All cleaned up!\n");
}
 int printRandoms(int lower, int upper)//printRandom function is a function that return random values between lower and upper values
{
        Integer_Type Num = (rand() % (upper - lower + 1)) + lower;
        return Num;
}


int main()
{
    //atexit(cleanup);
    Integer_Type Input;//Integer type Input for switch statement case selection
    Integer_Type Nav2_for_EOF;//Integer type variable to navigate till end of file
    Character_Type fname[File_Size];//For storing the file name when the user inputs it
    
    (void) printf("Please Enter 1 to Encrypt File\n");
    (void) printf("Please Enter 2 to Decrypt File\n");
    (void) printf("Please Enter your option :- ");
    (void)scanf("%1d",&Input);//Choice interger type
    
    switch (Input) {
          
            //Case 1 starts from here [Encryption]
            
        case 1:
        {
            Integer_Type Num_Of_Encryptions=0;//The number of encryptions the user wants
            Integer_Type i=0;//For the for loop

            FILE *fpto;//File type pointers
            FILE *fptu;
   
            (void)system("clear");
            
            (void)printf("\n\n Encrypt a text file \n");
            (void)printf("--------------------------\n");

            (void)printf(" Input the name of file to encrypt : ");
            (void)scanf("%20s", fname);
            (void)fflush(stdin);
           //Inputing the name of file to encrypt
            (void)printf("\n\nHow many encryptions do you want ? :- ");
            (void)scanf("%8d",&Num_Of_Encryptions);
         
            //input of Number of times the encryption has to be done
            fpto = fopen("code.txt","w");//Opening "code.txt" in write mode so that its contents are erased
            (void)fclose(fpto);//Closing "code.txt"
            (void)srand((unsigned)time(0));//Seeding the random value so as to generate new random numbers every time Printrandom() is called
            for(i = 0;i<Num_Of_Encryptions;i++)//Encrypting the file The number of times the user has mentioned
            {
                (void)Encrypt(fname);//Calling encrypt function
                if(i != (Num_Of_Encryptions-1)){
                    fptu = fopen("code.txt","r+");//opening "code.txt"
                while((Nav2_for_EOF = fgetc(fptu))!=EOF){
                    //Navigation till EOF in "code.txt"
                }
                    (void)fprintf(fptu,"%c",' ');//Adding WhiteSpace ' ' so that we can differentiate between the number encryption codes
                    (void)fclose(fptu);
                
            
        }
            }
            (void)printf("--------------------------\n");
            (void) printf("\nFile %s successfully encrypted ..!!\n\n", fname);//Printing success
            (void)printf("--------------------------\n");
        }
            
            break;
            
            //Case 2 starts from [Decrypting]
            
        case 2:
        {

            (void)system("clear");//Clear the screen for neatness
            (void)Decrypt();//Calling the Decrypt() FUnction
        }
            break;
            
        default:
            (void)printf("Error !!");//If some other option othere than 1 or 2 is given
            exit(EXIT_FAILURE);
            
    }
    return(EXIT_SUCCESS);
}
