/* C006:�n�C�X�R�A�����L���O  C�����  �i�����t�@�N�^�����O�O�j */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define C_MAX (100)/*�p�����[�^�̌��̍ő吔*/

static int calc_score(const double coeficient[C_MAX], const int haveitem[C_MAX], const int itemnum) {
    assert(itemnum <= sizeof(coeficient)/sizeof(coeficient[0]));
    assert(itemnum <= sizeof(haveitem)/sizeof(haveitem[0]));
    double score = 0.0;
    for (int i = 0; i < itemnum; i++) {
        score += (coeficient[i] * (double)haveitem[i]);
    }
    return (int)round(score);
}

static void rank_sort(int* score, const int peoplenum) {
    int tmp = 0;
    for (int i = 0; i < peoplenum - 1; i++) {
        for (int j = i + 1; j < peoplenum; j++) {
            if (score[i] < score[j]) {
                tmp = score[i];
                score[i] = score[j];
                score[j] = tmp;
            }
        }
    }
}

int main(void){
    char str[1000 + 1 + 1] = {0};/*������(1000)+���s(1)+�I�[(1)*/
    fgets(str, sizeof(str), stdin);
    
    const char* token = strtok(str, " ");
    const int itemnum = (int)strtol(token, NULL, 10);
    token = strtok(NULL, " ");
    const int peoplenum = (int)strtol(token, NULL, 10);
    token = strtok(NULL, " \n");
    const int topnum = (int)strtol(token, NULL, 10);
    
    fgets(str, sizeof(str), stdin);
    
    double coeficient[C_MAX] = {0.0};
    assert(itemnum <= C_MAX);
    token = strtok(str, " \n");
    coeficient[0] = strtod(token, NULL);
    for (int i = 1; i < itemnum; i++) {
        token = strtok(NULL, " \n");
        coeficient[i] = strtod(token, NULL);
    }
    
    int score[1000] = {0};/*�ő�1000�l���̃X�R�A*/
    assert(topnum <= sizeof(score)/sizeof(score[0]));
    for (int j = 0; j < peoplenum; j++) {
        fgets(str, sizeof(str), stdin);
        
        int haveitem[C_MAX] = {0};
        token = strtok(str, " \n");
        haveitem[0] = (int)strtol(token, NULL, 10);
        for (int i = 1; i < itemnum; i++) {
            token = strtok(NULL, " \n");
            haveitem[i] = (int)strtol(token, NULL, 10);
        }
        score[j] = calc_score(coeficient, haveitem, itemnum);
    }
    rank_sort(score, peoplenum);
    
    for (int i = 0; i < topnum; i++) {
        printf("%d\n", score[i]);
    }
    return EXIT_SUCCESS;
}

