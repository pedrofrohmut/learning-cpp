# Classes

## Classes 1 - Intro to classes

## Classes 2 - Default constructor and destructor

## Classes 3 - Copy Constructor and Copy Assignment Operator

- Shallow vs Deep copy

- Overriding default copy constructor to make a deep copy

- Operator overloading for =

## Classes 4 - Rule of 3 (and the lesser known rule of big 2)

- The law of 3 says that if you need to override the constructor or destructor or
the copy constructor you should always override the all 3 of them

- The law of big 2 is the law of 3 but if you use a smart pointer or some kind of
data structure, like a vector, you dont need to override the destructor

- In this case we would follow the rule of 3 but as we are using std::unique_ptr
we do not need to override the destructor that results in the rule of the big 2
