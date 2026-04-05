# Object_oriented_library_system
*WORK IN PROGRESS*

## class inheritance structure
LibraryItem (abstract)
 ├── Book
 ├── Magazine
 └── DVD

LibraryPatron (abstract)
 ├── Student
 └── Faculty

Transaction (abstract)
 ├── Checkout
 └── Return

 ## Project structure:
 LibrarySystem/
│
├── include/
│   ├── items/
│   │   ├── LibraryItem.h
│   │   ├── Book.h
│   │   ├── Magazine.h
│   │   └── DVD.h
│   │
│   ├── patrons/
│   │   ├── LibraryPatron.h
│   │   ├── Student.h
│   │   ├── Faculty.h
│   │   └── Guest.h
│   │
│   ├── transactions/
│   │   ├── Transaction.h
│   │   ├── Checkout.h
│   │   ├── Return.h
│   │   └── Reservation.h
│   │
│   ├── core/
│   │   ├── Library.h
│   │   └── LibraryExceptions.h
│
├── src/
│   ├── items/
│   ├── patrons/
│   ├── transactions/
│   └── core/
├── main.cpp        
├── CMakeLists.txt 
└── README.md