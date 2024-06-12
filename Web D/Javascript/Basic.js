// javasript does not need a compiler to work, it can run on web browser like Mozilla firefox,Chrome,safari,internet explorer.
// Mainly used for web development and web applications.
// its also used in smartwatches.
//  variables its name of memory location which acts as a container for storing data.
// constants  these are data types of fixed values which do not change during the execution time.
const pi = 3.144;

console.log(pi); //console.log() same as cout in c++.

let name = 'Devendra Singh';
let age = 1;
console.log(name);
console.log(age);
let option = true;
console.log(option);
let height;
console.log(height);

let shopping = [];
shopping = ['paintbrush', 'pencil', 'canvas'];
console.log(shopping);
let numbers = [];
numbers = [1, 3, 54, 6, 87, 89, 9];
console.log(numbers[1] + numbers[2]);
console.log(numbers.sort());
numbers.push(4);
console.log(numbers);
// An example of array with various data type;
let mix = [];
mix = ['one', 1, 'three', 3];
console.log(mix);


// Object: its also same as object in c++;
// example
let pen = {
    type: 'ballpoint',
    color: 'black',
    cost: 10
};
//various ways to access the data of the object;
// objectname.propertyname --> this method is known as the  dot notation
//objectname['propertyname']
console.log(pen.cost);
console.log(pen.color);
console.log(pen['type'])
// example 2
let Anjani = {
    age: 24, school: 'DPS',
    class: '10th std',
    subjects: ['physics', 'chemistry', 'biology', 'maths']
};
console.log(Anjani.subjects[1]);

// Functions:its a block of organized code that can be used to perform a single task and can be reused.
//example;
function hello() {
    console.log("Hello World");
}
hello();
// Example 2
function product1(a, b) {
    console.log(a * b);
}
function product2(a, b) {  // here a and b are  parameter;
    return a * b;
}
console.log(product2(3, 7)); // here 3 and 7 are called arguments.
product1(4, 3);
let x = product2(5, 8);
console.log(x);
// conditional statements: these are specified functions which only executes when a defined condition is met. like  if-else.
let number = [3, 45, 6, 6, 5, 3, 8, 6, 7, 2, 2, 1, 0];
if (number[3] >= 33) {
    console.log("The given number is greater or equal to the number at number[4");
}
else {
    console.log("This is been printed by the else statement.")
}

// Loops:its used to repeat a block of code specified inside the loop with different values until some end conditions are not met.
let e = 4;
while (e) {
    console.log(number[e]);
    e--;

}
// as same do while loop
//  for loop
// example
for (let i = 0; i < 5; i++) {
    console.log("the number is" + " " + i);
}
// Switch cases are also same as in c++.
// example

function first() {
    let z;
    z = prompt("please enter a number")
    let x = z % 2;
    switch (x) {
        case  0: console.log("The number is divisible by 2");
            break;
        case 1: console.log("The number is not divisible by 2");
        default:
            console.log("Invalid Input");
    }
}