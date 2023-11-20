/* Object-Oriented Programming (OOP) is a programming paradigm that revolves around the concept of "objects."
 In Java, OOP is a fundamental aspect of the language. Here are the main OOP concepts in Java:
*/

/*1. *Classes and Objects*:
   - *Class*: A class is a blueprint for creating objects. It defines the structure and behavior of objects.
    For example:
*/

    class Car {
        String make;
        String model;

        void start() {
            System.out.println("Car started.");
        }
    }

    /*
     * - *Object*: An object is an instance of a class. You can create multiple
     * objects from the same class, each with its own set of data.
     * java
     */
    Car myCar = new Car();myCar.make="Toyota";myCar.model="Camry";myCar.start();

    /*
     * 2. *Inheritance*:
     * - Inheritance allows a class (subclass or derived class) to inherit
     * properties and behaviors from another class (superclass or base class). Java
     * supports single inheritance for classes.
     * - Example:
     */
    class Animal {
        void eat() {
            System.out.println("Animal is eating.");
        }
    }

    class Dog extends Animal {
        void bark() {
            System.out.println("Dog is barking.");
        }
    }

    /*
     * 3. *Polymorphism*:
     * - Polymorphism allows objects of different classes to be treated as objects
     * of a common superclass. Java supports polymorphism through method overriding.
     * - Example:
     */

    Animal myDog = new Dog(); // Polymorphism
    myDog.eat(); // Calls the overridden method in Dog class

    /*
     * 4. *Abstraction*:
     * - Abstraction involves hiding the complex implementation details and showing
     * only the necessary features of an object.
     * - Abstract classes and methods are used to achieve abstraction. Abstract
     * methods have no implementation in the superclass and must be implemented in
     * the subclass.
     * - Example:
     */
    abstract class Shape {
        abstract void draw(); // Abstract method with no implementation
    }

    class Circle extends Shape {
        void draw() {
            System.out.println("Drawing a circle.");
        }
    }

    /*
     * 5. *Encapsulation*:
     * - Encapsulation is the bundling of data (attributes) and methods (functions)
     * that operate on the data into a single unit called a class. Access to the
     * data is controlled through access modifiers (e.g., private, public,
     * protected).
     * - Example:
     */
    class Student {
        private String name;
        private int age;

        public void setName(String n) {
            name = n;
        }

        public String getName() {
            return name;
        }
    }

    /*
     * 6. *Interface*:
     * - An interface is a contract that defines a set of methods that a class
     * implementing the interface must provide. Multiple interfaces can be
     * implemented by a single class.
     * - Example:
     */

    interface Shape {
        void draw();
    }

class Circle implements Shape {
    public void draw() {
        System.out.println("Drawing a circle.");
    }
}

// These are the core OOP concepts in Java. They enable the creation of
// organized, reusable, and maintainable code by modeling real-world entities as
// objects and defining their behaviors.