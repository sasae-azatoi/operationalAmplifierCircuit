#ifndef __COMPLEX_H__

// 二重読み込みを防ぐために、complex 構造体の定義などはここに記述

// ↓↓↓↓ complex の定義 by 3316 関口丞

// ↑↑↑↑ ここまでを 3316 関口丞 が記述

//////////////////////////////////////////////////////////////////////////////////////////

// プロトタイプ宣言部
// ↓↓↓↓ 3316 関口丞 記述部(この範囲以外に追加しない)
#define MAX_ROWS 1000
#define MAX_COLS 6
#define MAX_LINE_LEN 1024

void readCSV(const char *filename, double data[MAX_ROWS][MAX_COLS],
             int *row_count, int *col_count);
double calculateSlope(double *x, double *y, int n);
//////////////////////////////////////////////////////////////////////////////////////////

// ここから下には何も追記しないでください。

#endif