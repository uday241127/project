# 📚 Student Database System (C)

## 📌 Overview

This project implements a **student database system** using:

* Doubly Linked List (for ordered storage)
* Hash Tables (for fast lookup)
* File-based input/output
* SQL-like query processing

---

## 📂 Project Structure

* `main.c` → Handles file input/output and drives execution
* `lib.c` → Core logic (insert, delete, select, join, etc.)
* `lib.h` → Structure definitions and function declarations
* `Makefile` → Compilation automation

---

## ⚙️ Compilation (Using Makefile)

Run the following command:

```bash
make
```

This will generate the executable:

```bash
db
```

---

## ▶️ How to Run the Program

### 🔹 Command Format

```bash
./db <data_file> [join_file] <query_file>
```

---

### 🔹 Case 1: Without JOIN file

```bash
./db data.txt queries.txt
```

---

### 🔹 Case 2: With JOIN file

```bash
./db data.txt join.txt queries.txt
```

---

## 📁 Input File Formats

### 1. Data File (`data.txt`)

Contains initial student records:

```
<id> <name> <marks> <city>
```

Example:

```
101 Alice 90 Chennai
102 Bob 85 Delhi
103 Carol 78 Mumbai
```

---

### 2. Join File (`join.txt`) *(Optional)*

Used for JOIN operations:

```
<key> <value>
```

Example:

```
Chennai TN
Delhi DL
Mumbai MH
```

---

### 3. Query File (`queries.txt`)

Contains commands:

```
INSERT 104 David 88 Pune
SELECT *
SELECT * WHERE id = 101
SELECT * WHERE marks > 80
UPDATE 101 MARKS 95
DELETE 102
SELECT COUNT
SELECT MAX
SELECT MIN
SELECT AVG
SELECT * JOIN CITY
```

---

## 📤 Output

* Output is written to:

```
output.txt
```

* Some queries also print results to terminal.

---

## 🛠️ Supported Operations

### 🔹 INSERT

```
INSERT <id> <name> <marks> <city>
```

---

### 🔹 DELETE

```
DELETE <id>
DELETE ALL
```

---

### 🔹 UPDATE

```
UPDATE <id> NAME <new_name>
UPDATE <id> MARKS <new_marks>
UPDATE <id> CITY <new_city>
```

---

### 🔹 SELECT
prints the output on terminal
#### All records:

```
SELECT *
```

#### With conditions:

```
SELECT * WHERE id = 101
SELECT * WHERE id > 100
SELECT * WHERE marks < 90
SELECT * WHERE name Alice
SELECT * WHERE city Chennai
```

---

### 🔹 JOIN

```
SELECT * JOIN CITY
SELECT * JOIN ID
SELECT * JOIN NAME
SELECT * JOIN MARKS
```
prints the output on terminal and changes the output file
---

### 🔹 Aggregate Functions

```
SELECT COUNT
SELECT MAX
SELECT MIN
SELECT AVG
```

---

## ⚠️ Important Notes

* Duplicate IDs are not allowed → prints `error:DUPLICATE ID`
* Invalid queries → `INVALID QUERY`
* Missing records → appropriate error messages
* Output file is overwritten each run

---

## 🧹 Clean Build Files

```bash
make clean
```

---

## 🚀 Example Run

```bash
make
./db data.txt join.txt queries.txt
```

---

## 👨‍💻 Author

V.UDAY(CS25B090)
