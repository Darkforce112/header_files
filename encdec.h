#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<direct.h>

int enpasswd(){
int x=0;
 
FILE *file;
file=fopen("C:/Sys/.bin/encdec/passwd.txt","r");
if(file==NULL){
   srand(time(0));
    x=(rand()%100)+1;
   _mkdir("C:/Sys");
   _mkdir("C:/Sys/.bin");
   _mkdir("C:/Sys/.bin/encdec");
    file=fopen("C:/Sys/.bin/encdec/passwd.txt","w");
    fprintf(file,"%d",x);
    fclose(file);
    return x;
}
else{
    int etr; 
    printf("You Previously use this encryption on same file\n");
    printf("If you want to remove that encryption Enter 1 else Enter any Button\n");
    scanf("%d",&etr);
    if(etr==1){
        srand(time(0));
    x=(rand()%100)+1;
       file=fopen("C:/Sys/.bin/encdec/passwd.txt","w");
    fprintf(file,"%d",x); 
    fclose(file);
    return x;
    } 
    else{
      file=fopen("C:/Sys/.bin/encdec/passwd.txt","r");
      fscanf(file,"%d",&x);
      fclose(file);
       return x;
    }
   
}
}

int depasswd(){
    int x=0;
FILE *file;
    file=fopen("C:/Sys/.bin/encdec/passwd.txt","r");
    if(file==NULL){
        x=enpasswd();
        if(x==0){
        printf("Sorry key is lost");
        }
    }
    else{
        fscanf(file,"%d",&x);
    }
    return x;
}


int encrypt(char i[100],char o[100] ){
    FILE *enc;
    FILE *file;
    enc=fopen(i,"r");
      if(enc==NULL){  printf("File Not exist\n"); return 0;}
    file=fopen(o,"w");
    char c;
  int x=enpasswd();
    while((c=fgetc(enc))!=EOF){
       c+=x;   
fprintf(file,"%c",c);
    
    }
    fclose(enc);
    fclose(file);
    return 0;
}



int decrypt(char in[100],char out[100] ){
    FILE *enc;
    FILE *file;
    enc=fopen(in,"r");
    if(enc==NULL){
        printf("Encrypted File Not exist\n");
    }
    file=fopen(out,"w");
    char c;
      int x=depasswd();
    while((c=fgetc(enc))!=EOF){
       c-=x;
fprintf(file,"%c",c);
    
    }
    fclose(enc);
    fclose(file);
    return 0;
}
