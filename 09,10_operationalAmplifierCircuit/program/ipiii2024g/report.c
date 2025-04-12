// G班 complex.c

#include "report.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 6
#define MAX_LINE_LEN 1024

//////////////////////////////////////////////////////////////////////////////////////////

// ↓↓↓↓ 3316 関口丞 記述部(雛形まで。この範囲以外には追加しない)

// CSVファイルを読み込む関数
void readCSV(const char *filename, double data[MAX_ROWS][MAX_COLS],
             int *row_count, int *col_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("ファイルを開けませんでした");
        *row_count = -1;
        *col_count = -1;
        return;
    }

    char line[MAX_LINE_LEN];
    int row = 0;

    // ヘッダー行をスキップ
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL && row < MAX_ROWS) {
        char *token;
        int col = 0;

        token = strtok(line, ",");
        while (token != NULL && col < MAX_COLS) {
            data[row][col] = atof(token);
            token = strtok(NULL, ",");
            col++;
        }

        row++;
        *col_count = col;
    }

    *row_count = row;

    fclose(file);
}

// 最小二乗法で傾きを計算する関数
double calculateSlope(double *x, double *y, int n) {
    if (n <= 1) {
        fprintf(stderr, "データ点の数が不足しています。\n");
        return 0.0;
    }

    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumXX = 0.0;

    for (int i = 6; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }

    double numerator = (n - 6) * sumXY - sumX * sumY;
    double denominator = (n - 6) * sumXX - sumX * sumX;

    if (denominator == 0) {
        fprintf(stderr,
                "分母がゼロです。直線を一意に定めることができません。\n");
        return 0.0;
    }

    return numerator / denominator;
}
// ↑↑↑↑ ここまでを 3303 入山克 が記述(この範囲以外には追加しない)

//////////////////////////////////////////////////////////////////////////////////////////

// ここから下には何も追記しないでください。