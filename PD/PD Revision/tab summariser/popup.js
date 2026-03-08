document.addEventListener('DOMContentLoaded', function() {
    document.getElementById("summarize-btn").addEventListener("click", () => {
        chrome.runtime.sendMessage({ type: "summarizeCurrentTab" }, (response) => {
            if (response.success) {
                window.close(); // Close popup after initiating the summary
            } else {
                alert("Error: " + response.summary);
            }
        });
    });
});
