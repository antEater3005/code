function swap(a, b) {
  var temp = a;
  a = b;
  b = temp;
}
function bubble(arr) {
  var swapped;

  for (var b = 0; b < arr.length; b++) {
    swapped = false;

    for (var a = 0; a < arr.length - b - 1; a++) {
      if (arr[a] < arr[a + 1]) {
        var temp = arr[a];
        arr[a] = arr[a + 1];
        arr[a + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped) {
      console.log("Array is already sorted.");
      break;
    }
  }
  console.log(arr);
}
var arr = [547, 235, 234, 63, 55, 43, 6, 5];
bubble(arr);
