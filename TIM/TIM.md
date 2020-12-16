# 目次

# Interrupt
## callBackについて
callBack関数はwrapperで定義して`./Core/Src/stm32fxxx_it.cpp`の対応するIRQHandler関数で呼び出してください。

## Constructor


## start()
カウンターをスタートします。
```c++

```

## memo
enablexxxxxxInterrupt()を呼ぶ前にclearXXXXXXXflag()を呼ばないとenablexxxxxxInterrupt()直後に割り込みが発生する。
flagの初期値がsetになってる。

### 割り込みの基本手順
1. clearFlagInterrpt()
2. enable_____Interrpt()
3. start()
割り込み関数はwrapper.hppにプロトタイプ宣言をしてその中でintrruptCallback()を呼ぶ。　　
callbackの処理は割り込みの種類ごとに作成してset_____Callback()を使ってsetする。interrptCallback()からsetされた関数を呼び出す。