#!/bin/bash# タイムスタンプを生成
timestamp=$(date +"%Y%m%d%H%M%S")

# 作業用ディレクトリを作成mkdir -p ./temp
mkdir -p ./output

# 入力ZIPファイルを解凍
unzip -o ./input/tja.zip -d ./temp

# 改行コードをLFからCRLFに変換
find ./temp -type f -name "*.tja" -exec dos2unix -c mac {} \;

# 圧縮して出力ディレクトリに保存
output_zip="./output/tja_${timestamp}.zip"
zip -r "$output_zip" ./temp/*

# 作業用ディレクトリを削除rm -rf ./temp

echo"圧縮ファイルが$output_zipに作成されました。"