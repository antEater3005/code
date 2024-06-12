// variables var, let & const : let and const has block level scope;
// value of const cannot be changed or reassigned;

const name = "Avinash"; //string: it can be enclosed in a single or double quotes;
const age = 20; // number
const rating = 2.4; // its also a number because js does not have any float datatype
const isCool = true; // boolean data types
const x = null; // null data type
const y = undefined; //undefined data type
let z; // this is also an un defined data types

// concatenation
console.log("My name is " + name + " and I am " + age); // older method
// from ES6 using template string
console.log(`My name is ${name} and I am ${age}`);
// The above string can be assigned to a variable;
const my = `My name is ${name} and I am ${age}`;
console.log(my);

const s = "Hello World!";
console.log(s.length); // method for string to find the length of a string
console.log(s.substring(0, 5)); // spits out a substring

// split a method make an array from string
console.log(s.split("")); // the parameter given to the split method if '' that is nothing so it will split the array by a single character

const str = "technology, computers, IT, Code, CP"; // in this example each word of string is separated by ', '
console.log(str.split(", "));

// Array - variable that holds multiple values
// Method to initialize an array
// Method 1 : Using inbuilt constructor
const numbers = new Array(1, 2, 3, 4, 5);
console.log(numbers);
// Method 2:directly assigning the values
const fruits = ["apples", "oranges", "pears", 10, true]; // in  javascript the same array can carry different data types

// we can add data by
fruits[5] = "mangos";
// and can also be added using a push method, We should use this method because we don't know the size of an array
fruits.push("Pineapple");
// To add anything at the beginning we use unshift method
fruits.unshift("Strawberry");
console.log(fruits);
fruits.pop(); // pops out the last element;
console.log(fruits);

console.log(Array.isArray(fruits)); // it returns a bool value that whether something is an array or not: in this case it returns the true
console.log(Array.isArray("Hello")); // it returns false because the argument passed is a string
console.log(fruits.indexOf("oranges")); // it returns the index of the element passed in method if not present it will return -1;
// JavaScript is not a statically typed language that means during initializing of the variables we don't need to specifically define the data type.

// Javascript Literals:A JavaScript object literal is a comma-separated list of name-value pairs wrapped in curly braces;
//for example
const person = {
  name: {
    firstName: "John",
    lastName: "Doe",
  },
  age: 30,
  hobbies: ["music", "sports", "movies"],
  address: {
    street: "50 main street",
    city: "Boston",
    state: "MA",
  },
};

console.log(person);
// We can also access only some data from the object by using '.' operator;
console.log(person.name.firstName, person.name.lastName);
// Suppose we need the 2nd hobby of the person, we can get that by;
console.log(person.hobbies[1]); // since there is 0 based indexing the second element has index of 1;

// Destructuring: Destructuring is a JavaScript expression that allows us to extract data from arrays, objects, and maps and set them into new, distinct variables. Destructuring allows us to extract multiple properties, or items, from an array​ at a time.

// for example we want to extract first name and last name;
const {
  name: { firstName, lastName },
  address: { city },
} = person;
console.log(firstName, lastName, city);

// We can also create arrays of object;
const todos = [
  {
    id: 1,
    text: "Take out trash",
    isComplete: true,
  },
  {
    id: 2,
    text: "Wash cloths",
    isComplete: true,
  },
  {
    id: 3,
    text: "Fill the bottles",
    isComplete: false,
  },
];

// JSON:JavaScript Object Notation (JSON) is a standard text-based format for representing structured data based on JavaScript object syntax. It is commonly used for transmitting data in web applications (e.g., sending some data from the server to the client, so it can be displayed on a web page, or vice versa);

// to convert an object into JSON format there is function in Js known as JSON.stringify(); we have to pass the object as argument in the function
// For example:
const todosJSON = JSON.stringify(todos);
console.log(todosJSON);

// //Loops:: For
// for(let i=0;i<10;i++){
//     console.log(`For loop number:${i}`);
// }
// // While loop
// let i=0
// while(i<10){
//     console.log(`While loop number:${i}`);
//     i++;
// }
// For example if we want to log all the tasks;
for (let i = 0; i < todos.length; i++) {
  console.log(`Id:${todos[i].id} and task:${todos[i].text}`);
}
// the above thing can be done by another way:
for (let todo of todos) {
  console.log(`Task:${todo.text}`);
}
// Higher order array methods: forEach,filter,map;
// 1:forEach(); it takes an iterator and a function as arguments
todos.forEach(function (todo) {
  console.log(todo.text);
});
// 2:.map(); This will return an array of specified property using the array function passed; here the task variable is an array containing the tasks or formally texts present in the objects of todos array.
const tasks = todos.map(function (todo) {
  return todo.text;
});
console.log(tasks);
// Let's take another example, here we want the tasks which are completed then we use filter method so, the code for the former is

const completedTasksObj = todos.filter(function (todo) {
  return todo.isComplete === true;
});
console.log(completedTasksObj); // it log the whole object of todo which are completed

const completedTasks = todos
  .filter(function (todo) {
    return todo.isComplete === true;
  })
  .map(function (todo) {
    return todo.text;
  });
console.log(completedTasks); // it log the task of todos which are completed

// Conditional statement
const num = "10";
if (num == 10)
  // the double equal checks whether the num is equal to 10; it performs the type change and then compares
  console.log("true");

if (num === 10) console.log("True");
// the triple equal checks whether the value as well as the types are same or not: in this example the num is a string whereas it's compared to a number So,it returns false;
else console.log("false");

// We can also use different test conditions combined with each other using OR(||) and AND(&&) operator, these are known as conditional operators;

// Ternary Operator(?):this a shorthand form of if else condition
// For example:
const color = num > 10 ? "Red" : "Blue"; // if the condition is met first value i.e., "Red" is assigned to the variable color else "Blue" is assigned;
console.log(color);

// Switch:this is a shorthand form of writing multiples if conditions for a single variable;
// For example:
const inp = 20;

switch (inp) {
  case 10:
    console.log("Red");
    break;
  case 20:
    console.log("Black");
    break;
  case 30:
    console.log("White");
    break;
  default:
    console.log("Error");
}

// functions:

function addNums(num1, num2) {
  console.log(num1 + num2);
}
addNums(); // it will log NaN:Not a Number

// if we assign values to the parameter then, if any argument is not passed during function call it takes default values and if the arguments are passed it will override the default values.
function addNums2(num1 = 3, num2 = 5) {
  console.log(num1 + num2);
}
addNums2(); // it will log 8 by taking the default values
addNums2(4, 8);

// Arrow function helps to write shorter syntax
//For example
const multi = (a, b) => a * b; // We don't need to use return keyword to return anything; the parameter braces can also be eliminated if there is a single parameter to pass
console.log(multi(2, 7));

// example 2;
todos.forEach((todo) => console.log(todo.text));

// Object-Oriented Programming in Js

//  Constructor function
// The constructor function should start with a capital letter
function Person(firstName, lastName, DOB) {
  this.firstName = firstName;
  this.lastName = lastName;
  this.DOB = new Date(DOB); // The date is made an object using built-in constructor:: The format for date is mm-dd-yyyy;
  // In the constructor we can add methods on the Person object using functions or for simplicity an Arrow function;
  //For example
  this.getBirthYear = () => this.DOB.getFullYear();
  //Example 2:user defined to get the full name of person
  this.getFullName = () => `${this.firstName} ${this.lastName}`;
}
// Object instantiation
const person1 = new Person("John", "Doe", "3-28-1996");
const person2 = new Person("Sam", "Sung", "11-7-1993");
console.log(person1, person2.DOB.getMonth());
console.log(person2.getBirthYear()); // .getBirthYear() is a user defined method which returns the year of birth;
console.log(person1.getFullName()); // .getFullName() is a user defined method which returns the Full Name;

// Prototype Based programming::Prototypes are the mechanism by which JavaScript objects inherit features from one another.
const ob = new Objects("Furniture", "Reusable", ["Sofa", "Chair", "Table"]); // here we used the Objects constructor before it's defined.That is the main difference b/w classes declaration and function declaration
console.log(ob);
function Objects(name, type, content) {
  this.name = name;
  this.content = content;
  this.type = type;
}
// The examples of prototype
// every object has some predefined methods associated with itself prototyping allows us to add more methods to the library;
// ALERT:: We cannot use Arrow function(=>) in prototyping because it is logically equivalent to (the following isn't valid code since you can't have a variable named this):
/*(function(this){
  // code that uses "this"
})(this) */
Objects.prototype.getName = function () {
  return `${this.name}`;
};
Objects.prototype.getType = function () {
  return this.type;
};
Objects.prototype.getContent = function () {
  return this.content;
};
const object1 = new Objects("Dry-fruits", "consumables", [
  "Almond",
  "Raisin",
  "Cashew",
  "Walnut",
]);
const object2 = new Objects("Cloths", "Dressing", [
  "Shirt",
  "Trouser",
  "Pants",
  "Jacket",
]);
console.log(object2.getName(), object2.getType(), object2.getContent());

//Classes::classes are a template for creating objects. They encapsulate data with code to work on that data. Classes in JS are built on prototypes but also have some syntax and semantics that are not shared with ES5 class-like semantics.

// For Example
class Person2 {
  constructor(firstName, lastName, dob) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
  }
  // here we can define functions
  getFulYear = () => this.dob.getFullYear();
  // 2:there are many ways to do these things
  // getFullName = () => `${this.firstName} ${this.lastName}`;
  // getFullName = () => this.firstName + " " + this.lastName;
  getFullName() {
    return `${this.firstName} ${this.lastName}`;
  }
}
const person_x = new Person2("Will", "Smith", "12-4-1983");
console.log(person_x, person_x.getFulYear(), person_x.getFullName());
// We cannot use class declaration to create an object before it's defined but an object declaration can be.

/*
// From here we work on a basic form::DOM manipulation

console.log(window);

//Element selectors
// 1:: Single element selector
console.log(document.getElementById("my-form"));
console.log(document.querySelector("h1"));

// 2:: Multi element selector
console.log(document.querySelectorAll(".item")); // This gives an array known as NodeList over which we can use array methods
console.log(document.getElementsByClassName("item")); // like .querySelectorAll() this selector gives an array known as HTMLCollection but we cannot use array methods on it, to use array methods we need to convert the collection into array manually.
// there are various methods to convert htmlcollection to array
// 1. using Array.from() :: const arr=Array.from(htmlcollection);
// 2. using spread operator :: const arr=[...htmlcollection];
console.log(document.getElementsByTagName("li")); // gives HTMLCollections
const items = document.querySelectorAll(".item"); // items refers to the node list returned by the querySelectorAll
items.forEach((item) => console.log(item));

const ul = document.querySelector(".items");
// ul.remove() // this will remove the unordered list
ul.lastElementChild.remove(); // this will remove the last child of the element ul;

// to change content of an element or child of an element
ul.firstElementChild.textContent = "Hello";

// to select any intermediate child of an element: as we know the "query selector all" return a nodeList array having 0 based indexing so we use it
ul.children[1].innerHTML = "<h5><em>Will Smith</em></h5>";

const btn = document.querySelector(".btn");
btn.style.background = "orange"; // This will change the style i.e., button background colour

// Event handling
btn.addEventListener("click", (e) => {
  e.preventDefault();
  document.querySelector("#my-form").style.background = "#ccc";
  document.querySelector("body").classList.add("bg-dark");
  ul.lastElementChild.innerHTML = "<h1>Hello! Will Smith</h1>";
  alert('You have successfully submitted the form.')
});
*/
const myForm = document.querySelector("#my-form");
const nameInput = document.querySelector("#name");
const emailInput = document.querySelector("#email");
const message = document.querySelector(".msg");
const users = document.querySelector("#users");

myForm.addEventListener("submit", onSubmit);
function onSubmit(e) {
  e.preventDefault();
  if (nameInput.value === "" || emailInput.value === "") {
    message.classList.add("error");
    message.innerHTML = "Please enter all fields";
    setTimeout(() => message.remove(), 3000);
  } else {
    const li = document.createElement("li"); // Creates a new element
    li.appendChild(
      document.createTextNode(`${nameInput.value}:${emailInput.value}`)
    ); // appending a value to the created element
    users.appendChild(li); // appending the created element to an html element
    // clear fields
    nameInput.value = "";
    emailInput.value = "";
  }
}