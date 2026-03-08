document.addEventListener("DOMContentLoaded", () => {
    chrome.storage.local.get("tabSummaryData", (data) => {
        if (data.tabSummaryData) {
            document.getElementById("summary-content").innerHTML = data.tabSummaryData;
        } else {
            document.getElementById("summary-content").innerText = "No summary available.";
        }
    });
});
