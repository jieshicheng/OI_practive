package main

import "fmt"

func flipAndInvertImage(A [][]int) [][]int {
    for _, arr := range A {
        start := 0
        end := len(arr) - 1

	for start <= end {
            arr[start], arr[end] = 1 - arr[end], 1 - arr[start]
            start++
            end--
        }
    }
    return A
}

func main() {
    martix := [][]int{{0, 0, 1}, {1, 0, 0}}

    ans := flipAndInvertImage(martix)
    for _, arr := range ans {
	for _, val := range arr {
	    fmt.Printf("%d ", val);
	}
	fmt.Printf("\n");
    }
}
