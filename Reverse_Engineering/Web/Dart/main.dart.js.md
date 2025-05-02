# 変更防止のバイパス

`main.dart.js` 内部の `HashChangeEvent: true` を `HashChangeEvent: false` に変更

```diff
- HashChangeEvent: true
+ HashChangeEvent: false
```

`main.dart.js`はハッシュによって変更を管理しており、少しでも変更を加えた場合フリーズする。
この変更を加えることによって、そのフリーズをバイパスすることができる。

しかし、Dartで作られたアプリの本体部分は初めに初期化されるので途中で変更することは難しい。

そのため、事前に変更を加えておいた`main.dart.js`を読み込むようにする拡張機能を作れば動作の変更が容易になる。

例として[God Fieldの拡張機能](https://github.com/AnoHobby/Learning/tree/main/Reverse_Engineering/Web/godfield/godfield_extension)を作ったのでそれを見ると理解しやすい。
