// Find the first non-repeating character in a string

// Input : "aabbcde" , Output : "c"

// function nonRepeat(input) {
//   let mark = true;
// //   let i;
//    let j=0;
//   for (let i = 0; i < input.length; i++) {
//     if (input[i] != true && input[j]!=input[i]) {
//       return input[i];
//     } else {
//       input[i] = true;
//     }
//   }
// }
// console.log(nonRepeat('aabbcde'));

// input: [1, 2, 3, 4, 3, 5, 2, 1]
// Expected Output: [1, 2, 3]

function removeDuplicate(arr) {
  let ans = [];
  for (let i = 0; i < arr.length; i++) {
    for (let j = i+1; j < arr.length; j++) {
      if (arr[i] == arr[j]) {
        ans.push(arr[i]);
      }
    }
  }
  return ans;
}
console.log(removeDuplicate([1, 2, 3, 4, 3, 5, 2, 1]));
