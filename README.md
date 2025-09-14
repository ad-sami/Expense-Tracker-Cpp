# Expense Tracker (C++ Qt + MySQL)

This is a desktop expense tracker app built with **C++** and **Qt**.

### **Features:**
- Daily, weekly, and monthly expense tracking
- Salary-based budget calculation
- Emotion-tagged expenses
- Gamification with leaderboard (Sami, Din, Khadija)

### **Setup**

Follow these steps to set up and run the app:

#### **1. Set up MySQL Database:**
To create the necessary database tables, follow these steps:

1. **Open MySQL (or phpMyAdmin)**:  
   Open your MySQL server or phpMyAdmin at `http://localhost/phpmyadmin` and log in.

2. **Create the `expense_tracker` Database**:  
   In MySQL, create a new database named `expense_tracker` (if it doesn't exist already).
   
   You can create it manually using this query:
   ```sql
   CREATE DATABASE expense_tracker;
