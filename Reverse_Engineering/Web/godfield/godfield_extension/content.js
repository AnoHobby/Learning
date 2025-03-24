(() => {
  const targetScriptSrc = "main.dart.js"; // 置き換え対象のスクリプト

  const observer = new MutationObserver((mutations) => {
    for (const mutation of mutations) {
      for (const node of mutation.addedNodes) {
        if (node.tagName === "SCRIPT" && node.src.includes(targetScriptSrc)) {
          console.log(`Replacing script: ${node.src}`);

          // 監視を停止（以後の変化を無視）
          observer.disconnect();

          // 元のスクリプトを削除
          node.remove();

          // ローカルのスクリプトを追加
          const newScript = document.createElement("script");
          newScript.src = chrome.runtime.getURL("main.dart.js");
          newScript.defer = true;
          document.documentElement.appendChild(newScript);

          console.log("Local script injected!");

          return; // 関数を即終了
        }
      }
    }
  });

  observer.observe(document.documentElement, { childList: true, subtree: true });
})();
