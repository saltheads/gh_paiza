/* C005:アドレス調査 ver2 （★リファクタリング前）*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define IP_STR_MAX 102/*文字列(100)+改行(1)+終端(1)*/
#define NUM_MAX 5/*数字(3)+改行(1)+終端(1)*/

static bool ip_judge(char* ip_addr){
    int dot = 0;
    const char* p = ip_addr;
    
    while (*p != '\0') {
        if (*p == '.') {
            dot++;
        }
        p++;
    }

    if (dot != 3) {
        return false;
    }
    
    int byte = 0;
    const char* token = strtok(ip_addr, " .\n");
    
    do{    
        const int ip_cel = (int)strtol(token, NULL, 10);
        
        if (ip_cel < 0 || 255 < ip_cel) {
            return false;
        }
	
    	token = strtok(NULL, " .\n");
        byte++;
        
    } while (token != NULL);
    
    if (byte == 4) {
        return true;
    }
    /*12.32.12.のようにバイト数が足りないときにエラー*/
    return false;
    
}

int main(void){
    char roopnum[NUM_MAX] = {0};
    
    fgets(roopnum, sizeof(roopnum), stdin);
    const int roop = (int)strtol(strtok(roopnum, " .\n"), NULL, 10);
    
    for (int i = 0; i < roop; i++) {
        char ip_addr[IP_STR_MAX] = {0};
        fgets(ip_addr, sizeof(ip_addr), stdin);
            
        if (ip_judge(ip_addr) == true) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return EXIT_SUCCESS;
}

