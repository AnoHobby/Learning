(() => {
  const targetScriptSrc = "main.dart.js";

  const observer = new MutationObserver((mutations) => {
    for (const mutation of mutations) {
      for (const node of mutation.addedNodes) {
        if (node.tagName === "SCRIPT" && node.src.includes(targetScriptSrc)) {
          console.log(`Replacing script: ${node.src}`);

          observer.disconnect();
          node.remove();

          // Firebase SDK の必要なスクリプト全部を読み込む
          const localScripts = [
            chrome.runtime.getURL("firebase/firebase-app.js"),
            chrome.runtime.getURL("firebase/firebase-auth.js"),
            chrome.runtime.getURL("firebase/firebase-firestore.js")
          ];
          for (const src of localScripts) {
            const s = document.createElement("script");
            s.src = src;
            s.defer = true;
            document.head.appendChild(s);
          }

          // Firebase 初期化
          const initScript = document.createElement("script");

          // main.dart.js をローカルに差し替え
          const newScript = document.createElement("script");
          newScript.src = chrome.runtime.getURL("main.dart.js");
          newScript.defer = true;
          document.documentElement.appendChild(newScript);

          console.log("Injected local Firebase SDKs + script!");
          return;
        }
      }
    }
  });

  observer.observe(document.documentElement, { childList: true, subtree: true });
})();
