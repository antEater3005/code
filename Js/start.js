console.log("Tutorial start's from here!");
var a = confirm("Press a button!"); // It displays a warning and takes you input in yes or no form and return to the console.
if (a == true) {
  console.log("You pressed ok!");
} else {
  alert("You pressed cancel");
}
var person1 = "John Doe";
var person2 = "Satyansh";
console.log(person1, person2);
var joined = person1.concat(person2); // It joins the two strings
console.log(joined);
console.log(joined.charAt(9)); // it returns the character at the specified index;
console.log(joined.charCodeAt(9)); // it returns the ASCII code value of the character at the specified index;
console.log(String.fromCharCode(97)); // It changes ASCII code into a character;
console.log(person2.indexOf("a")); // it returns the index of the first occurrence of the character.
var inp;
console.log(prompt(inp)); // It opens a window and takes input.
/* Following are some array methods */

const items = [
  { name: "Bike", Price: 100 },
  { name: "Tv", Price: 20 },
  { name: "Phone", Price: 80 },
  { name: "Album", Price: 10 },
  { name: "Computer", Price: 500 },
  { name: "Keyboard", Price: 7 },
  { name: "Car", Price: 900 },
];
// 1. The filter method filters the array with some conditions
const FilteredItems = items.filter((items) => {
  return items.Price >= 100;
});
console.log(FilteredItems);
console.log(items);
// 2.The map method create an array of items of a different in a array.
// like in the below example the new array items can be of prices or the names of the items.
const itemsNames = items.map((items) => {
  return items.name;
});
console.log(itemsNames);
// 3. The 'Find' method finds the element in the array and returns the item's first match in the array, If the element is note there it returns null.
const FindItem = items.find((items) => {
  return items.name === "Bike"; // the three equal sign means the the value and type both are same.
});
console.log(FindItem);
// 4. The 'forEach' method log the values of all the items in an array.
items.forEach((items) => {
  console.log(items.name);
});
// 5. The some method is almost same as 'Filter' method instead it returns true or false.
// In the following example the condition i.e., 'items.Price <= 0' is checked, if there is any item which has price less the '0' the the function returns true else false. In this case it's false.
// the return type of this function is boolean
const hasInexpensiveItems = items.some((items) => {
  return items.Price <= 0;
});
console.log(hasInexpensiveItems);
// 6. The 'every' method is same as the some method instead it return true only if all the items in the array satisfy the condition.
// In the following example the condition that is the price of every item in the array is greater than '5' is true so it logs true.
const Every = items.every((items) => {
  return items.Price > 5;
});
console.log(Every);
// 7.The Total method add the values of the items. The currentTotal is updated in every iterations.
const total = items.reduce((currentTotal, items) => {
  return items.Price + currentTotal;
}, 0);
console.log(total);
// 8. The includes method checks wether it contains an item or note, It's return type is Boolean.
const item2 = [1, 2, 43, 54, 564, 67, 44];
const includes = item2.includes(564 && 1); // We can pass two arguments in the include method by clubbing it with logical operators.
console.log(includes);

let name = "Hariom";
let lastName = "Tiwari";
console.log(typeof name);
console.log(typeof lastName);

let greeting = document.getElementById("greet");
let name2 = "Avinash,";
let gre = " Welcome to this Js tutorial";
gre += "👋";
greeting.innerHTML = name + gre;
console.log(name + gre);
