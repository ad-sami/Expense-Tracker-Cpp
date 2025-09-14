CREATE DATABASE IF NOT EXISTS expense_tracker;
USE expense_tracker;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(100),
    password VARCHAR(100)
);

CREATE TABLE expenses (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    category VARCHAR(50),
    description VARCHAR(255),
    emotion VARCHAR(20),
    amount DECIMAL(10,2),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE leaderboard (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    points INT DEFAULT 0,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

INSERT INTO users (name, email, password) VALUES
('Sami', 'sami@mail.com', 'Pass123'),
('Din', 'din@mail.com', 'Pass123'),
('Khadija', 'khadija@mail.com', 'Pass123');
