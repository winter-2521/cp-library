---
title: 高速入出力 (Fast I/O)
documentation_of: //io/fastio.hpp
---

## 概要

`cin` / `cout` の代わりに使う高速な入出力。`fin` / `fout` というグローバルオブジェクトを `>>` / `<<` で使う。

- 入力は `fread` で 128 KiB ずつまとめて読む。整数は 8 桁ずつまとめて変換する（SWAR）。
- 出力は 0000〜9999 の文字列の表を使い、4 桁ずつ書き込む。バッファがいっぱいになったときとプログラム終了時に `fwrite` でまとめて書き出す。
- 手元での計測（$10^6$ 行の 64 bit 整数の和）: `cin`（sync オフ）0.16 秒、`scanf` 0.18 秒、`fastio` 0.03 秒。

## 使い方

```cpp
int n; long long x;
fin >> n >> x;                 // 整数 (int, long long, unsigned, __int128, unsigned __int128 など)
string s; char c;
fin >> s >> c;                 // 空白区切りの文字列 / 空白以外の 1 文字
double d; fin >> d;            // 浮動小数点数
vector<int> a(n); fin >> a;    // vector は要素数ぶん読む (あらかじめサイズを確保しておく)
pair<int, int> p; fin >> p;    // pair
mint m; fin >> m; fout << m;   // modint (自作 ModInt・ACL の modint どちらも可．val() を持つ型)
auto y = fin.read<long long>();  // 値を返す形でも読める

fout << x << ' ' << s << '\n';   // 整数・文字・文字列・bool (0/1)
fout << a << '\n';               // vector は空白区切り
fout.set_precision(10);          // 浮動小数点数の小数点以下の桁数 (デフォルト 15)
fout << d << '\n';
fout.flush();                    // 明示的に書き出す (プログラム終了時には自動で書き出される)
```

| 操作 | 計算量 |
| --- | --- |
| 整数の読み込み | $O(\text{桁数})$ |
| 整数の書き込み | $O(\text{桁数})$ |
| 文字列の読み込み・書き込み | $O(\lvert s \rvert)$ |

## 注意

- **`cin` / `cout` / `scanf` / `printf` と混ぜて使ってはいけない**（それぞれ別々にバッファを持っているため、順序が崩れる）。
- 入力は 128 KiB 単位でまとめて読むので、**インタラクティブ問題には使えない**。
- 出力はプログラム終了時（`fout` のデストラクタ）にまとめて書き出す。`exit()` で終わる場合も書き出されるが、`_Exit` / `quick_exit` / 異常終了では書き出されない。
- 整数の読み込みは入力が正しい形式であることを前提にしている（オーバーフローや不正な文字はチェックしない）。
- 浮動小数点数の出力は `snprintf` を使っているので、整数ほど速くはない。
