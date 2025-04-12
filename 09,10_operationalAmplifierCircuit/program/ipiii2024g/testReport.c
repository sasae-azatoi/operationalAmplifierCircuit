#include <math.h>
#include <stdio.h>

// 複素数構造体を使う時には次の行を活かす
#include "report.h"
#include "testCommon.h"

// 各自の場所に記載してください。順番が違ってもテストには問題ないので気にしないでください。

/* テスト関数の記述部 */
// ↓↓↓↓ 3316 関口丞 記述部(この範囲以外には追加しない)
void testReadData() {
    testStart("readData");
    // 3∠0
    ans = makeCompRT(3.0, 0);
    assertEqualsComplex(ans, makeComp(3.0, 0));
    // 2∠π/2
    ans = makeCompRT(2.0, M_PI / 2.0);
    assertEqualsComplex(ans, makeComp(0, 2.0));
    // 1∠(-π/4)
    ans = makeCompRT(1.0, -M_PI / 4.0);
    assertEqualsComplex(ans, makeComp(sqrt(2) / 2, -sqrt(2) / 2));
}
//////////////////////////////////////////////////////////////////////////////////////////

// ここから main の始まりまでは追加・変更しないでください。

/* main関数の記述部 */
int main() {
    // ↓↓↓↓ 3316 関口丞 記述部(この範囲以外には追加しない)

    testReadData()
        //////////////////////////////////////////////////////////////////////////////////////////

        // ここから下は追加・変更しないでください。

        testErrorCheck();  // これは消さないこと
    return 0;
}
