/*This program is coded by Prateek Mahajan, Omkar Hegde, Omkar Sulakhe, Prasad Vernekar.
In this program we perform simple hash
Input : provide input which is a string of characters in the file plainText.txt
Output : The output is a string of binary characters displayed on the console and printed in a file hash.txt
logic: Arrange the characters of the input string in a table form after converting to binary from ASCII, and perform column-wise exclusive OR.
https://www.youtube.com/watch?v=V2Gxqv3bJCk
*/
#include<stdio.h>
#include<string.h>
void toBin(int c,int *bin);
int main(){
    int *toBinPoint;//delare a pointer to the rows of binVal
    int i,j,noOfChars, binVal[50][8],hash[8];
    char plainText[50], hashPrint[9];
    //open an dread from file
    FILE *fpoint;
    fpoint=fopen("plainText.txt","r");
    fgets(plainText,50,fpoint);
    fclose(fpoint);
    //close file
    noOfChars=strlen(plainText);//number of characters

    for(i=0; i<noOfChars; i++){ //Here the base address of each rows of binVal in stored in toBinPoint
        toBinPoint=binVal[i];
        toBin(plainText[i],toBinPoint);// calling function and passing each character of plainText and the pointer.
    }

    for(j=0; j<8; j++){
            hash[j]=0;//initialize the hash
        for(i=0; i<noOfChars; i++)
            hash[j]=hash[j]^binVal[i][j];//xor each bit of jth column
       hashPrint[j]=(char)(hash[j]+48);//create a string hash print ,+48 is done to convert the digit to ASCII digit
    }
    hashPrint[j]='\0';

        printf("%s ",hashPrint);
    //store the hashPrint string to the file
    fpoint=fopen("hash.txt","w+");
    fputs(hashPrint,fpoint);
    fclose(fpoint);
}
void toBin(int c, int *bin){
    //this function converts a character to ASCII and then converts to binary and stores the binary digits in the table BinVal
    //each row of binVal represents the binary digits of each character of the plainText
    int i,arr[8];

    for(int i=0; i<8; i++){
        arr[i]=c%2;
        c/=2;
    }
    for(int i=0; i<8; i++){
        *bin=arr[7-i];
        bin++;
    }
}
