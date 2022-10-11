// parent class
class Person { 
    constructor(name) {
        this.name = name;
    }

    greet() {
        console.log(`Hello ${this.name}`);
    }
}

// inheriting parent class
class Student extends Person {

    constructor(name) {
    
        console.log("Creating student class");
        
        // call the super class constructor and pass in the name parameter
        super(name);
    }

}

let student1 = new Student('Affan');
student1.greet();