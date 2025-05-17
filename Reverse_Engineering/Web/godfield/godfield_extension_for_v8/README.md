# God Field Extension for Firebase SDK v8
## 何が違う?
God Field Extentionと違う点は、main.dart.jsで使用されているFirebase SDKのバージョンです。

v8が使われているときに保存されたmain.dart.jsをv9以降が使用されている現在のGod Fieldで使用するとエラーが発生します。

CSP回避のためローカルに保存したv8のソースを読み込ませることで、エラーを回避できるというものです。
