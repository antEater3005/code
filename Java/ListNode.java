import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.TreeSet;
import java.util.function.Consumer;
import java.util.stream.LongStream;
import java.util.stream.Stream;

class Student {
    private String name;
    int rollNo;
    int standard;
    static String school;

    public Student(String name, int rollNo, int standard) {
        this.name = name;
        this.rollNo = rollNo;
        this.standard = standard;
    }

    static {
        school = "SDDTIC";
    }

    public void showDetails() {
        System.out
                .println("name : " + name + " roll no : " + rollNo + " Standard : " + standard + " School : " + school);
    }
}

// Base, Super, or Parent class
class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public int subtract(int a, int b) {
        return a - b;
    }
}

// Derived, Sub, Child class
// Java doesn't supports multiple inheritance
// All the constructors of a class have super() method which call the
// constructor of the parent class
class AdvanceCalculator extends Calculator {

    public int multiply(int a, int b) {
        return a * b;
    }

    public int divide(int a, int b) {
        return a / b;
    }

    // Method overriding: redefining the method of a parent class in the child class
    public int add(int a, int b) {
        int res = a + b;
        System.out.println("Call from Advance Calc.");
        return res;
    }
}

class ScientificCalculator extends AdvanceCalculator {
    public double power(int a, int b) {
        return Math.pow(a, b);
    }
}

enum Status {
    Running, Pending, Success, Failed
}

enum Laptops {
    Acer(10000), Asus(11000), Lenovo;

    private int price;

    // Default Constructor

    private Laptops() {
        this.price = 5000;
    }

    private Laptops(int price) {
        this.price = price;
    }

    public int getPrice() {
        return this.price;
    }

    public int setPrice(int price) {
        this.price = price;
        return this.price;
    }

}

/********************** INTERFACE ************************** */
// ! All methods are abstract
// ! All variables are final and static
interface Car {
    public void drive();

    public void refuel();

    public void maintenance();

}

class WagonR implements Car {
    int fuelCapacity = 20;
    int distance = 100;

    @Override
    public void drive() {
        System.out.println("Driving...");
    }

    @Override
    public void refuel() {
        System.out.println("Driving...");
    }

    @Override
    public void maintenance() {
        System.out.println("Driving...");
    }

    public void sell() {
        System.out.println("Sold");
    }
}

@FunctionalInterface
interface Add {
    public int add(int a, int b);
}

class NewException extends Exception {
    public NewException(String msg) {
        super(msg);
    }
}

class A extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Hii, from A.");
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
}

class B extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++)
            System.out.println("Hii, from B.");
    }
}

class Counter {
    int count;

    // The synchronized keyword makes sure that increment method is executed by a
    // single thread at any given time during the program execution.
    public synchronized void increment() {
        count++;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }

}

class Solution {
    private static final int MOD = 1_000_000_007;

    private int findMaxDepth(List<List<Integer>> adj, int node) {
        int maxDepth = 0;
        for (int nextNode : adj.get(node))
            maxDepth = Math.max(maxDepth, findMaxDepth(adj, nextNode));
        return maxDepth + 1;
    }

    private long power(int base, int exp) {
        long result = 1;
        long b = base % MOD;
        while (exp > 0) {
            if ((exp & 1) == 1)
                result = (result * b) % MOD;
            b = (b * b) % MOD;
            exp >>= 1;
        }
        return result;
    }

    public int assignEdgeWeights(int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < edges.length + 1; i++)
            adj.add(new ArrayList<>());
        for (int i = 0; i < edges.length; i++)
            adj.get(edges[i][0] - 1).add(edges[i][1] - 1);

        int len = findMaxDepth(adj, 0) - 1;
        return (int) power(2, len - 1);
    }
}

class Hello {

    public static void main(String a[]) {

        // Array
        // int num[] = { 1, 2, 3
        // int num2[] = new int[4];
        // for (int i = 0; i < num.length; i++) {
        // System.out.println(num[i]);
        // }
        // int array2[][] = new int[3][3];
        // for (int i = 0; i < array2.length; i++) {
        // for (int j = 0; j < array2[i].length; j++) {
        // array2[i][j] = (int) (Math.random() * 100);
        // System.out.print(array2[i][j] + " ");
        // }
        // System.out.println("");
        // }

        // for (int n[] : array2) {
        // for (int i : n) {
        // System.out.print(i + " ");
        // }
        // System.out.println("");
        // }

        /* *******************************String******************************** */
        // String name = "Navin";
        // String name2 = "Navin";
        // System.out.println(name);
        // System.out.println(name2);
        // String constant pool: it uses the object multiple times is values are same,
        // name and name2 have same address

        /* String Buffer */
        // StringBuffer sb = new StringBuffer("Hello");
        // System.out.println(sb.capacity());
        // it gives extra size of 16 character

        // String str = sb.toString();
        // System.out.println(str);
        // int num1 = 123;

        // Student s1 = new Student("Kamal", 132, 11);

        // s1.showDetails();
        // System.out.println(Student.school);

        // To load a class
        // Class.forName("Student");

        // Calculator c1 = new ScientificCalculator() {

        // // this is an anonymous inner class
        // public int add(int a, int b) {
        // System.out.println("From new add");
        // return a + b;
        // }
        // };
        // c1.add(12, 21);
        // String numx = "12345";

        // Integer i = Integer.parseInt(numx);
        // System.out.println(i.intValue());

        /********************************** ENUM ******************************* */
        // Status ss[] = Status.values();

        // for (Status s : ss)
        // System.out.println(s);

        // Status s = Status.Failed;
        // System.out.println(s.ordinal());
        // switch (s) {
        // case Failed:
        // System.out.println("Failed");
        // break;
        // case Success:
        // System.out.println("Success");
        // break;
        // case Pending:
        // System.out.println("Pending");
        // break;
        // case Running:
        // System.out.println("Running");
        // break;
        // default:
        // System.out.println("Cannot find Status");
        // break;
        // }

        // Laptops laps[] = Laptops.values();

        // for (Laptops lap : laps)
        // System.out.println(lap + ", Price: " + lap.getPrice());

        // for (Laptops lap : Laptops.values())
        // System.out.println(lap + ", Price: " + lap.getPrice());

        /******************* INTERFACE ***************** */
        // in this way we cannot access the instance variable and methods
        // Car car1 = new WagonR();
        // WagonR car2 = new WagonR();
        // car2.sell();

        // Add calc1 = new Add() {
        // public int add(int a, int b) {
        // return a + b;
        // }

        // };

        // Using Lambda expression the above code can be converted into the following
        // one
        // Add calc2 = (x, y) -> x + y;

        // System.out.println(calc1.add(12, 23));

        /********************** Exception Handling ************************** */
        // int x = 34;
        // int res = 0;
        // int arr[] = new int[10];
        // try {
        // res = 16 / x;
        // if (res == 0)
        // throw new NewException("Result cannot be zero.");
        // } catch (NewException e) {
        // // TODO : handle exception
        // res = 18 / 1;
        // System.out.println("Error: " + e.getMessage());
        // } catch (ArrayIndexOutOfBoundsException e) {
        // System.out.println("Error: " + e.getMessage());
        // } catch (Exception e) {
        // System.out.println("Error: " + e.getMessage());
        // } finally {
        // System.out.println("Operation completed.");
        // }

        // System.out.println(res);
        // System.out.println("Hii");

        /********************** Input ************************** */

        // String m = "";

        // Method 1
        // BufferedReader br = null;
        // try {
        // br = new BufferedReader(new InputStreamReader(System.in));

        // // br.readLine(); method only takes string input, we have to convert it into
        // // integer using Integer.parseInt(); method
        // m = br.readLine();
        // // bf.close(); // Close this resource in finally block
        // } catch (Exception e) {
        // // TODO: handle exception
        // System.out.println("Error: " + e.getMessage());
        // } finally {
        // try {
        // br.close();
        // } catch (IOException e) {
        // // TODO Auto-generated catch block
        // e.printStackTrace();
        // }
        // }

        // Method 2 : The br will automatically release the resources

        // try (BufferedReader br = new BufferedReader(new
        // InputStreamReader(System.in))) {

        // // br.readLine(); method only takes string input, we have to convert it into
        // // integer using Integer.parseInt(); method
        // m = br.readLine();
        // // bf.close(); // Close this resource in finally block
        // } catch (Exception e) {
        // // TODO: handle exception
        // System.out.println("Error: " + e.getMessage());
        // }
        // System.out.println(m);

        // Other Method
        // Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
        // System.out.println(n);

        /*************************** THREADS & RUNNABLES **************************/

        // A obj1 = new A();
        // B obj2 = new B();
        // obj1.start();
        // obj2.start();

        // Counter cntr = new Counter();
        // Runnable obj3 = new Runnable() {
        // @Override
        // public void run() {
        // for (int i = 0; i < 5000; i++) {
        // // System.out.println("Hello");
        // // try {
        // // Thread.sleep(10);
        // // } catch (Exception e) {
        // // // TODO: handle exception
        // // e.printStackTrace();
        // // }

        // cntr.increment();
        // }
        // }
        // };
        // // initialization using anonymous class
        // Runnable obj4 = new Runnable() {
        // @Override
        // public void run() {
        // for (int i = 0; i < 5000; i++) {
        // // System.out.println("Hii");
        // // try {
        // // Thread.sleep(10);
        // // } catch (Exception e) {
        // // e.printStackTrace();
        // // }
        // cntr.increment();
        // }
        // }
        // };

        // initialization using lambda expression
        // Runnable obj5 = () -> {
        // for (int i = 0; i < 5; i++) {
        // System.out.println("Bonjour");
        // try {
        // Thread.sleep(10);
        // } catch (Exception e) {
        // e.printStackTrace();
        // }
        // }
        // };

        // Thread t1 = new Thread(obj3);
        // Thread t2 = new Thread(obj4);
        // // Thread t3 = new Thread(obj5);

        // t1.start();
        // t2.start();
        // try {
        // t1.join();
        // t2.join();
        // } catch (InterruptedException e) {
        // // TODO Auto-generated catch block
        // e.printStackTrace();
        // }

        // System.out.println(cntr.count);
        // t3.start();

        /*************************** Collections **************************/

        // List<Integer> nums = new ArrayList<Integer>();
        // nums.add(6);
        // nums.add(4);
        // nums.add(3);
        // nums.add(5);

        // System.out.println(nums.indexOf(3));
        // for (int n : nums)
        // System.out.println(n);

        // ************** HashSet or set

        // Set<Integer> set = new HashSet<Integer>();
        // Set<Integer> set = new TreeSet<Integer>(); // same as HashSet but the values
        // are sorted
        // set.add(54);
        // set.add(2);
        // set.add(4);
        // set.add(6);

        // Iterator<Integer> iterator = set.iterator();
        // for (; iterator.hasNext();) {
        // System.out.println(iterator.next());
        // }

        // for (int e : set)
        // System.out.println(e);

        // * Map

        // Map<String, Integer> map = new HashMap<>();
        // Map<String, Integer> map2 = new Hashtable<>(); // Hashtable is synchronized:
        // only a single thread can access at a time.

        // map.put("Navin", 125);
        // map.put("Sakshi", 110);
        // map.put("Naman", 135);
        // map.put("Pooja", 125);
        // map.replace("Navin", 145);
        // System.out.println(map.get("Navin"));

        // for (String name : map.keySet())
        // System.out.println(name);

        /******** Sorting **********/
        List<Integer> list2 = Arrays.asList(2, 7, 3, 4, 7, 9, 12);

        // Comparator<Integer> comp = new Comparator<Integer>() {
        // // * Comparator takes Class objects as input.
        // @Override
        // public int compare(Integer o1, Integer o2) {
        // /** Increasing order */
        // // return o1 - o2;

        // /** Decreasing order */
        // return o2 - o1;
        // }
        // };

        // System.out.println(list2);
        // Collections.sort(list2, (o1, o2) -> o1 - o2);
        // System.out.println(list2);

        /******** ForEach method *********** */

        // * Create a reference for Consumer and then pass it to forEach method */
        // Consumer<Integer> consumer = t -> {
        // System.out.print("Hello -> ");
        // System.out.println(t);
        // };
        // list2.forEach(consumer);
        // // * Use lambda expression directly into the forEach method */
        // list2.forEach(t -> {
        // System.out.print("Hello -> ");
        // System.out.println(t);
        // });

        /************ Stream **************/
        /**
         * It provides stream of elements and elements are copy not the actual one, so
         * it will not affect the actual list
         * It can only be used once
         */

        // Stream<Integer> stream = list2.stream();
        // Stream<Integer> stream2 = stream.filter(n -> n % 2 == 0);/*
        // * Filter method Takes Predicate object as input which
        // * is a
        // * functional interface with test method
        // */
        // Stream<Integer> stream3 = stream2.map(n -> n * 2);
        // // * returns a single value of same type */

        // int res = stream3.reduce(0, (c, e) -> c + e);

        // int res2 = list2.stream().filter(n -> n % 2 == 0).map(n -> n * 2).reduce(0,
        // (c, e) -> c + e);

        // // stream3.forEach(n -> System.out.println(n));
        // System.out.println(res + " " + res2);

        /***********
         * LVTI = Local variable Type Inference *********
         * var keyword can be used instead of the type, the compiler will infer the type
         * it can only be used for local variables, which are only meant for processing
         * and not for storage, like instance variable
         */

        // var array = Arrays.asList(1, 2, 3, 4, 5, 3);
        // for (int i : array)
        // System.out.println(i);

    }
}
