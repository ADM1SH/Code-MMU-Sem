<?php
session_start();

$new_username = $_POST['new_username'];
$new_password = $_POST['new_password'];

$credentials = [
    "username" => $new_username,
    "password" => $new_password
];

// Save the new credentials to a file
file_put_contents("credentials.json", json_encode($credentials));

echo "Username and password updated!";
?>