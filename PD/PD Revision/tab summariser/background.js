chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.type === "summarizeCurrentTab") {
        chrome.tabs.query({ active: true, currentWindow: true }, async (tabs) => {
            let activeTab = tabs[0];

            if (!activeTab) {
                sendResponse({ success: false, summary: "No active tab found." });
                return;
            }

            try {
                const content = await extractImportantInfo(activeTab.id);
                const tabSummary = generateTabSummary(content);

                // Save the summary to localStorage
                chrome.storage.local.set({ tabSummaryData: tabSummary });

                // Open the website.html to show the summary
                chrome.tabs.create({ url: "website.html" });

                sendResponse({ success: true });
            } catch (error) {
                console.error("Error extracting info from active tab:", error);
                sendResponse({ success: false, summary: error.message });
            }
        });

        return true;
    }
});

// Extract all the important content from the current tab
function extractImportantInfo(tabId) {
    return new Promise((resolve, reject) => {
        chrome.scripting.executeScript({
            target: { tabId: tabId },
            function: () => {
                try {
                    // Extract all paragraphs on the page
                    const paragraphs = [...document.querySelectorAll("p")].map(p => p.innerText);

                    // Join all paragraphs to create full content text
                    const fullText = paragraphs.join(" ");

                    // Return the full text of the page
                    return { fullText };
                } catch (error) {
                    return { error: error.message };
                }
            }
        }, (injectionResults) => {
            if (chrome.runtime.lastError) {
                // If there's a runtime error, reject the promise
                reject(chrome.runtime.lastError);
            } else if (injectionResults[0].result.error) {
                // If the script inside the webpage threw an error, reject with that message
                reject(new Error(injectionResults[0].result.error));
            } else {
                // Otherwise, resolve with the extracted content
                resolve(injectionResults[0].result);
            }
        });
    });
}

// Generate summary based on keyword frequency
function generateTabSummary(content) {
    const sentences = content.fullText.match(/[^\.!\?]+[\.!\?]+/g) || []; // Split into sentences
    if (sentences.length === 0) return "No content to summarize.";

    const keywords = extractKeywords(content.fullText);
    const importantSentences = sentences.filter(sentence => {
        return keywords.some(keyword => sentence.includes(keyword));
    }).slice(0, 15); // Limit to top 10 sentences

    return importantSentences.join(" ");
}

// Simple keyword extraction based on word frequency
function extractKeywords(text) {
    const words = text.toLowerCase().match(/\b\w+\b/g);
    const frequency = {};
    words.forEach(word => {
        frequency[word] = (frequency[word] || 0) + 1;
    });

    const sortedKeywords = Object.keys(frequency).sort((a, b) => frequency[b] - frequency[a]);
    return sortedKeywords.slice(0, 10); // Top 10 most frequent keywords
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.type === "summarizeCurrentTab") {
        chrome.tabs.query({ active: true, currentWindow: true }, async (tabs) => {
            let activeTab = tabs[0];

            if (!activeTab) {
                sendResponse({ success: false, summary: "No active tab found." });
                return;
            }

            try {
                const content = await extractImportantInfo(activeTab.id);
                const tabSummary = generateTabSummary(content);

                // Save the summary to localStorage
                chrome.storage.local.set({ tabSummaryData: tabSummary });

                // Open the website.html to show the summary
                chrome.tabs.create({ url: "website.html" });

                sendResponse({ success: true });
            } catch (error) {
                console.error("Error extracting info from active tab:", error);
                sendResponse({ success: false, summary: error.message });
            }
        });

        return true;
    }
});

// Extract all the important content from the current tab
function extractImportantInfo(tabId) {
    return new Promise((resolve, reject) => {
        chrome.scripting.executeScript({
            target: { tabId: tabId },
            function: () => {
                try {
                    // Extract all paragraphs on the page
                    const paragraphs = [...document.querySelectorAll("p")].map(p => p.innerText);

                    // Join all paragraphs to create full content text
                    const fullText = paragraphs.join(" ");

                    // Return the full text of the page
                    return { fullText };
                } catch (error) {
                    return { error: error.message };
                }
            }
        }, (injectionResults) => {
            if (chrome.runtime.lastError) {
                // If there's a runtime error, reject the promise
                reject(chrome.runtime.lastError);
            } else if (injectionResults[0].result.error) {
                // If the script inside the webpage threw an error, reject with that message
                reject(new Error(injectionResults[0].result.error));
            } else {
                // Otherwise, resolve with the extracted content
                resolve(injectionResults[0].result);
            }
        });
    });
}

// Generate summary based on keyword frequency
function generateTabSummary(content) {
    const sentences = content.fullText.match(/[^\.!\?]+[\.!\?]+/g) || []; // Split into sentences
    if (sentences.length === 0) return "No content to summarize.";

    const keywords = extractKeywords(content.fullText);
    const importantSentences = sentences.filter(sentence => {
        return keywords.some(keyword => sentence.includes(keyword));
    }).slice(0, 10); // Limit to top 10 sentences

    return importantSentences.join(" ");
}

// Simple keyword extraction based on word frequency
function extractKeywords(text) {
    const words = text.toLowerCase().match(/\b\w+\b/g);
    const frequency = {};
    words.forEach(word => {
        frequency[word] = (frequency[word] || 0) + 1;
    });

    const sortedKeywords = Object.keys(frequency).sort((a, b) => frequency[b] - frequency[a]);
    return sortedKeywords.slice(0, 10); // Top 10 most frequent keywords
}

