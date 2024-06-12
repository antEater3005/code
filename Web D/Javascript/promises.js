// let promise = new Promise((resolve, reject) => {
//   let a = 3 + 2;
//   if (a == 5)
//     resolve(
//       console.log(`Promise completed! issue is resolved.Value of a is ${a}`)
//     );
//   else
//     reject(
//       console.log(
//         `Promise not completed! Issue not resolved and the value of a is ${a}`
//       )
//     );
// });
// promise
//   .then((message = "Hello") => console.log(`This is from then ${message}`))
//   .catch((message = "Hello") =>
//     console.log(`This is from the catch ${message}`)
//   );

// //   then: is called if the promise is resolved and the catch: is called if the promise is not resolved

// const userLeft = false;
// const userWatchingCatMeme = false;

// function watchTutorialCallback(callback, errorCallback) {
//   if (userLeft) {
//     errorCallback({
//       name: "user left",
//       message: ":(",
//     });
//   } else if (userWatchingCatMeme) {
//     errorCallback({
//       name: "user watching cat meme",
//       message: "web dev simplified <cat",
//     });
//   } else callback("Thumbs up and subscribe");
// }
 