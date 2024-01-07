# Use case 1

A user opens a new uml diagram. They then drag on a class element to the canvas. They give it a 
name "animal". They then add two more class elements: "dog" and "cat". They make the "dog" and 
"cat" inherit from "animal". They add an interface element. Name it "speak". They make dog and
cat implement "speak". They then add another class called "bark" and implement it to "speak".
They then say that dog own bark. They add a note that says: "dog utilizes the class "back" to
speak. Dog does not speak by itself."

# Use case 2

A user wants to model a lexer parser. They create a uml diagram and create a class element call
lexer. They decide that inheritance is not appropriate and decide a "Token" interface would be good.
They create "symbol", "variable", "literal", "constant", and "operator" classes and show they implement
"Token". They add a function to lexer called Lex(). Lex returns a "Token" pointer. lexer class also has
a member variable for holding a string which is an input. It is set using a constructor that takes a string.
There is a peak method that returns a bool. There is also a IsError method that returns a bool and a error()
method that returns a error code.

