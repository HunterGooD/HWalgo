package main

import (
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().Unix())
	// arr := []int{4, 3, 2, 1, 2, 5, 6, 7, 8, 1, 2, 54}
	// fmt.Println(bubleSort(arr))
	// fmt.Println(quickSort(arr))
}

func bubleSort(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
	return arr
}

func quickSort(arr []int) []int {
	if len(arr) == 0 {
		return []int{}
	}
	var (
		x              int
		selectedFirst  = arr[rand.Intn(len(arr))]
		selectedSecond = arr[rand.Intn(len(arr))]
		selectedThird  = arr[rand.Intn(len(arr))]
	)

	if (selectedFirst >= selectedSecond && selectedFirst <= selectedThird) || (selectedFirst <= selectedSecond && selectedFirst >= selectedThird) {
		x = selectedFirst
	} else if (selectedSecond >= selectedFirst && selectedSecond <= selectedThird) || (selectedSecond <= selectedFirst && selectedSecond >= selectedThird) {
		x = selectedSecond
	} else if (selectedThird >= selectedFirst && selectedThird <= selectedSecond) || (selectedThird <= selectedFirst && selectedThird >= selectedSecond) {
		x = selectedThird
	}

	equals := filterArray(arr, x, func(el, x int) bool {
		return el == x
	})

	left := quickSort(filterArray(arr, x, func(el int, x int) bool {
		return el < x
	}))
	right := quickSort(filterArray(arr, x, func(el int, x int) bool {
		return el > x
	}))

	left = append(left, equals...)
	return append(left, right...)
}

func filterArray(arr []int, x int, filter func(el int, x int) bool) []int {
	var res = make([]int, 0)
	for _, el := range arr {
		if filter(el, x) {
			res = append(res, el)
		}
	}
	return res
}
