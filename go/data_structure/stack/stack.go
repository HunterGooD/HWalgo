package main

type Stack struct {
	arr []int
}

func NewStack() *Stack {
	return &Stack{
		arr: make([]int, 0),
	}
}

func (s *Stack) Push(x int) {
	s.arr = append(s.arr, x)
}

func (s *Stack) Pop() int {
	x := s.arr[len(s.arr)-1]
	s.arr = s.arr[:len(s.arr)-1]
	return x
}

func (s *Stack) Clone() *Stack {
	var newS = NewStack()
	copy(newS.arr, s.arr)
	return newS
}

func (s *Stack) Free() {
	s.arr = []int{}
}
