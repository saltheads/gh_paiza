// C001 �P��̃J�E���g C�����  �i�����t�@�N�^�����O�O�j
// �@�P��@���p�X�y�[�X�@�o���񐔂̏���1�s��1�P��ŏo���������ׂĂ̒P����o��
// �@1 <= n <= 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000

typedef struct {
    int count;      //�o����
    char *word;     //�o��������
} word_element;

int main(void){
    char string[BUF_SIZE] = {0};                //���͕�������i�[����o�b�t�@
    word_element word_table[BUF_SIZE] = {0};    //�o��������Əo�����̔z��
    int i = 0;

    //�擪�̕�����擾
    fgets(string, sizeof(string), stdin);
    char* word = strtok(string, " ");

    //�o�������v�Z
    while(word){
        for(i=0; i<BUF_SIZE; i++){
            if(!word_table[i].count){
                //���o���̕���������o
                word_table[i].word = word;
                break;
            }else if(!strcmp(word, word_table[i].word)){
                //���o�̕���������o
                break;
            }
        }
        word_table[i].count++;

        //�c��̕�������擾
        word = strtok(NULL, " ");
    }

    //������̏o�����ɏo������\��
    for(i=0; i<BUF_SIZE; i++){
        if(word_table[i].count){
            printf("%s %d\n", word_table[i].word, word_table[i].count);
        }else{
            //�o������0�̕���������o�����̂ŁA�\���͂����ŏI��
            break;
        }
    }

    printf("\n");

    return EXIT_SUCCESS;
}
