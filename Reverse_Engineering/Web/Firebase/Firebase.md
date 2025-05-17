# We have blocked all requests from this device due to unusual activity. Try again later. (auth/too-many-requests)
グローバル/ローカルIPアドレスにて判定している。

プライベートタブだとこのエラーが出てもプライベートタブを閉じてから再度開くことで1回の猶予が与えられる(どこで判定してるかまだ調べてない)。

もしかしたら以下のようなコードを追加すればバイパスできるかもしれないが、多分無理かもしれない(面倒で試していない)
```
firebase.auth().setPersistence(firebase.auth.Auth.Persistence.NONE);
```
