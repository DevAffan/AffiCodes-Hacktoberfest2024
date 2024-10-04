<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard</title>
    <link rel="stylesheet" href="src/css/dashboard.css">
</head>
<body>
    <?php include 'navbar.php'; ?>

    <div class="dashboard-container">
        
        <div class="sidebar">
            <h2>Admin Dashboard</h2>
            <ul>
                <li><a href="#">Overview</a></li>
                <li><a href="#">Reports</a></li>
                <li><a href="#">Analytics</a></li>
                <li><a href="#">Settings</a></li>
            </ul>
        </div>

        <div class="main-content">
            <div class="top-navbar">
                <h3>Welcome, Admin</h3>
                <a href="#">Logout</a>
            </div>

            <div class="content">
                <h1>Overview</h1>
                <p>Dashboard Content.</p>
                
                <div class="dashboard-cards">
                    <div class="card">
                        <h3>Users count</h3>
                        <p>1,245</p>
                    </div>
                    <div class="card">
                        <h3>Sales last month</h3>
                        <p>$2,340</p>
                    </div>
                    <div class="card">
                        <h3>Reports</h3>
                        <p>12 New</p>
                    </div>
                </div>
            </div>
        </div>

    </div>

    <?php include 'footer.php'; ?>
    
</body>
</html>
