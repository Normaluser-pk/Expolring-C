#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count(char name[]){
    return strlen(name);
}

char * lowercase(char *string){
    for(int i=0;i<count(string);i++){
        string[i]=tolower(string[i]);
    }
    return string;
}

char * nospace(char *string){
    int non_space_count = 0;
    for (int i = 0; string[i] != '\0'; i++){
        if (string[i] != ' '){
            string[non_space_count] = string[i];
            non_space_count++;
        }
    }
    string[non_space_count] = '\0';
    return string;
}

int lettersremove(char fname1[],char fname2[],int x,int y){
    int flag;
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            if(fname1[i]==fname2[j]){
                for(int k=i;k<x-1;k++){
                    fname1[k]=fname1[k+1];
                }
                x--;
                i--;
                for (int l=j;l<y-1;l++){
                    fname2[l]=fname2[l+1];
                }
                y--;
                j--;
            }
        }
    }
    flag=x+y;
    return flag;
}


char flames(char *flame,int orgsum,int temp){
    int flag=0,flag1=0,sum=orgsum;
    if(temp==1){
        return *(flame);
    }
    if(temp<sum){
        if(sum%temp!=0){
                sum=sum%temp;}
        else{
            sum=temp;
        }
    }
    for(int k=sum-1;k<=temp;k++){
        *(flame+k)=*(flame+k+1);
        flag++;
    }
    temp=temp-1;
    int temp1=temp;
    char none[temp1];
    strcpy(none,flame);
    if(temp!=1) {
            for(int k=sum-1;k<temp;k++){
                none[flag1]=*(flame+k);
                flag1++;
            }
            for(int k=sum-1,i=0;k>=i;i++){
                none[flag1]=*(flame+i);
                flag1++;
            }
        }
    char *ptr2=none;
    return flames(ptr2,orgsum,temp);
}

int main(){
    int size1,size2,sum;
    char name1[35],name2[35];
    char flame[]={"FLAMES"};
    int szofl=6;
    //For first name
    printf("Enter your name:");
    scanf(" %[^\n]s",name1);
    nospace(name1);
    lowercase(name1);
    size1=count(name1);
    //for second name
    printf("Enter the name of Person:");
    scanf(" %[^\n]s",name2);
    nospace(name2);
    lowercase(name2);
    size2=count(name2);
    //Total letters after removing similar letters
    sum=lettersremove(name1,name2,size1,size2);
    switch(flames(flame,sum,szofl)) {
        case 'F': {
            printf("The relation btw you is Friends\n");
            break;
        }
        case 'L' :{
            printf("The relation btw you is Love\n");
            break;
        }
        case 'A' :{
            printf("The relation btw you is Affection\n");
            break;
        }
        case 'M' :{
            printf("The relation btw you is Marriage\n");
            break;
        }
        case 'E' :{
            printf("The relation btw you is Enemy\n");
            break;
        }
        case 'S' :{
            printf("The relation btw you is Sister\n");
            break;
        }
        default:
            printf("Error in calculating\n");
    }
}
