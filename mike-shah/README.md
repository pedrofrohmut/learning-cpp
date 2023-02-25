# Classes

## Classes 1 - Intro to classes

## Classes 2 - Default constructor and destructor

## Classes 3 - Copy Constructor and Copy Assignment Operator

- Shallow vs Deep copy

- Overriding default copy constructor to make a deep copy

- Operator overloading for '='

## Classes 4 - Rule of 3 (and the lesser known rule of big 2)

- The law of 3 says that if you need to override the constructor or destructor or
the copy constructor you should always override the all 3 of them.

- The law of big 2 is the law of 3 but if you use a smart pointer or some kind of
data structure, like a vector, you dont need to override the destructor.

- In this case we would follow the rule of 3 but as we are using std::unique_ptr
we do not need to override the destructor that results in the rule of the big 2.

## Classes 5 - Avoiding Copies

- If you pass the class as argument to the function, ex: print(MyClass x), CPP will
automatically make a copy of it calling the Copy Constructor.

- If you want to avoid copies being made you should use references as arguments,
ex: print(MyClass& x), using the & symbol.

- To avoid the class being copied you can use the '=delete' at the Copy Contructor
of the class. This will make copies of the instance not possible and generate a
compiler error if someone tries to.

- Passing by reference is better for perfomance reasons and should be used where
it can make a difference.

## Classes 6 - Operator Overloading

- You can override the behavior of an operator when it interacts with instances
of your class.

- Exp of the sum operator '+' you can sum two vectors vec1{1, 2, 3} + vec2{2, 5, 6}
=> 'result = vec1 + vec2;' you can simplify your code this way.

- Or a the increment operator '++' => ++vec1;

- The operator '<<' you can ease the way to print => 'std:cout << vec1 << '\n';

- The operator '==' you can compare all the fields of two vectors in a simgle operation
in your code => 'are_equal = (vec1 == vec2);'
