chrome.runtime.onInstalled.addListener(() => {
    console.log("Extension installed!");
});

// Inject a script when the user clicks the extension icon
chrome.action.onClicked.addListener((tab) => {
    chrome.scripting.executeScript({
        target: { tabId: tab.id },
        files: ["content.js"]
    });
});