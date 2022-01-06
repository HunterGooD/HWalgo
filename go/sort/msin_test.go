package main

import (
	"math/rand"
	"sort"
	"testing"

	"github.com/stretchr/testify/require"
)

const MAX_LENGTH_ARRAY = 2 << 20

type testStrc struct {
	test   []int
	answer []int
}

var testExamples = []testStrc{
	{
		test:   []int{4, 3, 2, 1, 2, 5, 6, 7, 8, 1, 2, 54},
		answer: []int{1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 54},
	},
}

var randomTests = make([]testStrc, 10)

func TestMain(m *testing.M) {
	for i := 0; i < 10; i++ {
		arr := make([]int, rand.Intn(MAX_LENGTH_ARRAY))

		for i := range arr {
			arr[i] = rand.Intn(100)
		}

		var res = make([]int, len(arr))
		copy(res, arr)
		sort.Slice(res, func(i, j int) bool {
			return res[i] < res[j]
		})

		randomTests[i] = testStrc{
			test:   arr,
			answer: res,
		}
	}
	m.Run()
}

func TestQuickSort(t *testing.T) {
	for _, el := range testExamples {
		require.Equal(t, el.answer, quickSort(el.test))
	}
}

func TestBubleSort(t *testing.T) {
	for _, el := range testExamples {
		require.Equal(t, el.answer, bubleSort(el.test))
	}
}

func TestQuickSortRandomValues(t *testing.T) {
	for _, el := range randomTests {
		require.Equal(t, el.answer, quickSort(el.test))
	}
}
