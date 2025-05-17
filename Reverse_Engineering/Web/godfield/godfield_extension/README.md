# God Field Extension

## Notice
これは**God Fieldでの不正**を目的としたものではありません。  

## How to use?
1. `chrome://extensions/`などから各ブラウザの拡張機能管理画面にアクセスします。
2. **デベロッパーモード**を有効化します。
3. `パッケージ化されていない拡張機能を読み込む`から`godfield_extension`ディレクトリを選択します。
4. 拡張機能を有効化します。

## How does it work?
`main.dart.js`が読み込まれる前にローカルの`main.dart.js`に置き換えます。  
これには以下の利点があります：
- `main.dart.js`を変更するとhashにより検出
- プログラムの大部分は事前に定義されたものを使用しているため、後からの変更は無効になります（手間がかかる）

## Additional Info
### *AI-assisted Coding*  
一部のコードはAIによって生成されています。
