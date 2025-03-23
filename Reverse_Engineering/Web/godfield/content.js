(() => {
  const targetScriptSrc = "main.dart.js"; // 置き換え対象のスクリプト
  let replaced = false; // すでに置き換えたかどうかのフラグ

  const observer = new MutationObserver((mutations) => {
    if (replaced) return; // すでに置き換えていたらスキップ

    mutations.forEach((mutation) => {
      mutation.addedNodes.forEach((node) => {
        if (node.tagName === "SCRIPT" && node.src.includes(targetScriptSrc)) {
          console.log(`Replacing script: ${node.src}`);

          // 監視を一時停止
          observer.disconnect();

          // 元のスクリプトを削除
          node.remove();

          // ローカルのスクリプトを追加
          const newScript = document.createElement("script");
          newScript.src = chrome.runtime.getURL("main.dart.js");
          newScript.defer = true;
          document.documentElement.appendChild(newScript);

          console.log("Local script injected!");

          replaced = true; // 置き換えフラグを設定
        }
      });
    });
  });

  observer.observe(document.documentElement, { childList: true, subtree: true });
})();
