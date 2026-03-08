<?php
session_start();

// Load stored credentials
$credentials = json_decode(file_get_contents("credentials.json"), true);
$correct_username = $credentials["username"];
$correct_password = $credentials["password"];

// Get user input
$username = $_POST['username'];
$password = $_POST['password'];

if ($username === $correct_username && $password === $correct_password) {
    echo "Login successful! Welcome, " . htmlspecialchars($username) . "!";
} else {
    echo "Incorrect username or password.";
}
?>