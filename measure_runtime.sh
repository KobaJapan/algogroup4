#!/bin/bash

# Cファイルの名前を引数から取得
c_file="$1"
TIMEFORMAT="time: %3Rs"

# Cファイルをコンパイル
gcc "$c_file" -o a.out

# モデルごとにループ
for model in {1..2}; do
    time_sum=0
    all_result=true

    # 各データセットに対するループ
    for idx in {0..9}; do
        echo "MODEL${model}: ${idx}"
        args=("MODEL${model}_rev/data${idx}" "MODEL${model}_rev/range${idx}" "answer")
        time ./a.out "${args[@]}"
        # 結果の比較
        if cmp -s "MODEL${model}_rev/answer${idx}" "answer"; then
            echo "result: true"
        else
            echo "result: false"
            all_result=false
        fi
        echo
        # 一時ファイルの削除
        rm answer
    done
    # 合計結果の表示
    echo "MODEL${model}: all ${all_result}"
    echo
    echo
done
