# references-pattern-api
C++11 header-only that facilitates the creation of a reference pattern API.

Given an interface class based on `shared_ptr` objects,
this utility offer an easy way to create a layer that avoids the `shared_ptr` management across the API.
In other words, transform an API as `std::shared_ptr<MyClass> myObj;` into `MyClass myObj;`
keeping the behaviour (Now `MyClass` acts as a `shared_ptr<MyClass`).

You can see a small example of this concept into the [example](example) folder.

## How to use?
Easy! copy and paste the utility header [`include/refapi/refapi.hpp`](include/refapi/refapi.hpp) into your project and include it!
