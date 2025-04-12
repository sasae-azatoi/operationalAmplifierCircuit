#include <math.h>
#include <stdio.h>

#include "report.h"

#define MAX_ROWS 1000
#define MAX_COLS 6
#define MAX_LINE_LEN 1024
int main() {
    double data[MAX_ROWS][MAX_COLS] = {0.0};
    int rows, cols;

    // CSVファイルを読み込む
    readCSV("for-4_4.csv", data, &rows, &cols);
    if (rows < 0 || cols < 0) {
        printf("CSVファイルの読み込みに失敗しました。\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f,", data[i][j]);
        }
        printf("\n");
    }
    printf("読み込んだデータ: %d行 %d列\n", rows, cols);

    // ユーザーに列を選ばせる
    int x_col, y_col;
    printf("xに使用する列番号 (0〜%d): ", cols - 1);
    scanf("%d", &x_col);
    printf("yに使用する列番号 (0〜%d): ", cols - 1);
    scanf("%d", &y_col);

    if (x_col < 0 || x_col >= cols || y_col < 0 || y_col >= cols) {
        printf("無効な列番号です。\n");
        return 1;
    }

    // 選択した列を最小二乗法で処理
    double x[MAX_ROWS], y[MAX_ROWS];
    for (int i = 0; i < rows; i++) {
        x[i] = data[i][x_col];
        y[i] = data[i][y_col];
    }

    double slope = calculateSlope(x, y, rows);
    printf("傾き a = %f\n", slope);

    return 0;
}
