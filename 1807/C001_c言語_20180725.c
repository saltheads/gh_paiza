// C001 単語のカウント C言語版  （★リファクタリング前）
// 　単語　半角スペース　出現回数の順で1行に1単語で出現したすべての単語を出力
// 　1 <= n <= 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000

typedef struct {
    int count;      //出現数
    char *word;     //出現文字列
} word_element;

int main(void){
    char string[BUF_SIZE] = {0};                //入力文字列を格納するバッファ
    word_element word_table[BUF_SIZE] = {0};    //出現文字列と出現数の配列
    int i = 0;

    //先頭の文字列取得
    fgets(string, sizeof(string), stdin);
    char* word = strtok(string, " ");

    //出現数を計算
    while(word){
        for(i=0; i<BUF_SIZE; i++){
            if(!word_table[i].count){
                //未出現の文字列を検出
                word_table[i].word = word;
                break;
            }else if(!strcmp(word, word_table[i].word)){
                //既出の文字列を検出
                break;
            }
        }
        word_table[i].count++;

        //残りの文字列を取得
        word = strtok(NULL, " ");
    }

    //文字列の出現順に出現数を表示
    for(i=0; i<BUF_SIZE; i++){
        if(word_table[i].count){
            printf("%s %d\n", word_table[i].word, word_table[i].count);
        }else{
            //出現数が0の文字列を検出したので、表示はここで終了
            break;
        }
    }

    printf("\n");

    return EXIT_SUCCESS;
}
