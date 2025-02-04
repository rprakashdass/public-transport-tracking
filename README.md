# Public Transport Tracking System  

### Description  
The **Public Transport Tracking System** is a console-based C++ project designed to help developers learn how to:
- Connect to a **database** from C++ applications.
- Organize and manage clean, maintainable C++ code.
  
This project provides educational value for beginner C++ developers aiming to bridge the gap between programming logic and data management through database integration.


## Features  
- **Database Connectivity:** Demonstrates how to connect a C++ application to a database.  
- **CRUD Operations:** Add, update, delete, and fetch transport data from a database.  
- **Modular Code Structure:** Clean and maintainable code to encourage proper programming practices.  
- **User-Friendly Console:** Simple text-based user interface for interaction.  
- **Error Handling:** Handles exceptions and database connection failures effectively.



## Project Structure  
```
public-transport-tracking/
├── config/
│   ├── bus_management_system
│   ├── bus_management_system.db
│   └── fileDBStream.h
├── src/
│   ├── AppAdmin.cpp
│   ├── BusAdmin.cpp
│   ├── Guest.cpp
│   ├── dbStream.h
│   ├── main
│   └── main.cpp
├── output/
├── util/
├── db_connect.cpp
├── db.cpp
└── README.md
```
- **src:** Contains source files for the core logic.
- **include:** Header files to support modularity and organization.


## Setup Instructions  
### Prerequisites  
1. C++ Compiler (G++/Clang)  
2. Database Server (e.g., MySQL or SQLite)  
3. Database Connector Library for C++  

### Build
```bash
g++ src/main.cpp src/AppAdmin.cpp src/BusAdmin.cpp src/Guest.cpp db_connect.cpp db.cpp -o transport_tracker -Iconfig -Isrc
```

### Run
```bash
./transport_tracker
```


## Screenshots  

### Login and Register
![image](https://github.com/user-attachments/assets/aadaf584-1852-4f7a-84d9-32b14dd3dbf2)

### File DB
![Screenshot from 2024-10-25 17-10-27](https://github.com/user-attachments/assets/2a2c9c64-d0fa-4bb7-9272-c4c3b17a430d)

### SQLite DB
![image](https://github.com/user-attachments/assets/9f11362f-2c15-4e71-a017-32e3804e7c76)


## Learning Outcomes  
1. Understand the fundamentals of **database integration** with C++.  
2. Write modular and scalable C++ code by separating logic into appropriate files and headers.  
3. Learn best practices for handling **database errors** in C++ applications.  


## Contribution  
Feel free to fork the repo, create issues, and submit pull requests for improvements!
