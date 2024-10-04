<?php
// contact.php
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contact Us</title>
    <link rel="stylesheet" href="src/css/contact.css"> <!-- Link to contact CSS -->
</head>
<body>
    <?php include 'navbar.php'; ?>

    <div class="contact-container">
        <h1>Contact Us</h1>
        <p>If you have any questions or feedback, feel free to reach out to us using the form below.</p>

        <form action="#" method="post" class="contact-form">
            <div class="form-group">
                <label for="name">Name:</label>
                <input type="text" id="name" name="name" required>
            </div>
            <div class="form-group">
                <label for="email">Email Address:</label>
                <input type="email" id="email" name="email" required>
            </div>
            <div class="form-group">
                <label for="message">Message:</label>
                <textarea id="message" name="message" rows="5" required></textarea>
            </div>
            <button type="submit">Send Message</button>
        </form>
    </div>

    <?php include 'footer.php'; ?>
</body>
</html>
